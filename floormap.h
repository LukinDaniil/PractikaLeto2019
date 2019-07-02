#ifndef FLOORMAP_H
#define FLOORMAP_H
#include "vector"
#include "QTextStream"
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
public:
    FloorMap();
    FloorMap(int newWidth, int newHeight);
    int** getFloorMap();
    vector<vector<int>> getFloorForTheWay();
    void updateFloorMap();
    int getWidth();
    int getHeight();
    int getIJFloorMap(int i, int j);
};

#endif // FLOORMAP_H
