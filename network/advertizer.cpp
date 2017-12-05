#include "../include/network/network.hpp"
#include "../include/network/advertizer.hpp"

#include <iostream>

Advertizer::Advertizer(QObject *parent) : QObject(parent) {
	socket = new QUdpSocket(this);

	timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(broadcastDatagram()));

	timer->start(ADVERTIZER_INTERVAL);
}

Advertizer::~Advertizer() {}

void Advertizer::broadcastDatagram() {
	QByteArray datagram = DISCOVER_MSG;
	socket->writeDatagram(datagram.data(), datagram.size(), QHostAddress::Broadcast, PORT_NO);
}
