#include <iostream>
#include <fstream>
#include "GROUP.h"
#include "List.h"
#include "STUDENT.h"
using namespace std;

void two() {
	ifstream inp("input.txt");

	while (inp.peek() != EOF) {
		string first;
		string second;
		inp >> first >> second;

		if (!first.empty() && !second.empty()) {
			cout << second << ' ' << first << ' ';
		}
		else {
			cout << first;
		}
	}
}

int main()
{
	List<GROUP> list;
	int menu = 1, num;
	while (true) {
		cout << "menu" << endl;
		cout << "1. Add Group" << endl;
		cout << "2. Add Student" << endl;
		cout << "3. Print All" << endl;
		cout << "4. Print Students with high marks" << endl;
		cout << "5. Delete Group" << endl;
		cout << "6. Delete Student" << endl;
		cout << "7. String stream task" << endl;
		cout << "0. Exit" << endl;
		cout << ">>> ";
		cin >> menu;

		while (menu < 0 || menu > 8 || cin.fail()) {
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Incorrect entered, retry" << endl;
			cin >> menu;
		}

		try {

			switch (menu) {
			case 1: {
				cout << "enter group num: ";
				cin >> num;
				List<string> S;
				S.push_back("матем");
				S.push_back("физика");
				S.push_back("инф");
				list.push_back(GROUP(num, S));
				break; }
			case 2: {
				cout << "choose group: ";
				cin >> num;
				if (num >= 0 && num < list.size())
				{
					string name;
					List<int8_t> S;
					int m;
					cout << "enter name: ";
					cin >> name;
					for (size_t i = 0; i < list[num].getstudentsam(); i++)
					{
						cout << "enter mark: ";
						cin >> m;
						S.push_back(m);
					}
					list[num].addStudents(STUDENT(name, S));
				}
				break; }
			case 3: {
				for (size_t i = 0; i < list.size(); i++)
					list[i].print();
				break; }
			case 4: {
				for (size_t i = 0; i < list.size(); i++)
					list[i].findFour();
				break; }
			case 5: {
				cout << "choose group: ";
				cin >> num;
				if (num >= 0 && num < list.size())
				{
					list.pop(num);
				}
				break; }
			case 6: {
				cout << "choose group: ";
				cin >> num;
				int m;
				if (num >= 0 && num < list.size())
				{
					cout << "enter student num: ";
					cin >> m;
					list[num].del(m);
				}
				break; }
			case 7: {
				two();
				break; }

			case 0: {
				return 0; }

			}
		}
		catch (int) {
			cout << "error" << endl;
			return 1;
		}
	}
}

/*
1. Стандартные потоки
Определить классы с именем STUDENT и GROUP. STUDENT содержит
следующие поля:
	● фамилия и инициалы;
	● успеваемость (массив из нескольких элементов).
Определить объединение объектов типа STUDENT в GROUP.
Классов GROUP может быть несколько, заранее число не известно,
определяется пользователем.
GROUP определяет такие параметры как: средний балл в группы,
предметы группы, номер группы и пр.
Перегрузить операции извлечения и вставки для объектов типа
STUDENT.
Определить полноценное меню для работы пользователя с программой.
Написать программу, выполняющую следующие действия:
	● Определить ввод с клавиатуры данных STUDENT в GROUP, записи
		должны быть упорядочены по возрастанию номера группы;
	● вывод на дисплей фамилий и номеров групп для всех студентов,
		включенных в массив, если средний балл студента больше 4.0;
	● если таких студентов нет, вывести соответствующее сообщение.
2. Файловые и строковые потоки
С использованием файловых и строковых потоков написать программу,
которая считывает текст из файла и выводит его на экран, меняя местами
каждые два соседних слова.
*/