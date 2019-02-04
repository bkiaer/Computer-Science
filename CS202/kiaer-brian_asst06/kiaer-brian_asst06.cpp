#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;

void resize(double *&, size_t, size_t&);
double deviation(double*, size_t);
double mean(double*, size_t); 

int main(int args, char * argv[])
{
  size_t size = 0;
  size_t capacity = 0; 
  double meanvalue; 
  double deviationval;
  double median;
  double tmp_med;
  double * array; 
  ifstream in;
  in.open(argv[1]);

  size_t incAmount = atoi(argv[2]);
  capacity = incAmount; 
  array = new double[capacity];

  while(in)
    {
     
      in>>array[size];
      if(size == capacity)
	resize(array, incAmount, capacity);
	size++;
    }

  sort(array, array + size); 
  in.close();

  if(size%2 == 1)
   median = array[(size/2)]; 

  meanvalue = mean(array,size);
   
  if(size%2 == 0)
     {
     median = array[(size/2)];
     cout << median << endl;
     tmp_med = array[(size/2)-1];
     median = (median+tmp_med)/2;
     }
  cout<< fixed << setprecision(2);
  deviationval = deviation(array, size);
  cout << fixed << setprecision(2); 
  cout << left << setfill(' ') << setw(17) << "Median" << setfill(' ')<< right << setw(10)<< median << endl;
  cout << left << setfill(' ') << setw(17) << "Mean" << setfill(' ') << right << setw(10) << meanvalue<<endl;
  cout << left << setfill(' ') << setw(17) << "Standard Deviation" << setfill(' ') << right << setw(9) << deviationval << endl;
  delete [] array;
  return 0;
}

/*--------------------------------------------------------
Function name: resize 
PARAMETERS: Array of values, increment amount, capacity of the array
POSTCONDITION: This function is responsible for resizing the array everytime the capacity and 
size are equal. It will increment the capacity everytime size and capacity are equal.
---------------------------------------------------------*/ 
void resize(double *& array, size_t incAmount, size_t& capacity)
{
  double * tmp_array;
  capacity = capacity + incAmount;
  tmp_array = new double[capacity]; 
  for(int i = 0; i < 1+capacity-incAmount ; i++)
    tmp_array[i] = array[i]; 
    
    delete [] array;
    array = tmp_array; 
    tmp_array = NULL;
    delete [] tmp_array;
    return;

}
/*------------------------------------------------------
Function name: deviation
PARAMETERS: array of values and size of the array
POSTCONDITION: this function is responsible for calculating the standard deviation for the values inside
the input file. 
---------------------------------------------------------*/
double deviation(double * array, size_t length)
{

  double *  tmp_arr;
  tmp_arr = new double[length];
  double meanval1;
  double meanval2;
  meanval1 = mean(array, length);
  for(int i = 0; i < length; i++)
    {
      tmp_arr[i] = array[i]-meanval1;
      tmp_arr[i] = tmp_arr[i]*tmp_arr[i];
    }
  meanval2 = mean(tmp_arr,length);

  
   delete [] tmp_arr; 
  return sqrt(meanval2); 
 
}
/*-------------------------------------------------------------
Function name: mean
PARAMETERS: Passing the array of numbers and size_t which is the size of the array 
POSTCONDITION: This function is responsible for calculating the mean of the total array.
-----------------------------------------------------------*/
double mean(double * array, size_t length)
{
  double mean=0; 
  for(int i = 0; i < length ; i++)
    mean = array[i] + mean; 
  return mean/length; 

}
