/*!
 * \file dource/d_mid0005.cpp
 * \brief file for the definition of the class "DMid0005"
 * \author poles
 * \date 2022-9-7
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
#include "mids/d_mid0005.h"

void DMid0005::processData(QByteArray data_byte_array)
{
    data_fields.insert(-1, data_byte_array.mid(0, 4)); // Accepted Mid

}


DMid0005::DMid0005(QByteArray arr)
    : DOpenProtocolMid(arr)
{
    DMid0005::processData(arr.mid(20, -1));
}

DMid0005::DMid0005(QMap<int, QByteArray> args) : DMid0005(-1, args)
{}

DMid0005::DMid0005(int revision, QMap<int, QByteArray> args)
{
    data_fields = args;
    QString header_str = formatNumber(getDataFieldsLength() + 20, 4);
    header_str += "0005";
    header_str += revision < 0 ? "   " : formatNumber(revision, 3);
    header_str += "0000     ";

    header = std::make_shared<DOpenProtocolHeader>(header_str);

    // Assign MID enum from its ID
    mid_ID = static_cast<midType>(header->mid);
}
