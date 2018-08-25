/*
Author:		Arman Augusto

Layout of the direction the program takes dependent on the user input.
*/

#include "stdafx.h"
#include "GradeCalculatorProcess.h"

GradeCalculatorProcess::GradeCalculatorProcess()
{
	firstName = " ";
	lastName = " ";
	studentID = 0;
	assignmentPercent = 0.0;
	examPercent = 0.0;
	projectPercent = 0.0;
	midtermPercent = 0.0;
	finalPercent = 0.0;
	participationPercent = 0.0;
	otherPercent = 0.0;
	totalPercentageGrade = 0.0;
	totalPercentage = 0.0;
	grade = " ";

	gradeCalculation();
}

GradeCalculatorProcess::~GradeCalculatorProcess()
{

}

void GradeCalculatorProcess::gradeCalculation()
{
	studentInfo();
	gradeCalculatorMenu();
	menuActions();
}

/*
gathers student info from user
prompts user for
first name, last name, and student identification number
*/
void GradeCalculatorProcess::studentInfo()
{
	cout << "Enter student's first name:\t\t\t\t";
	getline(cin, firstName);

	cout << "Enter student's last name:\t\t\t\t";
	getline(cin, lastName);

	cout << "Enter student's student identification number:\t\t";
	cin >> studentID;
	cout << "\n" << endl;

	printStudentInfo(firstName, lastName, studentID);
}

/*
printStudentInfo function prints student information
first and last name, and student identification number
*/
void GradeCalculatorProcess::printStudentInfo(string fName, string lName, int stID)
{
	firstName = fName;
	lastName = lName;
	studentID = stID;

	cout << "**********Student Info**********\n" << endl;
	cout << "Name:\t\t" << firstName << " " << lastName << endl;
	cout << "Student ID:\t" << setw(9) << setfill('0') << studentID << endl;
}

/*
gradeCalculatorMenu function displays the initial options
for the user toward calculating specific scores
*/
void GradeCalculatorProcess::gradeCalculatorMenu()
{
	cout << endl;
	cout << "********Grade Calculator********\n" << endl;

	cout << "1 : Assignments" << endl;
	cout << "2 : Exams" << endl;
	cout << "3 : Projects" << endl;
	cout << "4 : Midterm Exams" << endl;
	cout << "5 : Final Exams" << endl;
	cout << "6 : Particiption" << endl;
	cout << "7 : Other" << endl;
	cout << "8 : Calculate Final Grade" << endl;

	cout << endl;
}

/*
Function that responds with the corresponding function
dependent on the user's choice
*/
void GradeCalculatorProcess::menuActions()
{
	AssignmentCalculator AC;
	ExamCalculator EC;
	ProjectCalculator PC;
	MidtermCalculator MC;
	FinalCalculator FC;
	ParticipationCalculator PartC;
	OtherCalculator OC;

	bool valid = false;

	while (!valid)
	{
		int choice = 0;

		cout << "Menu Option:\t";
		cin >> choice;

		switch (choice)
		{
		case 1: // go to assignment calculator function
			AC.assignmentCalculation();
			valid = true;
			assignmentPercent = AC.getAssignmentPercentageOfGrade();
			cout << "Percentage of final grade:\t" << assignmentPercent << endl;
			gradeCalculatorMenu();
			menuActions();
			break;
		case 2: // go to exam calculator function
			EC.examCalculation();
			valid = true;
			examPercent = EC.getExamPercentageOfGrade();
			cout << "Percentage of final grade:\t" << examPercent << endl;
			gradeCalculatorMenu();
			menuActions();
			break;
		case 3: // go to project calculator function
			PC.projectCalculation();
			valid = true;
			projectPercent = PC.getProjectPercentageOfGrade();
			cout << "Percentage of final grade:\t" << projectPercent << endl;
			gradeCalculatorMenu();
			menuActions();
			break;
		case 4: // go to midterm calculator function
			MC.midtermCalculation();
			valid = true;
			midtermPercent = MC.getMidtermPercentageOfGrade();
			cout << "Percentage of final grade:\t" << midtermPercent << endl;
			gradeCalculatorMenu();
			menuActions();
			break;
		case 5: // go to final calculator function
			FC.finalCalculation();
			valid = true;
			finalPercent = FC.getFinalPercentageOfGrade();
			cout << "Percentage of final grade:\t" << finalPercent << endl;
			gradeCalculatorMenu();
			menuActions();
			break;
		case 6: // go to participation calculator function
			PartC.participationCalculation();
			valid = true;
			participationPercent = PartC.getParticipationPercentageOfGrade();
			cout << "Percentage of final grade:\t" << participationPercent << endl;
			gradeCalculatorMenu();
			menuActions();
			break;
		case 7: // go to other calculator function
			OC.otherCalculation();
			valid = true;
			otherPercent = OC.getOtherPercentageOfGrade();
			cout << "Percentage of final grade:\t" << otherPercent << endl;
			gradeCalculatorMenu();
			menuActions();
			break;
		case 8: // calculate the total percentage grade
			totalGradeCalculation(assignmentPercent, examPercent, projectPercent,
				midtermPercent, finalPercent, participationPercent, otherPercent);

			valid = true;
			break;
		default:
			cout << "\n\n****Error: Invalid Option****\n\nPlease choose a valid option from the menu.\n\n" << endl;
			valid = false;
			break;
		}
	}
}

/*
Calculates total grade from user's input of scores and percentage weights.
*/
void GradeCalculatorProcess::totalGradeCalculation(double, double, double,
	double, double, double, double)
{
	cout << "\nCalculating Total Percentage Grade:\n" << endl;

	cout << "Assignments: " << assignmentPercent << " + "
		<< "Exams: " << examPercent << " + "
		<< "Projects: " << projectPercent << " + "
		<< "Midterm Exams: " << midtermPercent << "\n+ "
		<< "Final Exams: " << finalPercent << " + "
		<< "Participation: " << participationPercent << " + "
		<< "Other: " << otherPercent;

	totalPercentageGrade = assignmentPercent + examPercent +
		projectPercent + midtermPercent + finalPercent +
		participationPercent + otherPercent;

	cout << "\n\t= " << totalPercentageGrade << "\n" << endl;

	totalPercentage = totalPercentageGrade * 100;

	cout << "Total Percentage:\t" << totalPercentage << "%" << endl;

	letterGrade(totalPercentage);
}

/*
Interprets the final grade percentage into a letter grade.
*/
void GradeCalculatorProcess::letterGrade(double)
{
	if (totalPercentage <= 100.00 && totalPercentage >= 93.00)
		grade = "A";
	else if (totalPercentage <= 92.99 && totalPercentage >= 90.00)
		grade = "A-";
	else if (totalPercentage <= 89.99 && totalPercentage >= 87.00)
		grade = "B+";
	else if (totalPercentage <= 86.99 && totalPercentage >= 83.00)
		grade = "B";
	else if (totalPercentage <= 82.99 && totalPercentage >= 80.00)
		grade = "B-";
	else if (totalPercentage <= 79.99 && totalPercentage >= 77.00)
		grade = "C+";
	else if (totalPercentage <= 76.99 && totalPercentage >= 73.00)
		grade = "C";
	else if (totalPercentage <= 72.99 && totalPercentage >= 70.00)
		grade = "C-";
	else if (totalPercentage <= 69.99 && totalPercentage >= 67.00)
		grade = "D+";
	else if (totalPercentage <= 66.99 && totalPercentage >= 63.00)
		grade = "D";
	else if (totalPercentage <= 62.99 && totalPercentage >= 60.00)
		grade = "D-";
	else
		grade = "F";

	cout << "\nGrade:\t\t\t" << grade << "\n" << endl;
	grade.clear();
}