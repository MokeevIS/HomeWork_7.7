#include "bad_range.h"

const char* bad_range::what() const noexcept 
{
    return "ERROR: Incorrect array length is provided!";
}
