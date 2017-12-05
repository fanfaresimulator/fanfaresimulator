#pragma once

#include <QUdpSocket>
#include <QTimer>

#define ADVERTIZER_INTERVAL 1000

class Advertizer : public QObject {
	Q_OBJECT
public:
	Advertizer(QObject *parent = Q_NULLPTR);
	~Advertizer();
private:
	QUdpSocket *socket;
	QTimer *timer;
private slots:
	void broadcastDatagram();
};
