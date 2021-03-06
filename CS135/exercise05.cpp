#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
const double PI = 3.141592653589; //value of Pi 
int main()
{
  cout << "Brian Kiaer LecSec#1010 LabSec#1005 Exercise #5" << endl;
  char shape; //variable that holds the character of each shape
  double radius; //radius for the sphere
  double length; //length for the rectangle
  double width; // width for the rectangle
  double diameter; // diameter for the circle
  cout << fixed << setprecision(8);
  cout << "Please enter a shape (R, C, S)" << endl;
  cin >> shape; 
  if (shape == 'R')
    {
     cout << "What is the length of the Rectangle?" << endl;
     cin >> length;
     cout << "What is the width of the Rectangle?" << endl; 
     cin>> width;
     cout << "Shape: Rectangle"<< endl;
     cout << "Length: " << length << endl;
     cout << "Width: " << width<< endl;
     cout << "Perimeter of Rectangle: "<< 2*(length+width)<< endl;
    }
  else 
    if (shape == 'C')
      {
	cout << "What is the diameter length of the Circle?" << endl;
        cin>> diameter;
	cout << "Shape: Circle" << endl;
	cout << "Diameter: " << diameter << endl;
	cout << "Circumference: " << 2*PI*(diameter/2) << endl;
      }
    else 
      if (shape == 'S')
	{
	  cout << "What is the radius of the Sphere?" << endl;
	  cin>> radius; 
	  cout << "Shape: Sphere" << endl;
	  cout << "Radius: " << radius << endl;
	  cout << "Volume: " << double (4*PI*(pow(radius,3)))/3<< endl;
	}
return 0;
}
 

 
