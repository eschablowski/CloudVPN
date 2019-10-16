#include "Server/TCP.h"

using boost::asio::ip::tcp;

TCPServer::TCPServer(boost::asio::io_service &io_context, short port) : acceptor(io_context, tcp::endpoint(tcp::v4(), port))
{
  this->do_accept();
}

class session
    : public std::enable_shared_from_this<session>
{
public:
  session(tcp::socket socket)//, std::string host)
      : socket_(std::move(socket))
  {
    // this->endpoint = new EndpointSocket(tcp::resolver::query(host, "endpoint"));
  }

  void start()
  {

    do_read();
  }

private:
  // EndpointSocket *endpoint;
  void do_read()
  {
    auto self(shared_from_this());
    socket_.async_read_some(boost::asio::buffer(data_, max_length),
                            [this, self](boost::system::error_code ec, std::size_t length) {
                              if (!ec)
                              {
                                do_write(length);
                              }
                            });
  }

  void do_write(std::size_t length)
  {
    auto self(shared_from_this());
    boost::asio::async_write(socket_, boost::asio::buffer(data_, length),
                             [this, self](boost::system::error_code ec, std::size_t /*length*/) {
                               if (!ec)
                               {
                                 do_read();
                               }
                             });
  }

  tcp::socket socket_;
  enum
  {
    max_length = 1024
  };
  char data_[max_length];
};

void TCPServer::do_accept()
{
  this->acceptor.async_accept(
      [this](boost::system::error_code ec, tcp::socket socket) {
        if (!ec)
        {
          std::make_shared<session>(std::move(socket))->start();
        }

        this->do_accept();
      });
}
