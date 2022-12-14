/*!
 * \file d_mid0038.cpp
 * \brief file for the definition of the class "DMid0038"
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
#include "d_mid0038.h"

#define REGISTER_RESPONSES() valid_responses.append({MID0004, MID0005})

void DMid0038::processData(QByteArray data_byte_array)
{
    if (header->revision <= 1)
        data_fields.insert(0, data_byte_array.mid(0, 2));

   if (header->revision == 2)
       data_fields.insert(0, data_byte_array.mid(0, 4));
}

DMid0038::DMid0038(QByteArray arr)
    : DOpenProtocolMid(arr)
{
    DMid0038::processData(arr.mid(20, -1));
    REGISTER_RESPONSES();
}

DMid0038::DMid0038(QMap<int, QByteArray> args, int spindle_id) : DMid0038(-1, args, spindle_id)
{}

DMid0038::DMid0038(int revision, QMap<int, QByteArray> args, int spindle_id)
    : DMid0038(revision, args, spindle_id, 1)
{}

DMid0038::DMid0038(int revision, QMap<int, QByteArray> args, int spindle_id, int station_id)
{
    data_fields = args;
    QString header_str = formatNumber(getDataFieldsLength() + 20, 4);
    header_str += "0038";
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
