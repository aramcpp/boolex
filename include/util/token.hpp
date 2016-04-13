#ifndef UTIL_TOKEN_H
#define UTIL_TOKEN_H

#include <global.hpp>

enum class token_type {
    var,
    op,
    brace,
    end
};

typedef char token_value;

class token
{
public:
    token(token_type, token_value);
    
    token_type get_type();
    token_value get_value();
private:
    token_type type;
    token_value value;
};

typedef vector<token> token_list;

#endif // UTIL_TOKEN_H