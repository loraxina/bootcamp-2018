#include <vector>

//This file includes the class position which is a vector
//that holds a position of an object

class position
{
 public:
  position( double& x , double& y , double& z );
  ~position();
  std::vector<double> pos;

 private:
  double x_;
  double y_;
  double z_;
};
