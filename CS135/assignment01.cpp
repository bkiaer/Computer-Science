//Brian Kiaer, Lecture#1010, Assignment#01
//The expected input should be the estimated hourly rate of a user and the estimated labor hours they worked
//The expected output should be the calculated results from the users inputs to find their Gross Earnings, Taxes taken,money spent on clothes and school supplies
//The last expected outputs are the amount of money  saved and the amount left to spend
#include <iostream>
#include <iomanip> //setprecision manipulator
using namespace std;
const double TAXR = .1;                                     //tax rate on earnings                        
const double CLOTHES = .08;                                 //percentage of money spent on clothes        
const double SUPPLIES = .15;                                //percentage of money spent on supplies       
const double SAVE = .3;                                     //percentage of savings
int main ()
{
  double rate;                                                //hourly pay rate
  double estimated_hours;                                     //estimated labor hours worked
  cout << "Brian Kiaer LecSection#1010 LabSection#1005 Assignment#01" << endl;
  cout << "Please enter estimated hourly pay rate" << endl;
  cin >> rate;                                                //users hourly pay rate                 
  cout  << "Please enter estimated labor hours worked" << endl;
  cin >> estimated_hours;                                     //users estimated hours worked    
  double earnings = rate * estimated_hours;                   //gross earnings
  double taxes = earnings * TAXR;                             //taxes taken from earnings
  double earnings1 = earnings - taxes;                        //earnings after taxes taken out
  double clothes = earnings1 * CLOTHES;                       //amount of money spent on clothes
  double school = earnings1 * SUPPLIES;                       //amount of money spent on school supplies
  double earnings2 = earnings1 - school - clothes;            //earnings after clothes and school supplies
  double savings = earnings2 * SAVE;                          //amount of money put into savings
  double leftover = earnings2 - savings;                      //leftover money after spent money
  cout << fixed << setprecision(2);
  cout << "Pay Rate: $" << rate << endl;
  cout << "Estimated Hours Worked: " << estimated_hours << endl;
  cout << "Gross Earnings: $" << earnings << endl; 
  cout << "Taxes: $" << taxes << endl;
  cout << "Amount for Clothes: $" << clothes << endl;
  cout << "Amount for school supplies: $" << school << endl; 
  cout << "Amount Saved: $" << savings << endl;
  cout << "Amount Left to Spend: $" << leftover << endl;
  return 0;
}
