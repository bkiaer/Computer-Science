//Brian Kiaer, CS 202-1002, Assignment #1, This code is written to check words from an input file and check if they are Palindrome words, meaning they can be read from left to right or right to left. The code uses a value returning function to state if the word is "true" (is a palindrome) or "false" (not a palindrome). Depending on the value that is being returned an output statement will be displayed.                                                                                                                                        
#include <iostream>
#include <string>
#include <cctype>
  using namespace std;

bool isPalindrome(string);  //value-returning function prototype                                                                                                                     

int main ()
{
  string data;
  string palindrome;
  bool check;
  cin>>palindrome;        //read the first word in input file.                                                                                                                       
  while(cin)              //while loop that reads until end of file.                                                                                                                 
    {
      check = isPalindrome(palindrome);  //function call and returns a bool value                                                                                                    
      if(check == true)                  //if true then word is a palindrome                                                                                                         
	cout << palindrome << " is a Palindrome" << endl;
      else                               //if false then word is not a palindrome                                                                                                    
	cout << palindrome << " is not a Palindrome" << endl;
      cin>>palindrome;                       //continue to read input file until end of file.                                                                                        
    }
  return 0;
}
bool isPalindrome (string palindrome)   //function definition that passes the string from the input and returns a bool value                                                         
{
  int j=0;
  int k=0;
  j = palindrome.size();
  k = j;
  for(int i=0; i<=k; i++)
    {
      if(tolower(palindrome[i]) != tolower(palindrome[j-1])) //lower case letters to ensure it is not case sensitive.                                                              
	return false; //return false if values are not equal                                                                                                                       
      else
	j--;
    }
  return true; //if values are all equal than return true that the input word is a palindrome.                                                                                     
}
