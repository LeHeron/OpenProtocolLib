/*!
 * \file include/d_open_protocol_map.h
 * \brief file for the definition of the class "DOpenProtocolMap"
 * \author poles
 * \date 2022-9-9
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
#ifndef DOPENPROTOCOLMAP_H
#define DOPENPROTOCOLMAP_H

#include <QMap>
#include <mutex>
#include "d_open_protocol_mid.h"
#include "d_open_protocol_factory.h"
#include "d_open_protocol_factory_base.h"
#include "lib_open_protocol_global.h"

class LIB_OPEN_PROTOCOL_EXPORT DOpenProtocolMap
{
	// Singleton properties
	// ======>
private:
	DOpenProtocolMap();
	~DOpenProtocolMap();
	static DOpenProtocolMap*					getInstance();

	static DOpenProtocolMap*					m_instance;
	static std::mutex							m_mutex;


public:
	DOpenProtocolMap(const DOpenProtocolMap&)	= delete;
	void operator=(const DOpenProtocolMap&)		= delete;
	// <=====

	static QMap<DOpenProtocolMid::midType, DOpenProtocolFactoryBase*>& getMap();
private:
	QMap<DOpenProtocolMid::midType, DOpenProtocolFactoryBase*> mid_constructor_map;

};

#endif // DOPENPROTOCOLMAP_H
