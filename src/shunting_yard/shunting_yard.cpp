#include <shunting_yard/shunting_yard.hpp>
#include <util/exceptions.hpp>

shunting_yard::shunting_yard(const token_list &_in) : in(_in)
{
    //
}

token_list shunting_yard::transform()
{
    stack<token> cs;
    
    token_list out;
    
    int br_count = 0;
    
    for (int i = 0; i < in.size(); i++)
    {
        if (in[i].is_var())
        {
            out.push_back(in[i]);
        }
        else if (in[i].is_op())
        {
            while (!cs.empty() && cs.top().is_op() && cs.top().get_op() >= in[i].get_op())
            {
                out.push_back(cs.top());
                cs.pop();
            }
            
            cs.push(in[i]);
        }
        else if (in[i].is_brace()) 
        {
            if (in[i].get_type() == token_type::OPEN_BRACE)
            {
                cs.push(in[i]);
                br_count++;
            }
            else if (in[i].get_type() == token_type::CLOSE_BRACE)
            {
                while (!cs.empty() && cs.top().get_type() != token_type::OPEN_BRACE)
                {
                    out.push_back(cs.top());
                    cs.pop();
                }
                
                if (cs.empty())
                {
                    throw syntax_error("brace closed without opening at " + i);
                }
                
                cs.pop();
                
                br_count--;
            }
        }
    }    

    if (br_count != 0)
    {
        throw syntax_error("brace opened but not closed");
    }
    
    while (!cs.empty())
    {
        out.push_back(cs.top());
        cs.pop();
    }
    
    return out;
}