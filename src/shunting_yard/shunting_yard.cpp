#include <shunting_yard/shunting_yard.hpp>
#include <util/exceptions.hpp>

shunting_yard::shunting_yard(token_list &in1) : in(in1) {}

token_list shunting_yard::transform()
{
    stack<token> cs;
    token_list out;
    int n = in.size();
    int br_count = 0;
    for (int i = 0; i < n ; i++)
    {
        if (in[i].is_var())
        {
            cs.push(in[i]);
        } else
        if (in[i].is_op())
        {
            while (!cs.empty() && cs.top().is_op() && cs.top().get_op() >= in[i].get_op())
            {
                out.push_back(cs.top());
                cs.pop();
            }
            cs.push(in[i]);
            break;
        } else
        if (in[i].is_brace()) 
        {
            if (in[i].get_type() == token_type::OPEN_BRACE)
            {
                cs.push(in[i]);
                br_count++;
            } else
            if (in[i].get_type() == token_type::CLOSE_BRACE){
                while (!cs.empty() && cs.top().get_type() != token_type::OPEN_BRACE)
                {
                    out.push_back(cs.top());
                    cs.pop();
                }
                if (cs.top().get_type() != token_type::OPEN_BRACE)
                {
                    throw syntax_error("Brace mismatch, closed but not opened, pos = " + i);
                }
                cs.pop();
                br_count--;
            }
        }
    }    

    if (br_count != 0)
    {
        throw syntax_error("Brace mismatch, non closed brace");
    }
    while (!cs.empty())
    {
        out.push_back(cs.top());
        cs.pop();
    }
    
    return out;
}