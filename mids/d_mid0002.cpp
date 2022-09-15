/*!
 * \file dource/d_mid0002.cpp
 * \brief file for the definition of the class "DMid0002"
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
#include "mids/d_mid0002.h"

void DMid0002::processData(QByteArray data_byte_array)
{

	data_fields.insert(1, data_byte_array.mid(2, 4)); // Cell ID
	data_fields.insert(2, data_byte_array.mid(8, 4)); // Channel ID
	data_fields.insert(3, data_byte_array.mid(14, 25)); // Controller name

	if (header->revision >= 2)
		data_fields.insert(4, data_byte_array.mid(41, 3)); // Supplier code

	if (header->revision >= 3) {
		data_fields.insert(5, data_byte_array.mid(46, 19)); // Open Protocol Version
		data_fields.insert(6, data_byte_array.mid(67, 19)); // Controller software version
		data_fields.insert(7, data_byte_array.mid(88, 19)); // Tool software version
	}
}


DMid0002::DMid0002(QByteArray arr)
	: DOpenProtocolMid(arr)
{
	DMid0002::processData(arr.mid(20, -1));
}

DMid0002::DMid0002(QMap<int, QByteArray> args)
{
	data_fields = args;
	QString header_str = formatNumber(getDataFieldsLength() + 20, 4);
	header_str += "0002   0000     ";

	header = std::make_shared<DOpenProtocolHeader>(header_str);

	// Assign MID enum from its ID
	mid_ID = static_cast<midType>(header->mid);
}
