#include "../include/network/network.hpp"

static int intFromJson(QJsonValue val) {
  if (val.isUndefined() || val.isNull()) {
    throw "Incorrect type";
  } else {
    return val.toInt();
  }
}

static bool boolFromJson(QJsonValue val) {
  if (val.isUndefined() || val.isNull()) {
    throw "Incorrect type";
  } else {
    return val.toBool();
  }
}

static double doubleFromJson(QJsonValue val) {
  if (!val.isDouble()) {
    throw "Incorrect type";
  } else {
    return val.toDouble();
  }
}


static std::string stringFromJson(QJsonValue val) {
  if (!val.isString()) {
    throw "Incorrect type";
  } else {
    return val.toString().toStdString();
  }
}

QJsonArray arrayFromJson(QJsonValue val) {
  if (!val.isDouble()) {
    throw "Incorrect type";
  } else {
    return val.toArray();
  }
}

QJsonObject objectFromJson(QJsonValue val) {
  if (!val.isObject()) {
    throw "Incorrect type";
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
  std::vector<Note> notes;
  for (auto && n : arrayFromJson(o["notes"])) {
    notes.push_back(noteFromJson(objectFromJson(n)));
  }
  Partition partition(notes);
  return partition;
}

QJsonObject noteToJson(Note note) {
  QJsonObject JsonNote;
  JsonNote["timestamp"] = note.getTime();
  JsonNote["signal"] = note.getSignal();
  JsonNote["pupitre"] = pupitreToJson(note.getPupitre());
  JsonNote["key"] = note.getKey();
  JsonNote["velocity"] = note.getVelocity();
  JsonNote["track"] = note.getTrack();
  return JsonNote;
}

Note noteFromJson(QJsonObject obj) {
  double timestamp = doubleFromJson(obj["timestamp"]);
  bool signal = boolFromJson(obj["signal"]);
  Pupitre pupitre = pupitreFromJson(obj["pupitre"].toObject()).first;
  int key = intFromJson(obj["key"]);
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

std::pair<Pupitre, bool> pupitreFromJson(QJsonObject o) {
  int track = intFromJson(o["track"]);
  Instrument instr = instrumentFromJson(objectFromJson(o["instrument"]));
  Pupitre pupitre(track, instr);
  bool taken = false;
  if (o["taken"].isBool()) {
    taken = o["taken"].toBool();
  }
  return std::make_pair(pupitre, taken);
}