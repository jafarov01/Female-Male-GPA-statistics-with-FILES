#include <iostream>
#include <iomanip>
#include <fstream>
#include <windows.h>
using namespace std;

/*
* SAMPLE INPUT FILE DATA FORMAT:
* m 70.0
* f 60.0
*/

//Function prototypes
void initializer(int& countF, int& countM, double& sumF,
	double& sumM, double& mAvg, double& fAvg, double& fGrade, double& mGrade);
void openFiles(ifstream& data, ofstream& output);
void avgGrades(double num_f, double num_m, double& sumFemale, double& sumMale,
	double& avgF, double& avgM);
void sumGrades(double FGrade, double MGrade, double& sumFemale, double& sumMale);
void printResults(ofstream& outData, int numFemale, int numMale,
	double sumGPAf, double sumGPAm, double avgGPAm, double avgGPAf);

int main()
{
	//Variable declerations 
	ifstream readData;
	ofstream writeData;
	char male_or_female;
	int count_female;
	int count_male;
	double sumFemaleGPA;
	double sumMaleGPA;
	double avgFemaleGPA;
	double avgMaleGPA;
	double gradeF;
	double gradeM;

	int option;

	//---------------------------------------------------------------------------
	//Initilizing variables to 0
	initializer(count_female, count_male, sumFemaleGPA, sumMaleGPA,
		avgMaleGPA, avgFemaleGPA, gradeF, gradeM);
	//----------------------------------------------------------------------------
	//File opening and checking if it opens
	openFiles(readData, writeData);
	//----------------------------------------------------------------------------
	//Reading data from the file
	while (readData >> male_or_female) //reading the first data in each line
	{
		if (male_or_female == 'f')     //checking if the first letter is f
		{
			count_female++;            //incrementing the number of females
			readData >> gradeF;        //reading the grade
			gradeM = 0;
		}
		else if (male_or_female == 'm')//checking if the first letter is m
		{
			count_male++;              //incrementing the number of males
			readData >> gradeM;        //reading the grade
			gradeF = 0;
		}
		sumGrades(gradeF, gradeM, sumFemaleGPA, sumMaleGPA);
	}

	//----------------------------------------------------------------------------
	//The function which calculates the avarage grades for females and males
	avgGrades(count_female, count_male, sumFemaleGPA,
		sumMaleGPA, avgFemaleGPA, avgMaleGPA);

	//----------------------------------------------------------------------------
	//The function which prints the relevant data on the output file
	printResults(writeData, count_female, count_male,
		sumFemaleGPA, sumMaleGPA, avgMaleGPA, avgFemaleGPA);
	//----------------------------------------------------------------------------
	//Open the files
	cout << ">>> The data has been worked and the result is on the output file.\n";
	cout << "\n\n|-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|\n\n";
	cout << ">>> Your message has been taken and encoded.\n\n";
	cout << "\t\t1- Open the input and ouput files\n\t\t2- EXIT\n";
	cout << "\n\n|-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|\n\n";
	cout << "Your option: ";
	cin >> option;
	switch (option)
	{
	case 1:
	{
		ShellExecuteW(NULL, L"open", L"C:\\Users\\Mexluq\\source\\repos\\Female Male GPA Comparison FILES\\readData.txt", L"", L"C:\\Users\\Mexluq\\source\\repos\\Female Male GPA Comparison FILES\\", SW_SHOW);
		ShellExecuteW(NULL, L"open", L"C:\\Users\\Mexluq\\source\\repos\\Female Male GPA Comparison FILES\\writeData.txt", L"", L"C:\\Users\\Mexluq\\source\\repos\\Female Male GPA Comparison FILES\\", SW_SHOW);
		break;
	}
	case 2:
		exit(0);
	default:
		break;
	}
	//closing files and exitting program
	readData.close();
	writeData.close();
	return 0;
}

void openFiles(ifstream& data, ofstream& output)
{
	data.open("readData.txt");
	output.open("writeData.txt");
	if (!data) {
		cerr << "Cannot open input file.\n";
	}
	output << fixed << showpoint
		<< setprecision(2);
}

void initializer(int& countF, int& countM, double& sumF,
	double& sumM, double& mAvg, double& fAvg, double& fGrade, double& mGrade)
{
	countF = 0;
	countM = 0;
	sumF = 0;
	sumM = 0;
	fGrade = 0;
	mGrade = 0;
	fAvg = 0;
	mAvg = 0;
}

void sumGrades(double FGrade, double MGrade, double& sumFemale, double& sumMale)
{
	sumFemale += FGrade;
	sumMale += MGrade;
}

void avgGrades(double num_f, double num_m, double& sumFemale, double& sumMale,
	double& avgF, double& avgM)
{
	avgF = sumFemale / num_f;
	avgM = sumMale / num_m;
}

void printResults(ofstream& outData, int numFemale, int numMale,
	double sumGPAf, double sumGPAm, double avgGPAm, double avgGPAf)
{
	outData << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n";
	outData << "\t\tFEMALE STUDENTS\n\n";
	outData << "NUMBER OF STUDENTS: " << numFemale << endl;
	outData << "       SUM OF GPAs: " << sumGPAf << endl;
	outData << "   Avarage of GPAs: " << avgGPAf << endl;
	outData << "\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n";
	outData << "\t\t\MALE STUDENTS\n\n";
	outData << "NUMBER OF STUDENTS: " << numMale << endl;
	outData << "       SUM OF GPAs: " << sumGPAm << endl;
	outData << "   Avarage of GPAs: " << avgGPAm << endl;
	outData << "\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n";
}