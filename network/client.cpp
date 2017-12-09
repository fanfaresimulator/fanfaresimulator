#include "../include/network/client.hpp"

/* PRIVATE */
void NetworkClient::sendJsonObject(QJsonObject o) {
  QJsonDocument doc = QJsonDocument(o);
  QByteArray msg = doc.toJson(JSON_FORMAT);
  size_t size = msg.size();
  msg.push_front(';'); // separator
  msg.push_front((std::to_string(size)).c_str());
  std::cout << "SENDING (size: "<< size << " bytes)\n" << msg.toStdString();
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
  QByteArray msg = socket->readAll();
  std::cout << "READING\n" <<  QString(msg).toStdString() << std::endl;

  bool ok;
  size_t objBeg = msg.indexOf(';');
  int size = msg.left(objBeg).toInt(&ok,10);
  std::cout << "size:" << size << std::endl;
  if (!ok) { // in the middle of the message
    size = msg.size(); // we take it all...
    objBeg = 0;        // ...from the begining
  }

  QByteArray content = msg.right(size - objBeg + 2); // +1 cannot bug
  pending.append(content);
  std::cout << "pending content" << QString(content).toStdString();
  std::cout << "pending size : "<< pending.size();
  if (pending.size() != size) { // only parts of the message has arrived
    return;
  }
  // message is arrived entirely
  QJsonParseError jerror;
  QJsonDocument doc = QJsonDocument::fromJson(pending, &jerror);
  if (jerror.error != QJsonParseError::ParseError::NoError) {
    std::cout << jerror.errorString().toStdString() << std::endl;
    return;
  }
  handleJsonDoc(doc);
}

/* PUBLIC */
NetworkClient::NetworkClient(QHostAddress addr, quint16 port, std::string username, QObject *parent) : QObject(parent) {
  this->username = username;

  this->socket = new QTcpSocket(this);
  // socket->connectToHost(QHostAddress::SpecialAddress::LocalHost, PORT_NO);
  this->socket->connectToHost(addr, port);
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
