/*!
 * \file source/d_open_protocol_map.cpp
 * \brief file for the definition of the class "DOpenProtocolMap"
 * \author dogadev
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
#include "include/d_open_protocol_map.h"
#include "d_open_protocol_factory.h"

#include "mids/d_mid0001.h"
#include "mids/d_mid0002.h"
#include "mids/d_mid0003.h"
#include "mids/d_mid0004.h"
#include "mids/d_mid0005.h"
#include "mids/d_mid0030.h"
#include "mids/d_mid0031.h"
#include "mids/d_mid9999.h"

DOpenProtocolMap* DOpenProtocolMap::m_instance{nullptr};
std::mutex DOpenProtocolMap::m_mutex;

DOpenProtocolMap::DOpenProtocolMap()
{
	mid_constructor_map[DOpenProtocolMid::MID0001] = new DOpenProtocolFactory<DMid0001>();
	mid_constructor_map[DOpenProtocolMid::MID0002] = new DOpenProtocolFactory<DMid0002>();
	mid_constructor_map[DOpenProtocolMid::MID0003] = new DOpenProtocolFactory<DMid0003>();
	mid_constructor_map[DOpenProtocolMid::MID0004] = new DOpenProtocolFactory<DMid0004>();
	mid_constructor_map[DOpenProtocolMid::MID0005] = new DOpenProtocolFactory<DMid0005>();

	mid_constructor_map[DOpenProtocolMid::MID0030] = new DOpenProtocolFactory<DMid0030>();
	mid_constructor_map[DOpenProtocolMid::MID0031] = new DOpenProtocolFactory<DMid0031>();

	mid_constructor_map[DOpenProtocolMid::MID9999] = new DOpenProtocolFactory<DMid9999>();
}

DOpenProtocolMap* DOpenProtocolMap::getInstance()
{
	std::lock_guard<std::mutex> lock(m_mutex);
	if (m_instance == nullptr)
	{
		m_instance = new DOpenProtocolMap();
	}
	return m_instance;
}

QMap<DOpenProtocolMid::midType, DOpenProtocolFactoryBase*>& DOpenProtocolMap::getMap()
{
	return getInstance()->mid_constructor_map;
}
