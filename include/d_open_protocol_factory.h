/*!
 * \file include/d_open_protocol_factory.h
 * \brief file for the definition of the class "DOpenProtocolFactory"
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
#ifndef DOPENPROTOCOLFACTORY_H
#define DOPENPROTOCOLFACTORY_H

#include <memory>
#include "d_open_protocol_factory_base.h"

template <typename T>
class DOpenProtocolFactory : public DOpenProtocolFactoryBase
{
public:
	std::shared_ptr<DOpenProtocolMid> createMid(QString& str) const {
		return std::make_shared<T>(str);
	}
	std::shared_ptr<DOpenProtocolMid> createMid(QByteArray& arr) const {
		return std::make_shared<T>(arr);
	}
	std::shared_ptr<DOpenProtocolMid> createMid(QMap<int, QByteArray> args) const {
		return std::make_shared<T>(args);
	}
};

#endif // DOPENPROTOCOLFACTORY_H
