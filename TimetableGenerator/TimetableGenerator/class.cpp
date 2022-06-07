#include "course.h"
#include "slot.h"
#include "cell.h"
#include <iostream>
#include <string>
#pragma warning(disable:4996)
using namespace std;

void slot_loc(course temp, cell* loc)
{
	char day[4];
	char start_time[6];
	char end_time[6];

	strcpy(day,temp.getday());
	strcpy(start_time, temp.getstime());
	strcpy(end_time, temp.getetime());

	//cell loc;
	if (strcmp(day, "MON") == 0)
	{
		(*loc).column = 0;
	}
	else if (strcmp(day, "TUE") == 0)
	{
		(*loc).column = 1;
	}
	else if (strcmp(day, "WED") == 0)
	{
		(*loc).column = 2;
	}
	else if (strcmp(day, "THU") == 0)
	{
		(*loc).column = 3;
	}
	else if (strcmp(day, "FRI") == 0)
	{
		(*loc).column = 4;
	}
	
	int s_value;
	int e_value;
	s_value = (start_time[0] - '0') * 10 + (start_time[1] - '0');
	e_value = (end_time[0] - '0') * 10 + (end_time[1] - '0');

	int i, j;
	i = (s_value - 9) * 2;
	if (start_time[3] == '3') i += 1;

	j = (e_value - 9) * 2;
	if (end_time[3] == '3') j += 1;

	(*loc).start_row = i;
	(*loc).end_row = j - 1;

}

void course::getdata(int i)
{

	cout << "Enter the title of the class(" << i + 1 << "): ";
	getchar();	//ignore enter
	cin.getline(title, 20, '\n');

	cout << "Enter the day of the class(" << i + 1 << "): ";
	cin >> day;
	cout << "Enter the starting time of the class(xx:xx) (" << i + 1 << "): ";
	cin >> start_time;
	cout << "Enter the ending time of the class(xx:xx) (" << i + 1 << "): ";
	cin >> end_time;

	cout << "Enter the instructor's name of the class(" << i + 1 << "): ";
	getchar();	//ignore enter
	cin.getline(instructor, 30, '\n');
	
	cout << "Enter the classroom of the class(" << i + 1 << "): ";
	cin >> classroom;
}

char* course::getday()
{
	return this->day;
}

char* course::getstime()
{
	return this->start_time;
}

char* course::getetime()
{
	return this->end_time;
}

void course::display(int i)
{
	cout << i << ": " << title << " / " << instructor << " / " << classroom << "\n";
}

void slot::storedata(course info)
{
	//fill(0->1)
	flag = 1;

	strcpy(title, info.title);
	strcpy(classroom, info.classroom);
}

int course::dayvalid()
{
	if (strcmp(day, "MON")!=0 && strcmp(day, "TUE")!=0 && strcmp(day, "WED")!=0 && strcmp(day, "THU")!=0 && strcmp(day, "FRI")!=0) 
		return 1;
	else return 0;
}

int course::timevalid()
{
	if (strcmp(start_time, end_time) > 0) return 1;
	if (strcmp(start_time, "09:00") < 0) return 1;
	if (strcmp(end_time, "20:00") > 0) return 1;
	return 0;
}

void slot::display()
{
	cout << title << "(" << classroom << ")";
	int l = strlen(title) + strlen(classroom) + 2;
	for (int i = 0; i < 20 - l; i++) {
		cout << " ";
	}
}