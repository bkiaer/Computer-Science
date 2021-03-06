#include<iostream>
#include<fstream>
#include<cstdlib>
#include<vector>
using namespace std;

template<class Type>
struct node
{
	Type item;
	node*link;
};

int dfs(struct node<int>**, node<int>*, vector<bool>&, vector<bool>, int);

int main(int args, char*argv[])
{
	string input_file(argv[2]);
	int nodes = atoi(argv[1]);
	ifstream infile; 
	int first;
	int second;

	infile.open(input_file.c_str());
	if (!infile.is_open())
	{
		cout << "Error, could not open file. Try again." << endl;
		return 0;
	}
	node<int> ** outNeighborList;
	vector<bool> processed;
	vector<bool> recStack;
	recStack.resize(nodes);
	processed.resize(nodes);
	int cycles = 0;
	for(int i = 0; i < nodes-1; i++)
	  {
	    processed[i] = false;
	    recStack[i] = false;
	  }
	outNeighborList = new node<int>*[nodes];
	for (int i = 0; i < nodes - 1; i++)
		outNeighborList[i] = NULL;


	infile >> first >> second;

	
	while (infile)
	{
		if (outNeighborList[first] == NULL)
		{
			outNeighborList[first] = new node<int>;
			outNeighborList[first]->item = second; 
			outNeighborList[first]->link = NULL;
			
		}
		else
		{
			node<int> *temp; 
			 
			temp = outNeighborList[first];
			outNeighborList[first]= new node<int>;
			outNeighborList[first]->item = second; 
			outNeighborList[first]->link = temp; 
		
		}
		infile >> first >> second; 
	}
	for (int i = 0; i < nodes - 1; i++)
	{
	  cycles = cycles + dfs(outNeighborList, outNeighborList[i], processed, recStack, i);

	}
      
	for (int i = 0; i < nodes; i++)
	{
		node<int>* it = outNeighborList[i];
		cout << i << ": "; 
		while (it != NULL )
		{
			cout << it->item << " -> ";
			it = it->link;
			if (it == NULL)
				cout << "NULL";
		}
		cout << endl;
	}
	cout << endl;
	cout << "The graph has " << cycles<< " cycle(s)" << endl;
	return 0;
}

/*-----------------------------------------------------------------
FUNCTION: Depth First Search
PARAMETERS: The adjaceny list, the current node, bool array processed, bool array recStack, index of current node
PURPOSE: The purpose of this function is to call depth first search and then find the number of cycles recursively 
for each node. 
  -------------------------------------------------------------------*/
int dfs(struct node<int>** list,struct node<int>* currentNode, vector<bool> &processed, vector<bool> recStack, int y)
{
   int x = currentNode->item;
    if(recStack[x] == true)
     {
       
       processed[y] = true;
     if(currentNode->link != NULL)
       return 1 + dfs(list, list[currentNode->link->item], processed, recStack,y);
     else
       return 1;
     }
  if(currentNode == NULL || processed[x] == true)
    {
     
      if(currentNode->link != NULL)
	return dfs(list, list[currentNode->link->item], processed, recStack,y);
      else
	return 0;
    }
  else
    {
      
      recStack[x] = true; 
      return  dfs(list, list[currentNode->item], processed, recStack,y);
     
      }
}
