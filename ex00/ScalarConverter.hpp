#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <limits.h>
#include <cmath>

class ScalarConverter
{

    public:
    ScalarConverter();
    ScalarConverter(std::string str);
    ScalarConverter(ScalarConverter const & src);
    ~ScalarConverter();
    ScalarConverter & operator=(ScalarConverter const & rhs);

    void convert();
    void printChar();
    void printInt();
    void printFloat();
    void printDouble();

    private:
    std::string _str;


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
