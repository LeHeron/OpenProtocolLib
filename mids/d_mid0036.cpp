/*!
 * \file d_mid0036.cpp
 * \brief file for the definition of the class "DMid0036"
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
#include "d_mid0036.h"

void DMid0036::processData(QByteArray data_byte_array)
{
}

DMid0036::DMid0036(QByteArray arr)
    : DOpenProtocolMid(arr)
{
    DMid0036::processData(arr.mid(20, -1));
}

DMid0036::DMid0036(QMap<int, QByteArray> args) : DMid0036(-1, args)
{}

DMid0036::DMid0036(int revision, QMap<int, QByteArray> args)
{
    data_fields = args;
    QString header_str = formatNumber(getDataFieldsLength() + 20, 4);
    header_str += "0036";
    header_str += revision < 0 ? "   " : formatNumber(revision, 3);
    header_str += "0000     ";

    header = std::make_shared<DOpenProtocolHeader>(header_str);

    // Assign MID enum from its ID
    mid_ID = static_cast<midType>(header->mid);
}
