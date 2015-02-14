#ifndef World_h
#define World_h
#include <vector>
#include "object.h"

// thread unsafe
class Coordinate
{
public:
  Coordinate& operator+=(const Coordinate&);
  const Coordinate operator+(const Coordinate&) const;
  Coordinate& operator-=(const Coordinate&);
  const Coordinate operator-(const Coordinate&) const;
  int x, y, z;
  Coordinate(int = 0, int = 0, int = 0);
};

// thread unsafe
class World
{
public:
  Object getObject(Coordinate, Coordinate) const;
  Object getObject(int, int, int, int, int, int) const;
  World(int, int, int);
  Coordinate getSize() const;
  int getSizeX() const;
  int getSizeY() const;
  int getSizeZ() const;
  //Array for count of materials by elevation

  //2dArray for count of materials by x, y

  //Int of total material count in a region
  int countTemplateInRegion(int, int, int, int, int, int, int) const;

private:
  int* checkForTemplateInRegion(int xStart, int xEnd, int yStart, int yEnd, int zStart, int zEnd, int templateId);
  std::vector<std::vector<std::vector<Object>>> map;
  int sizeX, sizeY, sizeZ;
};
#endif
