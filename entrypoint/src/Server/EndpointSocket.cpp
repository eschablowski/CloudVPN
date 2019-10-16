#include "EndpointSocket.h"
#include <string.h>
#include <boost/array.hpp>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

EndpointSocket::EndpointSocket(tcp::resolver::query query)
{
  boost::asio::io_service io_service;
  tcp::resolver resolver(io_service);
  tcp::resolver::iterator endpoint_iterator = resolver.resolve(query);
  tcp::resolver::iterator end;
  tcp::socket socket(io_service);
  boost::system::error_code error = boost::asio::error::host_not_found;
  while (error && endpoint_iterator != end)
  {
    socket.close();
    socket.connect(*endpoint_iterator++, error);
  }
  this->socket = &socket;
}

std::ostream &operator<<(std::ostream &os, const EndpointSocket &es)
{
  boost::array<char, 128> buf;
  boost::system::error_code error;

  size_t len = es.socket->read_some(boost::asio::buffer(buf), error);
  if (error == boost::asio::error::eof)
    return os; // Connection closed cleanly by peer.
  else if (error)
    throw boost::system::system_error(error); // Some other error.
  os << buf.data();
  return os;
}
std::string &operator<<(std::string &str, const EndpointSocket &es)
{
  boost::array<char, 128> buf;
  boost::system::error_code error;

  size_t len = es.socket->read_some(boost::asio::buffer(buf), error);
  if (error == boost::asio::error::eof)
    return str; // Connection closed cleanly by peer.
  else if (error)
    throw boost::system::system_error(error); // Some other error.
  str += buf.data();
  return str;
}
EndpointSocket &operator<<(EndpointSocket &es, std::string str)
{
  boost::system::error_code error;
  size_t len = es.socket->write_some(boost::asio::buffer(str), error);
  if (error == boost::asio::error::eof)
    return es; // Connection closed cleanly by peer.
  else if (error)
    throw boost::system::system_error(error); // Some other error.
  return es;
}

std::string EndpointSocket::getBuffer(){
  boost::array<char, 128> buf;
  boost::system::error_code error;

  size_t len = this->socket->read_some(boost::asio::buffer(buf), error);
  return std::string(buf.begin(), buf.end());
}
