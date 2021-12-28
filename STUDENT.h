#pragma once
#include <string>
#include "List.h"
using namespace std;
class STUDENT
{
private:
	float averageMark;
	string name;
	List<int8_t> marks;

public:
	STUDENT(string name, List<int8_t> marks);

	float GetAverageMark();
	string GetName();
	List<int8_t> GetMarks();

};

