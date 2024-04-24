#include <iostream>
#include <windows.h>
#include <vector>
#include <algorithm>
#include <cmath>

std::vector<int> getPrimeNumbers(int start, int end); // task 3
bool isPrime(int num);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::vector<int> testVec = {42, 12, 18};
    std::vector<int> resultVec = getCommonDivisors(testVec);
    std::cout << "[ ";
    for(int number : resultVec)
    {
        std::cout << number << " ";
    }
    std::cout << "]\n";

    return 0;
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
