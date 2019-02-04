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
using namespace std;

void draw_rectangle(int,int,char);

int main()
{
  int vlength,hwidth;   //the vertical length and horizontal width of a rectangle
  char symbol;          //character used for the border of the rectangle
  cin >> vlength;
  while (cin)
    {
      cin >> hwidth >> symbol;
      draw_rectangle(vlength,hwidth,symbol);
      cout << endl;
      cin >> vlength;
    }
}
void draw_rectangle(int length, int width, char draw)
//Given the vertical length and horizontal width of a rectangle along with
//a character to be used for drawing it, if both length and width are >= 2,
//display the outline of the rectangle with a label that includes the length
//and width. If the length and/or the width are less than 2, display a message
//stating that the rectangle will not be drawn. Include the requested dimensions
//in the message.
{

}
