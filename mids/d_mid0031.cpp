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

void DMid0031::processData(QByteArray data_byte_array)
{

	if (header->revision <= 1) {
		data_fields.insert(1, data_byte_array.mid(2, 2)); // number of jobs

		// TODO stanley is not respecting Documentation ?????????????????????????????????
		//for (int i = 0; )
		return;
	}

	if (header->revision == 2) {

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
