#pragma once

#include <QJsonObject>
#include <QJsonArray>

#include "../pupitre.hpp"
#include "../instrument.hpp"
#include "../partition.hpp"
#include "../note.hpp"

#define PORT_NO 15051
#define DISCOVER_MSG "fanfaresimulator"

typedef enum {
    SIG_HELLO,
    SIG_NOTE,
    SIG_CHOICE_LOBBY,
    SIG_CHOICE_INSTRUMENT,
    SIG_READY,
    SIG_START,
    SIG_LOBBIES,
    SIG_INSTRUMENTS,
    SIG_PARTITION
} Protocol_sig;

QJsonObject instrumentToJson(Instrument instrument);

Instrument instrumentFromJson(QJsonObject o);

QJsonObject partitionToJson(Partition partition);

Partition partitionFromJson(QJsonObject o);

QJsonObject noteToJson(Note note);

Note noteFromJson(QJsonObject o);

QJsonObject pupitreToJson(Pupitre pupitre);

QJsonObject pupitreToJson(Pupitre pupitre, bool b);

Pupitre pupitreFromJson(QJsonObject o);