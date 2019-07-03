#include "cabinet.h"

Cabinet::Cabinet(int newNumOfCabinet, PathOfWay newExitOfCabinet)
{
    NumOfCabinet = newNumOfCabinet;
    ExitOfCabinet = newExitOfCabinet;
}

void Cabinet::pushDesk(PathOfWay newDesk)
{
    desks.push_back(newDesk);
    used.push_back(false);
}

PathOfWay::PathOfWay()
{
    X = 0;
    Y = 0;
}
PathOfWay::PathOfWay(int NewX, int NewY)
{
    X = NewX;
    Y = NewY;
}

void Cabinet::pushTeachersPlace(PathOfWay newTeachersPlace)
{
    TeachersPlace = newTeachersPlace;
}
