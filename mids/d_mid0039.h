/*!
 * \file d_mid0039.h
 * \brief file for the definition of the class "DMid0039"
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
#ifndef DMID0039_H
#define DMID0039_H

#include "d_open_protocol_mid.h"

class DMid0039 : public DOpenProtocolMid
{
public:
    explicit	DMid0039(QByteArray arr);
    explicit	DMid0039(QString str)		: DMid0039(str.toUtf8()) {}
    explicit	DMid0039(QMap<int, QByteArray> args, int spindle_id = 1);
    explicit	DMid0039(int revision, QMap<int, QByteArray> args, int spindle_id = 1);
    explicit    DMid0039(int revision, QMap<int, QByteArray> args, int spindle_id, int station_id);

protected:
    void processData(QByteArray data_byte_array) override;
};

#endif // DMID0039_H
