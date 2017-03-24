#include "fibonacci.hpp"

/*
Suite de fibonnaci:

https://fr.wikipedia.org/wiki/Suite_de_Fibonacci

Premiers termes: 1, 1, 2, 3, 5, 8, 13, 21

Le zéro est omis.

*/

int fibonacciRecursif(int n)
{
  if (n < 2) return 1;
  
  return fibonacciRecursif(n - 1) + fibonacciRecursif(n - 2);
}

int fibonacciIteratif(int n)
{
  int i = 0;
  int j = 1;
  int temp = 1;
  
  for (int k = 0; k < n; k++)
  {
    temp = i + j; // Calcul du terme suivant
    i = j; // Mémorise l'élément courant
    j = temp; // Mémorise l'élémént suivant
  }
  
  return temp;
}
