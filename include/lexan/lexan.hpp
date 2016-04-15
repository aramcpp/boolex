#ifndef LEXAN_HPP
#define LEXAN_HPP

#include <global.hpp>
#include <util/token.hpp>

class lexan
{
public:
    lexan(const string&);
    
    token_list parse();
private:
    bool is_op(char);

    string inp;
};

#endif // LEXAN_HPP