/*!
 * \file d_mid0033.cpp
 * \brief file for the definition of the class "DMid0033"
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
#include "d_mid0033.h"

#define REGISTER_RESPONSES() valid_responses.append({})

void DMid0033::processData(QByteArray data_byte_array)
{
    data_fields.insert(1, data_byte_array.mid(2, 2)); // Job ID
    data_fields.insert(2, data_byte_array.mid(6, 25)); // Job Name
    data_fields.insert(3, data_byte_array.mid(33, 1)); // Forced ORder
    data_fields.insert(4, data_byte_array.mid(36, 4)); // Max time for first tightening
    data_fields.insert(5, data_byte_array.mid(42, 5)); // Max time to complete job
    data_fields.insert(6, data_byte_array.mid(49, 1)); // Job batch mode / batch count type
    data_fields.insert(7, data_byte_array.mid(52, 1)); // Lock at Job done
    data_fields.insert(8, data_byte_array.mid(55, 1)); // Use line control
    data_fields.insert(9, data_byte_array.mid(58, 1)); // Repeat Job
    data_fields.insert(10, data_byte_array.mid(61, 2)); // Tool loosening
    data_fields.insert(11, data_byte_array.mid(66, 1)); // Reserved
    data_fields.insert(12, data_byte_array.mid(69, 2)); // Number of set

    int paramNumber = 12 * data_fields[12].toInt();
    data_fields.insert(13, data_byte_array.mid(72, paramNumber)); // Job list
}

DMid0033::DMid0033(QByteArray arr)
    : DOpenProtocolMid(arr)
{
    DMid0033::processData(arr.mid(20, -1));
    REGISTER_RESPONSES();
}

DMid0033::DMid0033(QMap<int, QByteArray> args)
{
    data_fields = args;
    QString header_str = formatNumber(getDataFieldsLength() + 20, 4);
    header_str += "0033   0000     ";

    header = std::make_shared<DOpenProtocolHeader>(header_str);
    REGISTER_RESPONSES();

    // Assign MID enum from its ID
    mid_ID = static_cast<midType>(header->mid);
}
