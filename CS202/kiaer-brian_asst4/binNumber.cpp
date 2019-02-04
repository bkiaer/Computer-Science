#include "binNumber.h"
#include <iostream>
#include <string>
using namespace std;
/*----------------------------------------------------
Default Constructor
PARAMETERS: numString
POSTCONDITION: Initialized numString to be set to 0.
----------------------------------------------------*/
binNumber::binNumber()
{
  numString ="0"; 	
}
/*----------------------------------------------------
Constructor
PARAMETERS: literal string. 
POSTCONDITION: If string "literal" starts with a 0 then erase that digit until 1.
----------------------------------------------------*/
binNumber::binNumber(string literal)
{
  bool check=false;
  while(!check)
    {
     if(literal[0]== '0')
  literal.erase(0,1);
     else 
       check = true;
    }
  numString = literal; 
}
/*----------------------------------------------------
OPERATOR OVERLOADED: "="
PARAMETERS: literal string. 
POSTCONDITION: To assign literal string to numstring and to erase leading 0's. 
----------------------------------------------------*/
binNumber& binNumber::operator=(string literal)
{
  bool check = false;
  while(!check)
    {
  if(literal[0] == '0')
  literal.erase(0,1);
  else
    check = true;
    }
  numString = literal; 
	return *this; 
}
/*----------------------------------------------------
OPERATOR OVERLOADED: + class(string)
PARAMETERS: const binNumber bNum
POSTCONDITION: This operator overload is responsible for adding two strings that belong to two 
different classes. This will compare the two strings until they are equal lengths and then
convert them to integers by subtracting 0 and then returning the sum. 
----------------------------------------------------*/
binNumber binNumber::operator+(const binNumber& bNum) const
{
  string num1 = numString;
  string num2 = bNum.numString;
  if(num1.length()<num2.length())
    while(num1.length() != num2.length())
      num1 = "0" + num1; 
  else
    while(num1.length() != num2.length())
      num2 = "0" + num2;
  int carryOver = 0;
  string sum;
  sum.resize(num1.length());
  for(int i = num1.length()-1; i >= 0; i--)
    {
      int n1 = num1[i] - '0'; //Converts '1' or '0' at num1[i] to an integer 1 or 0
      int n2 = num2[i] - '0'; //Converts '1' or '0' at num2[i] to an integer 1 or 0
      int result = n1 + n2 + carryOver;
      carryOver = result /2 ;
      result = result%2;
      sum[i] = result + '0';
    }
  if(carryOver > 0)
    sum = "1" + sum;
  return binNumber(sum);
}
/*----------------------------------------------------
OPERATOR OVERLOADED: + string
PARAMETERS: string literal. 
POSTCONDITION: Passes a string but string gets copied into a temporary class.
Function then overloads "+" and returns the result. 
----------------------------------------------------*/
binNumber binNumber::operator+(string literal) const
{
  binNumber rhs(literal);
  binNumber lhs(numString);
  binNumber result;
  result = lhs + rhs;
  return binNumber(result);
}
/*----------------------------------------------------
OPERATOR OVERLOADED: - class(string)
PARAMETERS: const binNumber bNum
POSTCONDITION: Function copies the parameters strings into temp classes, and then
converts performs two's complement to the right hand side string. After that the function
will overload the + operator to add '1' then furthermore, the function will overload the "+" 
operator again to add the left hand side. Finally, the function will erase unneeded carries that
were resulted from the adding operations. 
----------------------------------------------------*/
binNumber binNumber::operator-(const binNumber& bNum) const
{
  binNumber temp1(numString);
  binNumber temp2(bNum.numString);
  binNumber tempresult;
  int size; 
  int check;
  string tmp;
  tmp = bNum.numString;
   if(numString.length()>tmp.length())
     {
   while(numString.length()!= tmp.length())
     tmp = "0" + tmp; 
     }
   size = tmp.length();
  for(int i = 0; i < size; i++)
    {
      if(tmp[i] == 48) // 48 and 49 are the ASCII Values for 0 and 1. 
	tmp[i] = 49;
      else
	if(tmp[i] == 49)
	  tmp[i] = 48;
    }
      temp2 = tmp;
      tempresult =  temp2 +"1";
    tempresult =  temp1 + tempresult;
    if(numString.length() > bNum.numString.length())
     tempresult.numString.erase(0,1);
    if(tempresult.numString[0] == '0')
   tempresult.numString.erase(0,1);
    if(numString == bNum.numString)
    tempresult.numString = "0";
  
  return binNumber(tempresult);
    
}
/*----------------------------------------------------
OPERATOR OVERLOADED: - string;
PARAMETERS: string literal;
POSTCONDITION: the string will be copied into a temporary class and then the
"-" operator will be overloaded and the result will be returned. 
----------------------------------------------------*/
binNumber binNumber::operator-(string literal) const
{
  binNumber rhs(literal);
  binNumber lhs(numString);
  binNumber result;
  result = lhs - rhs;
  return binNumber(result);
	
}
/*----------------------------------------------------
OPERATOR OVERLOADED: "==" 
PARAMETERS: binNumber bNum;
POSTCONDITION: 
----------------------------------------------------*/
bool binNumber::operator==(const binNumber& bNum) const
{
  bool check = true; 
  if(numString.length() == bNum.numString.length())
    for(int i = 0; i < numString.length() ; i++)
      if(numString[i] != bNum.numString[i])
	check = false;
    if(check == false) 
    return false;
    if(check == true)
      return true;
}
/*----------------------------------------------------
OPERATOR OVERLOADED: != 
PARAMETERS: binNumber bNum;
POSTCONDITION: function will check if length of strings are different and return true
if they are equal then there will be a for loop that will compare each char in the string until 
proven not equal. 
----------------------------------------------------*/
bool binNumber::operator!=(const binNumber& bNum) const
{
  bool check = true;
  if(numString.length() != bNum.numString.length())
    return true; 
  else
    for(int i = 0; i < numString.length(); i++)
      {
	if(numString[i] != bNum.numString[i])
	  return true; 
	else 
	  check = false;
      }
  if(check == true)
    return true; 
  else
    return false;
	  
}
/*----------------------------------------------------
OPERATOR OVERLOADED: <
PARAMETERS: binNumber bNum
POSTCONDITION: compare the sizes of the string with if statements if they are equal
then check which string has the highest most significant bit. Returns a bool statement regarding
the higher string.  
----------------------------------------------------*/
bool binNumber::operator<(const binNumber& bNum) const
{
  bool check;
   if(numString.length()>bNum.numString.length())
    return false;
  if(numString.length()<bNum.numString.length())
    return true;
  if(numString.length() == bNum.numString.length())
    {
      for(int i = 0; i < numString.length(); i++)
	{
	  if(numString[i] != bNum.numString[i])
	    if(bNum.numString[i] == '1')
	      return true;
	    else 
	      return false;
	}
    }

}
/*----------------------------------------------------
OPERATOR OVERLOADED: >
PARAMETERS: binNumber bNum
POSTCONDITION: compares the sizes of the string with if statements 
if they are equal the function will return a bool statement in regards
to which string has the highest significant bit. 
----------------------------------------------------*/
bool binNumber::operator>(const binNumber& bNum) const
{
  bool check; 
  if(numString.length() > bNum.numString.length())
    return true;
  if(numString.length() < bNum.numString.length())
    return false;
  if(numString.length() == bNum.numString.length())
    {
      for(int i = 0; i < numString.length()-1; i++)
	{
	  if(numString[i] != bNum.numString[i])
	    if(numString[i] == '1')
	      return true;
	    else 
	      return false;
	}
    }
}
/*----------------------------------------------------
OPERATOR OVERLOADED: <=
PARAMETERS: binNumber bNum
POSTCONDITION: the function will overload the operator <= and return a bool
function in regards to the operator. Uses if statements that overload operators such as
"==" "<" and ">".
----------------------------------------------------*/
bool binNumber::operator<=(const binNumber& bNum) const
{
  bool check;
  binNumber temp1 = numString;
  binNumber temp2 = bNum.numString;
  if(temp1 < temp2)
    check = true;
  if(temp1 == temp2)
    check = true;
  if(check == true)
    return true;
  else 
    return false;
 
  
}
/*----------------------------------------------------
OPERATOR OVERLOADED: >= 
PARAMETERS: binNumber bNum
POSTCONDITION: compares the two temporary classes numStrings by using if statements. 
The if statements use operator overloading for the comparisons. 
----------------------------------------------------*/
bool binNumber::operator>=(const binNumber& bNum) const
{
  bool check;
  binNumber temp1 = numString;
  binNumber temp2 = bNum.numString;
  if(temp1 > temp2)
    check = true;
  if(temp1 == temp2)
    check = true;
  if(check == true)
    return true;
  else 
    return false; 
    }
/*----------------------------------------------------
OPERATOR OVERLOADED: string + class
PARAMETERS: string lhs, binNumber rhs
POSTCONDITION: uses the friend functions to access private fields of the rhs class. 
then copies them into temporary classes and overloads the + operator. 
----------------------------------------------------*/
binNumber operator+(string lhs, const binNumber& rhs)
{
  binNumber temp1(lhs);
  binNumber temp2(rhs.numString);
  binNumber result; 
  result = temp1 + temp2; 
  return binNumber(result); 
}
/*----------------------------------------------------
OPERATOR OVERLOADED: string - class
PARAMETERS: string lhs, binNumber rhs
POSTCONDITION: copies the strings into temporary classes and then overloads the 
- operator and returns the result. 
----------------------------------------------------*/
binNumber operator-(string lhs, const binNumber& rhs)
{
  binNumber temp1(lhs);
  binNumber temp2(rhs.numString);
  binNumber result;
  result = temp1 - temp2;
  return binNumber(result);
}
/*----------------------------------------------------
  OPERATOR OVERLOADED: <<
PARAMETERS: ostream out, binNumber bNum
POSTCONDITION: overloads the << operator to display the string in the class. 
----------------------------------------------------*/
ostream& operator<<(ostream& out, const binNumber& bNum)
{
  out << bNum.numString;

	return out;
 }

