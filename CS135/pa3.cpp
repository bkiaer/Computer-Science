//Brian Kiaer, Lecture #1010, Lab #1005, Assignment #3
//The expected input of the program is a data file that contains various integers ranging from, positive, negative integers, and zero. Each data value are either seperated by a blank or a linefeed. This data file will be read by the program using Linux Redirection, and the expected integer could be between -100,000,000 and 100,000,000. 
//The expected output of the program consists of displaying the ALL the numbers in the data file, the factors of that number, and if it is either a prime or composite number, if the integer is less than or equal to zero the output will be blank. Also, after the numbers are calculated and displayed by the while loop, the program will output how many primes, composites, and the category that was neither, which were the blank spaces, overall. The program will also display my name, class, and assignment, and columns for the calculated outputs for NUMBER, FACTORS, and CATEGORY.
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
  int data;          //Variable for the integers stored in a data file to be read. 
  int p_factors =0;  //Variable for the Amount of Prime Numbers that appear in the data file. 
  int c_factors =0;  //Variable for the Amount of Composite Numbers that appear in the data file. 
  int n_factors =0;  //Variable for the Amount of Numbers that were neither Composite nor Prime. 
  cout <<"Brian Kiaer, Lec Sec #1010, Lab Sec #1005, Programming Assignment#3" <<endl;
  cout << setw(12) << "NUMBER" << setw(12) << "FACTORS" << setw(13) << "CATEGORY" << endl; 
  cin>>data;
 while (cin)
    {
      int count=0;   //Variable to count how many factors are in a integer
      for (int i =1;i<=data;i++)  //Variable to test through modulus to see how many numbers evenly divide by the integer given
	{
	  if((data%i)==0)
	    count++;
	}
      cout << setw(12) << data;
      if (count==0)
	cout <<setw(12) <<"";
      else 
      cout <<  setw(12) << count;
      if (count == 2)
	{
	cout << setw(10) << "Prime" << endl;
	p_factors++;
	}
      else 
	if (count>2)
	  {
	  cout << setw(14) << "Composite"<< endl;
	  c_factors++;
	  }
	else 
	  if (count ==0)
	    {
	    cout << setw(7) << "" << endl;
	    n_factors++;
	    }
      
      cin>> data;
      
 }
 cout << endl <<  "Primes: " << p_factors << endl;
 cout << "Composites: " << c_factors << endl;
 cout << "Neither Prime or Composite: "<< n_factors<< endl;
  return 0;
}
