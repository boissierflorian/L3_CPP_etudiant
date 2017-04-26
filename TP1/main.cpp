/*
Compilation standard: 
g++ -o main main.cpp fibonacci.cpp -Wall -Wextra -std=c++14 -g

Compilation séparée:
g++ -c fibonacci.cpp
g++ -c main.cpp
g++ -o main main.o fibonacci.o -Wall -Wextra -std=c++14 -g
 */
#include <iostream>

#include "fibonacci.hpp"

using namespace std;

int main(int argc, char** argv)
{
  cout << "fibonacciRecursif(7) = " << fibonacciRecursif(7) << endl;
  cout << "fibonacciIteratif(7) = " << fibonacciIteratif(7) << endl; 

  return 0;
}
