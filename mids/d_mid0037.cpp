/*!
 * \file d_mid0037.cpp
 * \brief file for the definition of the class "DMid0037"
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
#include "d_mid0037.h"

#define REGISTER_RESPONSES() valid_responses.append({MID0004, MID0005})

void DMid0037::processData(QByteArray data_byte_array)
{
}

DMid0037::DMid0037(QByteArray arr)
    : DOpenProtocolMid(arr)
{
    DMid0037::processData(arr.mid(20, -1));
    REGISTER_RESPONSES();
}

DMid0037::DMid0037(QMap<int, QByteArray> args) : DMid0037(-1, args)
{}

DMid0037::DMid0037(int revision, QMap<int, QByteArray> args)
{
    data_fields = args;
    QString header_str = formatNumber(getDataFieldsLength() + 20, 4);
    header_str += "0037";
    header_str += revision < 0 ? "   " : formatNumber(revision, 3);
    header_str += "0000     ";

    header = std::make_shared<DOpenProtocolHeader>(header_str);
    REGISTER_RESPONSES();

    // Assign MID enum from its ID
    mid_ID = static_cast<midType>(header->mid);
}
