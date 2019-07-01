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
    const int BLOCK_WIDTH = 10;
public:
    FloorMap();
    FloorMap(int newWidth, int newHeight);
    int** getFloorMap();
    void updateFloorMap();
    int getWidth();
    int getHeight();
    int getIJFloorMap(int i, int j);
};

#endif // FLOORMAP_H
