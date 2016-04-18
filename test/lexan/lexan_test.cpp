#include <lexan/lexan.hpp>
#include <global.hpp>
#include <util/exceptions.hpp>
#include <util/token.hpp>
#include <iostream>
#include <utility> //std::pair

using std::cout;

bool is_equal(token_list& op1, token_list& op2)
{
    int n = op1.size();
    
    if (n != op2.size())
    {
        return false;
    }
    
    for (int i = 0; i < n; i++)
    {
        if 
        (
            op1[i].get_type() != op2[i].get_type() ||
            (
                op1[i].get_type() == token_type::VAR && 
                op2[i].get_type() == token_type::VAR &&
                op1[i].get_var_name() != op2[i].get_var_name()
            )
        )
        return false;

    }
    return true;
}

int main(int argc, char **argv)
{
    vector<pair<string, token_list>> tests = 
    {
        
        {
            // ^ = f e w a
            {
                "\xe \xf  fewa"
                //"abc"
            },   
            {
                token (token_type::XOR),
                token (token_type::EQU, 'x'),
                token (token_type::VAR, 'f'),
                token (token_type::VAR, 'e'),
                token (token_type::VAR, 'w'),
                token (token_type::VAR, 'a')
            }
        },
        
        {
            // ^ = f e w a
            {
                "\xe \xf  fewa"
            },   
            {
                token (token_type::XOR),
                token (token_type::EQU, 'x'),
                token (token_type::VAR, 'f'),
                token (token_type::VAR, 'e'),
                token (token_type::VAR, 'w'),
                token (token_type::VAR, 'a')
            }
        },
        
        
        {
            //a | b & (c | (d = e))
            {
                "a \xc b \xb (c \xc (d \xf e))"
            },
            {
                token (token_type::VAR, 'a'),
                token (token_type::OR),
                token (token_type::VAR, 'b'),
                token (token_type::AND),
                token (token_type::OPEN_BRACE, 'a'),
                token (token_type::VAR, 'c'),
                token (token_type::OR),
                token (token_type::OPEN_BRACE, 'a'),
                token (token_type::VAR, 'd'),
                token (token_type::EQU),
                token (token_type::VAR, 'e'),
                token (token_type::CLOSE_BRACE),
                token (token_type::CLOSE_BRACE)
            }
        },
        
        {
            // a b c z u v a f e PI ~
            {
                "aBC ZUVa fe\x11 \xa"
            },
            {
                token (token_type::VAR, 'a'),
                token (token_type::VAR, 'b'),
                token (token_type::VAR, 'c'),
                token (token_type::VAR, 'z'),
                token (token_type::VAR, 'u'),
                token (token_type::VAR, 'v'),
                token (token_type::VAR, 'a'),
                token (token_type::VAR, 'f'),
                token (token_type::VAR, 'e'),
                token (token_type::PIERCE),
                token (token_type::NOT)
                
            }
        },
    
        
        
        {
            // ( ( ) )abc 
            {
                " ( ( ) ) abc"
            },
            {
                token (token_type::OPEN_BRACE),
                token (token_type::OPEN_BRACE),
                token (token_type::CLOSE_BRACE),
                token (token_type::CLOSE_BRACE),
                token (token_type::VAR, 'a'),
                token (token_type::VAR, 'b'),
                token (token_type::VAR, 'c')
            }
        },
        
        
        
        {
            //abc
            {
                "abc"
            },
            {
                token (token_type::VAR, 'a'),
                token (token_type::VAR, 'b'),
                token (token_type::VAR, 'c')
            }
        }
        
        
    };
    
    
    int correct = 0;
    int test_count = tests.size();
    //lexan lx[test_count];
    //token_list temp[test_count];
    //lexan lxt(tests[0].first);
    
    // cout << "bar\n";
    
    // lexan tlx(tests[2].first);
    // token_list tmp = tlx.parse();
    // if (is_equal(tests[2].second, tmp) )
    // {
    //     cout << "simple test passed!!!\n";
    // } else
    // {
    //     cout << "no pass\n";
    // }
    
    
    
    for (int i = 0; i < test_count; i++)
    {
        try
        {
            cout << "Test no " << i << " ";
            lexan lx(tests[i].first);
            
            token_list temp = lx.parse();
            
            if (is_equal(tests[i].second, temp))
            {
                cout << "succeeded!";
                correct++;
            } else
            {
                cout << "failed: wrong answer";
            }
        }
        catch(basic_exception &e)
        {
            cout << "failed: " << "\n" << e.what();
        }
        cout << "\n";
        //cout << tests[i].first << "\n"; 
    }
    cout << "Lexic analyzer test result:\ncorrect "
    << correct << " out of " << test_count 
    << "\nPercentage: " << correct*100.0/test_count << "\n";
    
    return 0;
}