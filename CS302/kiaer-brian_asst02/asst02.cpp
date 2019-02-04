#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

template <class Type>
class stack
{
public: 
  stack (); 
  stack (const stack<Type>&);
  const stack<Type>& operator=(const stack<Type>&);
  ~stack ();

  void push(const Type&);
  void pop();
  Type top() const;
  bool isEmpty() const;

private: 
  struct node
  {
    Type item;
    node*next;
  };

  node * topOfStack;
};

int main ()
{
  string input; 
  string output;
  bool check;
  bool check_char;
  stack<char> object;
  cout <<"Enter an infix string"<< endl;
  getline(cin, input); 
     for(int i = 0; i < input.length(); i ++)
       {

	 if(input[i]!= '+' && input[i] != '-' && input[i] != '*' && input[i] != '/') //check for any invalid characters
	   if(input[i] != '(' && input[i] != ')' && input[i] != ' ')
	     if(input[i] < '0' || input[i] > '9')
	       check_char = true;
	
      	 while(input[i] == ' ') //skip any blank spaces in the expression 
       	    i++;
	 if(input[i] != 32) //double checks that blank spaces are not included 
	{       
	  if(input[i] >= '0' && input[i] <= '9') //if input[i] is a digit the program will put that character at the end of the output string. 
	    {
	    output = output + input[i];
	    
	    }
	  else
	    {
	      if(input[i] == '(') //if '(' character appears it will push it onto the stack until the outer paranthesis is reached.
		object.push(input[i]);
	      else
		{
		  if(input[i] == '+' || input[i] == '-') //check for + or - operators
		    {
		      
		      if(object.isEmpty() == true)//if stack is empty than push onto stack
			{
			  object.push(input[i]);
		       
		          
			}
		      else
			{
		       
			  while (object.isEmpty() == false && object.top() != '(') //keep looping until the stack is either empty or a '(' is on the top of the stack 
			    {
			      
			      if(object.top() == '+' || object.top() == '-' || object.top() == '*' || object.top() == '/')
				{
				  output = output+object.top(); //if top is an operator it will add it to the output string and pop it off the stack until the while loop finishes.
				   object.pop();
				   
				}	
			    }
			  object.push(input[i]);//when all done the input[i] will be pushed onto the stack
			}	          
		    }
		  else
		    {
		      if(input[i] == '*' || input[i] == '/') //check for * or / operators
			{
			  if(object.isEmpty() == true)//if empty stack then push char onto stack.
			    object.push(input[i]);
			  else
			    {
			      while(object.isEmpty() == false && object.top() != '(' && object.top() != '+' && object.top() != '-') 
				{
				  if(object.top() == '*'|| object.top() == '/')
				    {
				      output = output + object.top(); //keep adding to the output string until loop has reached a certain operator on the stack or is empty.
				      object.pop();
				    }
				}
			      object.push(input[i]); //at the end push the char onto the stack.
			    }
			}
		    }
	    	  if(input[i] == ')') //when outer paranthesis has been reached then proceed with checking for the pair. 
		    {
		      if(object.isEmpty()==false)
			output = output + object.top(); //if the stack is not empty add to the output string.
		      if(object.isEmpty() == true) // if the stack is empty then there is a mismatch in paranthesis
			check = true;
		      else
			{
			  while(object.top() != '('&&object.isEmpty() == false)
			{
		          output = output + object.top();
			  object.pop(); //keep popping until the other paranthesis has been met.
			  
			  }
			  if(object.isEmpty() == true)
			    check = true; 
			  object.pop(); // then pop that paranthesis
			}
		      }

		}
	    }
	}
		 
       }
	   
     if(object.isEmpty() == false)
       while(object.isEmpty() == false)
	 {
	   if(object.top() == '(')
	     check = true;
	 output = output + object.top();
	 object.pop();
	 }
     if(check_char == true)
       cout <<"Invalid character(s) in the expression!" << endl << endl;
     else
       {
     if(check == true)
       cout <<"No matching paranthesis" << endl << endl;
     else
       {
     cout << "Equivalent post fix string" << endl;
     cout << output << endl << endl;
       }
       }
  return 0;
}
template<class Type>
stack<Type>::stack()
{
  topOfStack = NULL; 
}


template <class Type>
stack<Type>::stack(const stack<Type>& copy)
{
  
  node * tmp; 
  tmp = copy.topOfStack; 
  stack<char> stk; 

  while(tmp != NULL)
    {
      stk.push(tmp->item);
      tmp = tmp->link;
    }
  while(stk.isEmpty() == false)
    {
      push(stk.top());
      stk.pop();
    }
  this->topOfStack;
}

template <class Type>
const stack<Type>& stack<Type>::operator=(const stack<Type>& rhs)
{
  
 node * tmp;
  tmp = rhs.topOfStack;
  stack<char> stk;
  while(tmp != NULL)
    {
      stk.push(tmp->item);
      tmp = tmp -> link;
    }
  while(stk.isEmpty() == false)
    {
      push(stk.top());
      stk.pop();
    }
  this->topOfStack; 
}

template <class Type>
stack<Type>::~stack()
{
 
     while(isEmpty() == false)
    {
      pop(); 
      }
}

template <class Type>
void stack<Type>::push(const Type& x)
{
  node * tmp;
  tmp = new node; 
  tmp -> item = x;
  if(topOfStack == NULL)
    {
      topOfStack = tmp;
      topOfStack -> next = NULL;
      //      tmp = NULL;
    }
  else
    {
    tmp -> next = topOfStack; 
  topOfStack = tmp;
    }
  
    
}

template <class Type>
void stack<Type>::pop()
{
   if(topOfStack != NULL)
       {
    node * tmp;
    tmp = topOfStack->next;
    topOfStack = tmp;
     }
     
  
   
}

template <class Type>
Type stack<Type>::top() const
{ 
      return topOfStack->item;       
}

template <class Type> 
bool stack<Type>::isEmpty()const
{
  if(topOfStack == NULL)
    return true;
  else
    return false;
}

