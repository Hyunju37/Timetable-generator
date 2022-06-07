#include <iostream>
#include <string>
#include "course.h"
#include "slot.h"
#include "cell.h"
using namespace std;

int num;

course* arr = NULL;
slot table[22][5];

int overlap(slot table[][5], cell loc);

int main()
{
	cout << "Enter the number of courses: ";
	cin >> num;

	// Allocate array(size num)
	try {
		arr = new course[num];
		if (arr == NULL) throw 1;
	}
	catch (int x)
	{
		cout << "allocation faild";
		return 0;
	}

	course temp;

	cell loc;
	cell* ploc;
	ploc = &loc;

	//Input
	for (int i = 0; i < num; i++)
	{
		try {
			temp.getdata(i);
			if (temp.dayvalid()) {
				throw 'x';
			}
			if (temp.timevalid()) {
				throw 1;
			}
			slot_loc(temp, ploc);
			if (overlap(table, loc)) {
				i--;
				cout << "Overlapping on timetable. Try again\n";
				continue;
			}
			arr[i] = temp;
			for (int j = loc.start_row; j <= loc.end_row; j++) {
				table[j][loc.column].storedata(temp);
			}
		}
		catch (...) {
			i--;
			cout << "Wrong day/time input. Try again\n";
			continue;
		}
		
	}
	//test
	/*
	for (int i = 0; i < num; i++) {
		arr[i].display(i);
	}
	*/
	
	//timetable displayed
	cout << "\n\n========================================================================================================================\n\n";
	cout << "  \tMON                 TUE                 WED                 TUE                 FRI\n";
	int cnt = 9;
	for (int i = 0; i < 22; i++) {
		if (i % 2 == 0) {	//min(00)
			if (cnt < 10) {
				cout << "0" << cnt++ << "\t";
			}
			else cout << cnt++ << "\t";
		}
		else cout << "  \t";	//min(30)
		for (int j = 0; j < 5; j++) {
			if (table[i][j].flag == 1) {
				table[i][j].display();
			}
			else {
				for (int i = 0; i < 20; i++) {
					cout << " ";
				}
			}
		}
		cout << "\n";
	}
	delete[] arr;
}

using namespace std;

int overlap(slot table[][5], cell loc)
{
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