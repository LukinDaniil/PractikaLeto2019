#ifndef FLOORMAP_H
#define FLOORMAP_H
#include "vector"
#include "QTextStream"
#include "enums.h"
#include "cabinet.h"
using namespace std;

class FloorMap
{
private:
    int width;
    int height;
    int ** floor;
    vector<vector<int>> floorForTheWay;
    const int BLOCK_WIDTH = 10;
    QString pathToFile;
    vector<Cabinet> cabinets;
public:
    FloorMap();
    FloorMap(int newWidth, int newHeight, QString newPath);
    int** getFloorMap();
    vector<vector<int>> getFloorForTheWay();
    void updateFloorMap();
    int getWidth();
    int getHeight();
    int getIJFloorMap(int i, int j);
    int getAmountOfCabinets();
    QString getPathToFile();
    PathOfWay getCoordinatesOfCabinet(int numberOfCabinet);
    Cabinet* getICabinet(int i);
    void pushDeskIntoICabinet(int i, PathOfWay newDesk);
    int getAmountOfDesksInTheICabinet(int i);
    PathOfWay getCoordinatesOfTheDeskInTheICabinet(int numberOfTheDesk, int i);
    void pushNewStudentWayInTheICabinet(int i, vector<PathOfWay> newWay);
    PathOfWay getCoordinatesOfTheTeachersPlaceInTheICabinet(int i);
    void pushNewTeachersWayInTheICabinet(int i, vector<PathOfWay> newWay);
    void pushTeachersPlaceIntoICabinet(int i, PathOfWay newTeachersPlace);
    vector<PathOfWay> getDesksOfICabinet(int i);
    vector<Cabinet> getAllCabinets();
};

#endif // FLOORMAP_H
