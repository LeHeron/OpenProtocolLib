/*!
 * \file source/d_mid0001.cpp
 * \brief file for the definition of the class "DMid0001"
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
#include "mids/d_mid0001.h"

#define REGISTER_RESPONSES() valid_responses.append({MID0002, MID0004})

void DMid0001::processData(QByteArray data_byte_array)
{

}

DMid0001::DMid0001(QByteArray arr)
	: DOpenProtocolMid(arr)
{
	DMid0001::processData(arr.mid(20, -1));
	//valid_responses.append({MID0002, MID0004});
	REGISTER_RESPONSES();
}

DMid0001::DMid0001(QMap<int, QByteArray> args)
{
	data_fields = args;
	QString header_str = formatNumber(getDataFieldsLength() + 20, 4);
	header_str += "0001   0000     ";

	header = std::make_shared<DOpenProtocolHeader>(header_str);
	REGISTER_RESPONSES();

	// Assign MID enum from its ID
	mid_ID = static_cast<midType>(header->mid);
}
