#include <util/bin_operator.hpp>

bin_operator::bin_operator(token_type op): op(op)
{
    //
}

int bin_operator::get_priority() const
{
    int prior;
    switch(this->op)
    {
        case token_type::NOT:
            prior = 10;
            break;
        case token_type::AND:
            prior = 9;
            break;
        case token_type::OR:
            prior = 8;
            break;
        case token_type::IMP:
            prior = 7;
            break;
        case token_type::EQU:
            prior = 6;
            break;
        case token_type::XOR:
            prior = 5;
            break;
        case token_type::SHEFFER:
            prior = 4;
            break;
        case token_type::PIERCE:
            prior = 3;
            break;
        default:
            prior = -1;
    }
    return prior;
}

bool operator==(const bin_operator &op1, const bin_operator &op2)
{
    return op1.get_priority() == op2.get_priority();
}

bool operator!=(const bin_operator &op1, const bin_operator &op2)
{
    return op1.get_priority() != op2.get_priority();
}

bool operator<=(const bin_operator &op1, const bin_operator &op2)
{
    return op1.get_priority() <= op2.get_priority();
}

bool operator>=(const bin_operator &op1, const bin_operator &op2)
{
    return op1.get_priority() >= op2.get_priority();
}

bool operator<(const bin_operator &op1, const bin_operator &op2)
{
    return op1.get_priority() < op2.get_priority();
}

bool operator>(const bin_operator &op1, const bin_operator &op2)
{
    return op1.get_priority() > op2.get_priority();
}
