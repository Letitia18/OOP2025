#include "StudentComparisons.h"
int CompareByName(const Student& s1, const Student& s2) {
	if (s1.GetName() == s2.GetName()) {
		return 0;
	}
	return s1.GetName().compare(s2.GetName());
}

int CompareByMathGrade(const Student& s1, const Student& s2) {
	if (s1.GetMathGrade() == s2.GetMathGrade()) {
		return 0;
	}
	return s1.GetMathGrade() < s2.GetMathGrade() ? -1 : 1;
}

int CompareByEnglishGrade(const Student& s1, const Student& s2) {
	if (s1.GetEnglishGrade() == s2.GetEnglishGrade()) {
		return 0;
	}
	return s1.GetEnglishGrade() < s2.GetEnglishGrade() ? -1 : 1;
}

int CompareByHistoryGrade(const Student& s1, const Student& s2) {
	if (s1.GetHistoryGrade() == s2.GetHistoryGrade()) {
		return 0;
	}
	return s1.GetHistoryGrade() < s2.GetHistoryGrade() ? -1 : 1;
}

int CompareByAverageGrade(const Student& s1, const Student& s2) {
	if (s1.GetAverageGrade() == s2.GetAverageGrade()) {
		return 0;
	}
	return s1.GetAverageGrade() < s2.GetAverageGrade() ? -1 : 1;
}
