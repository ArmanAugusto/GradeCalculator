/*
Author:		Arman Augusto

Calculates cumulative participation grade percentage of course grade.
*/

#include "stdafx.h"
#include "ParticipationCalculator.h"

ParticipationCalculator::ParticipationCalculator()
{
	studentParticipationPoints = 0.00;
	totalParticipationPoints = 0.00;
	participationPercentageWeight = 0.00;
	studentTotalParticipationScore = 0.00;
	totalPossibleParticipationScore = 0.00;
	studentParticipationScore;
	totalPossibleParticipation;
	totalStudentParticipationPoints = 0.00;
	totalPossibleParticipationPoints = 0.00;
	participationPercentageOfGrade = 0.0;
	participation = 0.0;
}

ParticipationCalculator::~ParticipationCalculator()
{

}

void ParticipationCalculator::participationCalculation()
{
	do
	{
		cout << "\n****Participation Cumulative Score Calculator****\n" << endl;
		cout << "**When you are finished entering scores, type 9999**\n" << endl;
		// prompt user for totalParticipationPoints
		cout << "Enter total possible points for participation:    ";
		cin >> totalParticipationPoints;

		if (totalParticipationPoints != 9999) // sentinel = 9999
		{
			// add totalParticipationPoints to totalPossibleParticipation vector
			totalPossibleParticipation.push_back(totalParticipationPoints);

			// prompt user for studentParticipationPoints
			cout << "Enter student's score for participation:    ";
			cin >> studentParticipationPoints;
			studentParticipationScore.push_back(studentParticipationPoints);
		}
		else // totalParticipationPoints = 9999 (the sentinel)
		{
			// prompt user for percentage weight of final grade
			cout << "\nEnter the percentage weight (in decimal form)\n";
			cout << "\ttowards the final grade for participation:    ";
			cin >> participationPercentageWeight;

			// get studentParticipationScore cumulative total
			for (int i = 0; i < studentParticipationScore.size(); i++)
			{
				totalStudentParticipationPoints += studentParticipationScore[i];
			}

			cout << "\nTotal points earned:\t\t" << totalStudentParticipationPoints << "\n" << endl;

			// get totalPossibleParticipation cumulative total
			for (int i = 0; i < totalPossibleParticipation.size(); i++)
			{
				totalPossibleParticipationPoints += totalPossibleParticipation[i];
			}

			cout << "Total points possible:\t\t" <<totalPossibleParticipationPoints << "\n" << endl;

			double participationPercentage = totalStudentParticipationPoints / totalPossibleParticipationPoints;

			double percent = participationPercentageWeight * 100;

			participationPercentageOfGrade = participationPercentage * participationPercentageWeight;

			cout << "\n" << percent << "% is the weight for participation" << endl;
			cout << "\ttoward the final grade." << endl;
			cout << endl;
		}
	} while (totalParticipationPoints != 9999);

	setParticipationPercentageOfGrade(participationPercentageOfGrade);
}

void ParticipationCalculator::setParticipationPercentageOfGrade(double participationPercentageOfGrade)
{
	participation = participationPercentageOfGrade;
}

double ParticipationCalculator::getParticipationPercentageOfGrade()
{
	return participation;
}