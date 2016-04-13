#include <util/token.hpp>

token::token(token_type _type, token_value _value) : type(_type), value(_value)
{
    //
}

token_type token::get_type()
{
    return this->type;
}

token_value token::get_value()
{
    return this->value;
}