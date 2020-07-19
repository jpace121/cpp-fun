#include "James.hpp"

std::string James::name() const
{
    return "James";
}

James* create()
{
    return new James;
}

void destroy(James* ptr)
{
    delete ptr;
}
