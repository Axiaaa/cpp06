#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <limits.h>
#include <string>
#include <cmath>

using std::string;

class ScalarConverter
{

    public:

    static void convert(const std::string &str);

    private:
    ~ScalarConverter();
    ScalarConverter &operator=(const ScalarConverter &src);
    ScalarConverter(const ScalarConverter &src);
    ScalarConverter();
    static void printChar(const std::string &str);
    static void printInt(const std::string &str);
    static void printFloat(const std::string &str);
    static void printDouble(const std::string &str);


    class ImpossibleException : public std::exception
    {
        public:
        virtual const char* what() const throw()
        {
            return "impossible";
        }
    };

    class NonDisplayableException : public std::exception
    {
        public:
        virtual const char* what() const throw()
        {
            return "Non displayable";
        }
    };

    class ConversionException : public std::exception
    {
        public:
        virtual const char* what() const throw()
        {
            return "Conversion failed";
        }
    };

    class OverflowException : public std::exception
    {
        public:
        virtual const char* what() const throw()
        {
            return "Overflow";
        }
    };

    class NanfException : public std::exception
    {
        public:
        virtual const char* what() const throw()
        {
            return "nanf";
        }
    };

};
