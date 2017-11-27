#pragma once

#define PORT_NO 15051

typedef enum {
  HELLO,
  NOTE,
  CHOICE_LOBBY,
  CHOICE_INSTRUMENT,
  READY,
  LOBBIES,
  INSTRUMENTS,
  PARTITION
} Protocol_sig;
