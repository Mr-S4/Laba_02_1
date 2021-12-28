#pragma once
#include <iostream>
#include <string>
#include "List.h"
#include "STUDENT.h"
using namespace std;
class GROUP
{
private:
	float averageMark;
	int grupNum;
	List<string> subjects;
	List<STUDENT> students;
	

public:

	GROUP();
	GROUP(int grupNum, List<string> subjects);

	void addStudents(STUDENT S);
	void countAverageMark();
	float getAverageMark();
	void print();
	void findFour();

	bool operator< (GROUP const& other) const;
};

