#include<functional>
#include<numeric>
#include "tbb/blocked_range.h"
#include "tbb/parallel_reduce.h"
#include "Reduce.h"

//Template sum function
int Reduce::Summation(const int* first, const int* last, int identity ) {
  return tbb::parallel_reduce (
    // Index range for reduction
	tbb::blocked_range<const int*>(first,last),
	// Identity element
	identity,
	// Reduce a subrange and partial sum
	[&]( tbb::blocked_range<const int*> r, int partial_sum )->int {
	  return std::accumulate( r.begin(), r.end(), partial_sum );
	},
	// Reduce two partial sums
	std::plus<int>()
  );
};