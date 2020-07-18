#pragma once
#include "Hello.hpp"
#include <memory>

class James : public Hello
{
    std::string name() const override;
};

extern "C"
{
std::unique_ptr<James> create();
}
