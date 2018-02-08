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

bool Position::operator==(Position &right) {

	if (this->X == right.X && this->Y == right.Y) {

		return true;
	}

	return false;
}
