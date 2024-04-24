#include <iostream>
#include <windows.h>
#include <vector>
#include <algorithm>
#include <cmath>

std::vector<int> getCommonDivisors(std::vector<int> array); // task 2

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int start{}, end{};
    std::cout << "Введите граничные значения -> ";
    std::cin >> start >> end;
    std::vector<int> array = getPrimeNumbers(start, end);
    
    std::cout << "[ ";
    for(int num : array)
    {
        std::cout << num << " ";
    }
    std::cout << "]\n";

    return 0;
}

std::vector<int> getCommonDivisors(std::vector<int> array)
{
    std::vector<int> resultArray{};
    std::sort(array.begin(), array.end());
    bool isCorrect = true;
    for(int i = 2; i <= array[0]; ++i)
    {
        if(array[0] % i == 0)
        {
            for(int j = 1; j < array.size(); ++j)
            {
                if(array[j] % i != 0)
                {
                    isCorrect = false;
                    break;
                }
            }
            if(isCorrect)
            {
                resultArray.push_back(i);
            }
            isCorrect = true;
        }
    }
    return resultArray;
}
