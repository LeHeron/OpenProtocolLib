/*!
 * \file d_mid0043.cpp
 * \brief file for the definition of the class "DMid0043"
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

#include "mids/d_mid0043.h"

#define REGISTER_RESPONSES() valid_responses.append({MID0005})

void DMid0043::processData(QByteArray data_byte_array)
{

}

DMid0043::DMid0043(QByteArray arr)
    : DOpenProtocolMid(arr)
{
    DMid0043::processData(arr.mid(20, -1));
    REGISTER_RESPONSES();
}

DMid0043::DMid0043(QMap<int, QByteArray> args, int spindle_id) : DMid0043(-1, args, spindle_id)
{}

DMid0043::DMid0043(int revision, QMap<int, QByteArray> args, int spindle_id)
    : DMid0043(revision, args, spindle_id, 1)
{}

DMid0043::DMid0043(int revision, QMap<int, QByteArray> args, int spindle_id, int station_id)
{
    data_fields = args;
    QString header_str = formatNumber(getDataFieldsLength() + 20, 4);
    header_str += "0043";
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

