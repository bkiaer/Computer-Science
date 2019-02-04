#include "circleCylinder.h"
#include <iostream>
#include <cmath>
using namespace std;
/*----------------------------------------------------
Default Constructor
PARAMETERS: default constructor, radius
POSTCONDITION: sets radius to 1 automatically
------------------------------------------------------*/

circle::circle() 
{
  radius = 1; 
  
}
/*-----------------------------------------------------
Constructor
PARAMETERS: double value named literal
POSTCONDITION: To set radius to the double value passed named literal. 
 ------------------------------------------------------*/
circle::circle(double literal)
{
  radius = literal; 
}
/*----------------------------------------------------
Area of a Circle Function
POSTCONDITION: Function is responsible to calculate and return 
the area of a circle. 
  ---------------------------------------------------*/ 
double circle::area() const
{
  double temp;
  temp = radius*radius;
  return temp*PI;
}

/*---------------------------------------------------
Constructor
POSTCONDITION: This constructor is responsible for initializing
height to equal 1. It also has to call the circle constructor to initialize
the radius as well because it is a private field in the circle class. 
  ----------------------------------------------------*/ 
cylinder::cylinder() : circle()
{
  height = 1; 
  
}
/*---------------------------------------------------
Default Constructor
PARAMETERS: Passes two double values literal and tall.
POSTCONDITION: This is the default constructor for Cylinder it will initialize
height to be equal to the passed value "tall" the circle default constructor 
also has to get called to initialize radius with the double "literal"
  ---------------------------------------------------*/
cylinder::cylinder(double literal, double tall) : circle(literal)

{
  height = tall;
    
}
/*----------------------------------------------------
Area Function
POSTCONDITION: The purpose of this function is to calculate the area of a 
cylinder. It will call circle's area function solve for the private field of 
circle called "radius". Then it will use that value to calculate the area.
  ------------------------------------------------------*/
double cylinder:: area() const
{
  double temp = circle::area();
  double temp1 = circle::area();
  temp1 = temp/PI;
  temp1 = sqrt(temp1);
  temp = 2*temp;
  return temp + (height*2*PI*temp1);
}
/*--------------------------------------------------------
Volume Function
POSTCONDITION: The purpose of this function is to calculate volume of a cylinder.
To do this it will call circle::area() function and that will return the area of a
circle and this function will multiply that value by height to main. 
--------------------------------------------------------*/
double cylinder:: volume() const
{
  return circle::area()*height;
}
