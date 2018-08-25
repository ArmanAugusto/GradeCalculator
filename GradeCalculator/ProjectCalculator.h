/*
Author:		Arman Augusto

Project Calculator header file.
Calculates cumulative project grade percentage of course grade.
*/

#ifndef PROJECTCALCULATOR_H
#define PROJECTCALCULATOR_H

#include <vector>
#include <iostream>

using namespace std;

class ProjectCalculator
{
private:
	double studentProjectPoints;
	double totalProjectPoints;
	double projectPercentageWeight;
	double studentTotalProjectScore;
	double totalPossibleProjectScore;
	vector<double> studentProjectScore;
	vector<double> totalPossibleProject;
	double totalStudentProjectPoints;
	double totalPossibleProjectPoints;
	double projectPercentageOfGrade;
	double project;
public:
	ProjectCalculator();
	~ProjectCalculator();
	void projectCalculation();
	void setProjectPercentageOfGrade(double);
	double getProjectPercentageOfGrade();
};

#endif /* PROJECTCALCULATOR_H */