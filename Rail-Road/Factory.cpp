#include "Factory.h"
#include "Station.h"
using namespace std;

/*
	Unlike all other documents provided, you may modify this document slightly (but do not change its name)
*/
//=======================================================================================
/*
	createStation()

	Creates and returns an object whose class extends StationInterface.
	This should be an object of a class you have created.

	Example: If you made a class called "Station", you might say, "return new Station();".
*/
StationInterface* Factory::createStation()
{
	return new Station();
}
//=======================================================================================
