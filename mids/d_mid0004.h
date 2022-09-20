/*!
 * \file include/d_mid0004.h
 * \brief file for the definition of the class "DMid0004"
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
#ifndef DMID0004_H
#define DMID0004_H


#include "d_open_protocol_mid.h"

class DMid0004 : public DOpenProtocolMid
{
public:
    explicit	DMid0004(QByteArray arr);
    explicit	DMid0004(QString str)		: DMid0004(str.toUtf8()) {}
    explicit	DMid0004(QMap<int, QByteArray> args);
    explicit	DMid0004(int revision, QMap<int, QByteArray> args);

protected:
    void processData(QByteArray data_byte_array) override;
};

#endif // DMID0004_H
