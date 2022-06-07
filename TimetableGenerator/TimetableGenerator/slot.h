#ifndef SLOT_H
#define	SLOT_H

class slot
{
	friend class course;

	char title[10];
	char classroom[8];
public:
	int flag = 0;
	void storedata(course info);
	void display();
};
#endif