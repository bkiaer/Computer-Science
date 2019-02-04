//Brian Kiaer, Lecture Section#1010, Assignment#02
//The expected input would be the user's expterior length of the box, exterior width of the box, exterior height of the box, the thickness of the sides and bottom, and how many boxes were to be ordered by the user. Also all measurements are expected to be inputed in inches. 
//The expected output would be the dimensions of the box given (ext. length, width, height, and thickness), how many boxes were ordered, the amount of plastic needed measuered by cubic feet, the cost of the plastic, the overhead and other cost, and the total cost of the plastic and overhead combined. 
#include <iostream>
#include <iomanip>
using namespace std;
const double PLAST_COST = 5.00;  //The cost of plastic per cubic foot
const double OTHER_COST = .25;   //The percentage of the cost of plastic used for overhead costs
const double CU_FT = 1728;       //The conversion factor 1728 cu in = 1 cu ft.
int main ()
{ 
  double exterior_length;             //The exterior length provided by the user in inches
  double exterior_width;              //The exterior width provided by the user in inches
  double exterior_height;             //The exterior height provided by the user in inches
  double thickness;                   //The thickness of the bottom and sides of the box in inches
  int  box_amount;                    //The amount of boxes that needs to be ordered by the user
  double bottom_side;                 //The dimensions for the bottom panel of the box
  double interior_length;             //The exterior length of the box subtracted by the thickness
  double interior_width;              //The exterior width of the box subtracted by the thickness
  double interior_height;             //The exterior height of the box substracted by the thickness
  double longer_sides;                //The volume of the larger panels of the box
  double shorter_sides;               //The volume of the smaller panels of the box
  double cubic_inches;                //The amount of plastic needed in cubic inches
  double plastic_needed;              //The amount of plastic needed converted into cubic feet
  double overhead_cost;               //The amount of overhead money needed
  double totalcost_plast;             //The total cost of the overhead money and the plastic combined
  cout << "Enter exterior length in inches: " <<endl;
  cin >> exterior_length;
  cout << "Enter exterior width in inches: " <<endl;
  cin >> exterior_width;
  cout << "Enter exterior height in inches: " <<endl;
  cin >> exterior_height;
  cout << "Enter thickness of sides and bottom in inches: " <<endl;
  cin >> thickness;
  cout << "How many boxes are to be ordered?" <<endl;
  cin >> box_amount;
  cout << "Brian Kiaer Lecture Section#1010 Assign#2" <<endl;
  cout << "JOB COST ESTIMATE" <<endl;
  cout << "Dimensions of Box" <<endl;
  cout << fixed << setprecision(4);
  cout << "Exterior Length:" << right << setw(10) << exterior_length << " in." <<endl; 
  cout << "Exterior Width: " << right << setw(10) << exterior_width << " in." <<endl;
  cout << "Exterior Height:" << right << setw(10) << exterior_height << " in." <<endl;
  cout << "Side/Bottom Thickness:" << right << setw(10) << thickness << " in." <<endl;
  cout << " " <<endl;
  cout << setprecision(0);
  cout << "Boxes Ordered:" << right << setw(10) << box_amount <<endl;
  cout << setprecision (4);
  bottom_side = exterior_length * exterior_width * thickness;
  interior_length = exterior_length - thickness;
  interior_width = exterior_width - thickness;
  interior_height = exterior_height - thickness;
  longer_sides = interior_length * interior_height * thickness *  2;
  shorter_sides = interior_width * interior_height * thickness *  2;
  cubic_inches =(longer_sides + shorter_sides + bottom_side) * box_amount;
  plastic_needed = cubic_inches / CU_FT;
  totalcost_plast = PLAST_COST * plastic_needed;
  overhead_cost = OTHER_COST * totalcost_plast;
  cout << "Plastic Needed:" << right << setw(10) << plastic_needed  << " cu. ft." <<endl;
  cout << "" <<endl;
  cout << setprecision(2);
  cout << "Cost of Plastic:     $" << totalcost_plast <<endl;
  cout << "Cost of Overhead:    $" << overhead_cost << endl;
  cout << "Total Cost:          $" << totalcost_plast + overhead_cost <<endl;
  return 0;

}
