/*!
 * \file d_mid0013.cpp
 * \brief file for the definition of the class "DMid0013"
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

#include "mids/d_mid0013.h"

#define REGISTER_RESPONSES() valid_responses.append({})

void DMid0013::processData(QByteArray data_byte_array)
{
    data_fields.insert(1, data_byte_array.mid(2, 3)); // Parameter set ID
    data_fields.insert(2, data_byte_array.mid(7, 25)); // Parameter set name
    data_fields.insert(3, data_byte_array.mid(34, 1)); // Rotation direction
    data_fields.insert(4, data_byte_array.mid(37, 2)); // Batch size
    data_fields.insert(5, data_byte_array.mid(41, 6)); // Torque min
    data_fields.insert(6, data_byte_array.mid(49, 6)); // Torque max
    data_fields.insert(7, data_byte_array.mid(57, 6)); // Torque final target
    data_fields.insert(8, data_byte_array.mid(65, 5)); // Angle min
    data_fields.insert(9, data_byte_array.mid(72, 5)); // Angle max
    data_fields.insert(10, data_byte_array.mid(79, 5)); // Final angle target
}

DMid0013::DMid0013(QByteArray arr)
    : DOpenProtocolMid(arr)
{
    DMid0013::processData(arr.mid(20, -1));
    REGISTER_RESPONSES();
}

DMid0013::DMid0013(QMap<int, QByteArray> args, int spindle_id) : DMid0013(-1, args, spindle_id)
{}

DMid0013::DMid0013(int revision, QMap<int, QByteArray> args, int spindle_id)
    : DMid0013(revision, args, spindle_id, 1)
{}

DMid0013::DMid0013(int revision, QMap<int, QByteArray> args, int spindle_id, int station_id)
{
    data_fields = args;
    QString header_str = formatNumber(getDataFieldsLength() + 20, 4);
    header_str += "0013";
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

