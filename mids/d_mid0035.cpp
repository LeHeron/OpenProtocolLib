/*!
 * \file d_mid0035.cpp
 * \brief file for the definition of the class "DMid0035"
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
#include "d_mid0035.h"

#define REGISTER_RESPONSES() valid_responses.append({MID0036})

void DMid0035::processData(QByteArray data_byte_array)
{
    data_fields.insert(1, data_byte_array.mid(2, 2)); // Job ID
    data_fields.insert(2, data_byte_array.mid(6, 1)); // Job Status
    data_fields.insert(3, data_byte_array.mid(9, 1)); // Job Batch mode
    data_fields.insert(4, data_byte_array.mid(12, 4)); // Job Batch size
    data_fields.insert(5, data_byte_array.mid(18, 4)); // Job Batch counter
    data_fields.insert(6, data_byte_array.mid(24, 19)); // Time stamp
}

DMid0035::DMid0035(QByteArray arr)
    : DOpenProtocolMid(arr)
{
    DMid0035::processData(arr.mid(20, -1));
    REGISTER_RESPONSES();
}

DMid0035::DMid0035(QMap<int, QByteArray> args)
{
    data_fields = args;
    QString header_str = formatNumber(getDataFieldsLength() + 20, 4);
    header_str += "0035   0000     ";

    header = std::make_shared<DOpenProtocolHeader>(header_str);
    REGISTER_RESPONSES();

    // Assign MID enum from its ID
    mid_ID = static_cast<midType>(header->mid);
}
