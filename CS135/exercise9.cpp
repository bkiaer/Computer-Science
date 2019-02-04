#include <iostream>
#include <cctype>//include any additional header files needed by program
using namespace std;
bool consonant_checker (char);// insert function prototype for consonant checking function
bool vowel_checker (char);// insert function prototype for lowercase vowel checking function
int main()
{
  int consonants = 0; //consonant counter
  int vowels = 0;     //vowel counter
  char inputch;       //current input character
  bool valid=true;
  cout <<"Brian Kiaer, Lec#1010, Lab#1005, Ex9" <<endl;  // insert print statement to display name, lec and lab #s, exercise#

  cin >> inputch;
  while (cin)
    {
      if (valid=consonant_checker(inputch))
	consonants++;
      if (valid=vowel_checker(inputch))
	vowels++;
      cin >> inputch;
    }
  cout << "There were " << consonants 
       << " consonants found in the file." << endl;
  cout << "There were " << vowels 
       << " lowercase vowels found in the file." << endl;
  return 0;
}
bool consonant_checker (char inputch)
{
  inputch = tolower (inputch);
  if (inputch < 'A'|| inputch > 'Z' && inputch < 'a'|| inputch > 'z' )
    return false; 
    if (inputch == 'a' || inputch == 'e' ||inputch == 'i' ||inputch == 'o' || inputch =='u')
      return false;
    else return true;
}
bool vowel_checker (char inputch)
{
  if( inputch == 'a' || inputch == 'e' ||inputch == 'i' ||inputch == 'o' || inputch =='u')
    return true;
  else return false;
}
// Place function definition for consonant checker here.
// Place function definition for vowel checker here.

