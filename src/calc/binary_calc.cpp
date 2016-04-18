#include <calc/binary_calc.hpp>

#include <sstream>

using std::stringstream;

#include <iostream>

binary_calc::binary_calc(token_list _list)
{
    this->list = _list;
}

int binary_calc::get_vars_count()
{
    char max_var = -1;
    
    for (token &cur : this->list)
    {
        if (cur.is_var())
        {
            max_var = std::max(max_var, cur.get_var_name());
        }
    }
    return max_var - 'a' + 1 ;

}
  
  
void binary_calc::create_vars()
{
    int count = get_vars_count();
    
    int bsize = 1 << count;
   
    for (int i = 0; i < count; i++)
    {
        string bin_data = "";
        
        int period = 1 << (count - i - 1);
        
        int cur_bit = 0;
        
        int filled = 0;
        
        while (filled != bsize)
        {
            bin_data += string(period, cur_bit + '0');
            
            cur_bit = !cur_bit;
            
            filled += period;
        }
        
        vars.push_back(binary_operand(bin_data));
        
        std::cout << char('A' + i) << ": " << bin_data << std::endl;
    }
}

typedef matrix_column bcalc_item;

binary_operand binary_calc::eval()
{
    create_vars();
    
    stack<bcalc_item> st;
    
    int op_index = 1;
    
    for(token &cur : list)
    {
        if(cur.is_var())
        {
            st.push({
                string(1, cur.get_var_name()),
                no_index,
                vars[cur.get_var_name() - 'a'],
            });
        }
        
        binary_operand op1, op2;
        
        if(cur.is_op())
        {
            if(cur.get_op() == token_type::NOT)
            {
                op1 = st.top();
                st.pop();
                
                string cur_str = "";
                
                stringstream ss;
                
                if (op1.op_index != bcalc_item::no_index)
                {
                    ss << char(char2tok_base + 0) << ""
                }
                
                st.push({
                    
                    op1.op_not()
                });
                
                std::cout << "NOT: " << op1.op_not().to_string() << std::endl;
            }
            else if(cur.get_op() == token_type::AND)
            {
                op1 = st.top();
                st.pop();
                op2 = st.top();
                st.pop();
                st.push(op2.op_and(op1));
                
                std::cout << "AND: " << op2.op_and(op1).to_string() << std::endl;
            } 
            else if(cur.get_op() == token_type::OR)
            {
                op1 =st.top();
                st.pop();
                op2 = st.top();
                st.pop();
                st.push(op2.op_or(op1));
                
                std::cout << "OR: " << op2.op_or(op1).to_string() << std::endl;
            }
            else if(cur.get_op() == token_type::IMP)
            {
                op1 =st.top();
                st.pop();
                op2 = st.top();
                st.pop();
                st.push(op2.op_imp(op1));
                
                std::cout << "IMP: " << op2.op_imp(op1).to_string() << std::endl;
            }
            else if(cur.get_op() == token_type::XOR)
            {
                op1 =st.top();
                st.pop();
                op2 = st.top();
                st.pop();
                st.push(op2.op_xor(op1));
                
                std::cout << "XOR: " << op2.op_xor(op1).to_string() << std::endl;
            }
            else if(cur.get_op() == token_type::EQU)
            {
                op1 =st.top();
                st.pop();
                op2 = st.top();
                st.pop();
                st.push(op2.op_equ(op1));
                
                std::cout << "EQU: " << op2.op_equ(op1).to_string() << std::endl;
            }
            else if(cur.get_op() == token_type::SHEFFER)
            {
                op1 =st.top();
                st.pop();
                op2 = st.top();
                st.pop();
                st.push(op2.op_sheffer(op1));
                
                std::cout << "SHEFFER: " << op2.op_sheffer(op1).to_string() << std::endl;
            }
            else if(cur.get_op() == token_type::PIERCE)
            {
                op1 =st.top();
                st.pop();
                op2 = st.top();
                st.pop();
                st.push(op2.op_pierce(op1));
                
                std::cout << "PIERCE: " << op2.op_pierce(op1).to_string() << std::endl;
            }
        }
        
    }
    
    return st.top();
}


