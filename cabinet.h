#ifndef CABINET_H
#define CABINET_H
#include <vector>
class PathOfWay
{
public:
    int X;
    int Y;
    PathOfWay();
    PathOfWay(int NewX, int NewY);
};
using namespace  std;
class Cabinet
{

public:
    int NumOfCabinet;
    int CountOfStudentPlace;
    PathOfWay TeachersPlace;
    vector<PathOfWay> TeachersWay;
    PathOfWay ExitOfCabinet;
    vector<vector<PathOfWay>> Ways;
    vector<bool> used;//used - хранит значение, говорящее о том, занято место ии нет
    vector<PathOfWay> desks;
    Cabinet(int newNumOfCabinet, PathOfWay newExitOfCabinet);
    void pushDesk(PathOfWay newDesk);
    void pushTeachersPlace(PathOfWay newTeachersPlace);
};

#endif // CABINET_H
