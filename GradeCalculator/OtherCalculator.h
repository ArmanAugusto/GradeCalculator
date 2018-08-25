/*
Author:		Arman Augusto

Other Calculator header file.
Calculates cumulative 'other' percentage of course grade.
*/

#ifndef OTHERCALCULATOR_H
#define OTHERCALCULATOR_H

#include <vector>
#include <iostream>
#include <string>

using namespace std;

class OtherCalculator
{
private:
	double studentOtherPoints;
	double totalOtherPoints;
	double otherPercentageWeight;
	double studentTotalOtherScore;
	double totalPossibleOtherScore;
	vector<double> studentOtherScore;
	vector<double> totalPossibleOther;
	double totalStudentOtherPoints;
	double totalPossibleOtherPoints;
	double otherPercentageOfGrade;
	double other;
	string categoryName;
public:
	OtherCalculator();
	~OtherCalculator();
	void otherCalculation();
	void setOtherPercentageOfGrade(double);
	double getOtherPercentageOfGrade();
};

#endif /* OTHERCALCULATOR_H */