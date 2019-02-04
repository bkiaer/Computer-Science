#include <iostream>
#include <iomanip>
#include "circleCylinder.h"
using namespace std;

const double CUBIC_FOOT = 28.32;

int main()
{
  double * radius1;
  double *  paint;
  double *  height;
  double * shipping;
  int quantity;
  double  * shipcost;
  double  * paintcost; 
  cout <<"How many cylinders do you want to ship?" << endl;
    cin >> quantity; 
   shipcost = new double[quantity];
   paintcost = new double[quantity];
   radius1 = new double[quantity];
   paint = new double[quantity];
   height = new double[quantity];
   shipping = new double[quantity];
    cylinder**containers;
    containers = new cylinder*[quantity];

  for(int i = 0; i < quantity; i++)
    {
  cout <<"Input for cylinder no. "<< i+1 << endl; 
  cout <<"Enter the radius of the base of the cylinder and height (in feet)" << endl;
  cin >> radius1[i] >> height[i];

  while(!cin)
    {
      cin.clear();
      cin.ignore(100, '\n');
      cout << "Input for cylinder no. " << i+1 << endl; 
      cout << "Enter the radius of the base of the cylinder and height (in feet)" << endl;
      cin >> radius1[i]>> height[i];
  
      }


  cout << "Enter shipping cost per liter and paint cost per square foot" << endl;
  cin >> shipping[i] >> paint[i];

    while(!cin)
    { 
      cin.clear();
      cin.ignore(100, '\n');
      cout << "Enter shipping cost per liter and paint cost per square foot" << endl;
      cin >> shipping[i] >> paint[i];
      }
    cout <<" " << endl;
    }
  for(int j=0; j<quantity;j++)
    {
  
            containers[j] = new cylinder(radius1[j], height[j]);
            containers[j] -> volume();
      
	    cout << containers[j]->volume() << endl;
	    
	    paintcost[j] = containers[j]->area() * paint[j];
	    shipcost[j] = containers[j]->volume() * shipping[j]*CUBIC_FOOT;

        cout <<"Costs for cylinder no. " << j+1 << endl; 
  cout << fixed << setprecision(2);
  cout << left << setfill ('.')<< setw(30) <<"Price to ship container" << setfill(' ')<< "$"<< right << setw(10) << shipcost[j]<<endl;
  cout << left << setfill ('.') << setw(30) << "Price to paint container" << setfill(' ')<<  "$"   <<right << setw(10)<< paintcost[j] <<  endl;
  cout << left << setfill ('.') << setw(30) << "Total cost" << setfill(' ') << "$" << right << setw(10) <<  shipcost[j] + paintcost[j] << endl;
  cout << " " << endl;
    }
 
  delete [] shipcost;
  delete [] paintcost; 
   delete [] radius1;
  delete [] height;
   delete [] shipping;
  delete [] paint; 
  
  return 0;
}
