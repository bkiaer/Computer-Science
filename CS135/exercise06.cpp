#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main ()
{
  cout <<"Brian Kiaer LecSec#1010 LabSec#1005 Exercise #6" << endl;
  cout <<fixed<<setprecision(12);
  int terms;
  double pi;
  double final_terms=0.0;
  cout << left <<"Enter the number of terms to use in the estimates" << endl;
  cin >> terms;
  if (terms<=0)
    cout << left << terms << " is not a valid input for this program" << endl;
  else 
    {
      cout << left<<setw(17) <<"Number of Terms: "<< right << setw(23) << terms << endl;
  for(int i=0;terms>i;i++)
      final_terms = final_terms + (pow(-1,i+1.0)) / (2*i+1);
  pi=-4*final_terms;
  cout << left << setw(21)<< "Approximation of pi: "<< right <<setw(19) << pi << endl;
    }
       return 0;
       }
