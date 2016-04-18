#include <lexan/lexan.hpp>
#include <util/exceptions.hpp>

lexan::lexan(const string &_inp) : inp(_inp)
{
    //
}

bool lexan::is_op(char c)
{
    return char2tok.find(c) != char2tok.end();
}

bool lexan::is_brace(char c)
{
    return c == '(' || c == ')';
}

bool lexan::is_space(char c)
{
    return c == ' ';
}


string lexan::preprocess()
{
    string in;
    
    for (size_t i = 0; i < inp.length(); i++)
    {
        
        //if (isspace(inp[i]))
        if (is_space(inp[i]))
        {
            continue;
        }
        else if (isalpha(inp[i]))
        {
            if (isupper(inp[i]))
            {
                in += tolower(inp[i]);
            }
            else
            {
                in += inp[i];
            }
        }
        else if (is_op(inp[i]))
        {
            in += inp[i];
        }
        else if (is_brace(inp[i]))
        {
            in += inp[i];
        }
        else
        {
            throw lexic_error("unexpected tokne: " + inp[i]);
        }
    }
    
    return in;
}

token_list lexan::parse()
{
    string in = preprocess();
    
    token_list out;
    
    for (size_t i = 0; i < in.length(); i++)
    {
        if (isalpha(in[i]))
        {
            out.push_back(token(token_type::VAR, in[i]));
        }
        else if (is_op(in[i]))
        {
            out.push_back(char2tok.find( (size_t) in[i] )->second);
        }
        else if (is_brace(in[i]))
        {
            if (in[i] == '(')
            {
                out.push_back(token(token_type::OPEN_BRACE));
            }
            else if (in[i] == ')')
            {
                out.push_back(token(token_type::CLOSE_BRACE));
            }
        }
    }
    
    return out;
}