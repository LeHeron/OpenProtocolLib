/*!
 * \file d_mid0034.cpp
 * \brief file for the definition of the class "DMid0034"
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
#include "d_mid0034.h"

#define REGISTER_RESPONSES() valid_responses.append({MID0004, MID0005})

void DMid0034::processData(QByteArray data_byte_array)
{
}

DMid0034::DMid0034(QByteArray arr)
    : DOpenProtocolMid(arr)
{
    DMid0034::processData(arr.mid(20, -1));
    REGISTER_RESPONSES();
}

DMid0034::DMid0034(QMap<int, QByteArray> args)
{
    data_fields = args;
    QString header_str = formatNumber(getDataFieldsLength() + 20, 4);
    header_str += "0034   0000     ";

    header = std::make_shared<DOpenProtocolHeader>(header_str);
    REGISTER_RESPONSES();

    // Assign MID enum from its ID
    mid_ID = static_cast<midType>(header->mid);
}
