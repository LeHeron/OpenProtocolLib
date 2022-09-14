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
#include <QDebug>

GUI::GUI(QObject *parent)
	: QObject{parent}
{

}

void GUI::helloThere()
{
	qDebug() << "Hello there !\n General Kenobi ???????";
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
	}

	emit updateResponse("pickle rick");

	return false;
}
