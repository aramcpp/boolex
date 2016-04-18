#include <lexan/lexan.hpp>
#include <shunting_yard/shunting_yard.hpp>
#include <calc/binary_calc.hpp>
#include <util/exceptions.hpp>

#include <iostream>
#include <sstream>

int main()
{
    // a | b
    try
    {
        std::stringstream inp;
        
        inp << "(a" << char(12) << "b)" << char(11) << "e";
        
        lexan la(inp.str());
        
        token_list la_list = la.parse();
        
        shunting_yard sy(la_list);
        
        token_list sy_list = sy.transform();
        
        binary_calc bc(sy_list);
        
        binary_operand bo = bc.eval();
        
        std::cout << "result: " << bo.to_string() << std::endl;
    }
    catch (lexic_error &e)
    {
        std::cout << e.what() << std::endl;
    }
    catch (syntax_error &e)
    {
        std::cout << e.what() << std::endl;   
    }
    catch (exception &e)
    {
        std::cout << "unexpected error: " << e.what() << std::endl;
    }
    return 0;
}