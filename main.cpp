#include <iostream>
#include <windows.h>
#include <vector>
#include <algorithm>
#include <cmath>

std::string declination(int value); // task 1 
std::vector<int> getCommonDivisors(std::vector<int> array); // task 2
std::vector<int> getPrimeNumbers(int start, int end); // task 3
void printMultiplicationTable(int value); // task 4

bool isPrime(int num);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int value{};
    std::cout << "Введите число -> ";
    std::cin >> value;
    std::cout << declination(value) << "\n";

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

    std::vector<int> testVec = {42, 12, 18};
    std::vector<int> resultVec = getCommonDivisors(testVec);
    std::cout << "[ ";
    for(int number : resultVec)
    {
        std::cout << number << " ";
    }
    std::cout << "]\n";
    printMultiplicationTable(5);

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

std::vector<int> getPrimeNumbers(int start, int end)
{
    std::vector<int> resultArray{};
    for(int i = start; i <= end; ++i)
    {
        if(isPrime(i))
        {
            resultArray.push_back(i);
        }
    }
    return resultArray;
}

bool isPrime(int num) 
{
  if (num < 2) return false;
  for(int i = 2; i <= num / 2; ++i)
  {
    if(num % i == 0)
    {
        return false;
    }   
  }
  return true;
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
