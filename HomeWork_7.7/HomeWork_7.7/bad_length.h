#pragma once
#include <exception>

class bad_length : public std::exception
{
public:
    virtual const char* what() const noexcept override;
};

