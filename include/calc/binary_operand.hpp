#ifndef CALC_BINARY_OPERAND_HPP
#define CALC_BINARY_OPERAND_HPP

#include <global.hpp>
#include <util/binary_repr.hpp>


class binary_operand
{
public:
    binary_operand();
    binary_operand(const binary_operand&);
    binary_operand(const string&);
    binary_operand(const binary_repr&);


    binary_operand op_not();
    binary_operand op_and(binary_operand);
    binary_operand op_or(binary_operand);
    binary_operand op_imp(binary_operand);
    binary_operand op_xor(binary_operand);
    binary_operand op_equ(binary_operand);
    binary_operand op_sheffer(binary_operand);
    binary_operand op_pierce(binary_operand);

private:
    binary_repr bin;
};

#endif // CALC_BINARY_OPERAND_HPP