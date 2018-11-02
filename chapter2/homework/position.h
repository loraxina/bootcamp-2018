#ifndef CHAPTER2_POSITION_H
#define CHAPTER2_POSITION_H

#include <initializer_list>
#include <iostream>
#include <cmath>

/* Class properties:
   1. Should primarily act as a container for 3 position variables, currently typed double (or template as "Real"), spanning -inf to +inf
   2. Should obey the "rule of 6": default constructor is declared, so remaining 5 should be specified
   3. Should have sensible mathematical operations and features:
    a) Multiplication should be scalar
    b) Simple vector addition
    c) Simple vector subtraction
    d) No vector division
    e) Equality should be complete (x1==x2 && y1==y2 && z1==z2)
    f) Inequality should be !equality
    g) Math operation by operators not function calls where applicable
    h) Scalar length should be defined "double abs()"
    i) Output string should be obvious "(x,y,z)"
    j) Should interface sensibly with unit vector (scalar dot product)
   4. Should probably be mutable unless declared otherwise (i.e. as a "const position"). Therefore should have get and set functionality or equivalent.
   X. A thought occured that position and unit direction classes might benefit from inheriting from a new base class of vector3.
*/

namespace chapter2 {

  class position
  {
   public:

    //RULE OF 6 - mainly defaults, all functionality makes sense
    position() : x(0.0), y(0.0), z(0.0) {} // define default constructor - but do we want the default to be sane/crazy? or to delete?
                                           // Reminder - no default means difficulty with containers (e.g. std::vector<position>)
    position(double x, double y, double z) : x(x), y(y), z(z) {} // define full constructor
    ~position() = default; //default destructor: easy to release private variables
    position(const position&) = default; //default copy constructor
    position(position&&) = default; //default move constructor
    position& operator=(const position&) = default; //default copy assignment
    position& operator=(position&&) = default; //default move assignment

    //other operators - or should be free functions??

    position operator+(const position& p2) { return position(this->x + p2.x, this->y + p2.y, this->z + p2.z); } //addition - explicit "this" for no particular reason

    position operator-() { return position(-this->x, -this->y, -this->z); } //negative

    //position operator*(const double& s) {return position(this->x * s, this->y * s, this->z * s; } //multiplication, NOT WORKING??
    
    position operator-(position& p2) {return (*this)+ (-p2); } //simple subtraction, "this" dereference requires not const reference...?
    //position operator-(const position& p2) { return position(this->x - p2.x, this->y - p2.y, this->z - p2.z); } //other way to do it
    
    //getters and setters for private variables, though the variables _could_ be public? Or could use references to x, y, z.
    double get_x() const {return x;}; //const to satisfy ostream
    double get_y() const {return y;};
    double get_z() const {return z;}; 
    double set_x(double x) {this->x = x;}; //explicit "this" to avoid scoping issues
    double set_y(double y) {this->y = y;};
    double set_z(double z) {this->z = z;};
    
    double abs() {return std::sqrt(x*x + y*y + z*z);};
    //double dot(const direction& d) {return this->x * d.x + this->y * d.y + this->z * d.z;};
    double dot(const position& p) {return this->x * p.x + this->y * p.y + this->z * p.z;};
    
   private:
    double x, y, z;
  
  };

  std::ostream& operator<<(std::ostream& os, const position& p)
  {
    return os << "(" << p.get_x() << "," << p.get_y() << "," << p.get_z() << ")" ;
  }

}
    
#endif //CHAPTER2_POSITION_H
