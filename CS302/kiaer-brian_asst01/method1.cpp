#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int main()
{
  vector<int> v;
  int size;
  cout <<"Enter an integer"<<endl;
  cin>>size;
  
  v.resize(size); 
  for(int i = 0; i < v.size(); i++)
    {
      v[i] = rand ()% v.size() +1; //allocates an "array" of length size
      for(int j = 0; j < i; j++)
	{
	  for(int h=0; h < i; h++) //for loop that double checks the list to ensure no doubles are listed.
	    {
	  if(v[i] == v[j])
	    v[i] = rand ()% v.size() +1;
	  if(v[h] == v[i])
	    v[i] = rand()% v.size()+1;
	    }
	}
    }
  /*  for(int k = 0; k < v.size(); k++)
    {
      cout << v[k] << " ";
      }*/
  return 0; 
}
