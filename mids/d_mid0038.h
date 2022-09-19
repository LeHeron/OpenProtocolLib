/*!
 * \file d_mid0038.h
 * \brief file for the definition of the class "DMid0038"
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
#ifndef DMID0038_H
#define DMID0038_H

#include "d_open_protocol_mid.h"

class DMid0038 : public DOpenProtocolMid
{
public:
    explicit	DMid0038(QByteArray arr);
    explicit	DMid0038(QString str)		: DMid0038(str.toUtf8()) {}
    explicit	DMid0038(QMap<int, QByteArray> args);

protected:
    void processData(QByteArray data_byte_array) override;
};

#endif // DMID0038_H
