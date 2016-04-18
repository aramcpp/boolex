#ifndef MATRIX_GENERATOR_TRUTH_MATRIX_GENERATOR_HPP
#define MATRIX_GENERATOR_TRUTH_MATRIX_GENERATOR_HPP

#include <global.hpp>
#include <util/token.hpp>

struct matrix_column
{
    string op_str;
    
    int op_index;
    
    binary_operand op;
    
    static int no_index = -1;
};

typedef vector<matrix_column> truth_matrix;

class truth_matrix_generator
{
public:
    truth_matrix_generator();
    
    void add_column(binary_operand);
    
    truth_matrix get_matrix();
private:
    truth_matrix matrix;
};

#endif // MATRIX_GENERATOR_TRUTH_MATRIX_GENERATOR_HPP