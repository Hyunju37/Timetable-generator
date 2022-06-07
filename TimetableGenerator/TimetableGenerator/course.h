#ifndef CLASS_H
#define CLASS_H
class cell;
class course
{
	friend class slot;
	friend class cell;

private:
	char title[10];	
	

	char day[4];
	char start_time[6];
	char end_time[6];
	
	
	char classroom[8];	
	char instructor[30];

public:
	void getdata(int i);
	void display(int i);
	
	char* getday();
	char* getstime();
	char* getetime();
	
	int dayvalid();
	int timevalid();

	friend void slot_loc(course temp, cell* loc);
};
#endif