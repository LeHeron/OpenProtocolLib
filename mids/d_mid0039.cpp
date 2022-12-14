/*!
 * \file d_mid0039.cpp
 * \brief file for the definition of the class "DMid0039"
 * \author poles
 * \date 2022-9-16
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
#include "d_mid0039.h"

#define REGISTER_RESPONSES() valid_responses.append({MID0004, MID0033})

void DMid0039::processData(QByteArray data_byte_array)
{
    data_fields.insert(0, data_byte_array.mid(0, 2));
}

DMid0039::DMid0039(QByteArray arr)
    : DOpenProtocolMid(arr)
{
    DMid0039::processData(arr.mid(20, -1));
    REGISTER_RESPONSES();
}

DMid0039::DMid0039(QMap<int, QByteArray> args, int spindle_id) : DMid0039(-1, args, spindle_id)
{}

DMid0039::DMid0039(int revision, QMap<int, QByteArray> args, int spindle_id)
    : DMid0039(revision, args, spindle_id, 1)
{}

DMid0039::DMid0039(int revision, QMap<int, QByteArray> args, int spindle_id, int station_id)
{
    data_fields = args;
    QString header_str = formatNumber(getDataFieldsLength() + 20, 4);
    header_str += "0039";
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
