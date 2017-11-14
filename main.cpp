#include <asio.hpp>
#include <iostream>
#include "server.hpp"

using namespace std;

int main() {
  cout << "Hello, World!";

  // creating server
  try {
    asio::io_service io_service;
    tcp_server server(io_service);
    io_service.run();
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  try {
    asio::io_service io_service;
    tcp::resolver resolver(io_service);
    tcp::resolver::query query("host", "daylight");
    tcp::resolver::iterator endpoint_iterator = resolver.resolve(query);
    tcp::socket socket(io_service);
    asio::connect(socket, endpoint_iterator);

    while (true) {
      boost::array<char, 128> buf;
      asio::error_code error;

      size_t len = socket.read_some(asio::buffer(buf), error);
      if (error == asio::error::eof) {
        break; // Connection closed cleanly by peer.
      } else if (error) {
        throw asio::system_error(error); // Some other error.
      }
      std::cout.write(buf.data(), len);
    }
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}
