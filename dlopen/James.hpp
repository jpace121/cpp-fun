#pragma once
#include "Hello.hpp"

class James : public Hello
{
    std::string name() const override;
};

extern "C"
{
James* create();

void destroy(James *ptr);
}
