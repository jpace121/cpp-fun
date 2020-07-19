#pragma once
#include "Hello.hpp"
#include <memory>
#include <string>

class HelloWrapper
{
public:
    HelloWrapper(std::shared_ptr<void> lib):
        _lib{lib},
        _instance{HelloWrapper::build(lib)}
    {
    };

    Hello& operator*()
    {
        return *_instance;
    }

    Hello* operator->()
    {
        return _instance.get();
    }

    static std::shared_ptr<void> load(const std::string& path);
private:

    std::shared_ptr<void> _lib;
    std::shared_ptr<Hello> _instance;

    static std::shared_ptr<Hello> build(const std::shared_ptr<void> lib);
};
