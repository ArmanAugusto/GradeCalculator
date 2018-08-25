/*
Author:		Arman Augusto

Calculates cumulative assignment percentage of course grade.
*/

#include "stdafx.h"
#include "AssignmentCalculator.h"

AssignmentCalculator::AssignmentCalculator()
{
	studentAssignmentPoints = 0.00;
	totalAssignmentPoints = 0.00;
	assignmentPercentageWeight = 0.00;
	studentTotalAssignmentScore = 0.00;
	totalPossibleAssignmentScore = 0.00;
	studentAssignmentScore;
	totalPossibleAssignment;
	totalStudentAssignmentPoints = 0.00;
	totalPossibleAssignmentPoints = 0.00;
	assignmentPercentageOfGrade = 0.0;
	assignment = 0.0;
}

AssignmentCalculator::~AssignmentCalculator()
{

}

void AssignmentCalculator::assignmentCalculation()
{
	do
	{
		cout << "\n****Assignment Cumulative Score Calculator****\n" << endl;
		cout << "**When you are finished entering scores, type 9999**\n" << endl;
		// prompt user for totalAssignmentPoints
		cout << "Enter total possible points for assignment\n";
		cout << "\tIf it is an extra credit assignment, enter 0:    ";
		cin >> totalAssignmentPoints;

		if (totalAssignmentPoints != 9999) // sentinel = 9999
		{
			// add totalAssignmentPoints to totalPossibleAssignment vector
			totalPossibleAssignment.push_back(totalAssignmentPoints);

			// prompt user for studentAssignmentPoints
			cout << "Enter student's score on the assignment:    ";
			cin >> studentAssignmentPoints;
			studentAssignmentScore.push_back(studentAssignmentPoints);
		}
		else // totalAssignmentPoints = 9999 (the sentinel)
		{
			// prompt user for percentage weight of final grade
			cout << "\nEnter the percentage weight (in decimal form)\n";
			cout << "\ttowards the final grade for assignments:    ";
			cin >> assignmentPercentageWeight;

			// get studentAssignmentScore cumulative total
			for (int i = 0; i < studentAssignmentScore.size(); i++)
			{
				totalStudentAssignmentPoints += studentAssignmentScore[i];
			}

			cout << "\nTotal points earned:\t\t" << totalStudentAssignmentPoints << "\n" << endl;

			// get totalPossibleAssignment cumulative total
			for (int i = 0; i < totalPossibleAssignment.size(); i++)
			{
				totalPossibleAssignmentPoints += totalPossibleAssignment[i];
			}

			cout << "Total points possible:\t\t" << totalPossibleAssignmentPoints << "\n" << endl;

			double assignmentPercentage = totalStudentAssignmentPoints / totalPossibleAssignmentPoints;
		
			double percent = assignmentPercentageWeight * 100;

			assignmentPercentageOfGrade = assignmentPercentage * assignmentPercentageWeight;

			cout << "\n" << percent << "% is the weight for homework assignments" << endl;
			cout << "\ttoward the final grade." << endl;
			cout << endl;
		}
	} while (totalAssignmentPoints != 9999);

	setAssignmentPercentageOfGrade(assignmentPercentageOfGrade);
}

void AssignmentCalculator::setAssignmentPercentageOfGrade(double assignmentPercentageOfGrade)
{
	assignment = assignmentPercentageOfGrade;
}

double AssignmentCalculator::getAssignmentPercentageOfGrade()
{
	return assignment;
}