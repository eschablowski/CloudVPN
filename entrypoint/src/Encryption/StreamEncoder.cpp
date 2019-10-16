#include "StreamEncoder.h"
#include <string.h>
#include <iostream>

StreamEncoder::StreamEncoder(std::string token)
{
  this->token = token;
  this->buffer = "";
  this->i = 0;
}

std::ostream &operator<<(std::ostream &os, const StreamEncoder &se)
{
  os << se.buffer;
  return os;
}

std::string &operator<<(std::string &str, const StreamEncoder &se)
{
  str += se.buffer;
  return str;
}

StreamEncoder &operator<<(StreamEncoder &se, std::string str)
{
  std::string mask = se.token.substr(se.i, se.token.length() - se.i - 1);
  while (mask.length() < str.length())
  {
    mask += se.token;
  }
  for (int i = 0; i < str.length(); i++)
  {
    se.buffer += ((char)mask[i] ^ (char)str[i]);
  }
  se.i = (se.i + str.length()) % se.token.length();
  return se;
}
