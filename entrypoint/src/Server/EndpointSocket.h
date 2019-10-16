#include <string.h>
#include <boost/array.hpp>
#include <boost/asio.hpp>

class EndpointSocket
{
public:
  EndpointSocket(boost::asio::ip::tcp::resolver::query);
  ~EndpointSocket();

  friend std::ostream &operator<<(std::ostream &os, const EndpointSocket &es);
  friend std::string &operator<<(std::string &str, const EndpointSocket &es);
  friend EndpointSocket &operator<<(EndpointSocket &es, std::string str);
  std::string getBuffer();

private:
  boost::asio::ip::tcp::socket *socket;
};
