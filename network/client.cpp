#include "../include/network/client.hpp"

/* PRIVATE */
void NetworkClient::sendJsonObject(QJsonObject o) {
  QJsonDocument doc = QJsonDocument(o);
  QByteArray msg = doc.toJson(JSON_FORMAT);
  int size = msg.size();
  std::cout << "SENDING (size: "<< msg.size() << " bytes)\n";
  char b[sizeof(int)];
  memcpy(&b, &size, sizeof(int));
  socket->write(b, sizeof(int));
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

    case SIG_PUPITRES: {
      std::map<Pupitre, bool> pupitres = pupitresFromJson(arrayFromJson(obj["data"]));
      emit pupitresRecv(pupitres);
      break;
    }

    case SIG_PARTITION: {
      QJsonObject data = objectFromJson(obj["data"]);
      Partition partition = partitionFromJson(data);
      emit partitionRecv(partition);
      break;
    }

    default:
      std::cout << "Unsupported type: " << type << std::endl;
      break;
  }
}

void NetworkClient::readyRead() {
  while (socket->bytesAvailable()) {
    if (remainingBytes == 0) {
      char b[sizeof(int)];
      socket->read(b, sizeof(int));
      memcpy(&remainingBytes, &b, sizeof(int));
      std::cout << "MSG size: " << remainingBytes << std::endl;
    }

    QByteArray buffer = socket->read(remainingBytes);
    pending.append(buffer);
    std::cout << "READING " << buffer.size() << "/" << remainingBytes << "\n";
    remainingBytes -= buffer.size();

    if (remainingBytes != 0) { // message insn't complete
      return;
    }
    // message is arrived entirely
    QJsonParseError jerror;
    QJsonDocument doc = QJsonDocument::fromJson(pending, &jerror);
    if (jerror.error != QJsonParseError::ParseError::NoError) {
      std::cout << "QJsonParseError: "<< jerror.errorString().toStdString() << std::endl;
      std::cout << "With : "<< QString(pending).toStdString();
      return;
    }
    pending.clear();
    handleJsonDoc(doc);
  }
}

/* PUBLIC */
NetworkClient::NetworkClient(QHostAddress addr, quint16 port, std::string username, QObject *parent) : QObject(parent) {
  this->username = username;

  this->socket = new QTcpSocket(this);
  // socket->connectToHost(QHostAddress::SpecialAddress::LocalHost, PORT_NO);
  this->socket->connectToHost(addr, port);
  this->remainingBytes = 0;
  connect(socket, &QIODevice::readyRead, this, &NetworkClient::readyRead);

  std::cout << "new client: " << username << std::endl;
}

void NetworkClient::sendHello() {
  QJsonObject obj;
  obj["type"] = SIG_HELLO;
  obj["data"] = QString::fromStdString(username);
  this->sendJsonObject(obj);
}

void NetworkClient::sendPupitreChoice(Pupitre pupitre) {
  QJsonObject obj;
  obj["type"] = SIG_CHOICE_PUPITRE;
  obj["data"] = pupitreToJson(pupitre);
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
  obj["data"] = noteToJson(note);
  this->sendJsonObject(obj);
}
