/*
Author:		Arman Augusto

Calculates cumulative project grade percentage of course grade.
*/

#include "stdafx.h"
#include "ProjectCalculator.h"

ProjectCalculator::ProjectCalculator()
{
	studentProjectPoints = 0.00;
	totalProjectPoints = 0.00;
	projectPercentageWeight = 0.00;
	studentTotalProjectScore = 0.00;
	totalPossibleProjectScore = 0.00;
	studentProjectScore;
	totalPossibleProject;
	totalStudentProjectPoints = 0.00;
	totalPossibleProjectPoints = 0.00;
	projectPercentageOfGrade = 0.0;
	project = 0.0;
}

ProjectCalculator::~ProjectCalculator()
{

}

void ProjectCalculator::projectCalculation()
{
	do
	{
		cout << "\n****Project Cumulative Score Calculator****\n" << endl;
		cout << "**When you are finished entering scores, type 9999**\n" << endl;
		// prompt user for totalProjectPoints
		cout << "Enter total possible points for project\n";
		cout << "\tIf it is an extra credit project, enter 0:    ";
		cin >> totalProjectPoints;

		if (totalProjectPoints != 9999) // sentinel = 9999
		{
			// add totalProjectPoints to totalPossibleProject vector
			totalPossibleProject.push_back(totalProjectPoints);

			// prompt user for studentProjectPoints
			cout << "Enter student's score on the assignment:    ";
			cin >> studentProjectPoints;
			studentProjectScore.push_back(studentProjectPoints);
		}
		else // totalProjectPoints = 9999 (the sentinel)
		{
			// prompt user for percentage weight of final grade
			cout << "\nEnter the percentage weight (in decimal form)\n";
			cout << "\ttowards the final grade for projects:    ";
			cin >> projectPercentageWeight;

			// get studentProjectScore cumulative total
			for (int i = 0; i < studentProjectScore.size(); i++)
			{
				totalStudentProjectPoints += studentProjectScore[i];
			}

			cout << "\nTotal points earned:\t\t" << totalStudentProjectPoints << "\n" << endl;

			// get totalPossibleProject cumulative total
			for (int i = 0; i < totalPossibleProject.size(); i++)
			{
				totalPossibleProjectPoints += totalPossibleProject[i];
			}

			cout << "Total points possible:\t\t" << totalPossibleProjectPoints << "\n" << endl;

			double projectPercentage = totalStudentProjectPoints / totalPossibleProjectPoints;

			double percent = projectPercentageWeight * 100;

			projectPercentageOfGrade = projectPercentage * projectPercentageWeight;

			cout << "\n" << percent << "% is the weight for projects" << endl;
			cout << "\ttoward the final grade." << endl;
			cout << endl;
		}
	} while (totalProjectPoints != 9999);

	setProjectPercentageOfGrade(projectPercentageOfGrade);
}

void ProjectCalculator::setProjectPercentageOfGrade(double assignmentPercentageOfGrade)
{
	project = projectPercentageOfGrade;
}

double ProjectCalculator::getProjectPercentageOfGrade()
{
	return project;
}