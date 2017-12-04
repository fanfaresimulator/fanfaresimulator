#include "../include/network/client.hpp"

/* PRIVATE */
void NetworkClient::sendJsonObject(QJsonObject o) {
  QJsonDocument doc = QJsonDocument(o);
  QByteArray msg = doc.toJson();
  std::cout << "sending: " << QString(msg).toStdString() << std::endl;
  socket->write(msg);
}

void NetworkClient::handleJsonDoc(QJsonDocument doc) {
  QJsonObject obj = doc.object();
  int type = obj["type"].toInt();

  switch (type) {
    case SIG_START: {
      emit startRecv();
      break;
    }
    case SIG_LOBBIES: {
      std::cout << "NOT YET IMPLEMENTED" << std::endl;
      break;
    }

    case SIG_INSTRUMENTS: {
      if (!obj["data"].isArray()) {
        std::cout << "obj[\"data\"] is supposed to be an array not a " << obj["data"].type() << std::endl;
        return;
      }
      QJsonArray instruments = obj["data"].toArray();
      break;
    }

    case SIG_PARTITION: {
      if (!obj["data"].isArray()) {
        std::cout << "obj[\"data\"] is supposed to be an array not a " << obj["data"].type() << std::endl;
        return;
      }
      QJsonArray notes = obj["data"].toArray();
      break;
    }

    default:
      std::cout << "Unsupported type: " << type << std::endl;
      break;
  }
}

void NetworkClient::readyRead() {
  std::cout << "Client " << username << " is reading :" << std::endl << "##beg##\n";
  QByteArray msg = socket->readAll();
  std::cout <<  QString(msg).toStdString() << std::endl << "##end##\n";

  // parse JSON
  QJsonParseError jerror;
  QJsonDocument doc = QJsonDocument::fromJson(msg, &jerror);
  if(jerror.error != QJsonParseError::ParseError::NoError) {
    std::cout << jerror.errorString().toStdString() << std::endl;
    return;
  }
  handleJsonDoc(doc);
}

/* PUBLIC */
NetworkClient::NetworkClient(std::string username, QObject *parent) :
QObject(parent) {
  this->socket = new QTcpSocket(this);
  // socket->connectToHost(QHostAddress("127.0.0.1"), PORT_NO);
  this->socket->connectToHost(QHostAddress::SpecialAddress::LocalHost, PORT_NO);
  connect(socket, &QIODevice::readyRead, this, &NetworkClient::readyRead);
  this->username = username;
  std::cout << "new client: " << username << std::endl;
}

void NetworkClient::sendHello() {
  QJsonObject obj;
  obj["type"] = SIG_HELLO;
  obj["data"] = QString::fromStdString(username);
  this->sendJsonObject(obj);
}

void NetworkClient::sendInstrumentChoice(Instrument instrument) {
  QJsonObject obj;
  obj["type"] = SIG_CHOICE_INSTRUMENT;
  obj["data"] = QString::fromStdString("NOT YET IMPLEMENTED");
  this->sendJsonObject(obj);
}

void NetworkClient::sendReady(){
  QJsonObject obj;
  obj["type"] = SIG_READY;
  this->sendJsonObject(obj);
}

void NetworkClient::sendNote(Note note) {
  QJsonObject obj;
  obj["type"] = SIG_NOTE;
  QJsonObject JSonNote;
  JSonNote["timestamp"] = QString::fromStdString("NEED GETTER");
  JSonNote["signal"] = QString::fromStdString("NEED GETTER");
  JSonNote["instrument"] = QString::fromStdString("NEED GETTER");
  JSonNote["velocity"] = 0;
  JSonNote["key"] = 0;
  JSonNote["track"] = 0;
  obj["data"] = JSonNote;
  this->sendJsonObject(obj);
}
