#include <iostream>
#include <string>
using namespace std; 

template <class Type> 
class myHash
{
public:
  myHash(int = 10); 
  myHash(const myHash<Type>&);
  myHash& operator=(const myHash<Type>&);
  ~myHash();
  Type& operator[](std::string);
  void resize(int);
private:
  void destroyList();
  int getIndex(std::string);

  struct node
  {
    Type item;
    std::string key;
    node * link;
  };

  int size;
  node ** myHashList;
};

int main()
{
  myHash<int> h1;

  h1["nomar"] = 5; 
  h1["ramon"] = 12;
  h1["griffin"] = 14;
  h1["i"] = 33;
  h1["s"] = 22; 
  h1["p"] = 18;
  h1["z"] = 99;
  h1["n"] = 101;
  h1["x"] = 66;

  myHash<int> h2;

  h2 = h1; 

  h2.resize(3);
  h2["griffin"] = h2["griffin"] +5;
  
  cout << "h1[\"nomar\"] = " << h1["nomar"] << endl;
  cout << "h1[\"ramon\"] = " << h1["ramon"] << endl;
  cout << "h1[\"nomar\"] = " << h1["nomar"] << endl;
  cout << "h1[\"griffin\"] = " << h1["griffin"] << endl;
  cout << "h1[\"i\"] = " << h1["i"] << endl; 
  cout << "h1[\"s\"] = " << h1["s"] << endl;
  cout << "h1[\"p\"] = " << h1["p"] << endl;
  cout << "h1[\"z\"] = " << h1["z"] << endl;
  cout << "h1[\"n\"] = " << h1["n"] << endl;
  cout << "h1[\"x\"] = " << h1["x"] << endl;

  cout << endl;

  cout << "h2[\"nomar\"] = " << h2["nomar"] << endl;
  cout << "h2[\"ramon\"] = " << h2["ramon"] << endl;
  cout << "h2[\"nomar\"] = " << h2["nomar"] << endl;
  cout << "h2[\"griffin\"] = " << h2["griffin"] << endl;
  cout << "h2[\"i\"] = " << h2["i"] << endl;
  cout << "h2[\"s\"] = " << h2["s"] << endl;
  cout << "h2[\"p\"] = " << h2["p"] << endl;
  cout << "h2[\"z\"] = " << h2["z"] << endl;
  cout << "h2[\"n\"] = " << h2["n"] << endl;
  cout << "h2[\"x\"] = " << h2["x"] << endl;
  
  
  return 0;
}
/*--------------------------------------------------
FUNCTION: myHash Constructor 
PARAMETERS: the default integer being passed would be the size of the hash table with an index of 10
PURPOSE: The purpose of this function is to be a constructor
for the myHash object, it will create an array of linked lists in the form of a Hash Table.
  ---------------------------------------------------*/
template<class Type>
myHash<Type>::myHash(int init)
{
  size = init;
  myHashList = new node*[init];
  for(int i = 0; i < init; i++)
    {
      myHashList[i] = new node; 
   
    }
  
  
}
/*---------------------------------------------------
FUNCTION: Copy Constructor
PARAMETERS: Another object being passed in.
PURPOSE: The purpose of this function is to copy the copy.myHashList contents into
the current myHashList function.
  ---------------------------------------------------*/
template<class Type>
myHash<Type>::myHash(const myHash<Type>& copy)
{
  *this = copy;
}
/*-------------------------------------------
FUNCTION: Assignment Operator 
PARAMETERS: Another object is being passed in. 
PURPOSE: The purpose of this function is to overload the assignment 
operator and copy the contents of rhs.myHashList to the current myHashList. 
  -------------------------------------------*/
template<class Type>
myHash<Type>& myHash<Type>::operator=(const myHash<Type>& rhs)
{
  if(this!= & rhs)
    {
      if(rhs.myHashList != NULL)
	{
	  node*it1;
	  node*it2;	
	  for(int i = 0; i < size; i++)
	    {
	      it1 = rhs.myHashList[i];	      
	      it2 = myHashList[i];
	  
	      while(it1 != NULL && it1->item != 0)
		{	       
		   if(it2->link == NULL && it1->link != NULL)
		    {	     	    
		      it2 -> link = new node;		 
		    }
		  it2->item = it1->item; 
		  it2->key = it1 -> key; 
		 
		  it1 = it1->link;
		  it2 = it2->link;
     
		}
	    }
	}
    }
	      
	      
  return *this;
      
}
/*-----------------------------------------------
FUNCTION: operator[]
PARAMETERS: string called searchKey
PURPOSE: The purpose of this function is to look through
the Hash Table for the given key and returns the item 
that is identified with the key.
  ------------------------------------------------*/
template<class Type>
Type& myHash<Type>::operator[](std::string searchKey)
{
 
 
  int index = getIndex(searchKey);
  node*it = myHashList[index];
  it = myHashList[index];
 
  while(it != NULL)
    {
    
      if(it->key == searchKey)
	{
	return it->item;
	}
      else
	{
	  if(it->link == NULL)
	    {
	     
	      it->link = new node;
	      it->key = searchKey;
	      return it->item;
	    }
	  
      	it = it->link;

	}
    }
  
}
/*---------------------------------------------
FUNCTION: resize
PARAMETERS: integer called amount 
PURPOSE: The purpose of this function is to resize the 
current Hash Table index by the amount that is given.
  ----------------------------------------------*/
template<class Type>
void myHash<Type>::resize(int amount)
{
  
  
  
  myHash<int> temp; 

  temp.myHashList = myHashList;
  
  if(myHashList != NULL)
    {
      //      destroyList();
  myHashList = new node*[size+amount];
  for(int i = 0; i < (size+amount); i++)
    myHashList[i] = new node;
    }
  node*it1;
  node*it2;
  for(int i = 0; i < size; i++)
    {
    
      it1 = myHashList[i];
      
      it2 = temp.myHashList[i];
      
      while(it2 != NULL)
	{
	  if(it1->link == NULL)
	    {
	      it1->link = new node;
	    }
	  it1->item = it2->item;
	  it1->key = it2->key;
	  it2 = it2->link;
	  it1 = it1->link;
	}
  
    }
}
/*-----------------------------------
FUNCTION: Destructor
PURPOSE: The purpose of this is to deallocate 
the memory of the Hash Table to avoid memory leaks 
and dangling pointers.
--------------------------------------*/
template<class Type>
myHash<Type>::~myHash()
{
  destroyList();
}
/*--------------------------------------
FUNCTION: destroyList
PURPOSE: The purpose of this function is to deallocate
the myHashList to ensure there are no leaks.
  --------------------------------------*/
template<class Type>
void myHash<Type>::destroyList()
{
  for(int i = 0; i < size; i++)
    {
      node *it = myHashList[i];
      while(it != NULL)
	{
	  delete it;
	  it = it->link;
	}
    }
  

  return;
}
/*-------------------------------------
FUNCTION: getIndex
PARAMETERS: string called str
PURPOSE: the purpose of this function is to calculate 
the index by adding the ASCII values and mod size.
-----------------------------------------*/
template<class Type>
int myHash<Type>::getIndex(std::string str)
{
  int tmp = 0;
  for(int i = 0; i < str.size(); i++)
    tmp = tmp + str[i]; 
  tmp = tmp%size;
  
  return tmp;
}
