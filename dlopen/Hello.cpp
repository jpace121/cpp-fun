#include "Hello.hpp"
#include <iostream>

void Hello::print() const
{
    std::cout << "Hello " << name() << "!" << std::endl;
}
