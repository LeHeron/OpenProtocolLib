/*!
 * \file lib_open_protocol_global.h
 * \brief file for the definition of the class "%{Cpp:License:ClassName}"
 * \author poles
 * \date 2022-9-21
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
#ifndef LIB_OPEN_PROTOCOL_GLOBAL_H
#define LIB_OPEN_PROTOCOL_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(LIB_OPEN_PROTOCOL_LIBRARY)
#  define LIB_OPEN_PROTOCOL_EXPORT Q_DECL_EXPORT
#else
#  define LIB_OPEN_PROTOCOL_EXPORT Q_DECL_IMPORT
#endif

#endif // LIB_OPEN_PROTOCOL_GLOBAL_H
