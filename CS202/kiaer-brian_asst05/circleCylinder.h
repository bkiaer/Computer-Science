#include <iostream>
using namespace std;

class circle
{
 public: 
  circle ();
  circle (double);
  double area () const;
 protected:
  const static double PI=3.14;
 private: 
  double radius;
};

class cylinder : circle 
{
 public: 
  cylinder();
  cylinder(double, double); 
  double area() const;
  double volume() const;
 private: 
  double height;
};

