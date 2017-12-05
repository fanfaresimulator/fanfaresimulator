#include "../include/network/network.hpp"

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
  JsonNote["velocity"] = note.getVelocity();
  JsonNote["key"] = note.getKey();
  JsonNote["track"] = note.getTrack();
  return JsonNote;
}

Note noteFromJson(QJsonObject obj) {
  // if (obj["timestamp"].) {
  //
  // }
  double timestamp;
  bool signal;
  Pupitre pupitre;
  int key;
  int velocity;
  Note note(timestamp, signal, pupitre, key, velocity);
  return note;
}

QJsonObject pupitreToJson(Pupitre pupitre) {
  QJsonObject JsonPupitre;
  JsonPupitre["track"] = pupitre.getTrack();
  JsonPupitre["instrument"] = instrumentToJson(pupitre.getInstrument());
  return JsonPupitre;
}

Pupitre pupitreFromJson(QJsonObject o) {
  Pupitre p;
  return p;
}
