#include "bad_length.h"

const char* bad_length::what() const noexcept
{
    return "ERROR: Going outside the array";
}