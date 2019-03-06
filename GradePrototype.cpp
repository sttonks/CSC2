//Author:	Chris Orozco
//Goal:		Read in student's name and grade, calculate letter grade, and produces a summary report.

//Headers or Preprocessor Directives:
#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

//Prototypes:
void getData(string &studentName, double &studentGrade);
char calculateLetterGrade(double studentGrade);
void showResults(string studentName, double studentGrade, char letterGrade);

int main()
{
	string studentName;
	double studentGrade;
	char letterGrade;

	getData(studentName, studentGrade);
	letterGrade = calculateLetterGrade(studentGrade);
	showResults(studentName, studentGrade, letterGrade);

	return 0;
}

//user-defined methods:
void getData(string &studentName, double &studentGrade)//passing by reference, allowing this function access to read & write to the requested variables from the main
{
	cout << "\nEnter student name: ";
	getline(cin, studentName);
	cout << "\nEnter grade [0 - 100]: ";
	cin >> studentGrade;
}

char calculateLetterGrade(double studentGrade)
{
	if (studentGrade >= 75)
		return 'P';
	else
		return 'F';
}

void showResults(string studentName, double studentGrade, char letterGrade)
{
	cout << "\n Name: " << studentName
		<< " Grade: " << studentGrade
		<< " Letter: " << letterGrade
		<< endl;
}