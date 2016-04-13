// #include <shunting_yard/shunting_yard.hpp>


// int get_precede(char op) 
// {
//     int res;
//     switch(op)
//     {
//         case '!':
//             res = 10;
//             break;
//         case '&':
//             res = 9;
//             break;
//         case '|':
//             res = 8;
//             break;
//         case '+':
//             res = 7;
//             break;
//     }
// }


// bool is_precede(char op1, char op2)
// {
//     return get_precede(op1) >= get_precede(op2);
// }


// error_code shunting_yard(token_list& in, token_list& out)
// {
//     stack cs;
//     int n = in.size();
//     int k = 0;
//     int br_count = 0;
//     for (int i = 0; i < n ; i++)
//     {
//         switch(in[i].get_type)
//         {
//         case VAR:
//             out[k] = in[i];
//             k++;
//             break;
//         case OP:
//             while (!cs.empty() && is_precede(cs.top().get_value, in[i].get_value))
//             {
//                 out[k] = cs.top();
//                 k++;
//                 cs.pop();
//             }
//             cs.push(in[i]);
//             break;
//         case BRACE:
//             if (in[i].get_value == '(')
//             {
//                 cs.push(in[i]);
//                 br_count++;
//             } else
//             {
//                 while (!cs.empty() && cs.top() != '(')
//                 {
//                     out[k] = cs.top();
//                     k++;
//                     cs.pop();
//                 }
//                 if (cs.top() != '(')
//                 {
//                     return BRACE_MISMATCH;
//                 }
//                 cs.pop();
//                 br_count--;
//             }
//         }
//     }
//     if (br_count != 0)
//     {
//         return BRACE_MISMATCH;
//     }
//     while (!cs.empty())
//     {
//         out[k] = cs.top();
//         k++;
//         cs.pop();
//     }
    
//     return SUCCESS;
// }