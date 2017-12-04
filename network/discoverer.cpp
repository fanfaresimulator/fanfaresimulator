#include <iostream>
#include "../include/network_utils.hpp"
#include "../include/network/discoverer.hpp"

Discoverer::Discoverer(QObject *parent) : QObject(parent) {
	socket = new QUdpSocket(this);
	connect(socket, SIGNAL(readyRead()), this, SLOT(processPendingDatagrams()));

	socket->bind(PORT_NO, QUdpSocket::ShareAddress);
}

Discoverer::~Discoverer() {}

void Discoverer::processPendingDatagrams() {
	while (socket->hasPendingDatagrams()) {
		QByteArray b;
		b.resize(socket->pendingDatagramSize());
		QHostAddress addr;
		quint16 port;
		socket->readDatagram(b.data(), b.size(), &addr, &port);
		std::string s = QString(b).toStdString();
		if (s.compare(DISCOVER_MSG) != 0) {
			continue;
		}
		//std::cout << "Discovered server: " << addr.toString().toStdString() << ":" << port << std::endl;
		// TODO: port should be in the received message
		emit discovered(addr, PORT_NO);
	}
}
