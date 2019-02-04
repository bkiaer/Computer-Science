//Brian Kiaer, Lecture#1010, Assignment#4
//The input for this program is through Linux Redirection, the expected input from the source file is last name of the family first, their marital status, the number of the dependents being declared followed by the names of the dependents (including themselves), their gross income followed by the amount of taxes withheld, after that they will declare what type of deduction is being followed (standard or itemized) if it is itemized the amount of itemized deductions are added up until the file hits a "0." 
//The output for this program will display the Tax summary of each family with their name, their filing status if they are married or single, the names of each dependent with the first letter capitalized and the rest lowercase and each name seperated with a comma,the gross income given through the input with a dollar sign beside it, the amount of exemptions calculated by the number of dependents times 1200, if they have a standard deduction they will have - 3000, if they have an itemized deduction the amounts given will be added up; however, if the sum of the itemized deduction is less than 3000 they will have a standard deduction instead. Then the taxable income will be calculated by adding the total exemptions and the total deductions and subtracting that from the gross income; however, if that amount is higher than the gross income then their taxable income will equal 0.  Thus, making their Tax Payable category equal 0 as well. Also the tax rate will be displayed for each family and depends on if they are single or married and how much their taxable income is. The Tax Payable Category displayed is the rate provided times the calculated taxable income. The taxes withheld is displayed with "-" and  the amount of money provided from the input and lastly the taxes due category is the amount of taxes withheld minus the taxes payable; however, if the amount goes below 0 that means that the category will become "Refund Due" and it will have a dollar sign with a positive amount of money that was supposed to be negative. 
#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>

using namespace std;
const double STANDARD = 3000; //constant for the amount of Standard Deduction because the amount stays the same. 
const double PERCENT=100;    //constant for calculating percent for finding the rate variable
void reformat_name(string&);
void marital_status(string&);
void number_dependents(string&,double&);
void tax_rate(int&, string&, double&);
char standard_itemized(char&);
int main ()
{
  string name;              //string to find the family name 
  string status;            //string to read the marital status 
  string dependents;        //string to store the names of each dependent declared
  char  deduction;          //to find the first char of the deduction type if it is an 's' or 'i'
  int rate;                 //integer to provide what is the rate of each family
  double income;            //the variable for the gross income
  double exemptions;        //the variable to calculate the total amount of exemptions per how much is declared
  double itemized;          //the variable to store the amounts given for the itemized deductions 
  double final_itemized;    //the variable to calculate the sum of the itemized amounts
  double taxable_income;    //the variable to calculate the taxable income after deductions
  double taxes_payable;     //the variable for taxes payable after the rate has been calculated with the taxable income
  double withheld;          //the variable to stroe the taxes withheld
  double taxes_refund;      //the variable to store the amount of taxes due or refund due
  cin>>name;
  while(cin)
    {
    reformat_name(name);
    marital_status(status);
    number_dependents(dependents, exemptions);
    cin>>income;
    cin>>withheld;
    standard_itemized(deduction);
    cout << fixed << setprecision(2) <<endl; 
    cout << "Tax summary for "<< name <<" family" << endl;
    cout << "Filing status: "<< status << endl;
    cout << "Dependents: " << dependents << endl;
    cout << "Gross income: " <<setw(7)<<"$"<<setw(10)<< income << endl;
    cout <<"Exemptions: "<<setw(9)<<"-"<< setw(10)<<exemptions << endl;
    if(deduction=='s')
      {
      cout <<"Standard deduction: -" <<setw(10)<<STANDARD<< endl;
      final_itemized=STANDARD;
      }
    else
      if(deduction=='i')
	{
        cin>>itemized;
	final_itemized =0;
	while(itemized!=0)
	  {
	  
	    final_itemized = final_itemized + itemized;
	    itemized=final_itemized;
	    cin>>itemized;
	  }
	if(final_itemized<3000)
	  {
	  cout <<"Standard deduction: -" <<setw(10)<<STANDARD<< endl;
	  final_itemized=STANDARD;
	  }
	else
	cout <<"Itemized deduction: -" <<setw(10)<< final_itemized <<endl;
	}
    taxable_income=income-(exemptions+final_itemized);
    if(taxable_income>0)
      cout <<"Taxable income: "<<setw(15)<<taxable_income<< endl;
    else 
      {
      taxable_income=0;
    cout <<"Taxable income: "<<setw(15)<<taxable_income<< endl;
      }
    tax_rate(rate, status, taxable_income);
    cout <<"Tax rate: "<< setw(21)<<rate<<"%"<<endl;
    taxes_payable=taxable_income*(rate/PERCENT);
    cout <<"Taxes payable: "<<setw(16)<<taxes_payable<<endl;
    cout <<"Taxes withheld: "<<setw(5)<<"-"<<setw(10)<<withheld<<endl;
    taxes_refund=taxes_payable-withheld;
    if(taxes_refund<0)
      cout<<"Refund due: "<<setw(9)<<"$"<<setw(10)<<-1*taxes_refund<<endl;
    else
    cout <<"Taxes Due: "<<setw(10)<<"$"<<setw(10)<<taxes_refund<<endl;
    cin>>name;
    }
}
void reformat_name(string& last_name ) //This function is to reformat the family name and capitalize the first letter and lowercase the rest of the name. The string last_name gets passed an unformatted last name and passes the name of the family back into the main function.
{
  int n=last_name.length();  //n is to store the amount of characters in the string
  last_name[0]=toupper(last_name[0]);
  for(int i=1;i<n;i++)       //i is to count each subscript in the string 
    {
    last_name[i]=tolower(last_name[i]);
    }
}
void marital_status(string& status) //This function is to reformat and read the families marital status if they are single or married and make sure that the first letter is capitalized and the rest are lower case. The string status gets passed an unformatted word and  passes the reformatted string back to the function. 
{
  cin>>status;
  int n1=status.length();   //n1 is to store the amount of characters in the string
  status[0]=toupper(status[0]);
  for (int a=1;a<n1;a++)    //a is to count each subscript in the string
    status[a]=tolower(status[a]);
}
void number_dependents(string& dependents, double& exemptions) //This function is used to count how many dependents are being declared, how much the exemptions would cost, and to reformat the names of each dependent and seperate them by a comma. The string dependents passes back the reformatted names of the dependents with a capitalized first letter and lower case letters following. The variable exemptions passes back the amount being declared by each dependent.
{
  int number;              //is the variable to store the number of dependents
  int length;              //is the variable to store the amount of characters in the string
  string children;         //is the string to store the names of each dependent
  dependents="";
  cin>>number; 
  exemptions = number*1200;
  for(int b=0; b<number; b++)
    {
    cin>> children;
    children[0]=toupper(children[0]);
    length = children.length();
    for(int n=1;n<length; n++)
      {
      children[n]=tolower(children[n]);
    dependents[0]=toupper(dependents[0]);
      }
    if(b<number-1)
      children=children +  ", ";
  dependents = dependents + children;
    }
}
char standard_itemized(char& deduction) //This function is to pass back the value of the first letter of either an itemized or standard deduction, it will pass back either 'i' or 's' and that is how the main function will clarify what deduction is being used. 
{
  string type;           //this variable is to store the name of deduction either itemized or standard
  cin>>type;
   type[0]= tolower(type[0]);
    deduction=type[0];
}
void tax_rate(int& rate, string& status, double& taxable_income) //This function is to calculate the tax rate of each family, the variable for rate will pass back the rate tax rate to the main function, the string of status will take in if they are Married or Single, and the variable taxable_income will get the gross income calculated by the main function and will decide through this function what is the tax rate for the family. 
{
  if(taxable_income < 30000 && status[0] == 'S')
    rate=4;
  else
    if(taxable_income < 30000 && status[0]== 'M')
      rate=2;
  else 
    if(taxable_income>=30000 && taxable_income<100000 && status[0]== 'S')
      rate=8;
    else 
      if(taxable_income>=30000 && taxable_income<100000 && status[0]== 'M')
	rate=6;
      else 
	if(taxable_income>=100000 && taxable_income<1000000 && status[0]=='S')
	  rate=20;
	else 
	  if(taxable_income>=100000 && taxable_income<1000000 && status[0]=='M')
	    rate=18;
	  else 
	    if(taxable_income>=1000000 && status[0]=='S')
	      rate=35;
	    else 
	      if(taxable_income>=1000000 && status[0]=='M')
		rate=30;
}
