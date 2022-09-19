/*!
 * \file dource/d_mid0031.cpp
 * \brief file for the definition of the class "DMid0031"
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
#include "mids/d_mid0031.h"


#include <QDebug> // TODO remove
void DMid0031::processData(QByteArray data_byte_array)
{
    if (header->revision <= 1) {
        int init = -100;
        int ind = init + 1;
        data_fields.insert(init, data_byte_array.mid(0, 2)); // number of jobs

        int pos = 2;
        for (int i = 0; i < data_fields[init].toInt(); ++i, ++ind, pos += 2)
        {
            data_fields[ind] = data_byte_array.mid(pos, 2);
        }
        return;
    }

    if (header->revision == 2) {
        int init = -10000;

        data_fields.insert(init, data_byte_array.mid(0, 4)); // number of jobs

        int ind = init + 1;
        int pos = 4;
        for (int i = 0; i < data_fields[init].toInt(); ++i, ++ind, pos += 4)
        {
            data_fields[ind] = data_byte_array.mid(pos, 4);
        }
        return;
    }

}

DMid0031::DMid0031(QByteArray arr)
    : DOpenProtocolMid(arr)
{
    DMid0031::processData(arr.mid(20, -1));
}

DMid0031::DMid0031(QMap<int, QByteArray> args)
{
    data_fields = args;
    QString header_str = formatNumber(getDataFieldsLength() + 20, 4);
    header_str += "0031   0000     ";

    header = std::make_shared<DOpenProtocolHeader>(header_str);

    // Assign MID enum from its ID
    mid_ID = static_cast<midType>(header->mid);
}
