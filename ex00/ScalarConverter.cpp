#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(const char *input) : _input(input) {
    return;
}

ScalarConverter::~ScalarConverter() {
    return;
}

ScalarConverter::ScalarConverter(const ScalarConverter &cpy) {
    *this = cpy;
    return;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs) {
    if (this != &rhs) {
        this->_input = rhs._input;
    }
    return *this;
}

void ScalarConverter::convert() {
    std::cout << "char: ";
    try {
        char c = this->toChar();
        if (c >= 32 && c <= 126) {
            std::cout << "'" << c << "'" << std::endl;
        } else {
            std::cout << "Non displayable" << std::endl;
        }
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "int: ";
    try {
        int i = this->toInt();
        std::cout << i << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "float: ";
    try {
        float f = this->toFloat();
        std::cout << f;
        if (f - static_cast<int>(f) == 0) {
            std::cout << ".0";
        }
        std::cout << "f" << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "double: ";
    try {
        double d = this->toDouble();
        std::cout << d;
        if (d - static_cast<int>(d) == 0) {
            std::cout << ".0";
        }
        std::cout << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return;
}

int ScalarConverter::toInt() {
    int i = 0;
    try {
        i = std::stoi(this->_input);
    } catch (std::exception &e) {
        throw ScalarConverter::ImpossibleConversion();
    }
    return i;
}

float ScalarConverter::toFloat() {
    float f = 0.0f;
    try {
        f = std::stof(this->_input);
    } catch (std::exception &e) {
        throw ScalarConverter::ImpossibleConversion();
    }
    return f;
}

double ScalarConverter::toDouble() {
    double d = 0.0;
    try {
        d = std::stod(this->_input);
    } catch (std::exception &e) {
        throw ScalarConverter::ImpossibleConversion();
    }
    return d;
}

char ScalarConverter::toChar() {
    if (std::strlen(this->_input) == 1) {
        return static_cast<char>(this->_input[0]);
    }
    if (std::strlen(this->_input) == 3 && this->_input[0] == '\'' && this->_input[2] == '\'') {
        return static_cast<char>(this->_input[1]);
    }
    throw ScalarConverter::ImpossibleConversion();
}