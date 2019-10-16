#include <boost/asio.hpp>
#include <memory>
#include <utility>
#include "Server/EndpointSocket.h"

class TCPServer
{
public:
  TCPServer(boost::asio::io_service &io_context, short port);

protected:
  void do_accept();

private:
  boost::asio::ip::tcp::acceptor acceptor;
};
