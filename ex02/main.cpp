#include "Base.hpp"
#include "BaseA.hpp"
#include "BaseB.hpp"
#include "BaseC.hpp"
#include <iostream>
#include <cstdlib>

Base* generate(void) {
    srand(time(NULL));
    int i = rand() % 3;
    switch (i) {
        case 0: return new BaseA();
        case 1: return new BaseB();
        case 2: return new BaseC();
    }
    return NULL;
}

void identify(Base* p) {
    if (dynamic_cast<BaseA*>(p))
        std::cout << "BaseA" << std::endl;
    else if (dynamic_cast<BaseB*>(p))
        std::cout << "BaseB" << std::endl;
    else if (dynamic_cast<BaseC*>(p))
        std::cout << "BaseC" << std::endl;
}

void identify(Base& p) {
    try {
        BaseA &a = dynamic_cast<BaseA&>(p);
        (void)a;
        std::cout << "BaseA" << std::endl;
    }
    catch (std::exception &e) {
        try {
            BaseB &b = dynamic_cast<BaseB&>(p);
            (void)b;
            std::cout << "BaseB" << std::endl;
        }
        catch (std::exception &e) {
            try {
                BaseC &c = dynamic_cast<BaseC&>(p);
                (void)c;
                std::cout << "BaseC" << std::endl;
            }
            catch (std::exception &e) {
                std::cout << "Unknown" << std::endl;
            }
        }
    }
}

int main() {
    Base *base = generate();
    identify(base);
    identify(*base);
    Base *a= NULL;
    identify(*a);
    delete base;
    return 0;
}