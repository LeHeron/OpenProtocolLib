/*!
 * \file d_mid0033.h
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
#ifndef DMID0033_H
#define DMID0033_H

#include "d_open_protocol_mid.h"

class DMid0033 : public DOpenProtocolMid
{
public:
    explicit	DMid0033(QByteArray arr);
    explicit	DMid0033(QString str)		: DMid0033(str.toUtf8()) {}
    explicit	DMid0033(QMap<int, QByteArray> args);

protected:
    void processData(QByteArray data_byte_array) override;
};

#endif // DMID0033_H
