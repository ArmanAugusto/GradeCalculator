/*
Author:		Arman Augusto

Grade Calculator Process header file.
*/

#ifndef GRADECALCULATORPROCESS_H
#define GRADECALCULATORPROCESS_H

#include <iostream>
#include <string>
#include <iomanip>

#include "AssignmentCalculator.h"
#include "ExamCalculator.h"
#include "ProjectCalculator.h"
#include "MidtermCalculator.h"
#include "FinalCalculator.h"
#include "ParticipationCalculator.h"
#include "OtherCalculator.h"

using namespace std;

class GradeCalculatorProcess
{
private:
	string firstName;
	string lastName;
	int studentID;
	double assignmentPercent;
	double examPercent;
	double projectPercent;
	double midtermPercent;
	double finalPercent;
	double participationPercent;
	double otherPercent;
	double totalPercentageGrade;
	double totalPercentage;
	string grade;

public:
	GradeCalculatorProcess();
	~GradeCalculatorProcess();
	void gradeCalculation();
	void studentInfo();
	void printStudentInfo(string fName, string lName,
		int stID);
	void gradeCalculatorMenu();
	void menuActions();
	void totalGradeCalculation(double, double, double, double, double, double, double);
	void letterGrade(double);
};

#endif /* GRADECALCULATORPROCESS_H */