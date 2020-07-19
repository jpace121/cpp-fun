#include "HelloWrapper.hpp"
#include <memory>
#include <dlfcn.h>
#include <iostream>


int main(int argc, char *argv[])
{
    std::shared_ptr<void> lib(dlopen("./libJames.so", RTLD_LAZY),
                              &dlclose);
    if(not lib)
    {
        std::cout << "Failed to load!" << std::endl;
        return 1;
    }

    HelloWrapper james(lib);

    james.get()->print();

    return 0;
}

