#include <util/exceptions.hpp>

/// class basic_exception

basic_exception::basic_exception(string _msg) : msg(_msg)
{
    //
}

basic_exception::~basic_exception() throw()
{
    //
}

const char *basic_exception::what() const throw()
{
	return msg.c_str();
}

/// class lexic_error

lexic_error::lexic_error(string _msg) : basic_exception(_msg)
{
    //
}

lexic_error::~lexic_error() throw()
{
    //
}

const char *lexic_error::what() const throw()
{
	return ("lexic_error: " + msg).c_str();
}

/// syntax_error

syntax_error::syntax_error(string _msg) : basic_exception(_msg)
{
    //
}

syntax_error::~syntax_error() throw()
{
    //
}

const char *syntax_error::what() const throw()
{
	return ("syntax_error: " + msg).c_str();
}