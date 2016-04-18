#include <util/token.hpp>


token::token(token_type _type, char _var) : type(_type), var_name(_var), op(bin_operator(_type))
{
}

token_type token::get_type()
{
    return this->type;
}

bool token::is_op()
{
    if (this->type != token_type::VAR && this->type != token_type::OPEN_BRACE 
        && this->type != token_type::CLOSE_BRACE && this->type != token_type::END)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool token::is_brace()
{
    if (this->type == token_type::OPEN_BRACE 
        || this->type == token_type::CLOSE_BRACE)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool token::is_term()
{
    return (this->type == token_type::END);
}

bool token::is_var()
{
    return (this->type == token_type::VAR);
}

char token::get_var_name()
{
    return this->var_name;
}

bin_operator token::get_op()
{
    return this->op;
}

////////////////////////////////////////////////////////////////////////////////
map<char, token> char2tok = {
    {char2tok_op_base + 0,      token(token_type::NOT)},
    {char2tok_op_base + 1,      token(token_type::AND)},
    {char2tok_op_base + 2,      token(token_type::OR)},
    {char2tok_op_base + 3,      token(token_type::IMP)},
    {char2tok_op_base + 4,      token(token_type::XOR)},
    {char2tok_op_base + 5,      token(token_type::EQU)},
    {char2tok_op_base + 6,      token(token_type::SHEFFER)},
    {char2tok_op_base + 7,      token(token_type::PIERCE)}
};

map<token, char> tok2char {
    {token(token_type::NOT),        char2tok_op_base + 0},
    {token(token_type::AND),        char2tok_op_base + 1},
    {token(token_type::OR),         char2tok_op_base + 2},
    {token(token_type::IMP),        char2tok_op_base + 3},
    {token(token_type::XOR),        char2tok_op_base + 4},
    {token(token_type::EQU),        char2tok_op_base + 5},
    {token(token_type::SHEFFER),    char2tok_op_base + 6},
    {token(token_type::PIERCE),     char2tok_op_base + 7}
};