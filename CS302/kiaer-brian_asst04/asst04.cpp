#include<iostream>
#include <thread> //thread library
#include <vector> 
#include <cstdlib>
#include <math.h>
using namespace std;

void quickSort(int, int);
void mergeLists(int, int, int, int);
vector<int> v;

int main(int args, char*argv[])
{
    int numThreads = atoi(argv[1]);
    int listSize = atoi(argv[2]);

    
    vector<thread> threadPool;
  
    v.resize(listSize);
    for(int i=0; i < v.size(); i++)//loop to allocate random numbers into a list for listSize amount of numbers.
        v[i] = rand()%v.size();
 
    for(int i = 0; i < numThreads; i++) //quicksort implementation for listSize/numThreads for each block.
        threadPool.push_back(thread(quickSort, i*(listSize/numThreads), ((i+1)*(listSize/numThreads)-1)));

    for(int i = 0; i < threadPool.size(); i++)
        threadPool[i].join();

    threadPool.clear();

    int tmp  = numThreads;
    while(tmp != 1)
      {
	tmp = tmp/2; 
	for(int i=0; i <tmp; i++)
	  {
  
	    threadPool.push_back(thread(mergeLists, (i*(listSize/(tmp*2))+(listSize/(tmp*2))*i), (((listSize/(tmp*2))*i)+(i+1)*(listSize/(tmp*2))-1),((listSize/(tmp*2))*i)+((i+1)*(listSize/(tmp*2))),((listSize/(tmp*2))*(i)+((i+2)*(listSize/(tmp*2)))-1)));

	    for(int k=0; k < threadPool.size(); k++)
	      threadPool[k].join();
        
        
	    threadPool.clear();
        
	  }
    }
   
    /*    for(int i = 0; i < listSize; i++)
      cout << v[i] << " ";
    cout << "THE END" << endl;
    */
    
    return 0;
    
}
/*------------------------------------------
FUNCTION: void quickSort
PARAMETERS: two integers, for the left and right indices for each block
PURPOSE: The purpose of this function is to use the quickSort algorithm
to sort the list of each block that are called into the function. 
  ----------------------------------------------*/

void quickSort(int left, int right)
{
    int i = left;
    int j = right;
    int tmp;
    int pivot = v[(left+right)/2];

    
    while(i <= j)
    {
        while(v[i] < pivot )
            i++;
        while(v[j] > pivot )
            j--;
        if(i <= j)
        {
            tmp = v[i];
            v[i] = v[j];
            v[j] = tmp;
            i++;
            j--;
            
        }
    }
    if(left < j)
        quickSort(left, j);
    if(i < right)
        quickSort(i, right);
}
/*------------------------------------------------------
FUNCTION: void mergeLists
PARAMETERS: 4 integers that incorporate the two outer indices of 2 blocks 
PURPOSE: The purpose of this function is to merge two sorted blocks by comparing the
outer indices of each block. By merging the two blocks, this function will also sort 
the two sorted lists to make sure that they stay in chronilogical order. 
  --------------------------------------------------------*/

void mergeLists(int leftLeft, int leftRight, int rightLeft, int rightRight)
{
    int tmp;

    while(leftLeft!= rightRight && leftLeft < leftRight && rightLeft < rightRight)
    {
      
    while(v[leftLeft] < v[rightLeft])
        leftLeft++;
    if(v[leftLeft] >= v[rightLeft])
    {
        tmp = v[rightLeft];
        for(int i = 0; i <= (rightLeft-leftLeft); i++)
            v[rightLeft-i] = v[rightLeft-(i+1)];
        leftRight++;
        rightLeft++;
        v[leftLeft]=tmp;
    }
    while(v[rightRight]> v[leftRight])
      rightRight--;
     if(v[leftRight] >= v[rightRight])
        {
            tmp = v[leftRight];
            for(int i = 0; i <= (rightRight-leftRight); i++)
                v[leftRight+i] = v[rightLeft+i];
            rightLeft--;
            leftRight--;
            v[rightRight]=tmp;
        }
          }
}
