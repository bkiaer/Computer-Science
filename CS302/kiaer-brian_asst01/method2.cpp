#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
int main()
{
  vector<int> v;
  vector<bool> b;
  int randNum; 
  int size;

  cout <<"Enter an integer" <<endl;
  cin>>size;
  
  v.resize(size);
  b.resize(size);
  for(int i=0; i < v.size(); i++)
    {
      v[i] = rand()%v.size()+1;
      if(b[v[i]-1] == true)//if checker value is true  
	{
	  while(b[v[i]-1] == true)//keep looping until checker value is false
	  v[i] = rand()%v.size()+1;
	b[v[i]-1] = true; 
	}
      if(b[v[i]-1] ==false) //if the checker value is fale
	b[v[i]-1] = true; //change to true so the value cannot be repeated
       	
    }

  //   for(int k=0; k < v.size(); k++)
  // cout<< v[k] << " ";
  return 0;
}
