#pragma once
#include "Hello.hpp"
#include <memory>

class HelloWrapper
{
public:
    HelloWrapper(std::shared_ptr<void> lib):
        _lib{lib},
        _instance{HelloWrapper::build(lib)}
    {
    };

    Hello* get()
    {
        return _instance.get();
    }
private:

    std::shared_ptr<void> _lib;
    std::shared_ptr<Hello> _instance;

    static std::shared_ptr<Hello> build(const std::shared_ptr<void> lib);
};
