#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;
void reformat_name(string&);
int main()
{
  ifstream infile;
  string indata;
  ofstream outfile;
  string name;
  int start[2];
  int endt[6];
  char colon; 
  cout<<"What is the name of the input file?"<< endl;
  cin>> indata;

  infile.open(indata.c_str());
  outfile.open("kiaerprog05out");
  
  outfile <<"Brian Kiaer Sec#1010 Assignment#5" << endl;
  outfile <<""<<endl;
  outfile <<"NAME"<<setw(22)<<"START TIME"<<setw(13)<<"END TIME"<<setw(13)<<"TOTAL SECS"<<endl;
  infile >>name;
  while(infile)
    {
  reformat_name(name);
  for(int i=0;i<2;i++)
    infile>>start[i];
  outfile<< name << setw(13) <<start[1] << start[0];
  infile>>name;
    }
  infile.close();
  outfile.close();
  return 0;
}
void reformat_name(string& fname)
{  
  int n;
  n=fname.length();
  fname[0]=toupper(fname[0]);
  for(int i=1;i<n;i++)
    fname[i]=tolower(fname[i]);
}
