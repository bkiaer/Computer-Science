//The purpose of this program is to draw a series of rectangles.
//Expected input: a file (via Linux redirection) that contains several sets
//of data. Each data set consists of 2 integers and a character. The first
//integer is the vertical length and the second integer is the horizontal
//width of a rectangle. The character is used for the drawing.
//Expected output: for each data set, a picture of a rectangle. Each picture
//will be labeled and there will be at least one blank line between each drawing.
//For example, if a data set is: 4 7 $ the output should be
//  4 by 7 Rectangle
//  $$$$$$$
//  $     $
//  $     $
//  $$$$$$$

#include <iostream>
#include <iomanip>
using namespace std;

void draw_rectangle(int,int,char);

int main()
{
  int vlength,hwidth;   //the vertical length and horizontal width of a rectangle
  char symbol;          //character used for the border of the rectangle
  cout << "Brian Kiaer, Lecture Section #1010 Lab Section #1005 Exercise#8" << endl;
  cin >> vlength;
  while (cin)
    {
      cin >> hwidth >> symbol;
      draw_rectangle(vlength,hwidth,symbol);
      cin >> vlength;
	}
}
void draw_rectangle(int vlength, int hwidth, char symbol)
//Given the vertical length and horizontal width of a rectangle along with
//a character to be used for drawing it, if both length and width are >= 2,
//display the outline of the rectangle with a label that includes the length
//and width. If the length and/or the width are less than 2, display a message
//stating that the rectangle will not be drawn. Include the requested dimensions
//in the message.
{
  if (vlength >=2 && hwidth >=2)
    {
      cout << vlength << " by " << hwidth << " Rectangle" << endl;
      for (int i=0; i<hwidth; i++)
	cout << symbol;
      cout << endl;
      for (int j=2; j <vlength; j++)
	cout << symbol << setw(hwidth-1)<< symbol << endl;
      for (int i=0; i<hwidth; i++)
	cout << symbol;
      cout <<""<<endl;
    }
  else
    {
      cout <<""<<endl;
      cout << "Length of " << vlength << " and/or width of " << hwidth << " is/are invalid." << endl;
      cout << "The rectangle will not be drawn." << endl;
      cout <<""<<endl;
    }

}
