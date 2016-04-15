#ifndef SHUNTING_YARD_SHUNTING_YARD_HPP
#define SHUNTING_YARD_SHUNTING_YARD_HPP

#include <global.hpp>
#include <util/token.hpp>

class shunting_yard
{
public:
    shunting_yard();
    shunting_yard(token_list&);
    token_list transform();
    
private:
    int get_priority(token_type op);
     token_list in;
};




#endif //SHUNTING_YARD_SHUNTING_YARD_HPP