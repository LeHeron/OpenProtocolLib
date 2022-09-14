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

#include <QObject>
#include <QMap>

class GUI : public QObject
{
	Q_OBJECT
public:
	explicit GUI(QObject *parent = nullptr);

public slots:
	void helloThere();
	void addParameter();
	bool sendMid(QString mid, QList<QString> paramValue, QList<int> paramIndex);
signals:
	void updateResponse(QString response);

};

#endif // GUI_H
