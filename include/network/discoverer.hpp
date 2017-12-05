#pragma once

#include <QHostAddress>
#include <QUdpSocket>

class Discoverer : public QObject {
	Q_OBJECT
public:
	Discoverer(QObject *parent = Q_NULLPTR);
	~Discoverer();
signals:
	void discovered(QHostAddress addr, quint16 port);
private:
	QUdpSocket *socket;
private slots:
	void processPendingDatagrams();
};
