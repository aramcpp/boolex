#ifndef UTIL_BIN_OPERATORS_HPP
#define UTIL_BIN_OPERATORS_HPP

#include <global.hpp>

class bin_operator
{
public:
    bin_operator(token_type);
    
    int get_priority() const;
    
    friend bool operator<(const bin_operator&, const bin_operator&);
    friend bool operator>(const bin_operator&, const bin_operator&);
    friend bool operator==(const bin_operator&, const bin_operator&);
    friend bool operator!=(const bin_operator&, const bin_operator&);
    friend bool operator<=(const bin_operator&, const bin_operator&);
    friend bool operator>=(const bin_operator&, const bin_operator&);
private:
    token_type op;
};

#endif // UTIL_BIN_OPERATORS_HPP