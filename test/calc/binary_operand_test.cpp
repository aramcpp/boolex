#include <global.hpp>
#include <calc/binary_operand.hpp>
//#include <util/bin_operators.hpp>

#include <iostream>
#include <fstream>

using namespace std;

void test_all(string str , int index)
{
    string name ,val;
    binary_operand ob1 ,ob2 ;
   // cout<<str<<endl;
    ifstream file(str);
    int i = 0 ,k = i;
    
    if(file.is_open())
    {
        while (getline(file, name))
        {
            
            if(k == 0)
               {
                   ob1 = name;
                   ++k;
               }
               else if(k == 1)
               {
                   ob2 = name;
                   ++k;
               }
               else if(k == 2 )
               {
                   val = name ;
                   if(ob1.op_and(ob2).to_string() == val)
                   {
                       cout<<"OK... "<< endl ;
                   }
                   else
                   {
                       cout<<"don`t"<< endl;
                   }
                   k = 0;
               }
               
               ++i;
         }
         file.close();
    }
    else
    {
        cout<< "file is not open"<< endl;
    }
}

int main()
{

   test_all("test_operators_and.txt",2);
        
    return 0 ;
}






