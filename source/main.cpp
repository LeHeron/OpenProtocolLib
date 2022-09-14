/*!
 * \file %{Cpp:License:FileName}
 * \brief file for the definition of the class "%{Cpp:License:ClassName}"
 * \author dogadev
 * \date 2022-9-13
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
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickStyle>
#include <QQmlContext>
#include "gui.h"

int main(int argc, char *argv[])
{
	if (qEnvironmentVariableIsEmpty("QTGLESSTREAM_DISPLAY")) {
		qputenv("QT_QPA_EGLFS_PHYSICAL_WIDTH", QByteArray("213"));
		qputenv("QT_QPA_EGLFS_PHYSICAL_HEIGHT", QByteArray("120"));

#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
		QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
	}
	QGuiApplication app(argc, argv);

	QQuickStyle::setStyle("Material");


	QQmlApplicationEngine engine;
	const QUrl url(QStringLiteral("qrc:/main.qml"));
	QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
					 &app, [url](QObject *obj, const QUrl &objUrl) {
		if (!obj && url == objUrl)
			QCoreApplication::exit(-1);
	}, Qt::QueuedConnection);

	GUI gui;
	engine.rootContext()->setContextProperty("gui", &gui);
	engine.load(url);

	return app.exec();
}
