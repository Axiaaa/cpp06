#include <iostream>
#include <stdint.h>

typedef struct Data {
    std::string s1;
    std::string s2;
} Data;


class Serializer {

    public:
        Serializer();
        ~Serializer();
        Serializer(Serializer const & src);
        Serializer & operator=(Serializer const & rhs);

        static Data* deserialize(uintptr_t raw);
        static uintptr_t serialize(Data* ptr);
};