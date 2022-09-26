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
#include "mids/d_mid0012.h"
#include "mids/d_mid0013.h"
#include "mids/d_mid0018.h"
#include "mids/d_mid0030.h"
#include "mids/d_mid0031.h"
#include "mids/d_mid0032.h"
#include "mids/d_mid0033.h"
#include "mids/d_mid0034.h"
#include "mids/d_mid0035.h"
#include "mids/d_mid0036.h"
#include "mids/d_mid0037.h"
#include "mids/d_mid0038.h"
#include "mids/d_mid0039.h"
#include "mids/d_mid0040.h"
#include "mids/d_mid0041.h"
#include "mids/d_mid0042.h"
#include "mids/d_mid0043.h"
#include "mids/d_mid0060.h"
#include "mids/d_mid0061.h"
#include "mids/d_mid0062.h"
#include "mids/d_mid0063.h"
#include "mids/d_mid9999.h"

DOpenProtocolMap* DOpenProtocolMap::m_instance{nullptr};
std::mutex DOpenProtocolMap::m_mutex;

DOpenProtocolMap::DOpenProtocolMap()
{
    // Communication
    mid_constructor_map[DOpenProtocolMid::MID0001] = new DOpenProtocolFactory<DMid0001>();
    mid_constructor_map[DOpenProtocolMid::MID0002] = new DOpenProtocolFactory<DMid0002>();
    mid_constructor_map[DOpenProtocolMid::MID0003] = new DOpenProtocolFactory<DMid0003>();
    mid_constructor_map[DOpenProtocolMid::MID0004] = new DOpenProtocolFactory<DMid0004>();
    mid_constructor_map[DOpenProtocolMid::MID0005] = new DOpenProtocolFactory<DMid0005>();

    // Parameter set
    mid_constructor_map[DOpenProtocolMid::MID0012] = new DOpenProtocolFactory<DMid0012>();
    mid_constructor_map[DOpenProtocolMid::MID0013] = new DOpenProtocolFactory<DMid0013>();
    mid_constructor_map[DOpenProtocolMid::MID0018] = new DOpenProtocolFactory<DMid0018>();

    // Job
    mid_constructor_map[DOpenProtocolMid::MID0030] = new DOpenProtocolFactory<DMid0030>();
    mid_constructor_map[DOpenProtocolMid::MID0031] = new DOpenProtocolFactory<DMid0031>();
    mid_constructor_map[DOpenProtocolMid::MID0032] = new DOpenProtocolFactory<DMid0032>();
    mid_constructor_map[DOpenProtocolMid::MID0033] = new DOpenProtocolFactory<DMid0033>();
    mid_constructor_map[DOpenProtocolMid::MID0034] = new DOpenProtocolFactory<DMid0034>();
    mid_constructor_map[DOpenProtocolMid::MID0035] = new DOpenProtocolFactory<DMid0035>();
    mid_constructor_map[DOpenProtocolMid::MID0036] = new DOpenProtocolFactory<DMid0036>();
    mid_constructor_map[DOpenProtocolMid::MID0037] = new DOpenProtocolFactory<DMid0037>();
    mid_constructor_map[DOpenProtocolMid::MID0038] = new DOpenProtocolFactory<DMid0038>();
    mid_constructor_map[DOpenProtocolMid::MID0039] = new DOpenProtocolFactory<DMid0039>();

    // Tool messages (Lock / Unlock)
    mid_constructor_map[DOpenProtocolMid::MID0040] = new DOpenProtocolFactory<DMid0040>();
    mid_constructor_map[DOpenProtocolMid::MID0041] = new DOpenProtocolFactory<DMid0041>();
    mid_constructor_map[DOpenProtocolMid::MID0042] = new DOpenProtocolFactory<DMid0042>();
    mid_constructor_map[DOpenProtocolMid::MID0043] = new DOpenProtocolFactory<DMid0043>();

    // Tightening result
    mid_constructor_map[DOpenProtocolMid::MID0060] = new DOpenProtocolFactory<DMid0060>();
    mid_constructor_map[DOpenProtocolMid::MID0061] = new DOpenProtocolFactory<DMid0061>();
    mid_constructor_map[DOpenProtocolMid::MID0062] = new DOpenProtocolFactory<DMid0062>();
    mid_constructor_map[DOpenProtocolMid::MID0063] = new DOpenProtocolFactory<DMid0063>();

    // Keep Alive
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
