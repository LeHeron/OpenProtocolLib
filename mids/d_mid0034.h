/*!
 * \file d_mid0034.h
 * \brief file for the definition of the class "DMid0034"
 * \author poles
 * \date 2022-9-16
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
#ifndef DMID0034_H
#define DMID0034_H

#include "d_open_protocol_mid.h"

class DMid0034 : public DOpenProtocolMid
{
public:
    explicit	DMid0034(QByteArray arr);
    explicit	DMid0034(QString str)		: DMid0034(str.toUtf8()) {}
    explicit	DMid0034(QMap<int, QByteArray> args, int spindle_id = 1);
    explicit	DMid0034(int revision, QMap<int, QByteArray> args, int spindle_id = 1);
    explicit    DMid0034(int revision, QMap<int, QByteArray> args, int spindle_id, int station_id);

protected:
    void processData(QByteArray data_byte_array) override;
};

#endif // DMID0034_H
