
#include "ScalarConverter.hpp"
#include "ft_atof.cpp"

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
