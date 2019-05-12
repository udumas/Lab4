#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const	int LENGTH=100;
	 	



	void getData(int year[], string courseString[], int student[], int& size);

	int main(){

		int size = 0;
		int year[LENGTH];
		int student[LENGTH];
		string courseString[LENGTH];
		getData(year, courseString, student, size);

/**
 *precondition:  	size is equal to the number of elements 
 *				in the array minus 1
 *postcondition:	new element aded to all three arrays
 *
 * function: getData()
 * takes a series of values of the form
 * YEAR COURSE NUMBEROFSTUDENTS
 * and saves these values into three arrays 
 * YEAR[] COURSE[] AND STUDENTS[]
 * if the first value of a string of values is -1 
 * program stops inputing data.
 *
 */
	 
	 	void getData(int year[], string courseString[], int student[], int& size){
		

		cout << "Enter the year (four digit for eg. 2002,\n";
		cout << "Course Identifier (formatted as \"Dept\"\"number\" eg. CSC101\n";
		cout << "and number of Students on one line.\n";

		cin >> year[size] >> courseString[size] >> student[size];

		size++;


	}

	int TotalPerCourse(int year[], string courseString[], int student[] int& size, String courseName){
		boolean alreadyCounted=false;
		int count = 0;
		for(int i=0;i<size;;i++){
			if(courseName==courseString[i])
				count++;	
			}
		}
	}

