/*
Author:		Arman Augusto

Calculates cumulative exam percentage of course grade.
*/

#include "stdafx.h"
#include "ExamCalculator.h"

ExamCalculator::ExamCalculator()
{
	studentExamPoints = 0.00;
	totalExamPoints = 0.00;
	examPercentageWeight = 0.00;
	studentTotalExamScore = 0.00;
	totalPossibleExamScore = 0.00;
	studentExamScore;
	totalPossibleExam;
	totalStudentExamPoints = 0.00;
	totalPossibleExamPoints = 0.00;
	examPercentageOfGrade = 0.0;
	exam = 0.0;
}

ExamCalculator::~ExamCalculator()
{

}

void ExamCalculator::examCalculation()
{
	do
	{
		cout << "\n****Exam Cumulative Score Calculator****\n" << endl;
		cout << "**When you are finished entering scores, type 9999**\n" << endl;
		// prompt user for totalExamPoints
		cout << "Enter total possible points for exam:    ";
		cin >> totalExamPoints;

		if (totalExamPoints != 9999) // sentinel = 9999
		{
			// add totalExamPoints to totalPossibleExam vector
			totalPossibleExam.push_back(totalExamPoints);

			// prompt user for studentExamPoints
			cout << "Enter student's score on the exam:    ";
			cin >> studentExamPoints;
			studentExamScore.push_back(studentExamPoints);
		}
		else // totalExamPoints = 9999 (the sentinel)
		{
			// prompt user for percentage weight of final grade
			cout << "\nEnter the percentage weight (in decimal form)\n";
			cout << "\ttowards the final grade for exams:    ";
			cin >> examPercentageWeight;

			// get studentExamScore cumulative total
			for (int i = 0; i < studentExamScore.size(); i++)
			{
				totalStudentExamPoints += studentExamScore[i];
			}

			cout << "\nTotal points earned:\t\t" << totalStudentExamPoints << "\n" << endl;

			// get totalPossibleExam cumulative total
			for (int i = 0; i < totalPossibleExam.size(); i++)
			{
				totalPossibleExamPoints += totalPossibleExam[i];
			}

			cout << "Total points possible:\t\t" << totalPossibleExamPoints << "\n" << endl;

			double examPercentage = totalStudentExamPoints / totalPossibleExamPoints;
	
			double percent = examPercentageWeight * 100;

			examPercentageOfGrade = examPercentage * examPercentageWeight;

			cout << "\n" << percent << "% is the weight for exams" << endl;
			cout << "\ttoward the final grade." << endl;
			cout << endl;
		}
	} while (totalExamPoints != 9999);

	setExamPercentageOfGrade(examPercentageOfGrade);
}

void ExamCalculator::setExamPercentageOfGrade(double assignmentPercentageOfGrade)
{
	exam = assignmentPercentageOfGrade;
}

double ExamCalculator::getExamPercentageOfGrade()
{
	return exam;
}