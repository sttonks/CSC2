// EratosthenesFindNumberAlgorithmApp.cpp : Defines the entry point for the console application.
//Author:	Chris Orozco
//Goal:		Discover prime numbers in the range [0..n].
//			Using Eratosthenes algorithm.

//Preprocessor Declarations
#include "stdafx.h"
#include <iostream>
using namespace std;

//Prototypes (Headers or Signatures)
int findNextUnmarkedValue(bool a[], int n, int startingPosition);

//Main Function
int main()
{
	const int N = 30;
	bool a[N + 1];

	//initialization (all cells claim to be the candidate for prime)
	for (int i = 0; i < N + 1; i++) a[i] = true;

	int p = 2;

	while (p*p < N)
	{
		//disqualification
		for (int i = 2 * p; i < N + 1; i += p) a[i] = false;
		//find next unmarked value
		p = findNextUnmarkedValue(a, N, p);
	}
	
	//show results
	for (int i = 2; i < N + 1; i++)
		if (a[i]) cout << i << " ";//if (x == true) = if (x); as well if (x == false) = if (!x)

	cout << "\nAll done!\n";
	return 0;
}

//User-Defined Methods
int findNextUnmarkedValue(bool a[], int n, int startingPosition)
{
	for (int i = startingPosition + 1; i < n; i++)
		if (a[i]) return i;
	return -1;
}