
/**
 * A histogram
 *
 * A histogram is the partitioning of a given space into cells, 
 * where each cell has a value associated with it which represents 
 * the number of objects in that cell.
 * 
 * Only the number of objects in a cell are represented in a histogram.  
 * A histogram in an imprecise representation of the original space.
 * It's a lossy compression algorithm.
 *
 * Assumptions:
 *  - Assume cells are contiguous sub-spaces.
 *  - Each object has a position.
 */

#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <cmath>

// Homework - Comment out the next three lines and
//            implement array and pair.  You only need
//            to implement enough so that this compiles
//            and you get the same result.
// #include <array> 
// using std::array;
// using std::pair;


template <class T1, class T2> struct pair;


template <typename ValueType, std::size_t N>
struct array {
  typedef ValueType value_type;
  typedef std::size_t size_type;

  typedef value_type* iterator;
  typedef value_type* pointer;
  typedef value_type& reference;
  typedef value_type* const_iterator;
  typedef value_type* const_pointer;
  typedef value_type& const_reference;
  typedef value_type _type[N];
  
  _type _elem; 

  const_pointer data() const
  { return const_cast<value_type*>(_elem);}

  const_iterator begin() const {
    return iterator(data());
  }

  iterator end() const {
    return iterator(data() + N);
  }

  constexpr size_type size() const {
    return N;
  }

  void fill(const value_type& x) {
    std::fill_n(begin(), size(), x);
  }

reference operator[](size_type n) {
    return const_cast<value_type&>(_elem[n]);
  }
};


template <typename X, size_t N, typename W = unsigned>
class histogram{
public:
  using axis_t = array<X,N+1>;
  using bin_t = array<W,N>;

  histogram(const axis_t& axis) : axis(axis){
    bins.fill(0);
  }
  
  size_t get_n() const { return n; }
  const axis_t& get_axis() const { return axis; }
  const bin_t& get_bins() const { return bins; }
  void fill(const X& value, const W& weight){
    size_t bin_index{0};
    for(auto leading_edge : axis){
      if(value < leading_edge){
	bins[bin_index-1] += weight;
	break;
      }
      bin_index++;
    }
  }
  
private:
  size_t n = N;
  axis_t axis;
  bin_t bins;
};


template <typename T, size_t N>
void print(const array<T,N>& a){
  for(auto v : a){
    std::cout<<v<<" ";
  }
  std::cout<<std::endl;
}

struct dom{
  unsigned string;
  unsigned om;
};

bool operator<(const dom& lhs, const dom& rhs){
  return (lhs.string < rhs.string || lhs.om < rhs.om);
}

int main(int argc, char** argv){

  using histogram_t = histogram<dom, 4>;  
  histogram_t::axis_t h_axis{dom{1,1}, dom{1,2}, dom{2,1}, dom{2,2}, dom{3,3}};    
  histogram_t h(h_axis);
  array<dom, 5> hits{dom{1,1}, dom{1,2}, dom{1,1}, dom{1,2}, dom{2,2}};
  for(auto hit : hits){
    h.fill(hit,1);
  }
  print(h.get_bins());
}

