#ifndef server_h
#define server_h

#include "Print.h"

class Client;

class Server : public Print {

public:
  virtual void begin() = 0;
  virtual size_t write(uint8_t) = 0;
  virtual size_t write(const uint8_t *buf, size_t size) = 0;

  virtual Client * client() = 0; //funzione per ottenere un puntatore a client

  using Print::write;

};

#endif
