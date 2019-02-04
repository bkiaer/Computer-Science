#include "mastermind.h"
#include <string>
using namespace std;

/*--------------------------------------------------------------
CONSTRUCTOR
PARAMETERS: An Integer that will pass the column size
POSTCONDITION: Set column (col) size, set max moves to 10, set moves to 0,
and set elements of pegs to the color red. 
--------------------------------------------------------------*/
mastermind::mastermind(int size) : MAX_MOVES(10)
{
     cols = size; 
     moves = 0;
     for(int i = 0; i < size; i++)
     pegs[i] = "red";
}

/*--------------------------------------------------------------
CONSTRUCTOR
PARAMETERS: Integer that will pass the column size, string that passes cols 
elements of pegs to the elements in inital. 
POSTCONDITION:
--------------------------------------------------------------*/
mastermind::mastermind(int size, string initial[]): MAX_MOVES(10)
{
  cols = size;
  moves = 0;
  for(int i =0; i < size; i ++)
    pegs[i] = initial[i];
}

/*--------------------------------------------------------------
FUNCTION NAME: MOVE
PARAMETERS: string that takes in the sequence of colors the player inputs
the two reference integers are to hold the amount of skinny pegs after the players moves. 
POSTCONDITION: This function will return a value that is either 1 (win) -1 (lose) or 0(continue playing) this function will do all of the work for the main file. It will use bool values to compare string arrays to count for the gold and silver pegs. Also it will comfirmthat the colors are incase-sensitive. It will also check if the moves reach 10, if so then the program will terminate and display a "you Lose" message. 
--------------------------------------------------------------*/
int mastermind::move(string playerMove[], int& gold, int& silver)
{
  int length;
  string temp;
  for(int l = 0; l < cols; l++)
    {
    length = playerMove[l].size();
    temp = playerMove[l];
    for(int k = 0; k < length; k++)
      temp[k] = tolower(temp[k]);
    playerMove[l] = temp;
    }
  bool correct[10];
  bool player[10];
  if(moves == MAX_MOVES)
    return 0;
  for(int i = 0; i < cols; i++)
    {
    correct[i] = player[i] = false;
    silver = gold = 0;
    }
  for(int j = 0; j< cols; j++)
    {
    if(playerMove[j] == pegs[j])
      {
      gold++;
      player[j] = correct[j] = true;
      }
    }
  for(int y =0; y< cols; y++)
      if(!player[y])
	for(int x = 0; x< cols; x++)
	  if(!correct[x])
	    if(playerMove[y] == pegs[x])
	      {
	      silver++;
	      correct[x] = true;
	  }  
	  
  if(gold == cols)
    return 1;
  if(moves == MAX_MOVES-1)
    return -1;
  else 
    {
      moves++;
    return 0;
    }
  
}	

/*--------------------------------------------------------------
FUNCTION NAME: getMoveIndex
PARAMETERS: 
POSTCONDITION:The function adds 1 to the value of the private field "moves"
--------------------------------------------------------------*/
int mastermind::getMoveIndex()
{
  return moves+1;	
}

/*--------------------------------------------------------------
FUNCTION NAME: getNumberOfColumns
PARAMETERS:
POSTCONDITION: the function returns the number of columns.
--------------------------------------------------------------*/
int mastermind::getNumberOfColumns()
{
  return cols;
}
