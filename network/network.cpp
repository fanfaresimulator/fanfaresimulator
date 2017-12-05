#include "../include/network/network.hpp"

static int intFromJson(QJsonValue val) {
  if (val.isUndefined() || val.isNull()) {
    throw val.type();
  } else {
    return val.toInt();
  }
}

static bool boolFromJson(QJsonValue val) {
  if (val.isUndefined() || val.isNull()) {
    throw val.type();
  } else {
    return val.toBool();
  }
}

static double doubleFromJson(QJsonValue val) {
  if (!val.isDouble()) {
    throw val.type();
  } else {
    return val.toDouble();
  }
}


static std::string stringFromJson(QJsonValue val) {
  if (!val.isString()) {
    throw val.type();
  } else {
    return val.toString().toStdString();
  }
}

static QJsonArray arrayFromJson(QJsonValue val) {
  if (!val.isDouble()) {
    throw val.type();
  } else {
    return val.toArray();
  }
}

static QJsonObject objectFromJson(QJsonValue val) {
  if (!val.isObject()) {
    throw val.type();
  } else {
    return val.toObject();
  }
}

QJsonObject instrumentToJson(Instrument instrument) {
  QJsonObject JsonInstr;
  JsonInstr["id"] = instrument.getNumber();
  return JsonInstr;
}

Instrument instrumentFromJson(QJsonObject o) {
  Instrument instr;
  return instr;
}

QJsonObject partitionToJson(Partition partition) {
  QJsonArray JsonNotes;
  for (Note & n : partition.getNotes()) {
    JsonNotes.append(noteToJson(n));
  }

  QJsonArray JsonPupitre;
  for (Pupitre & p : partition.getPupitre()) {
    JsonPupitre.append(pupitreToJson(p));
  }

  QJsonObject JsonPart;
  JsonPart["notes"] = JsonNotes;
  JsonPart["pupitre"] = JsonPupitre;
  return JsonPart;
}

Partition partitionFromJson(QJsonObject o) {
  Partition partition;
  return partition;
}

QJsonObject noteToJson(Note note) {
  QJsonObject JsonNote;
  JsonNote["timestamp"] = note.getTime();
  JsonNote["signal"] = note.getSignal();
  JsonNote["pupitre"] = QString::fromStdString("TODO pupitre to JSON");
  JsonNote["key"] = note.getKey();
  JsonNote["velocity"] = note.getVelocity();
  JsonNote["track"] = note.getTrack();
  return JsonNote;
}

Note noteFromJson(QJsonObject obj) {
  double timestamp = doubleFromJson(obj["timestamp"]);
  bool signal = boolFromJson(obj["signal"]);
  Pupitre pupitre = pupitreFromJson(obj["pupitre"].toObject());
  int key = intFromJson("key");
  int velocity = intFromJson(obj["velocity"]);
  Note note(timestamp, signal, pupitre, key, velocity);
  return note;
}

QJsonObject pupitreToJson(Pupitre pupitre) {
  QJsonObject JsonPupitre;
  JsonPupitre["track"] = pupitre.getTrack();
  JsonPupitre["instrument"] = instrumentToJson(pupitre.getInstrument());
  return JsonPupitre;
}

QJsonObject pupitreToJson(Pupitre pupitre, bool b) {
  QJsonObject JsonPupitre;
  JsonPupitre["track"] = pupitre.getTrack();
  JsonPupitre["instrument"] = instrumentToJson(pupitre.getInstrument());
  JsonPupitre["taken"] = b;
  return JsonPupitre;
}

Pupitre pupitreFromJson(QJsonObject o) {
  Pupitre p;
  return p;
}
