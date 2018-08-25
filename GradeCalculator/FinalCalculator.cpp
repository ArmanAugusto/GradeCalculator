/*
Author:		Arman Augusto

Calculates cumulative final exam percentage of course grade.
*/

#include "stdafx.h"
#include "FinalCalculator.h"

FinalCalculator::FinalCalculator()
{
	studentFinalPoints = 0.00;
	totalFinalPoints = 0.00;
	finalPercentageWeight = 0.00;
	studentTotalFinalScore = 0.00;
	totalPossibleFinalScore = 0.00;
	studentFinalScore;
	totalPossibleFinal;
	totalStudentFinalPoints = 0.00;
	totalPossibleFinalPoints = 0.00;
	finalPercentageOfGrade = 0.0;
	final = 0.0;
}

FinalCalculator::~FinalCalculator()
{

}

void FinalCalculator::finalCalculation()
{
	do
	{
		cout << "\n****Final Exams Cumulative Score Calculator****\n" << endl;
		cout << "**When you are finished entering scores, type 9999**\n" << endl;
		// prompt user for totalFinalPoints
		cout << "Enter total possible points for final exam:    ";
		cin >> totalFinalPoints;

		if (totalFinalPoints != 9999) // sentinel = 9999
		{
			// add totalFinalPoints to totalPossibleFinal vector
			totalPossibleFinal.push_back(totalFinalPoints);

			// prompt user for studentFinalPoints
			cout << "Enter student's score on the final exam:    ";
			cin >> studentFinalPoints;
			studentFinalScore.push_back(studentFinalPoints);
		}
		else // totalFinalPoints = 9999 (the sentinel)
		{
			// prompt user for percentage weight of final grade
			cout << "\nEnter the percentage weight (in decimal form)\n";
			cout << "\ttowards the final grade for final exams:    ";
			cin >> finalPercentageWeight;

			// get studentMidtermScore cumulative total
			for (int i = 0; i < studentFinalScore.size(); i++)
			{
				totalStudentFinalPoints += studentFinalScore[i];
			}

			cout << "\nTotal points earned:\t\t" << totalStudentFinalPoints << "\n" << endl;

			// get totalPossibleFinal cumulative total
			for (int i = 0; i < totalPossibleFinal.size(); i++)
			{
				totalPossibleFinalPoints += totalPossibleFinal[i];
			}

			cout << "Total points possible:\t\t" << totalPossibleFinalPoints << "\n" << endl;

			double finalPercentage = totalStudentFinalPoints / totalPossibleFinalPoints;

			double percent = finalPercentageWeight * 100;

			finalPercentageOfGrade = finalPercentage * finalPercentageWeight;

			cout << "\n" << percent << "% is the weight for final exams" << endl;
			cout << "\ttoward the final grade." << endl;
			cout << endl;
		}
	} while (totalFinalPoints != 9999);

	setFinalPercentageOfGrade(finalPercentageOfGrade);
}

void FinalCalculator::setFinalPercentageOfGrade(double finalPercentageOfGrade)
{
	final = finalPercentageOfGrade;
}

double FinalCalculator::getFinalPercentageOfGrade()
{
	return final;
}