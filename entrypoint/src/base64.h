//
//  base64 encoding and decoding with C++.
//  Version: 1.01.00
//

#ifndef BASE64_H_C0CE2A47_D10E_42C9_A27C_C883944E704A
#define BASE64_H_C0CE2A47_D10E_42C9_A27C_C883944E704A

#include <string>
namespace base64
{
bool is_base64(unsigned char c);
bool is_base64(std::string);
std::string encode(std::string);
std::string decode(std::string const &s);
} // namespace base64
#endif /* BASE64_H_C0CE2A47_D10E_42C9_A27C_C883944E704A */
