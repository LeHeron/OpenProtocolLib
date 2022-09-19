/*!
 * \file gui.cpp
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
#include "gui.h"
#include "d_open_protocol.h"
#include <QDebug>

GUI::GUI(QObject *parent)
    : QObject{parent}
{
    connect(&dp, &DOpenProtocol::disconnected, this, [this](){emit connected(false);});
    connect(&dp, &DOpenProtocol::onSubscription, this, &GUI::bindSubscription);
}

void GUI::helloThere()
{
    qDebug() << "Hello there !\nGeneral Kenobi ???????";
}


void GUI::addParameter()
{

}

bool GUI::sendMid(QString mid, QList<QString> paramValue, QList<int> paramIndex)
{
    //qDebug() << "Got mid" << mid << "with value: " << paramValue << "and index" << paramIndex;
    QMap<int, QByteArray> param;
    for (int i = 0; i < paramValue.length(); ++i) {
        if (paramValue[i] == "")
            continue;

        param[paramIndex[i]] = paramValue[i].toUtf8();
        //qDebug() << paramIndex[i] << "=" << paramValue[i].toUtf8();
    }

    // Create mid
    bool flag;
    int midInt = mid.toInt(&flag);
    if (!flag) // Fail if string contains other char than digits
        return false;
    mid_ptr midObj = DOpenProtocolMap::getMap()[static_cast<DOpenProtocolMid::midType>(midInt)]->createMid(param);

    // Bind response
    connect(midObj.get(), &DOpenProtocolMid::onResponse, this, [this, midObj](){
        QList<int> indexValue;
        QVariantList paramValue;

        QMap<int, QByteArray> dataFields = midObj->getResponse()->getDataFields();
        for (auto e : dataFields.keys()) {
            indexValue.append(e);
            paramValue.append(dataFields[e]);
        }

        emit updateResponse(midObj->getResponse()->mid_ID, indexValue, paramValue);
    });

    // Send mid
    dp.sendMid(midObj);

    return true;
}


void GUI::bindSubscription(mid_ptr sub) {

    if (sub->mid_ID == 35)
        dp.sendMid(DOpenProtocolMap::getMap()[DOpenProtocolMid::MID0036]->createMid({}));

    QList<int> indexValue;
    QVariantList paramValue;

    QMap<int, QByteArray> dataFields = sub->getDataFields();
    for (auto e : sub->getDataFields().keys()) {
        indexValue.append(e);
        paramValue.append(dataFields[e]);
    }
    emit receivedSubscription(sub->mid_ID, indexValue, paramValue);
}

void GUI::doConnect()
{
    //QString addr = "localhost";
    QString addr = "192.168.1.100";
    if (!dp.doConnect(addr))
        return;

    mid_ptr initMid = DOpenProtocolMap::getMap()[DOpenProtocolMid::MID0001]->createMid({});
    connect(initMid.get(), &DOpenProtocolMid::onResponse, this, [this, initMid](){
        if (initMid->getResponse()->mid_ID == 2)
            emit connected(true);
    });

    dp.sendMid(initMid);
}
