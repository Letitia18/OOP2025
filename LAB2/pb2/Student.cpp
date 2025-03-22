#include "Student.h"

Student::Student() : name(" "), MathGrade(0), EnglishGrade(0), HistoryGrade(0) {}

Student::Student(const std::string& name, float MathGrade, float EnglishGrade, float HistoryGrade)
	: name(name), MathGrade(MathGrade), EnglishGrade(EnglishGrade), HistoryGrade(HistoryGrade) {}

void Student::SetName(const std::string& name) {
	this->name = name;
}

void Student::SetMathGrade(float grade) {
	if (grade >= 1 && grade <= 10) {
		this->MathGrade = grade;
	}
}

void Student::SetEnglishGrade(float grade) {
	if (grade >= 1 && grade <= 10) {
		this->EnglishGrade = grade;
	}
}

void Student::SetHistoryGrade(float grade) {
	if (grade >= 1 && grade <= 10) {
		this->HistoryGrade = grade;
	}
}

std::string Student::GetName() const {
	return name;
}

float Student::GetMathGrade() const {
	return MathGrade;
}

float Student::GetEnglishGrade() const {
	return EnglishGrade;
}

float Student::GetHistoryGrade() const {
	return HistoryGrade;
}

float Student::GetAverageGrade() const {
	return (MathGrade + EnglishGrade + HistoryGrade) / 3;
}
