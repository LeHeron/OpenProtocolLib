/*!
 * \file gui.h
 * \brief file for the definition of the class "GUI"
 * \author dogadev
 * \date 2022-9-14
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
#ifndef GUI_H
#define GUI_H

#include "d_open_protocol.h"
#include "d_open_protocol_mid.h"
#include "d_open_protocol_map.h"
#include <QObject>
#include <QMap>

class GUI : public QObject
{
    Q_OBJECT
public:
    explicit GUI(QObject *parent = nullptr);

public slots:
    void doConnect();
    void helloThere();
    void addParameter();
    bool sendMid(QString mid, QList<QString> paramValue, QList<int> paramIndex);
    void bindSubscription(mid_ptr sub);

signals:
    void receivedSubscription(int mid, QList<int> indexValue, QVariantList paramValue);
    void updateResponse(int mid, QList<int> indexValue, QVariantList paramValue);
    void connected(bool isConnected);

private:
    DOpenProtocol dp;
};

#endif // GUI_H
