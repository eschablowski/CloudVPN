#include "Encryption/httpRequest.h"
#include <stdexcept>

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
  ((std::string *)userp)->append((char *)contents, size * nmemb);
  return size * nmemb;
}

HTTPRequest::HTTPRequest(std::string url)
{
  this->curl = curl_easy_init();
  if (this->curl)
  {
    curl_easy_setopt(this->curl, CURLOPT_FOLLOWLOCATION, 1L);
    curl_easy_setopt(this->curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(this->curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(this->curl, CURLOPT_WRITEDATA, &this->readBuffer);
  }
  else
  {
    throw std::runtime_error("cURL was unable to initialize");
  }
}

HTTPRequest::~HTTPRequest()
{
  curl_easy_cleanup(this->curl);
}

HTTPRequest::response HTTPRequest::request()
{
  if (this->curl)
  {
    CURLcode res = curl_easy_perform(this->curl);
    if (res == 0)
    {
      HTTPRequest::response response;
      response.code = res;
      response.text = this->readBuffer;
      this->readBuffer = "";
      return response;
    }
    throw std::runtime_error("cURL encountered an error of code: " + res);
  }
  throw std::runtime_error("cURL uninitialized (should never happen)");
}

CURL *HTTPRequest::getCURL()
{
  return this->curl;
}
