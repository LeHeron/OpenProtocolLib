/*!
 * \file d_mid0011.h
 * \brief file for the definition of the class "DMid0011"
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

#ifndef DMID0011_H
#define DMID0011_H

#include "d_open_protocol_mid.h"

class DMid0011 : public DOpenProtocolMid
{
public:
    explicit	DMid0011(QByteArray arr);
    explicit	DMid0011(QString str)		: DMid0011(str.toUtf8()) {}
    explicit	DMid0011(QMap<int, QByteArray> args, int spindle_id = 1);
    explicit	DMid0011(int revision, QMap<int, QByteArray> args, int spindle_id = 1);
    explicit    DMid0011(int revision, QMap<int, QByteArray> args, int spindle_id, int station_id);
protected:
    void processData(QByteArray data_byte_array) override;
};

#endif // DMID0011_H



