#pragma once

#include <string>

class Hello
{
public:
    void print() const;

private:
    virtual std::string name() const = 0;
};
