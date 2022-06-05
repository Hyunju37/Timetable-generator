#ifndef CLASS_H
#define CLASS_H
class cell;
class course
{
	friend class slot;
	friend class cell;

private:
	char title[30];	//displayed
	
	//timeslot info
	char day[4];
	char start_time[6];
	char end_time[6];
	
	//additional info
	char classroom[10];	//displayed
	char instructor[30];

public:
	void getdata(int i);
	void display(int i);
	
	char* getday();
	char* getstime();
	char* getetime();
	
	friend void slot_loc(course temp, cell* loc);
};
#endif