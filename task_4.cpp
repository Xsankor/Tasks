#include <iostream>
#include <windows.h>
#include <vector>
#include <algorithm>
#include <cmath>

void printMultiplicationTable(int value); // task 4

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    printMultiplicationTable(5);

    return 0;
}

void printMultiplicationTable(int value)
{
    for(int i = 0; i <= value; ++i)
    {
        if(i == 0)
        {
            std::cout << " \t";
        }else
        {
            std::cout << i << "\t";
        }
        for(int j = 1; j <= value; ++j)
        {
            if(i == 0)
            {
                std::cout << j << "\t";
            }else
            {
                std::cout << j * i << "\t";
            }
        }
        std::cout << "\n";
    }
}
