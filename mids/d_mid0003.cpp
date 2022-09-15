/*!
 * \file dource/d_mid0003.cpp
 * \brief file for the definition of the class "DMid0003"
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
#include "mids//d_mid0003.h"

#define REGISTER_RESPONSES() valid_responses.append({MID0005})

void DMid0003::processData(QByteArray data_byte_array)
{

}

DMid0003::DMid0003(QByteArray arr)
	: DOpenProtocolMid(arr)
{
	DMid0003::processData(arr.mid(20, -1));
	REGISTER_RESPONSES();
}

DMid0003::DMid0003(QMap<int, QByteArray> args)
{
	data_fields = args;
	QString header_str = formatNumber(getDataFieldsLength() + 20, 4);
	header_str += "0003   0000     ";

	header = std::make_shared<DOpenProtocolHeader>(header_str);
	REGISTER_RESPONSES();

	// Assign MID enum from its ID
	mid_ID = static_cast<midType>(header->mid);
}
