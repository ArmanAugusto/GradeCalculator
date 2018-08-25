/*
Author:		Arman Augusto

Exam Calculator header file.
Calculates cumulative exam percentage of course grade.
*/

#ifndef EXAMCALCULATOR_H
#define EXAMCALCULATOR_H

#include <vector>
#include <iostream>

using namespace std;

class ExamCalculator
{
private:
	double studentExamPoints;
	double totalExamPoints;
	double examPercentageWeight;
	double studentTotalExamScore;
	double totalPossibleExamScore;
	vector<double> studentExamScore;
	vector<double> totalPossibleExam;
	double totalStudentExamPoints;
	double totalPossibleExamPoints;
	double examPercentageOfGrade;
	double exam;
public:
	ExamCalculator();
	~ExamCalculator();
	void examCalculation();
	void setExamPercentageOfGrade(double);
	double getExamPercentageOfGrade();
};

#endif /* EXAMCALCULATOR_H */