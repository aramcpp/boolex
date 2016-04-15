#include <calc/binary_calc.hpp>

binary_calc::binary_calc(token_list _list)
{
    this->list = _list;
}

int binary_calc::get_vars_count()
{
    char max = this->list[0].get_var_name();
    
    for(size_t i = 1 ;i<this->list.size(); ++i)
    {
        if(max < this->list[i].get_var_name())
             max = this->list[i].get_var_name();
    }
    return max -  'a' + 1 ;

}
  
  
void binary_calc::create_vars()
{
   
    int  count = get_vars_count();  //.  size  varibls // 
   
    for(size_t j = 0 ; j<this->list.size();++j)
    {
        int index_gen_var = this->list[j].get_var_name()  - 'a' + 1 ;  
        int l;
        int alg = 1<<(count - index_gen_var);
        int  var_len = 1<<count;
        binary_repr var(var_len); 
        
        
        for(int i = 0 ; i < var_len ;++i)
    	{
    		if( alg  >=  l )
    		{
    			var[i] =  0 ;
    			++l ;
    		}
    		
    		if( l > alg  && l<= 2*alg )
            {
                var[i] = 1 ;
                ++l;
            }
    
            if(l > 2* alg )
            {
                l = 0 ;
            }
    	//	cout<< var[i]<< endl ;
    	}
        vars.push_back(var);
    }
}


binary_repr binary_calc::eval()
{
    int list_size = list.size();
    stack<binary_operand> st ;
    
    
    for(int i = 0 ; i<list_size ;++i)
    {
        if(list[i].is_var())
        {
            st.push(vars[list[i].get_var_name() - 'a' + 1]);
        }
        
        binary_operand op1, op2;
        
        if(list[i].is_op())
        {
            
            // switch(list[i].get_op())
            // {
            //     case token_type::NOT :
            //          op1 = st.top();
            //          st.pop();
            //          st.push(op1.op_not());
            //          break;
                     
            //     case token_type::AND :
            //          op1 = st.top();
            //          st.pop();
            //          op2 = st.top();
            //          st.pop();
            //          st.push(op1.op_and(op2));
            //          break;
            // }
            
            if(list[i].get_op() == token_type::NOT)
            {
                op1 = st.top();
                st.pop();
                st.push(op1.op_not());
            }
            else if(list[i].get_op() == token_type::AND)
            {
                op1 = st.top();
                st.pop();
                op2 = st.top();
                st.pop();
                st.push(op1.op_and(op2));
            } 
            else if(list[i].get_op() == token_type::OR)
            {
                op1 =st.top();
                st.pop();
                op2 = st.top();
                st.pop();
                st.push(op1.op_or(op2));
            }
            else if(list[i].get_op() == token_type::IMP)
            {
                op1 =st.top();
                st.pop();
                op2 = st.top();
                st.pop();
                st.push(op1.op_imp(op2));
            }
            else if(list[i].get_op() == token_type::XOR)
            {
                op1 =st.top();
                st.pop();
                op2 = st.top();
                st.pop();
                st.push(op1.op_xor(op2));
            }
            else if(list[i].get_op() == token_type::EQU)
            {
                op1 =st.top();
                st.pop();
                op2 = st.top();
                st.pop();
                st.push(op1.op_equ(op2));
            }
            else if(list[i].get_op() == token_type::SHEFFER)
            {
                op1 =st.top();
                st.pop();
                op2 = st.top();
                st.pop();
                st.push(op1.op_sheffer(op2));
            }
            else if(list[i].get_op() == token_type::PIERCE)
            {
                op1 =st.top();
                st.pop();
                op2 = st.top();
                st.pop();
                st.push(op1.op_pierce(op2));
            }
            
            
        }
            
            
        
        
        
        
    }
    
    
}


