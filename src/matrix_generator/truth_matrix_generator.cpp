#include <matrix_generator\truth_matrix_generator>


truth_matrix_generator(size_t _size) : size(_size)
{
    for (size_t i = 0; i < size; i++)
    {
        matrix.push_back({});
    }
}



void add_var(char c, const binary_operand &b) 
{
    if (c - 'a' < size)
    {
        matrix[c - 'a'] = {to_string(c), matrix_column::no_index, b};
    }
    else
    {
        throw exception("matrix generator exception: var index is bigger than size");
    }
} 

    
void add_column(const matrix_column& col)
{
    matrix.push_back(col);
}


truth_matrix get_matrix()
{
    return matrix;
}

