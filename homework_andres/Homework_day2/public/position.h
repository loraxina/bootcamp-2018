#include <vector>

//This file includes the class position which is a vector
//that holds a position of an object

class position
{
 public:
  position( double x , double y , double z );
  ~position();
  std::vector<double> pos;

  double operator* ( position& vector1 ) {
    double result = 0;
    for( int i = 0 ; i < 3 ; i++){
      result += this->pos[i] * vector1.pos[i];
    }
    return result;
  }
  position operator+ ( position& vector1 ){
    position result = position(0,0,0);
    double x_component = this->pos[0] + vector1.pos[0];
    double y_component = this->pos[1] + vector1.pos[1];
    double z_component = this->pos[2] + vector1.pos[2];
    result.pos[0] = x_component;
    result.pos[1] = y_component;
    result.pos[2] = z_component;
    return result;
  }

  
 private:
  double x_;
  double y_;
  double z_;
};
