#include <iostream>
#include <cctype>//include any additional header files needed by program
using namespace std;

bool consonant_checker(char);
bool vowel_checker (char);// insert function prototype for consonant checking function
// insert function prototype for lowercase vowel checking function

int main()
{
  int consonants = 0; //consonant counter
  int vowels = 0;     //vowel counter
  char inputch;       //current input character
  bool valid = true;

  cout << "Brian Kiaer, Lec#1010, Lab#1005, Ex#9" <<endl;

  cin >> inputch;
  cout << inputch <<endl;
  while (cin)
    {
      if (consonant_checker (char inputch))
       	consonants++;
      if (vowel_checker(char inputch))
	vowels++;
      cin >> inputch;
    }
  cout << "There were " << consonants 
       << " consonants found in the file." << endl;
  cout << "There were " << vowels 
       << " lowercase vowels found in the file." << endl;
  return 0;
}
bool consonant_checker (char inputch);
{
char  inputch = tolower (inputch);
    if(!inputch == 'a' || !inputch == 'e' ||!inputch == 'i' ||!inputch == 'o' || !inputch =='u')
      return true;
}
bool  vowel_checker (char inputch);
{
    if(inputch == 'a' ||inputch == 'e' ||inputch == 'i' ||inputch == 'o' || inputch =='u')
  return true;
}
 // Place function definition for consonant checker here.
// Place function definition for vowel checker here.

