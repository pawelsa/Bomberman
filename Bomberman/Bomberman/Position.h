#pragma once
class Position
{
public:
	Position();
	Position(int x, int y);

	~Position();
	int X;
	int Y;

	int operator==(Position right);

private:

	
};

