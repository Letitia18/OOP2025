#pragma once
#include<string>
using namespace std;
class Student
{
private:
	string name;
	float MathGrade;
	float EnglishGrade;
	float HistoryGrade;
public:
	Student();
	Student(const string& name, float MathGrade, float EnglishGrade, float HistoryGrade);
	void SetName(const string& name);
	void SetMathGrade(float grade);
	void SetEnglishGrade(float grade);
	void SetHistoryGrade(float grade);
	string GetName() const;
	float GetMathGrade() const;
	float GetEnglishGrade() const;
	float GetHistoryGrade() const;
	float GetAverageGrade() const;
};
