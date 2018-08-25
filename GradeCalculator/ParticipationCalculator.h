/*
Author:		Arman Augusto

Participation Grade Calculator header file.
Calculates cumulative participation grade percentage of course grade.
*/

#ifndef PARTICIPATIONCALCULATOR_H
#define PARTICIPATIONCALCULATOR_H

#include <vector>
#include <iostream>

using namespace std;

class ParticipationCalculator
{
private:
	double studentParticipationPoints;
	double totalParticipationPoints;
	double participationPercentageWeight;
	double studentTotalParticipationScore;
	double totalPossibleParticipationScore;
	vector<double> studentParticipationScore;
	vector<double> totalPossibleParticipation;
	double totalStudentParticipationPoints;
	double totalPossibleParticipationPoints;
	double participationPercentageOfGrade;
	double participation;
public:
	ParticipationCalculator();
	~ParticipationCalculator();
	void participationCalculation();
	void setParticipationPercentageOfGrade(double);
	double getParticipationPercentageOfGrade();
};

#endif /* PARTICIPATIONCALCULATOR_H */