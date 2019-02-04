#include <iostream>
#include <cstdlib>
#include "matrix.h"
using namespace std;

int** matrixFactory(size_t, size_t, int[][2]);
int** matrixFactory(size_t, size_t, int[][3]);
int** matrixFactory(size_t, size_t, int[][5]);
void deallocate(size_t, int**&);

int main()
{
	int ** pass;
	int a1[4][2] = { {7, 3}, {2, 5}, {6, 8}, {9, 0} };
	int a2[2][3] = { {7, 4, 9}, {8, 1, 5} };
	int a3[3][5] = { {1, 5, 7, 11, 12}, {11, 2, 1, 7, 9}, {8, 2, 5, 6, 11} };
	int a4[2][2] = { {5, 6}, {2, 4} };
	int a5[2][3] = { {11, 6, 8}, {9, 0, 2} };

	pass = matrixFactory(4, 2, a1);
	matrix m1(4, 2, pass);
	deallocate(4, pass);
	

       	pass = matrixFactory(2, 3, a2);
	matrix m2(2, 3, pass);
	deallocate(2, pass);
	
	pass = matrixFactory(3, 5, a3);
	matrix m3(3, 5, pass);
	deallocate(3, pass);

       	pass = matrixFactory(2, 2, a4);
	matrix m4(2, 2, pass);
	deallocate(2, pass);

	pass = matrixFactory(2, 3, a5);
	matrix m5(2, 3, pass);
	deallocate(2, pass);
	
	matrix result;
       
	
      	result = m1 * m2;
	cout << "m1 * m2" << endl << result << endl << endl;
	
       	result = m3 * m5;
	cout << "m3 * m5" << endl << result << "Empty matrix" << endl << endl;

	result = m5 * m3;
	cout << "m5 * m3" << endl << result << endl << endl;
	
	result = m2 * m3;
	cout << "m2 * m3" << endl << result << endl << endl;
	
	result = m3 * m2;
	cout << "m3 * m2" << endl << result << "Empty matrix" << endl << endl;
	
	result = m2 + m5;
	cout << "m2 + m5" << endl << result << endl << endl;

	result = m1 + m2;
	cout << "m1 + m2" << endl << result << "Empty matrix" << endl << endl;
	
	result = 4 * m1;
	cout << "4 * m1" << endl << result << endl << endl;

	result = m4 * 2;
	matrix answer(result);
	cout << "m4 * 2" << endl << answer << endl << endl;
	
	return 0;
}

/*-----------------------------------------------------------------

A bunch of functions to make life easier, because C++ 2D
arrays are mean and don't play nice...

-----------------------------------------------------------------*/

int** matrixFactory(size_t rows, size_t columns, int a[][2])
{
  int**m;
  m = new int*[rows];
  for(int i = 0; i < rows; i++)
    m[i] = new int[columns];
  for(int j = 0; j < rows; j++)
    for(int k = 0; k < columns; k++)
      m[j][k] = a[j][k];
  return m; 
}

int** matrixFactory(size_t rows, size_t columns, int a[][3])
{
  int ** m;
  m = new int*[rows];
  for(int i = 0; i < rows; i++)
    m[i] = new int[columns];
  for(int j = 0; j < rows; j++)
    for(int k=0; k < columns; k++)
      m[j][k] = a[j][k];
  return m;
}

int** matrixFactory(size_t rows, size_t columns, int a[][5])
{
  int **m;
  m = new int*[rows];
  for(int i = 0 ; i < rows; i++)
    m[i] = new int[columns];
  for(int j = 0; j < rows; j++)
    for(int k = 0; k < columns; k++)
      m[j][k]=a[j][k];
  return m;
}

void deallocate(size_t rows, int**& pass)
{
  for(int i = 0; i < rows; i++)
    delete [] pass[i];
  delete [] pass;
}
