
#include "ScalarConverter.hpp"

double	ft_atof(const char *str);

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const & src) { (void)src; }

ScalarConverter::~ScalarConverter() {}

ScalarConverter & ScalarConverter::operator=(ScalarConverter const & rhs) { (void)rhs; return *this; }

void ScalarConverter::convert(const string& str)
{
    if (str == "nan" || str == "nanf" || str == "+inf" || str == "+inff" || str == "-inf" || str == "-inff" || str == "inf")
        std::cout << "char: impossible" << std::endl;
    else 
        printChar(str);
    printInt(str);
    if (str == "nan" || str == "nanf" || str == "+inf" || str == "+inff" || str == "-inf" || str == "-inff" || str == "inf") {
        if (str == "nan" || str == "nanf")
            std::cout << "float: nanf" << std::endl;
        else
            std::cout << "float: " << str << std::endl;
    }
    else
        printFloat(str);
    if (str == "nan" || str == "nanf" || str == "+inf" || str == "+inff" || str == "-inf" || str == "-inff" || str == "inf") {
        if (str == "nan" || str == "nanf")
            std::cout << "double: nan" << std::endl;
        else
            std::cout << "double: " << str << std::endl;
    }
    else
        printDouble(str);
}

void ScalarConverter::printChar(const string& str)
{
    std::cout << "char: ";
    try
    {
        int i = strtol(str.c_str(), NULL, 10);
        if (i < 0 || i > 255)
            throw OverflowException();
        if (isprint(i))
            std::cout << "'" << static_cast<char>(i) << "'" << std::endl;
        else
            throw NonDisplayableException();
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
}


void ScalarConverter::printInt(const string& str)
{
    std::cout << "int: ";
    try
    {

        long i = strtol(str.c_str(), NULL, 10);
        if (i < INT_MIN || i > INT_MAX)
            throw OverflowException();
        if (i == 0 && str != "0")
            throw ConversionException();
        std::cout << i << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
}

void ScalarConverter::printFloat(const string& str)
{
    std::cout << "float: ";
    try
    {
        double f = ft_atof(str.c_str());
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

void ScalarConverter::printDouble(const std::string &str)
{
    std::cout << "double: ";
    try
    {
        double d = ft_atof(str.c_str());
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