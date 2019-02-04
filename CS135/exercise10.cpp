#include <iostream>
#include <cctype>
#include <string>
using namespace std;


void reformat (string&);

int main()
{
  cout <<"Brian Kiaer, Lec#1010, Lab#1005, Ex#10" << endl;
  string title;
  int size;
  getline(cin,title);
    while (cin)
    {
      size=title.length();
      reformat(title);
      for(int i=0;i<size;i++)
	{
	if(title[i-1]==' ')
	  title[i]=toupper(title[i]);
	} 
      cout << title << endl;
      getline(cin,title);
      
    }	
}

void reformat (string& title)
{
  int word_length;
  word_length = title.length();
  title [0] = toupper(title[0]);
  for (int i=1; i<word_length; i++)
    {
      title[i]=tolower(title[i]);
	for(int count=0;title[i]==' '&& title[i+1]==' ';count++)
	     {
	     title.erase(i,count);
	     count=0;
	     }
    }

	
    

}
