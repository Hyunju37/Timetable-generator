#include <iostream>
#include <string>
#include "course.h"
#include "slot.h"
#include "cell.h"
using namespace std;

int num;

course* arr;
slot table[22][5];

int overlap(slot table[][5], cell loc);

//main 함수 최대한 간소화
int main()
{
	cout << "Enter the number of courses: ";
	cin >> num;

	// Allocate array(size num)
	arr = new course[num];
	
	//exception handling(allocation faild)

	course temp;

	cell loc;
	cell* ploc;
	ploc = &loc;

	//Input
	for (int i = 0; i < num; i++)
	{
		temp.getdata(i);
		slot_loc(temp, ploc);
		if (overlap(table, loc)) {
			i--;
			cout << "Overlapping on timetable. Try again\n";
			continue;
		}
		arr[i] = temp;

	}
	//test
	for (int i = 0; i < num; i++) {
		arr[i].display(i);
	}
}

using namespace std;
int overlap(slot table[][5], cell loc)
{
	//int ov = 0;
	int j = loc.column;
	for (int i = loc.start_row; i <= loc.end_row; i++)
	{
		if (table[i][j].flag)
		{
			return -1;
		}
	}
	return 0;
}