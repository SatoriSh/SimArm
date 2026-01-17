#include "church.h"
#include "../map.h"

Church::Church(int wN, int rN, int x, int y, Map& map)
	: Building(std::string("⛪"),  wN, rN, x, y, map)
{

}



Church::~Church()
{

}
