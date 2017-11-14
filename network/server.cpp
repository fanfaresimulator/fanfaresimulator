#include <asio.hpp>
#include <boost/bind.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/shared_ptr.hpp>
#include <ctime>
#include <iostream>
#include <string>

#include "server.hpp"

using asio::ip::tcp;

std::string make_daytime_string() {
  using namespace std; // For time_t, time and ctime;
  time_t now = time(0);
  return ctime(&now);
}

typedef boost::shared_ptr<tcp_connection> pointer;

static pointer create(asio::io_service &io_service) {
  return pointer(new tcp_connection(io_service));
}

// Socket getter
tcp::socket &socket() { return socket_; }

void start() {
  message_ = make_daytime_string();

  asio::async_write(socket_, asio::buffer(message_),
                    boost::bind(&tcp_connection::handle_write,
                                shared_from_this(), asio::placeholders::error,
                                asio::placeholders::bytes_transferred));
}

tcp_connection(asio::io_service &io_service) : socket_(io_service) {}

void handle_write(const asio::error_code & /*error*/,
                  size_t /*bytes_transferred*/) {}

tcp::socket socket_;
std::string message_;

tcp_server(asio::io_service &io_service)
    : acceptor_(io_service, tcp::endpoint(tcp::v4(), 13)) {
  start_accept();
}

void start_accept() {
  tcp_connection::pointer new_connection =
      tcp_connection::create(acceptor_.get_io_service());

  acceptor_.async_accept(new_connection->socket(),
                         boost::bind(&tcp_server::handle_accept, this,
                                     new_connection,
                                     asio::placeholders::error));
}

void handle_accept(tcp_connection::pointer new_connection,
                   const asio::error_code &error) {
  if (!error) {
    new_connection->start();
  }

  start_accept();
}
