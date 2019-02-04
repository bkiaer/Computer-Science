//Brian Kiaer, Assignment #2, CS 202-1002. 
//This code's purpose is to open a .txt file through filestream and use it as a database. The code will prompt the user to input an attribute and a type of attribute, if the attribute's were correct then the code will search through all the cars in the database and output the statistics of the cars that match the chosen attributes. The code will continue to prompt the user to input attributes until the user types in 'q'. If the user types in an invalid attribute then the code will display an error message and continue to ask to try again. 

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct automobile
{
  string make;
  string model;
  unsigned int year;
  string engine;
  string color;
};

const unsigned int DEALERSHIP_SIZE = 20;
void lowercase(string&); //void function prototype to make the input incase-sensitive.
bool  checktype(string); //value-returning function prototype that returns a bool value.
 
int main (int args, char * argv[])
{ 
  automobile cars[DEALERSHIP_SIZE]; //Array of cars
  string type1;//input variable for attribute.
  string type2;//input variable to search/compare with struct values.
  bool check=0;//bool variable to check if attribute is valid.
  int type3;  //input value to compare the value for year.

  ifstream in;
  in.open(argv[1]); //attempt to open the filename given by the commandline

  if (!in.is_open()) //if file is not found
    {
      cout << "File not found!" << endl;
      in.close();
      return 0;
    }
  in>> cars[0].make >> cars[0].model >> cars[0].year >> cars[0].engine>> cars[0].color;//read & store values into struct.
  for(int i=1; i<DEALERSHIP_SIZE; i++)
    {
      in>>cars[i].make>> cars[i].model>> cars[i].year >>cars[i].engine>> cars[i].color;//read & store values till all 20 cars have been stored. 
    }
  while(type1 != "q") //while loop until user inputs "q" to quit the program.
    {
      type1 =""; //reset attribute 
      type2 = "";//reset type of attribute
      type3 = 0;
      cout << ""<<endl;
      cout <<"Enter search type or 'q' to quit: ";
      cin >> type1; //read attribute
      lowercase(type1);//format attribute
      check = checktype(type1); //return bool value if attribute is incorrect.
      if(type1 == "Q")//quit program if "q" is inputted (It is capital Q because it goes through the lowercase function)
	 return 0;
      if(type1=="Year")//if attribute: Year was typed read in an integer value instead.
	{
	  cin>>type3;
	  type2 ="0";
	}

      if(check == 0)//if attribute was not valid display error message. 
	{
	cout << endl << "Invalid Input! Try Again. "<< endl;
	cin.ignore(100,'\n');
	}
      if( type1 == "Make" || type1 =="Model" || type1 == "Engine"|| type1 == "Color")//read type of attribute if not "Year"
	  cin>> type2;
      lowercase(type2);   //format type of attribute
      for(int i = 0; i < DEALERSHIP_SIZE; i++) //for loop to search through all struct variables in car to look for "type2" attributes.
  {
   if(cars[i].year == type3 ||cars[i].make == type2 || cars[i].model ==type2  || cars[i].engine == type2 || cars[i].color == type2)
  {
    cout << ""<<endl;
  cout << "Make : " << cars[i].make << endl;
  cout << "Model : "<< cars[i].model << endl;
  cout << "Year : "<< cars[i].year << endl;
  cout << "Engine : "<< cars[i].engine <<endl;
  cout << "Color : "<<cars[i].color << endl;
      }
  }
    }
  in.close();//close filestream
  return 0; 
}
void lowercase(string& type)//function that passes by reference to reformat the strings being inputted.
{
  int j = type.size();
  type[0] = toupper(type[0]);
  for(int i =1; i<j; i++)
      type[i] = tolower(type[i]);
  if(type == "4-cylinder") //reformat "4-cylinder" to capitalize Cylinder.
    type[2]=toupper(type[2]);
      
}
bool checktype(string type)//value-returning bool function to check if attribute was valid. 
{
  if(type == "Make" || type== "Model" || type == "Year" || type == "Engine"|| type=="Color")
      return true;
  else
  return false;

}
    


       
