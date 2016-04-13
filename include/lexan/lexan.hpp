#ifndef LEXAN_H
#define LEXAN_H

#include <global.hpp>
#include <util/token.hpp>

class lexan
{
public:
    lexan(cosnt string&);
    
    token_list parse();
private:
    string inp;
}

#endif // LEXAN_H