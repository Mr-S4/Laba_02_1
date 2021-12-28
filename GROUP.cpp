#include "GROUP.h"

GROUP::GROUP() : averageMark(0.0), grupNum(0)
{
}

GROUP::GROUP(int grupNum, List<string> subjects) : averageMark(0.0), grupNum(grupNum), subjects(subjects)
{
}

void GROUP::addStudents(STUDENT S)
{
	students.push_back(S);
}

void GROUP::countAverageMark()
{
	for (size_t i = 0; i < students.size(); i++)
		averageMark += students[i].GetAverageMark();
}

float GROUP::getAverageMark()
{
	return averageMark;
}


void GROUP::print()
{
	cout << "Group " << grupNum << "\naverageMark: " << averageMark << "\nsubjects:\n";
	for (size_t i = 0; i < subjects.size(); i++)
		cout << "\t" << subjects[i] << endl;
	cout << "students:\n";
	for (size_t i = 0; i < students.size(); i++)
		cout << "\t" << students[i].GetName() << "\naverageMark: " << students[i].GetAverageMark() << "\n"
		<< "\t\t" << subjects[i] << " " << students[i].GetMarks() << "\n";
	cout << endl;
}

void GROUP::findFour()
{
	cout << "Group " << grupNum << "\naverageMark: " << averageMark << "\nsubjects:\n";
	for (size_t i = 0; i < subjects.size(); i++)
		cout << "\t" << subjects[i] << endl;
	cout << "students:\n";
	for (size_t i = 0; i < students.size(); i++)
		if (students[i].GetAverageMark() > 4.0)
			cout << "\t" << students[i].GetName() << "\naverageMark: " << students[i].GetAverageMark() << "\n"
			<< "\t\t" << subjects[i] << " " << students[i].GetMarks() << "\n";
	cout << endl;
}

bool GROUP::operator<(GROUP const& other) const
{
	return this->averageMark < other.averageMark;
}
