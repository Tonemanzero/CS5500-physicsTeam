#ifndef Reduce_h
#define Reduce_h

class Reduce abstract
{
public:
  template<typename T>
  static T Summation(const T* first, const T* last, T identity);
};


//TODO: in world, create function to populate 1d array with all values we wish to sum
  //together from a region
  #endif