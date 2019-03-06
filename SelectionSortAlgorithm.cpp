// SelectionSortAlgorithm.cpp : Defines the entry point for the console application.
//Author:	Chris Orozco
//Goal:		Implement SelectionSortAlgorithm using array & pointer notation

//Pre-Processor Declarations:
#include "stdafx.h"
#include <iostream>
using namespace std;

//Prototypes:
void showArray(int a[], int size);
int findPosMax(int a[], int size);
void swap(int a[], int size, int posmax);

//Main Function:
int main()
{
	const int N = 8;
	int a[N] = { 44, 77, 33, 55, 66, 88, 11, 22 };
	showArray(a, N);
	for (int i = N; i >= 1; i--)
	{
		int posmax = findPosMax(a, i);// N will be cycling through the values of the array Changed N -> i
		cout << posmax << "  " << a[posmax] << endl;
		swap(a, i, posmax);//Swap the biggest with the current Changed N -> i
		showArray(a, N);//check for successful swap
	}
	//int posmax = findPosMax(a, N);// N will be cycling through the values of the array
	//cout << posmax << "  " << a[posmax] << endl;
	//swap(a, N, posmax);//Swap the biggest with the current
	//showArray(a, N);//check for successful swap
	return 0;
}

//User-Defined Functions:
void showArray(int a[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << a[i] << "  ";
	}
	cout << endl;
}

int findPosMax(int a[], int size)
{
	int posmax = 0;
	int maxValue = a[0];//Consider the 1st value of the array as the max
	for (int i = 1; i < size; i++)//Compares value in position 1 to position 0
	{
		if (a[i] > maxValue)
		{
			maxValue = a[i];
			posmax = i;
		}
	}
	return posmax;
}

void swap(int a[], int size, int posmax)
{
	int last = size - 1;//last element of the arrray
	int tmp = a[last];
	a[last] = a[posmax];
	a[posmax] = tmp;
}