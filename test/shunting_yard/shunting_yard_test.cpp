#include <shunting_yard/shunting_yard.hpp>
#include <util/token.hpp>
#include <iostream>


int main(int argc, char **argv)
{
    token_list input = {
        token(token_type::VAR, 'a'),
        token(token_type::AND, '1'),
        token(token_type::VAR, 'b'),
        token(token_type::OR, '2'),
        token(token_type::VAR, 'c'),
        token(token_type::XOR, '3'),
        token(token_type::NOT, '4'),
        token(token_type::OPEN_BRACE, '5'),
        token(token_type::VAR, 'd'),
        token(token_type::IMP, '6'),
        token(token_type::VAR, 'a'),
        token(token_type::CLOSE_BRACE, '7')
    };
    
    shunting_yard sh(input);
    token_list output = sh.transform();
    for (int i = 0; i < output.size(); i++)
    {
        std::cout << output[i].get_var_name() << " ";
    }
}