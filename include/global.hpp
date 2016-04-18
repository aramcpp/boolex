#ifndef GLOBAL_HPP
#define GLOBAL_HPP

#include <string>
#include <vector>
#include <stack>
#include <map>
#include <exception>
#include <utility> //std::pair
#include <locale>

using std::string;
using std::vector;
using std::stack;
using std::map;
using std::exception;
using std::pair;

using std::tolower;
using std::isalpha;
using std::isupper;

enum class token_type {
    VAR,
    NOT,
    AND,
    OR,
    IMP,
    XOR,
    EQU,
    SHEFFER,
    PIERCE,
    OPEN_BRACE,
    CLOSE_BRACE,
    END
};

#endif // GLOBAL_HPP