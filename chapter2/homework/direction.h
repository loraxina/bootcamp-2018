#ifndef CHAPTER2_DIRECTION_H
#define CHAPTER2_DIRECTION_H

#include <initializer_list>
#include <iostream>
#include <cmath>

/* Class properties:
   1. Should primarily act as a container for 3 position variables, currently typed double (or template as "Real"), constrained to length 1
   2. Should obey the "rule of 6": default constructor is declared, so remaining 5 should be specified
   3. Should have sensible mathematical operations and features:
    a) No multiplication, just rescaling
    b) Equality should be complete (x1==x2 && y1==y2 && z1==z2)
    c) Inequality should be !equality
    g) Math operation by operators not function calls where applicable
    h) Scalar length should be defined "double abs()"
    i) Output string should be obvious "(x,y,z)"
    j) Should interface sensibly with unit vector (scalar dot product)
   4. Should probably be mutable unless declared otherwise (i.e. as a "const position"). Therefore should have get and set functionality or equivalent.
   X. A thought occured that position and unit direction classes might benefit from inheriting from a new base class of vector3.
*/

namespace chapter2 {

  class direction
  {
   public:

    //RULE OF 6 - mainly defaults, all functionality makes sense
    direction() : x(0.0), y(0.0), z(1.0) {}
    direction(double x, double y, double z) : x(x), y(y), z(z)
    {
      double len = this->abs();
      this->x = x/len;
      this->y = y/len;
      this->z = z/len;
    } // define full constructor _with scaling_
    
    ~direction() = default; //default destructor: easy to release private variables
    direction(const direction&) = default; //default copy constructor
    direction(direction&&) = default; //default move constructor
    direction& operator=(const direction&) = default; //default copy assignment
    direction& operator=(direction&&) = default; //default move assignment

    position operator-() { return position(-this->x, -this->y, -this->z); } //negative

    //getters and setters for private variables, though the variables _could_ be public? Or could use references to x, y, z.
    const double get_x() const {return x;}; //const to satisfy ostream
    const double get_y() const {return y;};
    const double get_z() const {return z;}; 
    //no setters, could cause conflict with length
    
    double abs() {return std::sqrt(x*x + y*y + z*z);}; //or something smarter using dot?
    double dot(const direction& d) {return this->x * d.x + this->y * d.y + this->z * d.z;};
    //double dot(const position& p) {return this->x * p.x + this->y * p.y + this->z * p.z;};

    
   private:
    double x, y, z;
  
  };

  std::ostream& operator<<(std::ostream& os, const direction& d)
  {
    return os << "(" << d.get_x() << "," << d.get_y() << "," << d.get_z() << ")" ;
  }

}
    
#endif //CHAPTER2_DIRECTION_H
