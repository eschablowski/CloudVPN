#include <string>

class RequestToken {
  public:
    RequestToken();
    RequestToken(std::string);
    ~RequestToken();
    std::string getToken();
  private:
    std::string token;
    std::string url;
};
