#include "STUDENT.h"

STUDENT::STUDENT(string name, List<int8_t> marks) : averageMark(0.0), name(name), marks(marks)
{
	for (size_t i = 0; i < marks.size(); i++)
		averageMark += marks[i];
	averageMark /= marks.size();
}

float STUDENT::GetAverageMark()
{
	return averageMark;
}

string STUDENT::GetName()
{
	return name;
}

List<int8_t> STUDENT::GetMarks()
{
	return marks;
}
