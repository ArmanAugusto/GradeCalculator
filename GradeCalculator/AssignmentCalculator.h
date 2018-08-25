/*
Author:		Arman Augusto

Assignment Calculator header file.	
Calculates cumulative assignment percentage of course grade.
*/

#ifndef ASSIGNMENTCALCULATOR_H
#define ASSIGNMENTCALCULATOR_H

#include <vector>
#include <iostream>

using namespace std;

class AssignmentCalculator
{
private:
	double studentAssignmentPoints;
	double totalAssignmentPoints;
	double assignmentPercentageWeight;
	double studentTotalAssignmentScore;
	double totalPossibleAssignmentScore;
	vector<double> studentAssignmentScore;
	vector<double> totalPossibleAssignment;
	double totalStudentAssignmentPoints;
	double totalPossibleAssignmentPoints;
	double assignmentPercentageOfGrade;
	double assignment;
public:
	AssignmentCalculator();
	~AssignmentCalculator();
	void assignmentCalculation();
	void setAssignmentPercentageOfGrade(double);
	double getAssignmentPercentageOfGrade();
};

#endif /* ASSIGNMENTCALCULATOR_H */