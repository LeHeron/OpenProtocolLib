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

#include "d_open_protocol.h"
#include "d_open_protocol_map.h"
#include "d_open_protocol_mid.h"
#include "d_open_protocol_factory.h"
#include "d_open_protocol_factory_base.h"
#include "mids/d_mid9999.h"
#include <QObject>
#include <cmath>

#define TIMEOUT 3000
#define PORT 4545
#define KEEP_ALIVE_TIMEOUT 13000
#define BUFFER_READ 1024

DOpenProtocol::DOpenProtocol(QObject * parent) : QObject(parent)
{
	connect(&socket, &QTcpSocket::readyRead, this, &DOpenProtocol::readMid);
	connect(&socket, &QTcpSocket::disconnected, this, &DOpenProtocol::disconnected);
	connect(&socket, &QTcpSocket::errorOccurred, this, &DOpenProtocol::disconnected);
}

void DOpenProtocol::startTimer() {
	keep_alive_timer.start(KEEP_ALIVE_TIMEOUT);
}

void DOpenProtocol::stopTimer() {
	keep_alive_timer.stop();
}


bool DOpenProtocol::doConnect(QString& addr)
{
	qDebug() << "Attempting connection ..." << "\n";
	socket.connectToHost(addr, PORT);

	if (socket.waitForConnected(TIMEOUT)) {
		qDebug() << "Connected, enabling keep alive" << "\n";
		connect(&keep_alive_timer,	&QTimer::timeout,	this, &DOpenProtocol::sendKeepAlive);
		keep_alive_timer.start(KEEP_ALIVE_TIMEOUT);
	}
	else {
		qDebug() << "Connection failed !!!!" << "\n";
		return false;
	}

	return true;
}

void DOpenProtocol::readMid() {
	startTimer();
	mid_ptr received_mid = DOpenProtocolMid::decodeMid(socket.read(BUFFER_READ));

	// Checking special signals
	if (received_mid->mid_ID == 2)
		emit connected();
	if (received_mid->mid_ID == 3)
		emit disconnected(); // TODO send MID0005

	// Assigning response
	for (auto it = waiting_response_queue.begin(); it != waiting_response_queue.end(); it++) {

		QVector<DOpenProtocolMid::midType>* valid_responses = (*it)->getValidResponses();
		if (valid_responses->contains(received_mid->mid_ID)) { // Response of former request
			(*it)->setResponse(received_mid);
			waiting_response_queue.erase(it);
			break;
		}
	}

}


bool DOpenProtocol::sendMid(mid_ptr mid)
{
	if (socket.state() != QAbstractSocket::ConnectedState) {
		qDebug() << "Cannot reach target" << "\n";
		stopTimer();
		return false;
	}

	//qDebug().nospace() << "Sending frame <" << mid->toQString() << ">\n";

	if (socket.write(mid->toQByteArray()) != -1 && socket.waitForBytesWritten(TIMEOUT))
	{
		waiting_response_queue.enqueue(mid);
		return true;
	}

	emit disconnected();
	return false;
}

void DOpenProtocol::sendKeepAlive() {
	std::shared_ptr<DOpenProtocolMid> mid_to_send = std::make_shared<DMid9999>(QString("00209999            "));
	sendMid(mid_to_send);
}
