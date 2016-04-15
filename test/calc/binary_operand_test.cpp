#include <global.hpp>
#include <calc/binary_operand.hpp>
//#include <util/bin_operators.hpp>

#include <iostream>

int main()
{
    binary_operand ob1("00001111"),ob2("01010101") ;
     ob1.op_not() ;
    return 0 ;
}