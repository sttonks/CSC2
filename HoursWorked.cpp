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
		//monthlyHours = monthlyHours + num;
		//string month2 = month.substr(0, 3);
		//if (month2 == "Dec")
		//{
		//	count++;
		//	if (count == 2)
		//	{
		//		cout << month2 << "  " << monthlyHours << endl;
		//		count = 0;
		//		monthlyHours = 0;
		//	}
		//}
		//else if (month2 == "Jan")
		//{
		//	count++;
		//	if (count == 3)
		//	{
		//		//monthlyHours = num;
		//		cout << month2 << "  " << monthlyHours << endl;
		//		count = 0;
		//		monthlyHours = 0;
		//	}
		//}
		//else if (month2 == "Feb")
		//{
		//	count++;
		//	if (count == 2)
		//	{
		//		//monthlyHours = num;
		//		cout << month2 << "  " << monthlyHours << endl;
		//		count = 0;
		//		monthlyHours = 0;
		//	}
		//}
		///*for (num; i < count; i++)
		//{
		//	int num2 = 0;
		//	if (month2 == "Dec" && num > 0)
		//	{
		//		num = num + num2;
		//		cout << num;
		//	}
		//}*/
		/*if (month2 != "Dec")
		{
			cout << month2 << "  " << monthlyHours;
		}*/
		//cout << month2 << "  " << num << endl;
	}
	cout << "Total hours:     " << totalHours << endl;
	inFile.close();
}

void monthlyHours(string &month, int &num)
{
	month = "";
	int count = 0;
	int monthlyHours = 0;
	ifstream inFile("C:\\Users\\coroz\\Desktop\\myloghours.txt");
	if (!inFile)
	{
		cout << "The file: myloghours.txt was unable to be opened." << endl;
	}
	while (inFile >> month >> num)
	{
		monthlyHours = monthlyHours + num;
		string month2 = month.substr(0, 3);
		if (month2 == "Dec")
		{
			count++;
			if (count == 2)
			{
				cout << month2 << "  " << monthlyHours << endl;
				count = 0;
				monthlyHours = 0;
			}
		}
		else if (month2 == "Jan")
		{
			count++;
			if (count == 3)
			{
				//monthlyHours = num;
				cout << month2 << "  " << monthlyHours << endl;
				count = 0;
				monthlyHours = 0;
			}
		}
		else if (month2 == "Feb")
		{
			count++;
			if (count == 2)
			{
				//monthlyHours = num;
				cout << month2 << "  " << monthlyHours << endl;
				count = 0;
				monthlyHours = 0;
			}
		}
		/*for (num; i < count; i++)
		{
			int num2 = 0;
			if (month2 == "Dec" && num > 0)
			{
				num = num + num2;
				cout << num;
			}
		}*/
		/*if (month2 != "Dec")
		{
			cout << month2 << "  " << monthlyHours;
		}*/
		//cout << month2 << "  " << num << endl;
	}
	inFile.close();
}