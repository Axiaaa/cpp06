#include <iostream>
#include <cstring>
class ScalarConverter {
    public:
        ScalarConverter(const char *input);
        ~ScalarConverter();
        ScalarConverter(const ScalarConverter &src);
        ScalarConverter &operator=(const ScalarConverter &src);
        void    convert();
        int     toInt();
        float   toFloat();
        double  toDouble();
        char    toChar();
    private:
        ScalarConverter();
        const char *_input;

    class ImpossibleConversion : public std::exception {
        public:
            virtual const char *what() const throw() {
                return "impossible";
            }
    };

    class NonDisplayable : public std::exception {
        public:
            virtual const char *what() const throw() {
                return "Non displayable";
            }
    };

    class InvalidInput : public std::exception {
        public:
            virtual const char *what() const throw() {
                return "Invalid input";
            }
    };
};