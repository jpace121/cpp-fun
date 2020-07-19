#include <dlfcn.h>
#include <iostream>
#include "Hello.hpp"
#include <memory>

int main(int argc, char *argv[])
{
    std::unique_ptr<void, decltype(&dlclose)> lib(dlopen("./libJames.so", RTLD_LAZY),
                                                 &dlclose);
    if(not lib)
    {
        std::cout << "Failed to load!" << std::endl;
        return 1;
    }

    using createFunc = Hello*(*)();
    using destroyFunc = void(*)(Hello*);

    dlerror();
    createFunc create = (createFunc) dlsym(lib.get(), "create");
    destroyFunc destroy = (destroyFunc) dlsym(lib.get(), "destroy");

    const char *dlsym_error = dlerror();
    if (dlsym_error)
    {
        std::cout << "Failed to find symbol." << std::endl;
        return 1;
    }

    std::unique_ptr<Hello, decltype(destroy)> james(create(), destroy);

    james->print();


    return 0;
}

