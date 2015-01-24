#ifndef world_h
#define world_h
#include <vector>
#include "object.h"

class coordinate
{
public:
    coordinate operator+(const coordinate) ;
    int x,y,z;
    coordinate();
    coordinate(int,int,int);
};

class world
{
public:
    object getObject(coordinate);
    object getObject(coordinate,coordinate);
    world(templateObjectList,int,int,int);
    
private:
    std::vector<std::vector<std::vector<object>>> map;
    int sizeX,sizeY,sizeZ;
};
#endif