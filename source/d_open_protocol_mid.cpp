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

#include "d_open_protocol_mid.h"
#include "d_open_protocol_map.h"

#include <cmath>
#include <QDebug>


int DOpenProtocolMid::getDataFieldsLength()
{
    int length = 0;
    for (auto e : data_fields.keys()) {
        if (e > 0)
            length += 2;

        length += data_fields[e].length();
    }
    return length;
}

QString DOpenProtocolMid::formatNumber(int n, int digits)
{
    int length = n == 0 ? 1 : int(log10(n)) + 1;

    if (length >= digits)
        return QString::number(n);

    QString res("");
    for (int i = 0; i < digits - length; i++) {
        res.append('0');
    }

    res += QString::number(n);
    return res;
}

mid_ptr DOpenProtocolMid::decodeMid(QByteArray&& arr)
{
    qDebug() << "Decoding" << arr;
    midType mid_type = static_cast<midType>(arr.mid(4, 4).toInt());
    return DOpenProtocolMap::getMap()[mid_type]->createMid(arr);
}


QString DOpenProtocolMid::toQString() const
{
    QString data("");

    for (auto e : data_fields.keys()) {
        if (e > 0)
            data += formatNumber(e, 2);
         data += QString(data_fields[e]);
    }


    QString message = formatNumber(header->length, 4);
    message += formatNumber(header->mid, 4);

    if (header->revision == -1)
        message += "   ";
    else
        message += formatNumber(header->revision, 3);

    message += formatNumber(header->no_ack_flag, 1);
    message += formatNumber(header->stationID, 1);
    message += formatNumber(header->spindelID, 2);
    message += "     "; // 5 spaces for reserved space
    message += data;

    return message;
}

void appendToArray(QByteArray& arr, int n, int digits)
{
    int length = n == 0 ? 1 : int(log10(n)) + 1;
    arr.append(digits - length, '0');

    arr.append(QByteArray::number(n));
}

QByteArray DOpenProtocolMid::toQByteArray() const
{
    QByteArray message;
    appendToArray(message, header->length, 4);
    appendToArray(message, header->mid, 4);

    if (header->revision == -1)
        message.append(3, ' ');
    else
        appendToArray(message, header->revision, 3);

    appendToArray(message, header->no_ack_flag, 1);
    appendToArray(message, header->stationID, 1);
    appendToArray(message, header->spindelID, 2);
    message.append("     "); // 5 spaces for reserved space

    for (auto e : data_fields.keys()) {
        if (e > 0)
            appendToArray(message, e, 2);
         message.append(data_fields[e]);
    }

    message.append('\0');
    return message;
}

QVector<DOpenProtocolMid::midType>* DOpenProtocolMid::getValidResponses() {
    return &valid_responses;
}


DOpenProtocolMid::DOpenProtocolMid(QByteArray arr)
{
    header = std::make_shared<DOpenProtocolHeader>(arr);

    // Assign MID enum from its ID
    mid_ID = static_cast<midType>(header->mid);
}

DOpenProtocolMid::DOpenProtocolMid(QString str)
    : DOpenProtocolMid(str.toUtf8())
{}

DOpenProtocolMid::DOpenProtocolHeader::DOpenProtocolHeader(QByteArray arr)
{
    if (arr.size() < 20)
        return; // Invalid header

    length		= arr.mid(0, 4).toInt();
    mid			= arr.mid(4, 4).toInt();

    QByteArray rev = arr.mid(8, 3);
    revision	= rev == "   " ? -1 : rev.toInt();

    unsigned char ack_flag = arr.at(11);
    no_ack_flag	= !(ack_flag == ' ' || ack_flag == '0' || ack_flag == '\0');

    stationID	= arr.mid(12, 1).toInt();
    spindelID	= arr.mid(13, 2).toInt();
}

const std::shared_ptr<DOpenProtocolMid> DOpenProtocolMid::getResponse() const
{
    return response;
}

void DOpenProtocolMid::setResponse(std::shared_ptr<DOpenProtocolMid> res)
{
    response = res;
    emit onResponse();
}

const QMap<int, QByteArray>& DOpenProtocolMid::getDataFields() const
{
    return data_fields;
}

DOpenProtocolMid::DOpenProtocolHeader::DOpenProtocolHeader(QString str)
    : DOpenProtocolHeader(str.toUtf8())
{}
