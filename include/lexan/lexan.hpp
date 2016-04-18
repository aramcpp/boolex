#ifndef LEXAN_LEXAN_HPP
#define LEXAN_LEXAN_HPP

#include <global.hpp>
#include <util/token.hpp>

class lexan
{
public:
    lexan(const string&);
    
    token_list parse();
private:
    string preprocess();
    bool is_op(char);
    bool is_brace(char);
    bool is_space(char);

    string inp;
};

#endif // LEXAN_LEXAN_HPP
