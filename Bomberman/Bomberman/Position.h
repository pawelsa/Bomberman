#pragma once
class Position
{
public:
	Position();
	Position(int x, int y);

	~Position();
	int X;
	int Y;

	bool operator==(Position &right);
	

private:

	
};

