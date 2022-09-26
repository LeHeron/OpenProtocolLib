/*!
 * \file d_mid0042.h
 * \brief file for the definition of the class "DMid0042"
 * \author poles
 * \date 2022-09-23
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

#ifndef DMID0042_H
#define DMID0042_H

#include "d_open_protocol_mid.h"

class DMid0042 : public DOpenProtocolMid
{
public:
    explicit	DMid0042(QByteArray arr);
    explicit	DMid0042(QString str)		: DMid0042(str.toUtf8()) {}
    explicit	DMid0042(QMap<int, QByteArray> args, int spindle_id = 1);
    explicit	DMid0042(int revision, QMap<int, QByteArray> args, int spindle_id = 1);
    explicit    DMid0042(int revision, QMap<int, QByteArray> args, int spindle_id, int station_id);
protected:
    void processData(QByteArray data_byte_array) override;
};

#endif // DMID0042_H



