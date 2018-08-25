/*
Author:		Arman Augusto

Calculates cumulative midterm exam percentage of course grade.
*/

#include "stdafx.h"
#include "MidtermCalculator.h"

MidtermCalculator::MidtermCalculator()
{
	studentMidtermPoints = 0.00;
	totalMidtermPoints = 0.00;
	midtermPercentageWeight = 0.00;
	studentTotalMidtermScore = 0.00;
	totalPossibleMidtermScore = 0.00;
	studentMidtermScore;
	totalPossibleMidterm;
	totalStudentMidtermPoints = 0.00;
	totalPossibleMidtermPoints = 0.00;
	midtermPercentageOfGrade = 0.0;
	midterm = 0.0;
}

MidtermCalculator::~MidtermCalculator()
{

}

void MidtermCalculator::midtermCalculation()
{
	do
	{
		cout << "\n****Midterm Cumulative Score Calculator****\n" << endl;
		cout << "**When you are finished entering scores, type 9999**\n" << endl;
		// prompt user for totalMidtermPoints
		cout << "Enter total possible points for midterm:    ";
		cin >> totalMidtermPoints;

		if (totalMidtermPoints != 9999) // sentinel = 9999
		{
			// add totalMidtermPoints to totalPossibleMidterm vector
			totalPossibleMidterm.push_back(totalMidtermPoints);

			// prompt user for studentMidtermPoints
			cout << "Enter student's score on the midterm:    ";
			cin >> studentMidtermPoints;
			studentMidtermScore.push_back(studentMidtermPoints);
		}
		else // totalMidtermPoints = 9999 (the sentinel)
		{
			// prompt user for percentage weight of final grade
			cout << "\nEnter the percentage weight (in decimal form)\n";
			cout << "\ttowards the final grade for midterm:    ";
			cin >> midtermPercentageWeight;

			// get studentMidtermScore cumulative total
			for (int i = 0; i < studentMidtermScore.size(); i++)
			{
				totalStudentMidtermPoints += studentMidtermScore[i];
			}

			cout << "\nTotal points earned:\t\t" << totalStudentMidtermPoints << "\n" << endl;

			// get totalPossibleMidterm cumulative total
			for (int i = 0; i < totalPossibleMidterm.size(); i++)
			{
				totalPossibleMidtermPoints += totalPossibleMidterm[i];
			}

			cout << "Total points possible:\t\t" << totalPossibleMidtermPoints << "\n" << endl;

			double midtermPercentage = totalStudentMidtermPoints / totalPossibleMidtermPoints;

			double percent = midtermPercentageWeight * 100;

			midtermPercentageOfGrade = midtermPercentage * midtermPercentageWeight;

			cout << "\n" << percent << "% is the weight for midterm" << endl;
			cout << "\ttoward the final grade." << endl;
			cout << endl;
		}
	} while (totalMidtermPoints != 9999);

	setMidtermPercentageOfGrade(midtermPercentageOfGrade);
}

void MidtermCalculator::setMidtermPercentageOfGrade(double midtermPercentageOfGrade)
{
	midterm = midtermPercentageOfGrade;
}

double MidtermCalculator::getMidtermPercentageOfGrade()
{
	return midterm;
}