#ifndef CALC_BINARY_CALC_HPP
#define CALC_BINARY_CALC_HPP

#include <global.hpp>
#include <util/token.hpp>
#include <calc/binary_operand.hpp>

class binary_calc
{
public:
    binary_calc(token_list);
    
    binary_repr eval(); 
private:
    void create_vars();
    int get_vars_count();
    
    vector<binary_operand> vars;
    token_list list;
};

#endif  // CALC_BINARY_CALC_HPP
