#ifndef SLOT_H
#define	SLOT_H

class slot
{
	char title[30];
	char classroom[10];
public:
	int flag = 0;

	friend class course;
};
#endif