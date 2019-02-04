//
//  asst07.cpp
//  kiaer-brian_asst07
//
//  Created by Brian Medrano on 8/1/17.

#include <iostream>
#include <fstream>
using namespace std;

template<class Type>
class binMinHeap
{
public:
    binMinHeap(int = 10);
    binMinHeap(const binMinHeap<Type>&);
    ~binMinHeap();
    binMinHeap& operator=(const binMinHeap<Type>&);
    void insert(const Type&);
    void deleteMin();
    Type getMin() const;
    int getSize() const;
private:
    void bubbleUp(int);
    void bubbleDown(int);
    
    int capacity;
    int size;
    Type* heapArray;
};

template<class Type>
class binMaxHeap
{
public:
    binMaxHeap(int = 10);
    binMaxHeap(const binMaxHeap<Type>&);
    ~binMaxHeap();
    binMaxHeap& operator=(const binMaxHeap<Type>&);
    void insert(const Type&);
    void deleteMax();
    Type getMax() const;
    int getSize() const;
private:
    void bubbleUp(int);
    void bubbleDown(int);
    
    int capacity;
    int size;
    Type*heapArray;
    
};

int main(int args, char*argv[])
{
    string input_file(argv[1]);
    ifstream infile;
	int value;
	double median;
    infile.open(input_file.c_str());
	if (!infile.is_open())
	{
	  cout << "Error, could not open file. Try again." << endl; // return error if file cannot open.
		return 0;
	}
	binMinHeap<int> min;
	binMaxHeap<int> max;
	infile >> value;
	max.insert(value);
	infile >> value; 
	while (infile)
	{
		
		if (value > max.getMax())
			min.insert(value);
		else
		{
				max.insert(value);
		}
		if (max.getSize() != min.getSize())
		{
			if (max.getSize() > min.getSize())
			{
				min.insert(max.getMax());
				max.deleteMax();
			}
			else
			{
				max.insert(min.getMin());
				min.deleteMin();
			}
		}
		if (min.getSize() == max.getSize())
			median = ((max.getMax() + min.getMin()) / 2.0);
		if (min.getSize() > max.getSize())
			median = min.getMin();
		if (min.getSize() < max.getSize())
			median = max.getMax();
		
		infile >> value;
		
	}
	if(min.getSize() == max.getSize())
		median = ((max.getMax() + min.getMin()) / 2.0);
	if (min.getSize() > max.getSize())
		median = min.getMin();
	if (min.getSize() < max.getSize())
		median = max.getMax();
	
	cout << "The median is " << median << endl;
       
	
	return 0;
}

/*----------------------------------------------------------
FUNCTION: binMinHeap<Type>::bubbleUp 
PARAMETERS: integer regarding the index of the integer.
PURPOSE: The purpose of this function is to move the integer/child up to 
the correct position if it is less than its parents. 
  ------------------------------------------------------------*/
template<class Type>
void binMinHeap<Type>::bubbleUp(int x)
{
	int temp;
	while (x / 2 > 0 && heapArray[x / 2] > heapArray[x])
	{
	  
		temp = heapArray[x / 2];
		heapArray[x/2] = heapArray[x];
		heapArray[x] = temp; 
		x = x / 2;
	}
}
/*----------------------------------------------------------------
FUNCTION: binMinHeap<Type>::bubbleDown
PARAMETERS: an integer in regards to the index of the integer in the heap.
PURPOSE: The purpose of this function is bring down the specific integer down 
the heap to the correct position, if the identified integer is larger than
either child then they will swap places.
  ------------------------------------------------------------------*/
template<class Type>
void binMinHeap<Type>::bubbleDown(int x)
{
	int temp;
	if (x * 2 > size)
		return;
	if (x * 2 + 1 > size)
	{
		if (heapArray[x * 2] < heapArray[x]) //if child is less than parent swap
		{
			temp = heapArray[x * 2];
			heapArray[x * 2] = heapArray[x];
			heapArray[x] = temp;
			return;
		}
	}
	
	while (heapArray[x]> heapArray[x * 2]  ||  heapArray[x] >= heapArray[x * 2 + 1]/* || heapArray[x]> heapArray[x * 2] || heapArray[x] < heapArray[x * 2 + 1]|| heapArray[x] <heapArray[x * 2] && heapArray[x] > heapArray[x * 2 + 1]*/)
	{
	 
	 
		if (x * 2 > size)
			return;
		if (x * 2 + 1 > size)
		{
		  
			if (heapArray[x * 2] < heapArray[x]) //if child is less than parent swap
			{
				temp = heapArray[x * 2];
				heapArray[x * 2] = heapArray[x];
				heapArray[x] = temp;
				return;
			}
			return;
		}
		
		else
		{
		  
			if (heapArray[x] > heapArray[x * 2] && heapArray[x] > heapArray[x * 2 + 1])
			{
				if (heapArray[x * 2] < heapArray[x * 2 + 1])
				{
				  
					temp = heapArray[x * 2];
					heapArray[x * 2] = heapArray[x];
					heapArray[x] = temp;
					x = x * 2;
				}
				else
				{
				  
					temp = heapArray[x * 2 + 1];
					heapArray[x * 2 + 1] = heapArray[x];
					heapArray[x] = temp;
					x = x * 2 + 1;
					
				}
			}
			else
			  {
			    
			    if (heapArray[x] > heapArray[x * 2] && heapArray[x] <= heapArray[x * 2 + 1])
			{
			  
				temp = heapArray[x * 2];
				heapArray[x * 2] = heapArray[x];
				heapArray[x] = temp;
				x = x * 2;
				
			}
			else
			  {
			    
			if (heapArray[x] > heapArray[x * 2 + 1] && heapArray[x]<= heapArray[x * 2])
			{
			  
				temp = heapArray[x * 2 + 1];
				heapArray[x * 2 + 1] = heapArray[x];
				heapArray[x] = temp;
				x = x * 2 + 1;
				
				
			}
			  }

			  }
		    
			if(x*2>size)
			  return;
			if(x*2+1 > size)
			  {
			  if(heapArray[x*2] < heapArray[x])
			    {
			      temp = heapArray[x*2];
			      heapArray[x*2] = heapArray[x];
			      heapArray[x] = temp;
			      return;
			    }
			  return;
			  }
		       
		       
			if(heapArray[x] <= heapArray[x*2] && heapArray[x] <= heapArray[x*2+1])
			  return;
			
		}
	}
	
}
/*---------------------------------------------------------------------
FUNCTION: binMinHeap<Type>::binMinHeap default Constructor
PARAMETERS: default capacity
PURPOSE: The purpose of this function is a default constructor to 
allocate a dynamic array and set the size of the object to 1. 
  --------------------------------------------------------------------------*/
template<class Type>
binMinHeap<Type>::binMinHeap(int capacity)
{
	this->capacity = capacity;
	heapArray = new int[capacity];
	size = 1;
}
/*------------------------------------------------------------------------
FUNCTION: Copy Constructor
PARAMETERS: Another object
PURPOSE: The purpose of this function is to create a deep copy of the passed object
into the current object and copy the other contents as well.
  ----------------------------------------------------------------------------*/
template<class Type>
binMinHeap<Type>::binMinHeap(const binMinHeap<Type>& copy)
{
  capacity = copy.capacity;
  size = copy.size;
  Type*tempArray; 
  tempArray = new int[copy.capacity];

  for(int i = 0; i < copy.capacity; i++)
    tempArray[i] = copy.heapArray[i];

  delete [] heapArray;

  heapArray = tempArray;
  tempArray = NULL;
  delete [] tempArray;
  return;
}
/*------------------------------------------------------------------------------
FUNCTION: Assignment Operator
PARAMETERS: rhs object
PURPOSE: The purpose of this function is that its the assignment operator, so it
overloads the = operator and copies the content from rhs to the current object. Also
ensures for a deep copy of the rhs.object too.
  -------------------------------------------------------------------------------*/

template<class Type>
binMinHeap<Type>& binMinHeap<Type>::operator=(const binMinHeap<Type>& rhs)
{
  capacity = rhs.capacity;
  size = rhs.size;
  Type*tempArray;
  tempArray = new int[rhs.capacity];

  for(int i = 0; i < rhs.capacity; i++)
    tempArray[i] = rhs.heapArray[i];
  
  delete [] heapArray;
  heapArray = tempArray;
  tempArray = NULL;
  delete [] tempArray;
  return;
    
}
/*--------------------------------------------------------------------------
FUNCTION: Destructor
PURPOSE: The purpose of this function is to ensure there are no memory leaks 
in the program. It will deallocate any allocated memory in the program. 
  ---------------------------------------------------------------------------*/
template<class Type>
binMinHeap<Type>::~binMinHeap()
{
  delete[]heapArray;
  heapArray = NULL;
}
/*---------------------------------------------------------------------------
FUNCTION: binMinHeap<Type>::insert
PARAMETERS: the item that is being put into the heap, Type item
PURPOSE: The purpose of this function is to insert an integer into the binary minHeap
and then ensure that it gets inserted in the correct position of the tree 
and also is responsible for resizing the array if the size == capacity. 
  -------------------------------------------------------------------------------*/
template<class Type>
void binMinHeap<Type>::insert(const Type& item)
{
	heapArray[size] = item;
	size++;
	bubbleUp(size - 1);
	if (size == capacity)
	{
		Type*tempArray;
		capacity = 2 * capacity;
		tempArray = new int[capacity];

		for (int i = 0; i < (capacity/2); i++)
			tempArray[i] = heapArray[i];

		delete[] heapArray;

		heapArray = tempArray;
		tempArray = NULL;
		delete[] tempArray;
		return;
	}

}
/*------------------------------------------------------------------------------
FUNCTION: binMinHeap<Type>::deleteMin()
PURPOSE: The purpose of this function is to delete the root or the head of the heap
by replacing the head by the largest number and bubbling down until the heap is correctly
positioned.
  ------------------------------------------------------------------------------*/
template<class Type>
void binMinHeap<Type>::deleteMin()
{
	heapArray[1] = heapArray[size-1];
	
	size--;
	bubbleDown(1);
       
}
/*----------------------------------------------------------------------------------------
FUNCTION: binMinHeap<Type>::getMin()
PURPOSE: The purpose of this function is to return the root of the bin min heap, the root 
should be the smallest number in the heap. 
  ------------------------------------------------------------------------------------------*/
template<class Type>
Type binMinHeap<Type>::getMin() const
{
	return heapArray[1];
}
/*---------------------------------------------------------------------------------------
FUNCTION: binMinHeap<Type>::getSize()
PURPOSE: The purpose of this function is to return the size of the heap.
  ------------------------------------------------------------------------------------------*/
template<class Type>
int binMinHeap<Type>::getSize() const
{
	return size-1;
}
/*------------------------------------------------------------------------------------------
FUNCTION: binMaxHeap<Type>::bubbleUp
PARAMETERS: passes in the index of the integer, x.
PURPOSE: the purpose of this function is to swap parent and child if the child is larger.
  -------------------------------------------------------------------------------------------*/
template<class Type>
void binMaxHeap<Type>::bubbleUp(int x)
{
	int temp;
	while (x / 2 > 0 && heapArray[x / 2] < heapArray[x])
	{
	 
		temp = heapArray[x / 2];
		heapArray[x / 2] = heapArray[x];
		heapArray[x] = temp;
		x = x / 2;
	}
}
/*------------------------------------------------------------------------------------------
FUNCTION: binMaxHeap<Type>::bubbleDown
PARAMETERS: passes in the index of the integer, x.
PURPOSE: The purpose of this function is to bring down the current integer down the heap if it 
is smaller than its children. 
  ---------------------------------------------------------------------------------------------*/
template<class Type>
void binMaxHeap<Type>::bubbleDown(int x)
{
	int temp;
	if (x * 2 > size)
		return;
	if (x * 2 + 1 > size)
	{
		if (heapArray[x * 2] > heapArray[x]) //if child is more than parent swap
		{
			temp = heapArray[x * 2];
			heapArray[x * 2] = heapArray[x];
			heapArray[x] = temp;
			return;
		}
	}
	while (heapArray[x] < heapArray[x * 2] && heapArray[x] <= heapArray[x * 2 + 1] || heapArray[x] < heapArray[x * 2] && heapArray[x] > heapArray[x * 2 + 1] || heapArray[x] > heapArray[x * 2] && heapArray[x] < heapArray[x * 2 + 1])
	{
	  
		if (x * 2 > size)
			return;
		if (x * 2 + 1 > size)
		{
			if (heapArray[x * 2] > heapArray[x]) //if child is more than parent swap
			{
				temp = heapArray[x * 2];
				heapArray[x * 2] = heapArray[x];
				heapArray[x] = temp;
				return;
			}
		}
		//x only has a left child
		else
		{
			if (heapArray[x] < heapArray[x * 2] && heapArray[x] < heapArray[x * 2 + 1])
			{
				if (heapArray[x * 2] > heapArray[x * 2 + 1])
				{
					temp = heapArray[x * 2];
					heapArray[x * 2] = heapArray[x];
					heapArray[x] = temp;
					x = x * 2;
				}
				else
				{
					temp = heapArray[x * 2 + 1];
					heapArray[x * 2 + 1] = heapArray[x];
					heapArray[x] = temp;
					x = x * 2 + 1;
				}
			}
			else
			  {
			if (heapArray[x] < heapArray[x * 2] && heapArray[x] >= heapArray[x * 2 + 1])
			{
				temp = heapArray[x * 2];
				heapArray[x * 2] = heapArray[x];
				heapArray[x] = temp;
				x = x * 2;
			}
			else
			  {
			if (heapArray[x] < heapArray[x * 2 + 1] && heapArray[x] > heapArray[x * 2])
			{
				temp = heapArray[x * 2 + 1];
				heapArray[x * 2 + 1] = heapArray[x];
				heapArray[x] = temp;
				x = x * 2 + 1;
			}
			  }

			  }
			//Determine which is smaller heapArray[x*2] or heapArray[x*2+1]
			//if one is smaller than parent then swap 
		}
	}
}
/*-----------------------------------------------------------------------------
FUNCTION: Default Constructor
PARAMETERS: Default Capacity Size
PURPOSE: The purpose of this function is to allocate a dynamic array in accordance
to the capacity that is passed in and will also set the object's size to 1. 
  ------------------------------------------------------------------------------*/

template<class Type>
binMaxHeap<Type>::binMaxHeap(int capacity)
{
	this->capacity = capacity;
	heapArray = new int[capacity];
	size = 1;
}
/*-----------------------------------------------------------------------------
FUNCTION: Copy Construcor
PARAMETERS: Copy object
PURPOSE: The purpose of this function is to copy the passed in object to the current object.
It copies the contents of the copy object as well. 
  -------------------------------------------------------------------------------*/
template<class Type>
binMaxHeap<Type>::binMaxHeap(const binMaxHeap<Type>& copy)
{
  capacity = copy.capacity;
  size = copy.size;
  Type*tempArray;
  tempArray = new int[copy.capacity];

  for(int i = 0; i < copy.capacity; i++)
    tempArray[i]  = copy.heapArray[i];

  delete [] heapArray;
  
  heapArray = tempArray;
  tempArray = NULL;
  delete[]tempArray;
  return;

}
/*------------------------------------------------------------------------------
FUNCTION: Assignment Operator
PARAMETERS: Right hand side object
PURPOSE: The purpose of this function is to copy the contents of the rhs object
into the current object. 
  -----------------------------------------------------------------------------*/
template<class Type>
binMaxHeap<Type>& binMaxHeap<Type>::operator=(const binMaxHeap<Type>& rhs)
{
  capacity = rhs.capacity;
  size = rhs.size;
  Type*tempArray;
  tempArray = new int[rhs.capacity];

  for(int i =0; i<rhs.capacity; i++)
    tempArray[i] = rhs.heapArray[i];

  delete [] heapArray;

  heapArray = tempArray;
  tempArray = NULL;
  delete [] tempArray;
  return;

}
/*----------------------------------------------------------------------------
FUNCTION: Destructor
PURPOSE: The purpose of this function is to deallocate any object that was created
to avoid any memory leaks.
  -----------------------------------------------------------------------------*/
template<class Type>
binMaxHeap<Type>::~binMaxHeap()
{
  delete [] heapArray;
  heapArray = NULL;
}
/*----------------------------------------------------------------------------------
FUNCTION: binMaxHeap<Type::insert
PARAMETERS: integer that will be inserted into the heap.
PURPOSE: The purpose of this function is insert the current integer and ensure that it
is placed in the correct position in the heap. 
  -----------------------------------------------------------------------------------*/
template<class Type>
void binMaxHeap<Type>::insert(const Type& item)
{
	heapArray[size] = item;
	size++;
	bubbleUp(size - 1);
	if (size == capacity)
	{
		Type*tempArray;
		capacity = 2 * capacity;
		tempArray = new int[capacity];

		for (int i = 0; i < (capacity / 2) ; i++)
			tempArray[i] = heapArray[i];

		delete[] heapArray;

		heapArray = tempArray;
		tempArray = NULL;
		delete[] tempArray;
		return;
	}
}
/*-------------------------------------------------------------------------------
FUNCTION: binMaxHeap<Type>::deleteMax()
PURPOSE: The purpose of this function is to replace the head of the heap by the last integer in
the heap and then bubble down that integer to delete that integer and make the heap smaller.
  -------------------------------------------------------------------------------*/
template<class Type>
void binMaxHeap<Type>::deleteMax()
{
	heapArray[1] = heapArray[size-1];
	size--;
	bubbleDown(1);
}
/*--------------------------------------------------------------------------------------
FUNCTION: binMaxHeap<Type>::getMax()
PURPOSE: The purpose of this function is return the head of the current heap to return 
the highest number on the heap.
  -------------------------------------------------------------------------------------------*/
template<class Type>
Type binMaxHeap<Type>::getMax() const
{
	return heapArray[1];
}
/*-------------------------------------------------------------------------------
FUNCTION: binMaxHeap<Type>::getSize()
PURPOSE: The purpose of this function is to return the current size of the heap.
  -----------------------------------------------------------------------------------*/
template<class Type>
int binMaxHeap<Type>::getSize() const
{
	return size-1;
}








