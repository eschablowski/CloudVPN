#include <string>
#include <curl/curl.h>
#include <curl/easy.h>

class HTTPRequest
{
public:
  struct response
  {
    int code;
    std::string text;
  };
  HTTPRequest(std::string url);
  ~HTTPRequest();
  CURL *getCURL();
  response request();

private:
  CURL *curl;
  std::string url;
  std::string readBuffer;
};
