#include <dlfcn.h>
#include <iostream>
#include "Hello.hpp"
#include <memory>

int main(int argc, char *argv[])
{
    void* lib = dlopen("./libJames.so", RTLD_LAZY);
    if(not lib)
    {
        std::cout << "Failed to load!" << std::endl;
        return 1;
    }

    using createFunc = std::unique_ptr<Hello>(*)();

    dlerror();
    createFunc create = (createFunc) dlsym(lib, "create");

    const char *dlsym_error = dlerror();
    if (dlsym_error)
    {
        std::cout << "Failed to find symbol." << std::endl;
        dlclose(lib);
        return 1;
    }

    auto james = create();

    james->print();

    dlclose(lib);


    return 0;
}

