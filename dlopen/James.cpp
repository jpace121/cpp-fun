#include "James.hpp"

std::string James::name() const
{
    return "James";
}

std::unique_ptr<James> create()
{
    return std::make_unique<James>();
}
