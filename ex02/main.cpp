#include "Base.hpp"
#include "BaseA.hpp"
#include "BaseB.hpp"
#include "BaseC.hpp"
#include <iostream>

Base* generate(void) {
    srand(time(NULL));
    int i = rand() % 3;
    if (i == 0)
        return new BaseA();
    else if (i == 1)
        return new BaseB();
    else
        return new BaseC();
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
    catch (std::bad_cast &bc) {
        try {
            BaseB &b = dynamic_cast<BaseB&>(p);
            (void)b;
            std::cout << "BaseB" << std::endl;
        }
        catch (std::bad_cast &bc) {
            try {
                BaseC &c = dynamic_cast<BaseC&>(p);
                (void)c;
                std::cout << "BaseC" << std::endl;
            }
            catch (std::bad_cast &bc) {
                std::cout << "Unknown" << std::endl;
            }
        }
    }
}



int main() {
    Base *base = generate();
    identify(base);
    identify(*base);
    return 0;
}