#include "FlatTextDatabase.h"

int main()
{
	FlatTextDatabase* database = FlatTextDatabase::getInstance();

	database->releaseDatabase();
	return 0;
}