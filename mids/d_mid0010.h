/*!
 * \file d_mid0010.h
 * \brief file for the definition of the class "DMid0010"
 * \author poles
 * \date 2022-09-26
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

#ifndef DMID0010_H
#define DMID0010_H

#include "d_open_protocol_mid.h"

class DMid0010 : public DOpenProtocolMid
{
public:
    explicit	DMid0010(QByteArray arr);
    explicit	DMid0010(QString str)		: DMid0010(str.toUtf8()) {}
    explicit	DMid0010(QMap<int, QByteArray> args, int spindle_id = 1);
    explicit	DMid0010(int revision, QMap<int, QByteArray> args, int spindle_id = 1);
    explicit    DMid0010(int revision, QMap<int, QByteArray> args, int spindle_id, int station_id);
protected:
    void processData(QByteArray data_byte_array) override;
};

#endif // DMID0010_H



