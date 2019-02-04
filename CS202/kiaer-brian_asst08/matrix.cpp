#include <iostream>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include "matrix.h"
using namespace std;
/*-----------------------------------------------
Default constructor: creates an empty matrix
-----------------------------------------------*/
matrix::matrix()
{
  rows = 0;
  columns = 0;
  element = NULL;
}
/*-----------------------------------------------
CONSTRUCTOR
PARAMETERS: r for number of rows, c for number of columns, pointer a 
to pass in 2D array
POSTCONDITION/RESULT: This constructor is responsible for making a 
deep copy of a 2D array into an object.
-----------------------------------------------*/
matrix::matrix(size_t r, size_t c, int ** a)
{
  rows = r; 
  columns = c; 
  element = new LinkedList<int>[rows];
  for(int i = 0; i < rows; i++)
    for(int j = 0; j < columns; j++)
      element[i].insert_back(a[i][j]);
}
/*-----------------------------------------------
CONSTRUCTOR
PARAMETERS: r for amount of rows, c for amount of columns
POSTCONDITION/RESULT: result is to resize a 2D array in an object
and default the values in the 2D array to be 0's. 
-----------------------------------------------*/
matrix::matrix(size_t r, size_t c)
{
  rows = r; 
  columns = c; 
  element = new LinkedList<int>[rows];
  for(int i = 0; i < rows; i++)
    for(int j =0; j < columns; j++)
      element[i].insert_back(0);
}
/*-----------------------------------------------
COPY CONSTRUCTOR
PARAMETERS: matrix object
POSTCONDITION/RESULT: the purpose of this is to create 
a deep copy of an object into another object. 
-----------------------------------------------*/
matrix::matrix(const matrix& copy)
{

  rows = copy.rows; 
  columns = copy.columns;
  element = new LinkedList<int>[rows];
  LinkedList<int>::iterator it;
  for(int i = 0; i < rows; i++)
    {
      it = copy.element[i].begin();
      for(int j = 0; j < columns; j++)
	{
	  element[i].insert_back(*it);
	  it++;
	}
    }
}
/*-----------------------------------------------
ASSIGNMENT OPERATOR
PARAMETERS: rhs object 
POSTCONDITION/RESULT: the purpose of this is to assign the values in 
rhs object into another object also creating a deep copy into an object.
-----------------------------------------------*/
const matrix& matrix::operator=(const matrix& rhs)
{
	if (this != &rhs)
	{
	  if(element != NULL)
	    {
	      for(int i = 0; i < rows-1; i ++)
		element[i].destroyList();
	      delete [] element;
	    }
	  if(rhs.element == NULL)
	    element = NULL;
	  else
	    {
	  rows = rhs.rows;
	  columns = rhs.columns;
	  element = new LinkedList<int>[rhs.rows];
	  LinkedList<int>::iterator it;
	  for(int i = 0; i < rows; i++)
	    {
	      it = rhs.element[i].begin();
	      for(int j = 0; j < columns; j++)
		{
		  element[i].insert_back(*it);
		  it++;
		}
	    
	    }
	    }
	}
	return *this; 
}
/*-----------------------------------------------
DESTRUCTOR: Deallocates the dynamic memory
-----------------------------------------------*/
matrix::~matrix()
{
  if(element != NULL)
    {
      for(int i = 0; i < rows-1; i++)
	element[i].destroyList();
      delete [] element;
    }
}
/*-----------------------------------------------
FUNCTION NAME: operator* object
PARAMETERS: rhs object
POSTCONDITION/RESULT: the purpose of this function is 
to multiply two matrix objects or return an empty matrix
if the matrices are unable to be multiplied. 
-----------------------------------------------*/
matrix matrix::operator*(const matrix& rhs) const
{
  if(columns != rhs.rows)
    return matrix();
  
    
  matrix temp(rows, rhs.columns);
  LinkedList<int>::iterator it;
  LinkedList<int>::iterator it2;
  LinkedList<int>::iterator it3;
    for(int i = 0; i < rows; i++)
    {
      it = element[i].begin();	    
	    for(int k = 0; k < columns; k++)
	      {
		it2 = rhs.element[k].begin(); 
		it3 = temp.element[i].begin();
		for(int l = 0; l < rhs.columns; l++)
		  {
		  *it3 += *it * *it2;
		  it3++;
		  it2++;
		  }
		it++;
	      }	       
	    }
  return temp;
  
}
/*-----------------------------------------------
FUNCTION NAME: operator+ object
PARAMETERS: rhs object
POSTCONDITION/RESULT: the purpose of this function is to 
add two matrix objects together. This function will return an 
empty matrix if the rows or columns are not equal with the other objects
rows or columns. 
-----------------------------------------------*/
matrix matrix::operator+(const matrix& rhs) const
{
  if(rows != rhs.rows || columns != rhs.columns)
    return matrix();
  else
    {
  matrix temp(rows, columns);
  LinkedList<int>::iterator it;
  LinkedList<int>::iterator it2;
  LinkedList<int>::iterator it3;
  
  for(int i = 0; i < rows; i++)
    {
      it = element[i].begin();
      it2 = rhs.element[i].begin();
      it3 = temp.element[i].begin();
      for(int j = 0; j < columns; j++)
	{
	  *it3 = *it + *it2;
	  it++;
	  it2++;
	  it3++;
	}
    }
  return temp;
    }
  
}
/*-----------------------------------------------
FUNCTION NAME: operator*int
PARAMETERS: int value to be multiplied
POSTCONDITION/RESULT: the result of this function is to 
multiply an object by an integer by overloading the * operator
-----------------------------------------------*/
matrix matrix::operator*(int rhs) const
{	
  matrix temp(rows, columns);
  LinkedList<int>::iterator it;
  LinkedList<int>::iterator it2;
  for(int i = 0; i < rows; i ++)
    {
    it = element[i].begin();
    it2 = temp.element[i].begin();
    for(int j = 0; j < columns; j++)
      {
      *it2 = *it * rhs;
      it2++;
      it++;
      }
    }
  return temp;

	
}
/*-----------------------------------------------
FUNCTION NAME: operator* (int lhs, matrix rhs)
PARAMETERS: int lhs for left hand side integer, and rhs object 
POSTCONDITION/RESULT: the purpose of this function is to overload the
* operator and multiply an object when there is an integer value on the left hand
side of the * operator
-----------------------------------------------*/
matrix operator*(int lhs, const matrix& rhs)
{
  return rhs*lhs;
}
/*-----------------------------------------------
  FUNCTION NAME: operator <<
PARAMETERS: ostream out, matrix object rhs
POSTCONDITION/RESULT: the purpose of this function is to overload the << operator 
it will display what is inside the linked lists and format them accordingly. If the 
element is empty it won't print anything.
-----------------------------------------------*/
ostream& operator<<(ostream& out, const matrix& rhs)
{
  LinkedList<int>::iterator it;
  if(rhs.element == NULL)
    out <<"";
  else
    {
  for(int i = 0; i < rhs.rows; i++)
    {
      it = rhs.element[i].begin();
      for(int j = 0; j < rhs.columns; j++)
	{
	  out << left << setw(5) << *it << " " ; 
	  it++;
	}
      out << endl;
    }
    }
	return out;
}
