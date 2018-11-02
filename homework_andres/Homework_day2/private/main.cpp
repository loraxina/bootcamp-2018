#include "position.h"
#include "unit_vector.h"
#include <iostream>

int main()
{
  unit_vector point1 = unit_vector(1,0,0);
  unit_vector point2 = unit_vector(1,1,1);
  unit_vector new_position = point1 + point2;
  
  std::cout <<
    "New xcomponent is: " <<
    new_position.unit[0] << std::endl <<
    "New ycomponent is: " <<
    new_position.unit[1] << std::endl <<
    "New ycomponent is: " <<
    new_position.unit[2] <<
    std::endl;
}
