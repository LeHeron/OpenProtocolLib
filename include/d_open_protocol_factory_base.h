/*!
 * \file include/d_open_protocol_factory_base.h
 * \brief file for the definition of the class "DOpenProtocolFactoryBase"
 * \author poles
 * \date 2022-9-8
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
#ifndef DOPENPROTOCOLFACTORYBASE_H
#define DOPENPROTOCOLFACTORYBASE_H

#include "d_open_protocol_mid.h"
#include "lib_open_protocol_global.h"

class DOpenProtocolMid;

class LIB_OPEN_PROTOCOL_EXPORT DOpenProtocolFactoryBase
{
public:
    virtual std::shared_ptr<DOpenProtocolMid> createMid(QString&) const = 0;
    virtual std::shared_ptr<DOpenProtocolMid> createMid(QByteArray&) const = 0;
    virtual std::shared_ptr<DOpenProtocolMid> createMid(QMap<int, QByteArray> args) const = 0;
    virtual std::shared_ptr<DOpenProtocolMid> createMid(int revision, QMap<int, QByteArray> args) const = 0;
};

#endif // DOPENPROTOCOLFACTORYBASE_H
