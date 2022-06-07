#ifndef CELL_H
#define	CELL_H

class cell
{
	friend class course;

public:
	int column;
	int start_row;
	int end_row;

	friend void slot_loc(course temp, cell* x);
};

#endif