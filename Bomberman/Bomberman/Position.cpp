#include "Position.h"



Position::Position()
{
}


Position::Position(int x, int y)
{
	this->X = x;
	this->Y = y;
}

Position::~Position()
{
}

int Position::operator==(Position right) {

	if (this->X == right.X && this->Y == right.Y) {

		return 1;
	}

	return 0;
}
