
#include "ScalarConverter.hpp"

double	ft_atof(const char *str);

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(std::string str) : _str(str) {}

ScalarConverter::ScalarConverter(ScalarConverter const & src) : _str(src._str) {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter & ScalarConverter::operator=(ScalarConverter const & rhs)
{
    if (this != &rhs)
        _str = rhs._str;
    return *this;
}

void ScalarConverter::convert()
{
    if (_str == "nan" || _str == "nanf" || _str == "+inf" || _str == "+inff" || _str == "-inf" || _str == "-inff")
        std::cout << "char: impossible" << std::endl;
    else 
        printChar();
    printInt();
    if (_str == "nan" || _str == "nanf" || _str == "+inf" || _str == "+inff" || _str == "-inf" || _str == "-inff") {
        if (_str == "nan" || _str == "nanf")
            std::cout << "float: nanf" << std::endl;
        else
            std::cout << "float: " << _str << std::endl;
    }
    else
        printFloat();
    if (_str == "nan" || _str == "nanf" || _str == "+inf" || _str == "+inff" || _str == "-inf" || _str == "-inff") {
        if (_str == "nan" || _str == "nanf")
            std::cout << "double: nan" << std::endl;
        else
            std::cout << "double: " << _str << std::endl;
    }
    else
        printDouble();
}

void ScalarConverter::printChar()
{
    std::cout << "char: ";
    try
    {
        int i = strtol(_str.c_str(), NULL, 10);
        if (i < 0 || i > 255)
            throw OverflowException();
        if (std::isprint(i))
            std::cout << "'" << static_cast<char>(i) << "'" << std::endl;
        else
            throw NonDisplayableException();
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
}


void ScalarConverter::printInt()
{
    std::cout << "int: ";
    try
    {

        long i = strtol(_str.c_str(), NULL, 10);
        if (i < INT_MIN || i > INT_MAX)
            throw OverflowException();
        if (i == 0 && _str != "0")
            throw ConversionException();
        std::cout << i << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
}

void ScalarConverter::printFloat()
{
    std::cout << "float: ";
    try
    {
        double f = ft_atof(_str.c_str());
        if (std::isinf(f) || std::isnan(f))
            throw NanfException();
        if (static_cast<int>(f) == f)
            std::cout << f << ".0f" << std::endl;
        else
            std::cout << f << "f" << std::endl;
    }

    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
}

void ScalarConverter::printDouble()
{
    std::cout << "double: ";
    try
    {
        double d = ft_atof(_str.c_str());
        if (std::isinf(d) || std::isnan(d))
            throw NanfException();
        if (static_cast<int>(d) == d)
            std::cout << d << ".0" << std::endl;
        else
            std::cout << d << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
}
#include <iostream>

static void	skip_whitespace(const char **str)
{
	while (**str == ' ' || **str == '\t' || **str == '\n'
		|| **str == '\v' || **str == '\f' || **str == '\r')
		(*str)++;
}

static int	get_sign(const char **str)
{
	int	sign;

	sign = 1;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			sign = -1;
		(*str)++;
	}
	return (sign);
}

static double	get_integer_part(const char **str)
{
	double	result;

	result = 0.0;
	while (std::isdigit(**str))
	{
		result = result * 10.0 + (**str - '0');
		(*str)++;
	}
	return (result);
}

static double	get_fractional_part(const char **str)
{
	double	fraction;
	double	divisor;

	fraction = 0.0;
	divisor = 1.0;
	if (**str == '.')
	{
		(*str)++;
		while (std::isdigit(**str))
		{
			fraction = fraction * 10.0 + (**str - '0');
			divisor *= 10.0;
			(*str)++;
		}
	}
	return (fraction / divisor);
}


double	ft_atof(const char *str)
{
	double	integer_part;
	double	fractional_part;
	int		sign;

	skip_whitespace(&str);
	sign = get_sign(&str);
	integer_part = get_integer_part(&str);
	fractional_part = get_fractional_part(&str);
	return (sign * (integer_part + fractional_part));
}