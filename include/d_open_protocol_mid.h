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

#ifndef D_OPEN_PROTOCOL_MID_H
#define D_OPEN_PROTOCOL_MID_H

#include <QObject>
#include <QString>
#include <QByteArrayList>
#include <QMap>
#include <memory>
#include <mutex>

#include "d_open_protocol_factory.h"

using mid_ptr = std::shared_ptr<DOpenProtocolMid>;

class DOpenProtocolMid : public QObject
{
    Q_OBJECT

public:
    // Enum items value must be equal to its id (i.e. MID0472 = 472)
    enum midType {
        MID0001 = 1,
        MID0002,
        MID0003,
        MID0004,
        MID0005,
        MID0030 = 30,
        MID0031,
        MID0032,
        MID0033,
        MID0034,
        MID0035,
        MID0036,
        MID0037,
        MID0038,
        MID0039,
        MID9999 = 9999
    };

    // Ctor
    explicit					DOpenProtocolMid(QByteArray);
    explicit					DOpenProtocolMid(QString);
    explicit					DOpenProtocolMid(QMap<int, QByteArray> args);
    explicit					DOpenProtocolMid(int revision, QMap<int, QByteArray> args);

    static mid_ptr				decodeMid(QByteArray&& arr);

    QString						toQString()										const;
    QByteArray					toQByteArray()									const;


protected:
    explicit					DOpenProtocolMid() {} // Needed for subclass Ctor

    virtual void				processData(QByteArray data_byte_array)			= 0;
    int							getDataFieldsLength();
    static QString				formatNumber(int n, int digits);

    struct DOpenProtocolHeader
    {
        explicit DOpenProtocolHeader(QByteArray arr); // TODO Avoid copy
        explicit DOpenProtocolHeader(QString str);

        int		length;
        int		mid;
        int		revision;
        bool	no_ack_flag;
        int		stationID;
        int		spindelID;
    };

public:
    midType									mid_ID;
    void									setResponse(std::shared_ptr<DOpenProtocolMid>);
    const mid_ptr							getResponse() const;
    QVector<midType>*						getValidResponses();
    const QMap<int, QByteArray>&					getDataFields() const;

protected:
    std::shared_ptr<DOpenProtocolHeader>	header;
    QMap<int, QByteArray>					data_fields; // Use negative key to prevent adding parameter number prefix
    QVector<midType>						valid_responses;
    mid_ptr									response;

signals:
    void									onResponse();
};

#endif // D_OPEN_PROTOCOL_MID_H
