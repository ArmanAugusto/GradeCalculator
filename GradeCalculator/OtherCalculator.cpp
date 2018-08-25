/*
Author:		Arman Augusto

Calculates cumulative 'other' percentage of course grade.
*/

#include "stdafx.h"
#include "OtherCalculator.h"

OtherCalculator::OtherCalculator()
{
	studentOtherPoints = 0.00;
	totalOtherPoints = 0.00;
	otherPercentageWeight = 0.00;
	studentTotalOtherScore = 0.00;
	totalPossibleOtherScore = 0.00;
	studentOtherScore;
	totalPossibleOther;
	totalStudentOtherPoints = 0.00;
	totalPossibleOtherPoints = 0.00;
	otherPercentageOfGrade = 0.0;
	other = 0.0;
	categoryName = " ";
}

OtherCalculator::~OtherCalculator()
{

}

void OtherCalculator::otherCalculation()
{
	// prompt user for categoryName
	cout << "Enter the name for this category:    ";
	cin.ignore();
	getline(cin, categoryName);
	cout << endl;

	do
	{
		cout << "\n****" << categoryName << " Cumulative Score Calculator****\n" << endl;

		cout << "**When you are finished entering scores, type 9999**\n" << endl;
		// prompt user for totalOtherPoints
		cout << "Enter total possible points for " << categoryName << "\n";
		cout << "\tIf it is an extra credit " << categoryName << ", enter 0:    ";
		cin >> totalOtherPoints;

		if (totalOtherPoints != 9999) // sentinel = 9999
		{
			// add totalOtherPoints to totalPossibleOther vector
			totalPossibleOther.push_back(totalOtherPoints);

			// prompt user for studentOtherPoints
			cout << "Enter student's score on " << categoryName << ":    ";
			cin >> studentOtherPoints;
			studentOtherScore.push_back(studentOtherPoints);
		}
		else // totalOtherPoints = 9999 (the sentinel)
		{
			// prompt user for percentage weight of final grade
			cout << "\nEnter the percentage weight (in decimal form)\n";
			cout << "\ttowards the final grade for " << categoryName << ":    ";
			cin >> otherPercentageWeight;

			// get studentOtherScore cumulative total
			for (int i = 0; i < studentOtherScore.size(); i++)
			{
				totalStudentOtherPoints += studentOtherScore[i];
			}

			cout << "\nTotal points earned:\t\t" << totalStudentOtherPoints << "\n" << endl;

			// get totalPossibleOther cumulative total
			for (int i = 0; i < totalPossibleOther.size(); i++)
			{
				totalPossibleOtherPoints += totalPossibleOther[i];
			}

			cout << "Total points possible:\t\t" << totalPossibleOtherPoints << "\n" << endl;

			double otherPercentage = totalStudentOtherPoints / totalPossibleOtherPoints;

			double percent = otherPercentageWeight * 100;

			otherPercentageOfGrade = otherPercentage * otherPercentageWeight;

			cout << "\n" << percent << "% is the weight for " << categoryName << endl;
			cout << "\ttoward the final grade." << endl;
			cout << endl;
		}
	} while (totalOtherPoints != 9999);

	setOtherPercentageOfGrade(otherPercentageOfGrade);
}

void OtherCalculator::setOtherPercentageOfGrade(double otherPercentageOfGrade)
{
	other = otherPercentageOfGrade;
}

double OtherCalculator::getOtherPercentageOfGrade()
{
	return other;
}