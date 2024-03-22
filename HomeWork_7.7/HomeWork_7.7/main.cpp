#include <iostream>
#include "IntegerArray.h"
#include "bad_range.h"
#include "bad_length.h"
#include <exception>

int main()
{
    std::cout << "Specify the number of array elements" << std::endl;
    int sizeArray{};
    std::cin >> sizeArray;
    try
    { 
        IntegerArray array(sizeArray);

        for (int i{ 0 }; i < array.getLength(); ++i)
        {
            array[i] = i + 1;
            std::cout << array[i] << ' ';
        }
        std::cout << std::endl;

        std::cout << "Specify the new number of array elements" << std::endl;
        std::cin >> sizeArray;
        array.resize(sizeArray);
        for (int i{ 0 }; i < array.getLength(); ++i)
            std::cout << array[i] << ' ';
        std::cout << std::endl;

        std::cout << "Add a new index value in the format: value index " << std::endl;
        int value{}, index{};
        std::cin >> value >> index;
        array.insertBefore(value, index);
        for (int i{ 0 }; i < array.getLength(); ++i)
            std::cout << array[i] << ' ';
        std::cout << std::endl;

        std::cout << "Delete an item by index" << std::endl;
        std::cin >> index;
        array.remove(index);
        for (int i{ 0 }; i < array.getLength(); ++i)
            std::cout << array[i] << ' ';
        std::cout << std::endl;

    }
    catch (std::exception& e)
    {
        std::cout << e.what();
    }
    std::cout << '\n';
    return 0;
}