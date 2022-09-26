/*!
 * \file d_mid0041.cpp
 * \brief file for the definition of the class "DMid0041"
 * \author poles
 * \date 2022-09-23
 *
 * \details
 *
 * \copyright
 ****************************************************************************
 *        Ce logiciel est la propriete de DOGA®.
 *         -------------------------------------
 *
 *    Il ne peut etre reproduit ni communique en totalite ou partie sans
 *    son autorisation ecrite.
 *
 ****************************************************************************
 *        This software is the property of DOGA®.
 *         -------------------------------------
 *
 *    It cannot be reproduced nor disclosed entirely or partially without
 *    a written agreement.
 *
 ****************************************************************************
 */

#include "mids/d_mid0041.h"

#define REGISTER_RESPONSES() valid_responses.append({})

void DMid0041::processData(QByteArray data_byte_array)
{
    data_fields.insert(1, data_byte_array.mid(2, 14)); // Tool serial number
    data_fields.insert(2, data_byte_array.mid(18, 10)); // Tool number of tightening
    data_fields.insert(3, data_byte_array.mid(30, 19)); // Last calibration date
    data_fields.insert(4, data_byte_array.mid(51, 10)); // Controller serial number

    if (header->revision == 2)
    {
        data_fields.insert(5, data_byte_array.mid(63, 6)); // Calibration Value
        data_fields.insert(6, data_byte_array.mid(71, 19)); // Last Service Date
        data_fields.insert(7, data_byte_array.mid(92, 10)); // Tightening since service
        data_fields.insert(8, data_byte_array.mid(104, 2)); // Tool type
        data_fields.insert(9, data_byte_array.mid(108, 2)); // Motor size
        data_fields.insert(10, data_byte_array.mid(112, 3)); // Open end data
        data_fields.insert(11, data_byte_array.mid(117, 19)); // Controller software version
    }
}

DMid0041::DMid0041(QByteArray arr)
    : DOpenProtocolMid(arr)
{
    DMid0041::processData(arr.mid(20, -1));
    REGISTER_RESPONSES();
}

DMid0041::DMid0041(QMap<int, QByteArray> args, int spindle_id) : DMid0041(-1, args, spindle_id)
{}

DMid0041::DMid0041(int revision, QMap<int, QByteArray> args, int spindle_id)
    : DMid0041(revision, args, spindle_id, 1)
{}

DMid0041::DMid0041(int revision, QMap<int, QByteArray> args, int spindle_id, int station_id)
{
    data_fields = args;
    QString header_str = formatNumber(getDataFieldsLength() + 20, 4);
    header_str += "0041";
    header_str += revision < 0 ? "   " : formatNumber(revision, 3);
    header_str += '0'; // No ack flag
    header_str += formatNumber(station_id, 1); // Station ID
    header_str += formatNumber(spindle_id, 2); // spindle_id
    header_str += "     "; // 5 space reserved

    header = std::make_shared<DOpenProtocolHeader>(header_str);
    REGISTER_RESPONSES();

    // Assign MID enum from its ID
    mid_ID = static_cast<midType>(header->mid);
}

