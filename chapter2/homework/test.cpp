#include "position.h"
#include "direction.h"
#include <iostream>

/*
  This code is not as clever as it could be, but there are time constraints
  Main things to change: 
  1a. make compilation more library/project-like
  1b. includes separating out current headers into .h and .cpp files
  2. experiment more with (smart) pointers and their applicability
  3. experiment with inheritance
  4. experiment with templating
*/

using namespace chapter2;

double dot(const position& p, const direction& d)
{
  return ( p.get_x() * d.get_x() + p.get_y() * d.get_y() + p.get_z() * d.get_z() );
}

int main()
{
  position p1(1.0, 2.0, 3.0);
  position p2(2.0, -1.0, 5.0);
  std::cout << "p1: " << p1 << std::endl;
  std::cout << "p2: " << p2 << std::endl;
  std::cout << "p1 + p2: " << p1 + p2 << std::endl;
  std::cout << "p1 - p2: " << p1 - p2 << std::endl;
  std::cout << "p1.p2: " << p1.dot(p2) << std::endl;
  
  direction d1(1.0, 2.0, 3.0);
  direction d2(2.0, -1.0, 5.0);
  std::cout << "d1: " << d1 << std::endl;
  std::cout << "d2: " << d2 << std::endl;
  std::cout << "d1.d2: " << d1.dot(d2) << std::endl;

  std::cout << "p1.d2: " << dot(p1,d2) << std::endl;
  
  return 0;
}
