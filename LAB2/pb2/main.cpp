#include<iostream>
#include "Student.h"
#include "StudentComparisons.h"
using namespace std;
int main() {
	Student s1("Alexandra", 9, 8, 7);
	Student s2("Miruna", 8, 7, 6);
	Student s3("George", 4, 5, 6);
	cout << CompareByName(s1, s2) << endl;
	cout << CompareByMathGrade(s1, s2) << endl;
	cout << CompareByEnglishGrade(s1, s2) << endl;
	cout << CompareByHistoryGrade(s1, s2) << endl;
	cout << CompareByAverageGrade(s1, s2) << endl;
	cout << CompareByName(s1, s3) << endl;
	cout << CompareByMathGrade(s1, s3) << endl;
	cout << CompareByEnglishGrade(s1, s3) << endl;
	cout << CompareByHistoryGrade(s1, s3) << endl;
	cout << CompareByAverageGrade(s1, s3) << endl;
	return 0;
}
