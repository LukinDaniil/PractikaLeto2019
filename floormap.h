#ifndef FLOORMAP_H
#define FLOORMAP_H
#include "vector"
using namespace std;

class FloorMap
{
private:
    int width;
    int height;
    vector<vector<int>> floor;
public:
    void createFloorMap();
    FloorMap(int newWidth, int newHeight);
    int getWidth();
    int getHeight();
    int getIJFloorMap(int i, int j);
};

#endif // FLOORMAP_H
