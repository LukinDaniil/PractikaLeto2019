#ifndef FLOORMAP_H
#define FLOORMAP_H
#include "vector"
using namespace std;

class floorMap
{
private:
    int width;
    int height;
    vector<vector<int>> floor;
public:
    floorMap();
    int getWidth();
    int getHeight();
};

#endif // FLOORMAP_H
