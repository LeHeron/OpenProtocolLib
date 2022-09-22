/*!
 * \file include/d_mid0001.h
 * \brief file for the definition of the class "DMid0001"
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
#ifndef DMID0001_H
#define DMID0001_H

#include "d_open_protocol_mid.h"

class DMid0001 : public DOpenProtocolMid
{
public:
    explicit	DMid0001(QByteArray arr);
    explicit	DMid0001(QString str)		: DMid0001(str.toUtf8()) {}
    explicit	DMid0001(QMap<int, QByteArray> args, int spindle_id = 1);
    explicit	DMid0001(int revision, QMap<int, QByteArray> args, int spindle_id = 1);
    explicit    DMid0001(int revision, QMap<int, QByteArray> args, int spindle_id, int station_id);
protected:
    void processData(QByteArray data_byte_array) override;
};

#endif // DMID0001_H
