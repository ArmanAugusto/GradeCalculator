/*
Author:		Arman Augusto

Final Exam Calculator header file.
Calculates cumulative final exam percentage of course grade.
*/

#ifndef FINALCALCULATOR_H
#define FINALCALCULATOR_H

#include <vector>
#include <iostream>

using namespace std;

class FinalCalculator
{
private:
	double studentFinalPoints;
	double totalFinalPoints;
	double finalPercentageWeight;
	double studentTotalFinalScore;
	double totalPossibleFinalScore;
	vector<double> studentFinalScore;
	vector<double> totalPossibleFinal;
	double totalStudentFinalPoints;
	double totalPossibleFinalPoints;
	double finalPercentageOfGrade;
	double final;
public:
	FinalCalculator();
	~FinalCalculator();
	void finalCalculation();
	void setFinalPercentageOfGrade(double);
	double getFinalPercentageOfGrade();
};

#endif /* FINALCALCULATOR_H */