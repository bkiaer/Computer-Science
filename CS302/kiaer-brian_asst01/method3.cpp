#include <iostream>
#include <vector>
#include <cstdlib> 
using namespace std;

int main()
{
  vector<int> v;
  int randin1;
  int randin2;
  int temp;
  int size;
  cout <<"Please enter an integer" << endl;
  cin>>size;
  v.resize(size);
  for(int i=0; i < v.size(); i++)
    {
      v[i] = i+1; //assign values for the list in numerical order
    }
    for(int j = 0; j < v.size(); j++)
    {
      randin1 = rand ()% v.size(); //get two random values
      randin2 = rand ()% v.size (); 
      if(randin1 == randin2) //if both random values are equal than randomize them again
	{
	      randin1 = rand ()% v.size(); 
	      randin2 = rand ()% v.size();
	    
	    }
      if(randin1 != randin2) // if both values are not equal then swap the places of the values in the list until it has done it v.size() times. 
	    {
	      temp = v[randin1];
	  	v[randin1] = v[randin2];
		v[randin2] = temp;
	}
	}
  return 0; 
}
