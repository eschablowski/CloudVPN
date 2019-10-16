#include "RequestToken.h"
#include "Encryption/httpRequest.h"
#include <string.h>
#include <stdexcept>
#include <iostream>

static std::string base64_encode(const std::string &in);

RequestToken::RequestToken()
{
  this->url = "https://authenticator.local/token";
  HTTPRequest request(this->url);
  this->token = request.request().text;
}

RequestToken::RequestToken(std::string url)
{
  this->url = url;
  HTTPRequest request(url);
  this->token = request.request().text;
}

RequestToken::~RequestToken()
{
  HTTPRequest request(this->url + "/" + curl_easy_escape(request.getCURL(), this->token.c_str(), this->token.length()));
  // curl_easy_setopt(request.getCURL(), CURLOPT_CUSTOMREQUEST, "DELETE");
  request.request();
}

std::string RequestToken::getToken()
{
  return this->token;
}
