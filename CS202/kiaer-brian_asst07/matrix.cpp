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
  columns =0;
  element = NULL;
  //element[0] = new int[columns];
}
/*-----------------------------------------------
CONSTRUCTOR
PARAMETERS: size_t r for radius, size_t c for columns, and an array pointer
POSTCONDITION/RESULT: constructor to size a 2D array and create a deep copy of the passed 2D array.
-----------------------------------------------*/
matrix::matrix(size_t r, size_t c, int ** a)
{
  rows = r; 
  columns = c; 
  element = new int*[r];
    for(int i = 0; i < r; i++)
   element[i] = new int[c];
  for(int j = 0; j < r; j++)
    for(int k = 0; k < c; k++)
      element[j][k] = a[j][k];
    
}
/*-----------------------------------------------
CONSTRUCTOR
PARAMETERS: r for rows, and c for columns
POSTCONDITION/RESULT: constructor to size a 2D array 
in regards to the given rows and columns
-----------------------------------------------*/
matrix::matrix(size_t r, size_t c)
{
  rows = r;
  columns = c; 
  element = new int*[r];
  for(int i = 0; i < r; i++)
    element[i] = new int[c];
}
/*-----------------------------------------------
COPY CONSTRUCTOR
PARAMETERS: matrix object that will be copied
POSTCONDITION/RESULT: this constructor copies a
matrix object into another object. It will size the new array 
and allocate the numbers from the old array to the new arrray.
-----------------------------------------------*/
matrix::matrix(const matrix& copy)
{
  rows = copy.rows; 
  columns = copy.columns;
  element = new int*[rows];
  for(int x = 0 ; x < rows; x++)
    element[x] = new int[columns];
  for(int a = 0; a < rows; a++)
    for(int b = 0; b < columns; b++)
      element[a][b] = 0;
  for(int i = 0; i < rows; i++)
    for( int j = 0 ; j < columns; j++)
      element[i][j] = copy.element[i][j];
}

/*-----------------------------------------------
ASSIGNMENT OPERATOR
PARAMETERS: matrix object named rhs
POSTCONDITION/RESULT: the purpose of this operator overloading 
is to copy the right hand side object onto the left hand side object
it also checks to deallocate old elements before the element is copied
-----------------------------------------------*/
const matrix& matrix::operator=(const matrix& rhs)
{
	if (this != &rhs)
	  {
	    if(element != NULL)
	      {
		for(int k = 0; k < rows; k++)
		  {
		  delete [] element[k];
		  }
		delete [] element;
	      }
	    rows = rhs.rows;
	    columns = rhs.columns;
	      element = new int*[rows];
	      for(int l = 0; l < rows; l++)
		{
	      element[l] = new int[columns];
		}
	       for(int i = 0; i < rhs.rows; i++)
		 {
		   for(int j = 0; j < rhs.columns ; j++) 
		     {
		     element[i][j] = rhs.element[i][j];
		     }
		 }
	  }
	return *this; //LEAVE THIS PART IN
	
}
/*-----------------------------------------------
DESTRUCTOR: Deallocates the dynamic memory
-----------------------------------------------*/
matrix::~matrix()
{
	 if(element != NULL)
	  {
	 for(int i = 0; i < rows; i ++)
	 delete [] element[i];
	 delete[] element;
	 }
	 }
/*-----------------------------------------------
FUNCTION NAME: operator*
PARAMETERS: right hand side object (rhs)
POSTCONDITION/RESULT: this function will multiply two 2D arrays and return
a temporary object that holds the product. If array columns and rhs.rows are not equal
return an empty matrix.
-----------------------------------------------*/
matrix matrix::operator*(const matrix& rhs) const
{
  matrix temp;
  if(columns != rhs.rows)
    return temp;
  else
    {
  temp.rows = rows;
  temp.columns = rhs.columns;
      temp.element = new int*[rows];
      for(int x = 0; x < rows; x++)
	temp.element[x] = new int[rhs.columns];

      for(int a = 0; a < rows; a++)
	{
	  for(int b = 0; b < rhs.columns; b++)
	    {
	      temp.element[a][b] = 0;
	    }
	}
	for(int i = 0; i < rows; i++)
	  for(int j = 0; j < rhs.columns; j++)
	    for(int k = 0; k < columns; k++)
	      temp.element[i][j] += element[i][k] * rhs.element[k][j];
      return temp;
    }
    } 
/*-----------------------------------------------
FUNCTION NAME: operaotr+
PARAMETERS: right hand side object (rhs)
POSTCONDITION/RESULT: function will add two matrixes/2D arrays together.
if rhs.columns or rhs.rows are not equal with the left hand side objects parameters 
then the function will return an empty matrix.
-----------------------------------------------*/
matrix matrix::operator+(const matrix& rhs) const
{
  matrix temp;
  if(columns != rhs.columns || rows != rhs.rows)
    return temp;
  else
    {
      temp.rows = rows;
      temp.columns = columns;
      temp.element = new int*[rows];
	for(int x = 0; x < rows; x++)
	  temp.element[x] = new int[columns];
	for(int a = 0; a < rows; a++)
	  {
	    for(int b =0; b < columns; b++)
	      {
		temp.element[a][b] = 0;
	      }
	  }
	for(int i = 0; i < rows; i++)
	  for(int j = 0; j < columns; j++)
	    temp.element[i][j] = element[i][j] + rhs.element[i][j]; 
	return temp;
    }

}
/*-----------------------------------------------
FUNCTION NAME:operator*int
PARAMETERS:int rhs
POSTCONDITION/RESULT: this function will multiply a 2D array by an immediate value
it will also check to see if the 2D array is empty, if it is it will not multiply
and it will return an empty matrix. 
-----------------------------------------------*/
matrix matrix::operator*(int rhs) const
{	
  matrix temp;
  if(element == NULL)
    return temp;
  else
    {
      temp.rows = rows;
      temp.columns = columns;
      temp.element = new int*[rows];
      for(int x = 0; x < rows; x++)
	temp.element[x] = new int[columns];
      for(int a =0; a < rows; a++)
	for(int b=0; b < columns; b++)
	  temp.element[a][b] = 0; 
      for(int i = 0; i < rows; i++)
	for(int j =0; j < columns; j++)
	  temp.element[i][j] = element[i][j] * rhs;
      return temp;
    }
}
/*-----------------------------------------------
FUNCTION NAME: operator* (lhs*matrix rhs) 
PARAMETERS: integer lhs and matrix object rhs
POSTCONDITION/RESULT: this function will multiply a 2D array and an immediate; however
the immediate will be on the left hand side of the function overloading call. This function
will return an empty matrix if element == NULL.
-----------------------------------------------*/
matrix operator*(int lhs, const matrix& rhs)
{
  matrix temp;
  if(rhs.element == NULL)
    return temp;
  else
    {
      temp.rows = rhs.rows;
      temp.columns = rhs.columns;
      temp.element = new int*[rhs.rows];
      for(int x = 0; x < rhs.rows; x++)
	{
	temp.element[x] = new int[rhs.columns];
	}
      for(int a = 0; a < rhs.rows; a++)
	{
	  for(int b=0; b < rhs.columns; b++)
	    {
	      temp.element[a][b] = 0;
	    }
	}
      for(int i = 0; i < rhs.rows; i++)
	for(int j = 0; j < rhs.columns; j++)
	  temp.element[i][j] = rhs.element[i][j] * lhs;
      return temp;
    }
      
}
/*-----------------------------------------------
  FUNCTION NAME: operator <<
PARAMETERS: ostream out, matrix object rhs
POSTCONDITION/RESULT: this function will overload << 
this will act as a "cout" and display the values of the 2D arrays
it will also space the values properly with iomanip
-----------------------------------------------*/
ostream& operator<<(ostream& out, const matrix& rhs)
{
  for(int i = 0; i < rhs.rows; i++)
    {
      for( int j = 0; j < rhs.columns; j++)
	out<<left << setw(5)<<rhs.element[i][j]<< " ";
      out << endl;
    }
	//YOUR CODE COMES ABOVE THE RETURN STATEMENT
	return out; //LEAVE THIS PART IN
}
