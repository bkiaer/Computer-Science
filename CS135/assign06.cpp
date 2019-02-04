//Brian Kiaer, Lecture #1010, Assignment#6
//The input would be two files provided by the user, inside the first input file would consist a list of cars starting with the car's license plate, the make of the car, the model of the car, the type of the car given by a character. The second input file would consist of a list of license plates that would be rented; however some license plates may not match.
//The output would first consist of 5 columns seperating the license#, make, model,cartype, and that the car is available these are all implemented by the inventory file. Second the program will display that it is processing the rental cars by comparing the two input files and displaying the license# make and model and that it is being rented. Third there will be 5 columns again seperating the license#, make,model, car type, and status and it will display the information of the cars that were being rented. Fourth the code will  output a calculated price of a daily dollar amount according to the amount of carsbeing rented and what type of car type each car being rented is. Then it will display the amount of cars being rented and the cars that are available. Lastly, the 5 columns will be displayed again and show the information of each car again; however, it will show if the status is either rented or available.
#include<iostream>
#include<fstream>
#include<string>
#include<cctype>
#include<iomanip>
using namespace std;
const int  MAX = 40; //Maximum amount of cars in array 
const double PREM = 39.95; //price per rented premium car
const double STAN = 19.95; //price per rented standard car
const double COM = 11.95;  //price per rented compact car
struct cartype     //struct to hold the information of each car
{
  string license;  //string to store license number of car
  string make;     //string to store make of car
  string model;    //string to store model of car
  char category;   //char to store the category of the car
  bool status;     //bool to store if it is rented or available
};
void reformat(int&,cartype[], cartype&, ofstream&, ifstream&);
void rentals(int&,cartype[],cartype&, cartype&,ofstream&, ifstream&, ifstream&);
void rented_cars(int&,int&, cartype[], cartype[],ofstream&);
int main()
{
  cartype carinfo;  //struct to store information of car information
  cartype carinfo2; //struct to store and compare information of car
  cartype rented[MAX]; //array of a struct to store the rented car information 
  cartype avail[MAX];  //array of a struct to store the available car information
  ifstream infile_inventory; //ifstream to read the first input file
  ifstream infile_rental;   //ifstream to read the second input file
  string output; //string to store information of the outputfile
  string inventory; //string to store information of the first input file and the name of the file
  string rental;  //string to store information of the second input file and the name of the file
  ofstream outfile; //ofstream to output to the outputfile
  int count=0; //counts the cars being rented
  int available =0; //counts the cars that are available
  cout<<"Brian Kiaer, Lecture #1010, Assignment #5"<<endl<<endl;
  cout<<"Enter the name of the output file: "<< endl;
  cin>>output;
  cout<<"Enter name of inventory file: "<< endl;
  cin>>inventory;

  infile_inventory.open(inventory.c_str());
  outfile.open(output.c_str());

  outfile<<"Brian Kiaer  Assignment #6  Section #1010"<<endl<<endl;
  outfile<<"License#" <<setw(10)<<"Make"<<setw(13)<<"Model"<<setw(15)<<"Car Type"<<setw(9)<<"Status"<<endl;

  reformat(available,avail, carinfo,outfile,infile_inventory);

  cout <<"Enter rental file name: "<< endl;
  cin>>rental;

  infile_rental.open(rental.c_str());
  rentals(count,rented,carinfo,carinfo2,outfile,infile_rental,infile_inventory);
  outfile<<endl;
  outfile<< setw(14)<<"License#" <<setw(12)<<"Make"<<setw(12)<<"Model"<<setw(11)<<"Car Type"<<setw(9)<<"Status"<<endl;
  
  rented_cars(count,available,rented,avail,outfile);
    
  outfile.close();
  infile_rental.close();
  infile_inventory.close();
}
void reformat(int& available,cartype avail[],cartype& car, ofstream& outfile, ifstream& infile )//this function's purpose is to display 5 columns representing the license plate number, the car's make, the car's model, the category and to state that it is available the function will always reformat the license plate to be all capitalized letters and to capitalize only the first letter of the model and make and lowercase the rest, it will also choose on what category should be chosen. There is an int that is being passed by reference to store a counted integer, there is an array to store the information of the car, there is a cartype struct to read the information temporarily, there is ofstream to output into another file and the ifstream to read other input files given. 
{
  infile>>car.license>>car.make>>car.model>>car.category;
  while(infile)
    {
      int ma,mo,li; //stores the length of the fields
  ma=car.make.length();
  mo=car.model.length();
  li =car.license.length();
  car.make[0]=toupper(car.make[0]);
  car.model[0]=toupper(car.model[0]);
  for(int i=1; i<ma; i++)
    car.make[i]=tolower(car.make[i]);
      for(int j=1; j<mo;j++)
	car.model[j]=tolower(car.model[j]);
      for(int k=0;k<li;k++)
	car.license[k]=toupper(car.license[k]);
      outfile<<left<<setw(14)<<car.license<<setw(12)<<car.make<<setw(12)<<car.model<<setw(11);
      if(car.category == 'C' || car.category == 'c')
	outfile<< "Compact";
      if(car.category == 'S' || car.category =='s')
	outfile<< "Standard";
      if(car.category == 'P' || car.category =='p')
	outfile<<"Premium";
      outfile<<setw(12)<<"Available"<<endl;
      avail[available].status = false;
      avail[available].license = car.license;
      avail[available].make = car.make;
      avail[available].model = car.model;
      avail[available].category = car.category;
      available++;
      
      infile>>car.license>>car.make>>car.model>>car.category;
    }
  outfile<<endl;
  infile.clear();
  infile.seekg(0);
}
void rentals(int& count,cartype rented[],cartype& car, cartype& car2, ofstream& outfile, ifstream& infile_rentals, ifstream& infile_inventory)//this function is to process the rentals it will read and compare between the two files and store the common ones into an array struct and display which license plate matches are being rented and if there were any that didnt belong again it will also reformat the license plate to be all capitalized and the make and model to be properly formated with one uppercase and the rest lowercase. There is an array to store rented cars information and then there are two cartype structs being passed by reference to store information, two ifstreams passed by reference to read the two files there is an int being passed to count the rented cars and lastly there is an ofstream being passed by reference to output into a file. 
{
  int a,b;//stores the length of certain fields
  outfile<<"Processing Rentals"<<endl;
  infile_rentals>>car.license;
  infile_inventory>>car2.license>>car2.make>>car2.model>>car2.category;
  while(infile_rentals)
    {
      int n=car.license.length();
      for(int i=0;i<n;i++)
	car.license[i]=toupper(car.license[i]);
      for(int j=0;j<n;j++)
	car2.license[j]=toupper(car2.license[j]);
  while(infile_rentals && infile_inventory)
    {
  if(car.license == car2.license)
    {
     
      rented[count].license = car2.license;
      rented[count].make = car2.make;
      rented[count].model = car2.model;
      rented[count].category = car2.category;
	count++;
      a=car2.make.length();
      b=car2.model.length();
      car2.make[0]=toupper(car2.make[0]);
      car2.model[0]=toupper(car2.model[0]);
      for(int i=1; i<a; i++)
	car2.make[i]=tolower(car2.make[i]);
      for(int j=1; j<b;j++)
        car2.model[j]=tolower(car2.model[j]);
      outfile<<"License# "<<car.license<<" "<<car2.make<<" "<<car2.model<< " Rented."<<endl;
  infile_rentals>>car.license;
  infile_inventory>>car2.license>>car2.make>>car2.model>>car2.category;
  n=car.license.length();
  for(int i=0;i<n;i++)
    car.license[i]=toupper(car.license[i]);
  for(int j=0;j<n;j++)
    car2.license[j]=toupper(car2.license[j]);
  infile_inventory.clear();
  infile_inventory.seekg(0);
    }
    if(car.license != car2.license)
   {
    infile_inventory>>car2.license>>car2.make>>car2.model>>car2.category;
    if(infile_inventory.eof())
      {
	outfile<<"Error: "<< car.license<<" could not be found."<<endl;
      infile_rentals>>car.license;
      for(int i=0;i<n;i++)
	car.license[i]=toupper(car.license[i]);
      infile_inventory.clear();
      infile_inventory.seekg(0);
      }
    for(int j=0;j<n+1;j++)
   car2.license[j]=toupper(car2.license[j]);
 
   }
 
   
}
    }
  infile_inventory.clear();
  infile_inventory.seekg(0);
}
void rented_cars(int& count, int& available,cartype rented[],cartype avail[], ofstream& outfile)//This function is to display the five columns of (license, make,model,category, and status) however it will compare which is true and which is false thus concluding what the status of each car would contain, each license will be all uppercase and the rest of the colums will have one uppercase and the rest lowercase.The program will also determine the category of each car. Also, the function will count how many cars per category are being rented and it will calculate how much is the daily rental and how many cars are being rented and how many cars are available. There are two array records that are being passed and compated, two integers passed to count each car, and the ofstream to output into the output file. 
 {
   int temp1,temp2; //stores the length of each field
   double daily,s=0,c=0,p=0;//stores daily rental amount, and counts each type of category
    for(int i=0;i<count;i++)
     {
       temp1=rented[i].make.length();
       temp2=rented[i].model.length();
       outfile<<left<<setw(14)<<rented[i].license<<setw(12);
       
       rented[i].make[0]=toupper(rented[i].make[0]);
       rented[i].model[0]=toupper(rented[i].model[0]);
       for(int j=1; j<temp1; j++)
	 rented[i].make[j]=tolower(rented[i].make[j]);
       for(int k=1; k<temp2; k++)
	 rented[i].model[k]=tolower(rented[i].model[k]);
       outfile<<rented[i].make<<setw(12)<<rented[i].model<<setw(11);
       if(rented[i].category == 'C' || rented[i].category == 'c')
	 {
	 outfile<< "Compact";
	 c++;
	 }
       if(rented[i].category == 'S' || rented[i].category =='s')
	 {
	 outfile<< "Standard";
	 s++;
	 }
       if(rented[i].category == 'P' || rented[i].category == 'p')
	 {
	 outfile<< "Premium";
	 p++;
	 }
       outfile<<setw(12)<<"Rented"<<endl;
     }
    outfile<<endl;
    outfile<<fixed<<setprecision(2);
    daily = static_cast<double>(p*PREM)+(s*STAN)+(c*COM);
    outfile<<"Daily rental due is $"<<daily<<endl;
    outfile<< count <<" car(s) is(are) currently rented."<<endl;
    outfile << available-count<<" car(s) is(are) currently available."<<endl;
    outfile<<endl;
    outfile<< setw(14)<<"License#" <<setw(12)<<"Make"<<setw(12)<<"Model"<<setw(11)<<"Car Type"<<setw(9)<<"Status"<<endl;
    for(int l =0;l<available;l++)
      {
	for(int i=0;i<available;i++)
	  {
        if(rented[i].license == avail[l].license)
	  avail[l].status = true;
	
	       }
	
	outfile<<left<<setw(14)<<avail[l].license<<setw(12)<<avail[l].make<<setw(12)<<avail[l].model<<setw(11);
    if(avail[l].category == 'C' || avail[l].category == 'c')
	outfile<< "Compact";
    if(avail[l].category == 'S' || avail[l].category =='s')
	outfile<< "Standard";
    if(avail[l].category == 'P' || avail[l].category == 'p')
	outfile<< "Premium";
    if(avail[l].status == true)
      outfile<<setw(12)<<"Rented"<<endl;
    if(avail[l].status == false)
      outfile<<setw(12)<<"Available"<<endl;
      }
 }
