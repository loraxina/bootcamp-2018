#include "position.h"
#include <vector>

position::position( double x , double y , double z)
  : x_(x) , y_(y) , z_(z)
{
  pos.push_back(x_);
  pos.push_back(y_);
  pos.push_back(z_);
}

position::~position(){}

