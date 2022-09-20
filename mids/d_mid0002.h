/*!
 * \file include/d_mid0002.h
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
#ifndef DMID0002_H
#define DMID0002_H


#include "d_open_protocol_mid.h"

class DMid0002 : public DOpenProtocolMid
{
public:
    explicit	DMid0002(QByteArray arr);
    explicit	DMid0002(QString str)		: DMid0002(str.toUtf8()) {}
    explicit	DMid0002(QMap<int, QByteArray> args);
    explicit	DMid0002(int revision, QMap<int, QByteArray> args);

protected:
    void processData(QByteArray data_byte_array) override;
};

#endif // DMID0002_H
