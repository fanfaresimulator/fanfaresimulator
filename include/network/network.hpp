#pragma once

#include <utility>
#include <string>
#include <map>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

#include "../synth/pupitre.hpp"
#include "../synth/instrument.hpp"
#include "../synth/partition.hpp"
#include "../synth/note.hpp"

#define PORT_NO 15051
#define DISCOVER_MSG "fanfaresimulator"
#define JSON_FORMAT QJsonDocument::Indented

typedef enum {
  SIG_HELLO,
  SIG_NOTE,
  SIG_CHOICE_LOBBY,
  SIG_CHOICE_PUPITRE,
  SIG_READY,
  SIG_START,
  SIG_LOBBIES,
  SIG_PUPITRES,
  SIG_PARTITION,
  SIG_PING
} Protocol_sig;

int intFromJson(QJsonValue val);
bool boolFromJson(QJsonValue val);
double doubleFromJson(QJsonValue val);
std::string stringFromJson(QJsonValue val);

QJsonArray arrayFromJson(QJsonValue val);
QJsonObject objectFromJson(QJsonValue val);

QJsonObject instrumentToJson(Instrument instrument);
Instrument instrumentFromJson(QJsonObject o);

QJsonObject partitionToJson(Partition partition);
Partition partitionFromJson(QJsonObject o);

QJsonObject noteToJson(Note note);
Note noteFromJson(QJsonObject o);

QJsonObject pupitreToJson(Pupitre pupitre);
QJsonObject pupitreToJson(Pupitre pupitre, bool b);
std::pair<Pupitre, bool> pupitreFromJson(QJsonObject o);
std::map<Pupitre, bool> pupitresFromJson(QJsonArray a);

QJsonObject pingToJson(int seqNumber);
