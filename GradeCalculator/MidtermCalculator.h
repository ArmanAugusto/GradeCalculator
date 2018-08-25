/*
Author:		Arman Augusto

Midterm Exam Calculator header file.
Calculates cumulative midterm exam percentage of course grade.
*/

#ifndef MIDTERMCALCULATOR_H
#define MIDTERMCALCULATOR_H

#include <vector>
#include <iostream>

using namespace std;

class MidtermCalculator
{
private:
	double studentMidtermPoints;
	double totalMidtermPoints;
	double midtermPercentageWeight;
	double studentTotalMidtermScore;
	double totalPossibleMidtermScore;
	vector<double> studentMidtermScore;
	vector<double> totalPossibleMidterm;
	double totalStudentMidtermPoints;
	double totalPossibleMidtermPoints;
	double midtermPercentageOfGrade;
	double midterm;
public:
	MidtermCalculator();
	~MidtermCalculator();
	void midtermCalculation();
	void setMidtermPercentageOfGrade(double);
	double getMidtermPercentageOfGrade();
};

#endif /* MIDTERMCALCULATOR_H */