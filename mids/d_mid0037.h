/*!
 * \file d_mid0037.h
 * \brief file for the definition of the class "DMid0037"
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
#ifndef DMID0037_H
#define DMID0037_H

#include "d_open_protocol_mid.h"

class DMid0037 : public DOpenProtocolMid
{
public:
    explicit	DMid0037(QByteArray arr);
    explicit	DMid0037(QString str)		: DMid0037(str.toUtf8()) {}
    explicit	DMid0037(QMap<int, QByteArray> args);
    explicit	DMid0037(int revision, QMap<int, QByteArray> args);

protected:
    void processData(QByteArray data_byte_array) override;
};

#endif // DMID0037_H
