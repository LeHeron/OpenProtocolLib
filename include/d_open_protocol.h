/*!
 * \file source/d_test.cpp
 * \brief file for the definition of the class "DTest"
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


#ifndef DOPENPROTOCOL_H
#define DOPENPROTOCOL_H

#include "d_open_protocol_mid.h"
#include "lib_open_protocol_global.h"

#include <QObject>
#include <QtNetwork>

#define DEFAULT_PORT 4545

using mid_ptr = std::shared_ptr<DOpenProtocolMid>;

class LIB_OPEN_PROTOCOL_EXPORT DOpenProtocol : public QObject
{
    Q_OBJECT

public:
    DOpenProtocol               (QObject * parent = nullptr);
    bool						doConnect(QString& addr, int port = DEFAULT_PORT);

public slots:
    bool						sendMid(mid_ptr mid); // Send mid and link response if applicable

private slots:
    void						readMid();
    void						sendKeepAlive();
    void						startTimer();
    void						stopTimer();

signals:
    void						connected();
    void						disconnected();
    void                        onSubscription(mid_ptr mid);

private:
    QTcpSocket					socket;
    QTimer						keep_alive_timer;
    bool						lock_reading;
    QQueue<mid_ptr>				waiting_response_queue;
};

#endif // DOPENPROTOCOL_H
