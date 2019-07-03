#ifndef CABINET_H

#define CABINET_H

using namespace std;
#include "human.h"
class Cabinet
{

public:
    bool researched;
    int NumOfCabinet;
    int CountOfStudentPlace;
    PathOfWay TeachersPlace;
    vector<PathOfWay> TeachersWay;
    PathOfWay ExitOfCabinet;
    vector<vector<PathOfWay>> Ways;
    vector<bool> used;//used - хранит значение, говорящее о том, занято место ии нет
    Cabinet(int newNumOfCabinet, PathOfWay newExitOfCabinet);
};

#endif // CABINET_H
