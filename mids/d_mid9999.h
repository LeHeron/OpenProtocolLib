/*!
 * \file include/d_mid9999.h
 * \brief file for the definition of the class "DMid9999"
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
#ifndef DMID9999_H
#define DMID9999_H

#include "d_open_protocol_mid.h"

class DMid9999 : public DOpenProtocolMid
{
public:
	explicit	DMid9999(QByteArray arr);
	explicit	DMid9999(QString str)		: DMid9999(str.toUtf8()) {}
	explicit	DMid9999(QMap<int, QByteArray> args);

protected:
	void processData(QByteArray data_byte_array) override;
};

#endif // DMID9999_H
