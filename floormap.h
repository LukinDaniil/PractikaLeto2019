#ifndef FLOORMAP_H
#define FLOORMAP_H
#include "vector"
#include "QTextStream"
#include "enums.h"
using namespace std;

class FloorMap
{
private:
    int width;
    int height;
    //vector<vector<int>> floor;
    int ** floor;
    vector<vector<int>> floorForTheWay;
    const int BLOCK_WIDTH = 10;
    QString pathToFile;
public:
    FloorMap();
    FloorMap(int newWidth, int newHeight, QString newPath);
    int** getFloorMap();
    vector<vector<int>> getFloorForTheWay();
    void updateFloorMap();
    int getWidth();
    int getHeight();
    int getIJFloorMap(int i, int j);
    QString getPathToFile();
};

#endif // FLOORMAP_H
