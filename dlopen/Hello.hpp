#pragma once

#include <string>

class Hello
{
public:
    void print() const;
    virtual ~Hello() = default;

private:
    virtual std::string name() const = 0;
};
