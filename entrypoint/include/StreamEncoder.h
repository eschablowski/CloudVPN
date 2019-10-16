#include <iostream>
#include <string.h>

class StreamEncoder
{
private:
  std::string token;
  std::string buffer;
  int i;

public:
  StreamEncoder(std::string);
  friend std::ostream &operator<<(std::ostream &os, const StreamEncoder &se);
  friend std::string &operator<<(std::string &str, const StreamEncoder &se);
  friend StreamEncoder& operator<<(StreamEncoder& se, std::string str);
};
