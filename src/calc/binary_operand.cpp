#include <calc/binary_operand.hpp>

// constructors

binary_operand::binary_operand()
{
    this->bin = binary_repr();
}

binary_operand::binary_operand(const binary_operand &src)
{
    this->bin = binary_repr(src.bin);
}

binary_operand::binary_operand(const string &src)
{
   this->bin = binary_repr(src.begin(), src.end());
}
// operators

binary_operand binary_operand::op_not()
{
    binary_operand new_value;
    
    new_value.bin = binary_repr(this->bin.size());
    
    for (size_t i = 0 ; i < bin.size(); ++i)
    {
        new_value.bin[i] = !bin[i];
    }
    
    return new_value;
}

binary_operand binary_operand::op_and(binary_operand val)
{
    binary_operand new_value;
    
    new_value.bin = binary_repr(this->bin.size());
    
    for (size_t i = 0 ; i < this->bin.size(); ++i)
    {
        new_value.bin[i] = (this->bin[i] && val.bin[i]);
    }
    
    return new_value;
}

binary_operand binary_operand::op_or(binary_operand val)
{
    binary_operand  new_value;
    
    new_value.bin = binary_repr(this->bin.size());
    
    for (size_t i = 0 ; i < this->bin.size(); ++i)
    {
        new_value.bin[i] = (this->bin[i] || val.bin[i]);
    }
       
    return new_value;
       
}

binary_operand binary_operand::op_imp(binary_operand val)
{
    return this->op_not().op_or(val);
}

binary_operand binary_operand::op_xor(binary_operand val)
{
    return this->op_and(val.op_not()).op_or(this->op_not().op_and(val));
}

binary_operand binary_operand::op_equ(binary_operand val)
{
    return this->op_xor(val).op_not();
}

binary_operand binary_operand::op_sheffer(binary_operand val)
{
    return this->op_and(val).op_not();
}

binary_operand binary_operand::op_pierce(binary_operand val)
{
    return this->op_or(val).op_not();
}