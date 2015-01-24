#include "world.h"
#include "object.h"
#include <vector>
#include <algorithm>
coordinate::coordinate()
{
    x=0,y=0,z=0;
}
coordinate::coordinate(int ax, int ay, int az)
{
    x=ax,y=ay,z=az;
}
coordinate coordinate::operator+(const coordinate right)
{
    coordinate temp;
    temp.x= this->x + right.x;
    temp.y= this->y + right.y;
    temp.z= this->z + right.z;
    return temp;
}
//z is up and down
//add paralell fill
world::world(templateObjectList temp, int tempX=1,int tempY=1, int tempZ=1)
{
    sizeX=tempX;
    sizeY=tempY;
    sizeZ=tempZ;
    std::vector<object> list;
    list.resize(tempZ);
    std::vector<std::vector<object>> listOList;
    listOList.resize(tempY);
    std::vector<std::vector<std::vector<object>>> listOListOList;
    listOListOList.resize(tempX);
    std::fill(list.begin(),list.end(), temp.getTemplate(0));
    std::fill(listOList.begin(),listOList.end(), list);
    std::fill(listOListOList.begin(),listOListOList.end(), listOList);
    map=listOListOList;
}
 object world::getObject(coordinate temp)
 {
     while(temp.x>sizeX)
         temp.x-=sizeX;
     while(temp.x<0)
         temp.x+=sizeX;
     
     while(temp.y>sizeY)
         temp.y-=sizeY;
     while(temp.y<0)
         temp.y+=sizeY;

     while(temp.z>sizeZ)
         temp.z-=sizeZ;
     while(temp.z<0)
         temp.z+=sizeZ;

     return map[temp.x][temp.y][temp.z];
 }

 object world::getObject(coordinate temp, coordinate temp2)
 {
     temp = temp + temp2;
     while(temp.x>sizeX)
         temp.x-=sizeX;
     while(temp.x<0)
         temp.x+=sizeX;
     
     while(temp.y>sizeY)
         temp.y-=sizeY;
     while(temp.y<0)
         temp.y+=sizeY;

     while(temp.z>sizeZ)
         temp.z-=sizeZ;
     while(temp.z<0)
         temp.z+=sizeZ;

     return map[temp.x][temp.y][temp.z];
 }