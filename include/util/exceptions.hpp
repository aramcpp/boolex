#ifndef UTIL_EXCEPTIONS_HPP
#define UTIL_EXCEPTIONS_HPP

#include <global.hpp>

class basic_exception : public exception
{
public:
	explicit basic_exception(string _msg);
	
	virtual ~basic_exception() throw();
	
	virtual const char *what() const throw();
protected:
	string msg;
};

class lexic_error : public basic_exception
{
public:
	explicit lexic_error(string _msg);
	
	virtual ~lexic_error() throw();
	
	virtual const char *what() const throw();
};

class syntax_error : public basic_exception
{
public:
	explicit syntax_error(string _msg);
	
	virtual ~syntax_error() throw();
	
	virtual const char *what() const throw();
};

#endif // UTIL_EXCEPTIONS_HPP