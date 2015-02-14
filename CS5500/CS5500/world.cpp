#include "world.h"
#include "object.h"
#include "tbb/parallel_for.h"
#include "Reduce.h"
#include <vector>
#include <algorithm>
Coordinate::Coordinate(int ax, int ay, int az) : x(ax), y(ay), z(az)
{
}
Coordinate& Coordinate::operator+=(const Coordinate& right)
{
  this->x += right.x;
  this->y += right.y;
  this->z += right.z;
  return *this;
}
const Coordinate Coordinate::operator+(const Coordinate& right) const
{
  Coordinate temp = *this;
  temp += right;
  return temp;
}
Coordinate& Coordinate::operator-=(const Coordinate& right)
{
  this->x -= right.x;
  this->y -= right.y;
  this->z -= right.z;
  return *this;
}
const Coordinate Coordinate::operator-(const Coordinate& right) const
{
  Coordinate temp = *this;
  temp -= right;
  return temp;
}
// z is up and down
// add paralell fill
World::World(int X, int Y, int Z) : sizeX(X), sizeY(Y), sizeZ(Z)
{
  std::vector<Object> list;
  list.resize(sizeZ);
  std::vector<std::vector<Object>> listOList;
  listOList.resize(Y);
  std::vector<std::vector<std::vector<Object>>> listOListOList;
  listOListOList.resize(X);
  // std::fill(list.begin(),list.end(), temp.getTemplate(0));
  std::fill(listOList.begin(), listOList.end(), list);
  std::fill(listOListOList.begin(), listOListOList.end(), listOList);
  map = listOListOList;
}

// If out of bounds the object returned with have an id==-1
Object World::getObject(Coordinate position,
                        Coordinate offset = Coordinate(0, 0, 0)) const
{
  position += offset;

  // Wrapping X, Y
  position.x = (position.x % sizeX);
  position.y = (position.y % sizeY);
  // Out of bounds Z
  if (position.z >= sizeZ || position.z < 0)
  {
    return Object();
  }

  return map[position.x][position.y][position.z];
}

Object World::getObject(
  int posX, int posY, int posZ, int offX = 0, int offY = 0, int offZ = 0) const
{
  return getObject(Coordinate(posX, posY, posZ), Coordinate(offX, offY, offZ));
}

int World::getSizeX() const
{
  return sizeX;
}

int World::getSizeY() const
{
  return sizeY;
}

int World::getSizeZ() const
{
  return sizeZ;
}

Coordinate World::getSize() const
{
  return Coordinate(sizeX, sizeY, sizeZ);
}

int World::countTemplateInRegion(int xStart, int xEnd, int yStart, int yEnd, int zStart, int zEnd, int templateId)
{
  int* start = checkForTemplateInRegion(xStart, xEnd, yStart, yEnd, zStart, zEnd, templateId);
  int* end = start + (xEnd - xStart + 1)*(yEnd - yStart + 1)*(zEnd - zStart + 1);

  return Reduce::Summation<int> (start, end, 0);
}

//Coordinate ranges are inclusive
//Warning: requires start < end     but is currently not bounds checked
int* World::checkForTemplateInRegion(int xStart, int xEnd, int yStart, int yEnd, int zStart, int zEnd, int templateId)
{
  //TODO: bounds checking, etc.

  //Calculate size
  int sizeX = xEnd - xStart + 1;
  int sizeY = yEnd - yStart + 1;
  int sizeZ = zEnd - zStart + 1;
  int size = sizeX*sizeY*sizeZ;

  //Create new array
  int* result = new int[size];

  //Populate array
  tbb::parallel_for( tbb::blocked_range<size_t>(0, sizeof(int)*size),
    [&]( const tbb::blocked_range<size_t>& r) 
    {
      for(size_t i=r.begin(); i!=r.end(); i++)
      {
        if(getObject(xStart + (i % sizeX), yStart + ((i / sizeX) % sizeY), zStart + ((i / (sizeX*sizeY)) % sizeZ)).getId() == templateId) 
        {
          result[i] = 1;
        } 
        else 
        {
          result[i] = 0;
        }
      }
    }
  );
  

}