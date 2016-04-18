#include <shunting_yard/shunting_yard.hpp>
#include <util/exceptions.hpp>
#include <util/token.hpp>

#include <iostream>
#include <utility> //std::pair

using std::pair;
using std::cout;
using std::endl;


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
    // token_list input = {
    //     token(token_type::VAR, 'a'),
    //     token(token_type::AND, '1'),
    //     token(token_type::VAR, 'b'),
    //     token(token_type::OR, '2'),
    //     token(token_type::VAR, 'c'),
    //     token(token_type::XOR, '3'),
    //     token(token_type::NOT, '4'),
    //     token(token_type::OPEN_BRACE, '5'),
    //     token(token_type::VAR, 'd'),
    //     token(token_type::IMP, '6'),
    //     token(token_type::VAR, 'a'),
    //     token(token_type::CLOSE_BRACE, '7')
    // };
    
    vector<pair<token_list, token_list>> tests = {
        {
            {
            //a & b | c ^  ~(d -> a)
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
            },
            {
                //a b & c | d a -> ~ ^
                token(token_type::VAR, 'a'),
                token(token_type::VAR, 'b'),
                token(token_type::AND),
                token(token_type::VAR, 'c'),
                token(token_type::OR),
                token(token_type::VAR, 'd'),
                token(token_type::VAR, 'a'),
                token(token_type::IMP),
                token(token_type::NOT),
                token(token_type::XOR)
            }
        },
        
        
        {
            {
                //g PI ~( ~(a|(b&c)=e) SH ~f)
                token(token_type::VAR, 'g'),
                token(token_type::PIERCE),
                token(token_type::NOT),
                token(token_type::OPEN_BRACE),
                token(token_type::NOT, 'c'),
                token(token_type::OPEN_BRACE, '3'),
                token(token_type::VAR, 'a'),
                token(token_type::OR),
                token(token_type::OPEN_BRACE, 'd'),
                token(token_type::VAR, 'b'),
                token(token_type::AND),
                token(token_type::VAR, 'c'),
                token(token_type::CLOSE_BRACE, '2'),
                token(token_type::EQU),
                token(token_type::VAR, 'e'),
                token(token_type::CLOSE_BRACE),
                token(token_type::SHEFFER, '5'),
                token(token_type::NOT),
                token(token_type::VAR, 'f'),
                token(token_type::CLOSE_BRACE)
            },
            {
                //g a b c & | e = ~ f ~ SH ~ PI
                token(token_type::VAR, 'g'),
                token(token_type::VAR, 'a'),
                token(token_type::VAR, 'b'),
                token(token_type::VAR, 'c'),
                token(token_type::AND),
                token(token_type::OR),
                token(token_type::VAR, 'e'),
                token(token_type::EQU),
                token(token_type::NOT),
                token(token_type::VAR, 'f'),
                token(token_type::NOT),
                token(token_type::SHEFFER, '5'),
                token(token_type::NOT, 'c'),
                token(token_type::PIERCE)
            }
        }
    };
    
    int correct = 0;
    int test_count = tests.size();
    
    for (int i = 0; i < test_count; i++)
    {
        try {
            shunting_yard sh(tests[i].first);
            token_list temp = sh.transform();
            cout << "Test no " << i << " ";
            if (is_equal(tests[i].second, temp))
            {
                cout << "succeeded!";
                cout << "\nproof: " << temp[3].get_var_name() << " " << temp[4].get_var_name();
                cout << "\nproof: " << temp[5].get_var_name() << " " << temp[6].get_var_name();
                correct++;
            } else
            {
                cout << "failed: wrong answer";
            }
        } catch(basic_exception &e)
        {
            cout << "failed: " << e.what();
        }
        cout << "\n";
    }
    cout << "Shunting yard test result:\ncorrect "
    << correct << " out of " << test_count 
    << "\nPercentage: " << correct*100.0/test_count << "\n";
    
    
    return 0;
    
    // shunting_yard sh(input);
    // token_list output = sh.transform();
    // try
    // {
    //     for (int i = 0; i < output.size(); i++)
    //     {
    //         std::cout << output[i].get_var_name() << " ";
    //     }
    // } catch(lexic_error e)
    // {
    //     std::cout << "????" << std::endl;
    // }
    // std::cout << "aaaaa" << std::endl;
    // std::cout << std::endl;
}