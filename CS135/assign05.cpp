//Brian Kiaer, Lecture#1010, Assignment#5
//The expected input from an input file is  the customer's name in random format, the time their transaction started in military time and what time the transaction ended in military times.
//The expected output will be put into an output file created by the program, it will display my name and credentials,it will display the catergories such as name, times, and seconds, it will display the name of the customer with a capitalized first letter and lowercase letters following that, it will space out the times to be right justified with the categories, it will also provide leading zeros to the numbers that aren't double digits, it will also calculate the amount of seconds they had to wait for their order. On the bottom of the formatted output, the calculated average time would be displayed with two decimal places, with the standard deviation, and median of the data with one decimal place to the right if the number of data is even.
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<cmath>
using namespace std;
void reformat_name(string&);
int seconds(int&,int[],int[]);
double variance(double&,int [], double&,int&);
void median(int [],int&,double&,ofstream&);
int main()
{
  ifstream infile;  //necessary variable to read file through fstream
  string indata;    //to convert the input file into a string
  ofstream outfile; //necessary variable to stream the output to an output file
  string name;      //string to read the names of the customer
  int start[3];     //array to read start times hours, minutes, seconds
  int endt[3];      //array to read end times hours,minutes, seconds
  int data[50];     //array to store total seconds up to 50 times
  int sec;          //variable to store total seconds
  int count=0;      //variable to count how many customers are helped
  double faverage;  //variable to store the Average
  double deviation; //variable to store the standard deviation
  double median1;   //variable to store the median
  double variance1; //variable to store the variance
  char colon;       //character to store the colon in between hours, minutes, and seconds
  cout<<"What is the name of the input file?"<< endl;
  cin>> indata;

  infile.open(indata.c_str());
  outfile.open("kiaerprog05out");

  outfile <<"Brian Kiaer Sec#1010 Assignment#5" << endl;
  outfile <<""<<endl;
  outfile <<"NAME"<<setw(22)<<"START TIME"<<setw(13)<<"END TIME"<<setw(13)<<"TOTAL SECS"<<endl;
  infile >>name>>start[0]>>colon>>start[1]>>colon>>start[2]>>endt[0]>>colon>>endt[1]>>colon>>endt[2];
  while(infile)
    {
  reformat_name(name);
  seconds(sec,start,endt); 
  outfile << left <<setw(18)<<name << right << setfill('0')<< setw(2);
  outfile<< start[0]<<colon<<setfill('0')<<setw(2)<<start[1]<<colon<<setfill('0');
  outfile<< setw(2)<<start[2] << setw(5)<<setfill(' ');
  outfile <<"" <<setfill('0')<< setw(2)<<endt[0]<< colon;
  outfile <<setfill('0')<<setw(2)<< endt[1]<<colon<<left<<setfill('0')<<setw(2);
  outfile << endt[2]<<setw(10)<<setfill(' ')<<"";
  outfile<<right<<setw(3)<<sec<<endl;
  faverage=faverage+sec;
  infile >>name>>start[0]>>colon>>start[1]>>colon>>start[2]>>endt[0]>>colon>>endt[1]>>colon>>endt[2];
  data[count]=sec;
  count++;
    }
  outfile<<fixed<<setprecision(2)<<endl;
  faverage = faverage/count;
  variance(variance1,data,faverage,count);
  outfile <<"Average wait time: "<<faverage<<endl;
  outfile <<"Standard deviation: "<<sqrt(variance1)<<endl;
  median(data,count,median1,outfile);
  infile.close();
  outfile.close();
}
void reformat_name(string& fname) //This functions purpose is to reformat the customer's name to capitalize the first letter and then loweracse the following letters. The string fname is passed to the main function's name address. 
  {
    int n;
    n=fname.length();
    fname[0]=toupper(fname[0]);
    for(int i=1;i<n;i++)
      fname[i]=tolower(fname[i]);
  }
int seconds(int& second, int start_time[], int end_time[]) //This function's purpose is to return 1 int value back to the main function for second, the function goes through a series of if statements to calculate how long the customer had to wait. The start time and end time arrays are passed back and forth to compare each other. 
{
  if(start_time[2]<=end_time[2])
    {
    if(start_time[1]<=end_time[1])
      second=60*(end_time[1]-start_time[1])+(end_time[2]-start_time[2]);
    }
  if(start_time[2]>end_time[2])
    {
      if(start_time[1]<end_time[1])
	second=(60*(end_time[1]-start_time[1]))-(start_time[2]-end_time[2]);
      if(start_time[1]>end_time[1])
	second=(60*(60-start_time[1]+end_time[1])-(start_time[2]-end_time[2]));	  
    }
  
}
double variance(double& variance,int data[], double& faverage,int& i) //The purpose of this function is to calculate the variance and return it back to the main function to calculate standard deviation. The data array, faverage, and count is passed into the function and passed back to be implemented into the main function
{
  for(int j=0;j<i;j++)
    variance =  (pow((data[j]-faverage),2) + variance);
  variance = variance/(i-1);
}
void median(int data[],int& count,double& median2, ofstream& outfile) //This function is to order the data into ascending order and calculate the median of all the data calculated. The array data, the counter and the median variable are alll passed back to the main function to be implemented into the output. 
{
  int temp;
  int med;
  int n;
  for(int i=0; i< count-1;i++)
    for(int j=0; j < count-(i+1);j++)
      {
      if(data[j+1]<data[j])
	{
	  temp=data[j];
	  data[j]=data[j+1];
	  data[j+1]= temp;
	}
      }
  if((count)%2 == 0)
    {
      med= count/2;
      median2 = static_cast<double>(data[med-1]+data[med])/2.0;
      outfile<<setprecision(1);
      outfile <<"Median: "<< median2<<endl;
    }
else
  if(count%2!=0)
    {
    med = ((count-1)/2);
  outfile <<"Median: "<< data[med]<< endl;
    }
}
