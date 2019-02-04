#include <iostream>
#include <iomanip>
using namespace std;
int main ()
{
  cout <<"Brian Kiaer, Lecture Section#1010, Lab Section#1005, Exercise#7" <<endl;
  int first_number =0;
  int second_number =1;
  int reset=0;
  int n;
  int data;
  int fibonacci_int=0;
  cin>>n;
  for (int i = 0; i<n;i++)
    { 
      cin>>data;
      while (data > fibonacci_int)
	{
	  fibonacci_int = first_number + second_number;
	  first_number = second_number;
	  second_number = fibonacci_int;
	}
      switch (data)
	{
	case fibonacci_int: 	cout << data << " is  a Fibonacci Number" << endl;
	  break;
	default: cout << data << " is not a Fibonacci Number" << endl;



    }



  return 0;
}





