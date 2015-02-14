#include<functional>
#include<numeric>
#include "tbb/blocked_range.h"
#include "tbb/parallel_reduce.h"
#include "Reduce.h"

//Template sum function found at:
//https://www.threadingbuildingblocks.org/docs/help/tbb_userguide/Design_Patterns/Reduction.htm
//IMPORTANT: Do not use for types that are expensive to construct or are not totally associative (like floats)
template<typename T> 
T Reduce::Summation( const T* first, const T* last, T identity ) {
   return tbb::parallel_reduce(
       // Index range for reduction
       tbb::blocked_range<const T*>(first,last),
       // Identity element
       identity,
       // Reduce a subrange and partial sum
       [&]( tbb::blocked_range<const T*> r, T partial_sum )->float {
           return std::accumulate( r.begin(), r.end(), partial_sum );
       },
       // Reduce two partial sums
       std::plus<T>()
   );
}