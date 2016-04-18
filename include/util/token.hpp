#ifndef UTIL_TOKEN_HPP
#define UTIL_TOKEN_HPP

#include <global.hpp>
#include <util/bin_operator.hpp>

class token
{
public:
    token(token_type, char _var=0);
    
    token_type get_type();
    
    bool is_op();
    
    bool is_brace();
    
    bool is_term();
    
    bool is_var();
    
    char get_var_name();
    
    bin_operator get_op();
private:
    token_type type;
    char var_name;
    bin_operator op;
};

typedef vector<token> token_list;

extern map<char, token> char2tok;

extern map<token, char> tok2char;

const size_t char2tok_op_base = 10;
const size_t char2tok_op_count = 8;

#endif // UTIL_TOKEN_HPP