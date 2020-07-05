#pragma once
#include <iostream>
using namespace std;

struct room
{
	char* rID = new char[4];
	unsigned int usableArea, numOfPeople;
	bool furnished, haveBreakfast;
};
typedef struct room ROOM;

istream& operator>>(istream& in, ROOM& r);
ostream& operator<<(ostream& out, ROOM& r);