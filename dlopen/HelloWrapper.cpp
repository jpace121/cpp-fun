#include "HelloWrapper.hpp"
#include <dlfcn.h>


std::shared_ptr<Hello> HelloWrapper::build(const std::shared_ptr<void> lib)
{
    using createFunc_t = Hello*();
    using destroyFunc_t = void(Hello*);

    dlerror();
    createFunc_t* create = (createFunc_t*) dlsym(lib.get(), "create");
    destroyFunc_t* destroy = (destroyFunc_t*) dlsym(lib.get(), "destroy");

    const char *dlsym_error = dlerror();
    if (dlsym_error)
    {
        throw;
    }

    return std::shared_ptr<Hello>(create(), destroy);
}

std::shared_ptr<void> HelloWrapper::load(const std::string& path)
{
    std::shared_ptr<void> lib(dlopen(path.c_str(), RTLD_LAZY),
                              &dlclose);
    if(not lib)
    {
        throw;
    }

    return lib;
}
