#include "HelloWrapper.hpp"
#include <iostream>


int main(int argc, char *argv[])
{

    auto lib = HelloWrapper::load("./libJames.so");

    HelloWrapper james(lib);

    james->print();

    return 0;
}

