#ifndef SERVER_HPP
#define SERVER_HPP

#include <ctime>
#include <iostream>
#include <string>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <asio.hpp>


using asio::ip::tcp;

std::string make_daytime_string();

class tcp_connection : public boost::enable_shared_from_this<tcp_connection> {
public:
  typedef boost::shared_ptr<tcp_connection> pointer;

  static pointer create(asio::io_service &io_service);
  tcp::socket &socket();
  void start();

private:
  tcp_connection(asio::io_service &io_service) : socket_(io_service) {}

  void handle_write(const asio::error_code& /*error*/, size_t /*bytes_transferred*/) {}

  tcp::socket socket_;
  std::string message_;
};

class tcp_server {
public:
  tcp_server(asio::io_service &io_service)
      : acceptor_(io_service, tcp::endpoint(tcp::v4(), 13)) {
    start_accept();
  }

private:
  void start_accept();
  void handle_accept(tcp_connection::pointer new_connection, const asio::error_code &error);
  tcp::acceptor acceptor_;
};

#endif /* end of include guard:  */
