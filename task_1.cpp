#include <iostream>
#include <windows.h>
#include <vector>
#include <algorithm>
#include <cmath>

std::string declination(int value); // task 1 

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int value{};
    std::cout << "Введите число -> ";
    std::cin >> value;
    std::cout << declination(value) << "\n";

    return 0;
}

std::string declination(int value)
{
    std::string result = "компьютеров";
    int multipleTen = value % 10;
    int multipleHundred = value % 100;
    if(multipleTen == 1 && multipleHundred != 11)
    {
        result = "компьютер";
    }else if(multipleTen >= 2 && multipleTen <= 4 && 
            (multipleHundred < 12 || multipleHundred > 14))
    {
        result = "компьютера";
    }
    return std::to_string(value) + " " + result;
}
