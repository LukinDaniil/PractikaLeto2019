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
    vector<vector<int>> getFloorMap();
    FloorMap();
    void createFloorMap();
    int getWidth();
    int getHeight();
    int getIJFloorMap(int i, int j);
};

#endif // FLOORMAP_H
