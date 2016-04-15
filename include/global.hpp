#ifndef GLOBAL_HPP
#define GLOBAL_HPP

#include <string>
#include <vector>
#include <stack>
#include <map>
#include <exception>

using std::string;
using std::vector;
using std::stack;
using std::map;
using std::exception;

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