#include "unit_vector.h"
#include <cmath>
#include <vector>

unit_vector::unit_vector( double x , double y , double z)
  : x_(x) , y_(y) , z_(z)
{
  magnitude = sqrt(x_*x_ + y_*y_ + z_*z_) ;
  x_component = x_ / magnitude;
  y_component = y_ / magnitude;
  z_component = z_ / magnitude;
  unit.push_back(x_component);
  unit.push_back(y_component);
  unit.push_back(z_component);
}

unit_vector::~unit_vector(){}

    
