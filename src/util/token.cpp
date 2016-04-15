#include <util/token.hpp>

token::token(token_type _type, char _var = 0) : type(_type), var_name(_var), op(bin_operator(_type))
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
map<size_t, token> char2tok = {
    {char2tok_op_start, token(token_type::NOT)},
    {char2tok_op_start + 1, token(token_type::AND)},
    {char2tok_op_start + 2, token(token_type::OR)},
    {char2tok_op_start + 3, token(token_type::IMP)},
    {char2tok_op_start + 5, token(token_type::EQU)},
    {char2tok_op_start + 4, token(token_type::XOR)},
    {char2tok_op_start + 6, token(token_type::SHEFFER)},
    {char2tok_op_start + 7, token(token_type::PIERCE)}
};