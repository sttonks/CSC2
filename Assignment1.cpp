// Assignment1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Author:	Chris Orozco
//Goal:     Calculate hours worked from a .txt file with logged hours and dates.
//			Calculate the monthly sub-totals as well.

//Preprocessors Directives:
#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//Prototypes:
void totalHoursWorked(int totalHours, string &month, int &num);
void monthlyHours(string &month, int &num);

//Main Function:
int main()
{
	ifstream inFile("C:\\Users\\coroz\\Desktop\\myloghours.txt");
	if (!inFile)
	{
		cout << "The file: myloghours.txt was unable to be opened." << endl;
		return 0;
	}
	int num;
	string month;
	int totalHours = 0;
	int count = 0;
	totalHoursWorked(totalHours, month, num);
	monthlyHours(month, num);
	inFile.close();
	return 0;
}

//User-defined Methods:

void totalHoursWorked(int totalHours, string &month, int &num)
{
	month = "";
	totalHours = 0;
	int count = 0;
	int monthlyHours = 0;
	ifstream inFile("C:\\Users\\coroz\\Desktop\\myloghours.txt");
	if (!inFile)
	{
		cout << "The file: myloghours.txt was unable to be opened." << endl;
	}
	while (inFile >> month >> num)
	{
		totalHours = num + totalHours;
	}
	cout << "Total hours:     " << totalHours << endl;
	inFile.close();
}

void monthlyHours(string &month, int &num)
{
	int sum;
	int num2;
	//num2 = stoi(month);
	ifstream inFile("C:\\Users\\coroz\\Desktop\\myloghours.txt");
	if (!inFile)
	{
		cout << "The file: myloghours.txt was unable to be opened." << endl;
	}
	while (inFile >> month >> num)
	{
		string month2 = month.substr(0, 3);
		while (inFile >> month2 >> num2)
		{
			if (month.substr(0,3) == month2.substr(0,3))
			{
				sum = num + num2;
				num += num2;
			}
			else if (month.substr(0,3) != month2.substr(0,3))
			{
				cout << month.substr(0,3) << "  " << sum << endl;
				sum = 0;
				num = num2;
				month = month2;
			}
		}
		cout << month.substr(0, 3) << "  " << sum << endl;
	}
	inFile.close();
}
//These were my notes for configuring the return data, prior to your help in office hours, Thanks!
/*int num2 = stoi(month2);*/
	/*	if (month2 == "Dec")
		{
			count++;
			if (count == 2)
			{
				cout << month2 << "  " << sum << endl;
				count = 0;
				sum = 0;
			}
		}*/
		/*for (int i = 1; month2 <= month; i++)
		{
			i;
			if (month.substr(0,3) == month2)
			{
				sum = sum + num;
			}
			else if (month != month2)
			{
				cout << month2 << "  " << sum << endl;
			}
		}*/