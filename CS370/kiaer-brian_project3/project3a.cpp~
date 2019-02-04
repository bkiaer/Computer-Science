#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <queue>
#include <vector>
#include <stdlib.h>
using namespace std;

struct array
{
  int pid; 
  char   nice_value[256];
  string stop;
  int nice;
  int arrival;
  int timeslice;
  int original;
  int priority;
  int no_cpu;
  int no_io;
  int cpu_burst[200];
  int io_burst[200];
  double total_io;
  double total_cpu;
  int bonus;
  bool empty;
  int cpu_sum;
  int io_sum;
  int finish_time;
  int current_cpu;
  int current_io;
  int cpu_time;
  int io_time;
  bool in_io;
  bool in_cpu;

};
class compare //priority queue to prioritize arrival time
{
public: 
  bool operator()(const array& a, const array& b)
  {
   
    if(a.arrival !=  b.arrival)
    return a.arrival >= b.arrival;
    else 
	return a.pid >= b.pid;
    
  }

  };
class priority //priority queue to prioritize priority of the process
{
public:
  bool operator()(const array& a, const array& b)
  {
   
    return a.priority >= b.priority;
 
  }
};
class io_prior //priority queue to prioritize io_burst
{
public:
  bool operator()(const array& a, const array& b)
  {
    return a.io_burst[0] >= b.io_burst[0];
  }
};

class exhaust //priority queue to prioritize the finish_time of the process.
{
public:
  bool operator()(const array& a, const array& b)
  {    
    return a.finish_time >= b.finish_time;
  }
};
int main()
{
  bool not_done = true;
  bool cpu_empty,active_empty,io_empty,exhausted_burst,second;
  int i = 0;
  int total_pid, index=0;
  int  clock,temp1,count = 0;
  double waiting, tat, cpu_ut, ut, tt, wt;
  array process, active[200], expired[200], startup[200], temp, cpu, temp2;
  
  priority_queue<array, vector<array>, compare> start_arr; //start queue
  priority_queue<array, vector<array>, compare> filter; 
  priority_queue<array, vector<array>, priority> active_arr,expired_arr; //ready queue and expired queue
  priority_queue<array, vector<array>, io_prior> io_arr; //io queue
  priority_queue<array, vector<array>, io_prior> temp_io;
  priority_queue<array, vector<array>, exhaust> finish; //finish queue
  cin >> process.nice_value;
  process.stop = process.nice_value;
  while(process.stop != "***") //insert process information to process queue
    {
      
      process.nice = atoi(process.nice_value); //if the value is not *** then convert to an int
      process.pid = i;
      
      cin >> process.arrival;
      cin >> process.no_cpu;
      process.no_io = process.no_cpu-1;
      if(process.no_cpu == 1)
	{
	  cin>>process.cpu_burst[0];
	  process.total_cpu = process.cpu_burst[0];
	  process.total_io = 0;
	}
      else
	{
	  for(int j = 0; j < process.no_cpu-1; j++)
	    {
	      process.current_io = 0;
	      cin>> process.cpu_burst[j];
	      cin >> process.io_burst[j];
	      temp1 = j;
	    }
	  cin>> process.cpu_burst[process.no_cpu-1];
	  
	}
   
      start_arr.push(process);
      i++;
            cin>>process.nice_value;
	    process.stop = process.nice_value;
	    process.total_cpu = 0;
	    process.total_io = 0;
    }
  
  total_pid = i;
  not_done = true;
  cpu_empty = true;
  active_empty = true;
  io_empty = true;
  
    while(not_done)
    {
    
      while(start_arr.top().arrival == clock && !start_arr.empty()&& count < total_pid) //if they start at this clock tick then calculate priority and timeslice.
	    {
	      count++;
	      active_empty = false;
	      second = false;
	      temp = start_arr.top();
	      if(temp.no_cpu == 1){
		temp.cpu_sum = temp.cpu_burst[0];
		temp.io_sum = 0;
	      }
	      else{
	      for(int i = 0; i < temp.no_cpu-1 ; i++)
		{
		  temp.cpu_sum = temp.cpu_sum + temp.cpu_burst[i];
		  temp.io_sum = temp.io_sum + temp.io_burst[i];
		  temp1 = i;
		}
	      temp.cpu_sum = temp.cpu_sum + temp.cpu_burst[temp1+1];
	      } 
	      temp.original = ((((start_arr.top().nice+20)/39.0)*30)+0.5)+105;
	      if(start_arr.top().total_cpu < start_arr.top().total_io)
		temp.bonus = ((1-(start_arr.top().total_cpu/start_arr.top().total_io)*(-5))-0.5);
	      else
	      temp.bonus = ((1-(start_arr.top().total_io/start_arr.top().total_cpu)*(5))+0.5);
	      temp.priority = temp.original + start_arr.top().bonus;
	      temp.timeslice = (((1-(temp.priority/150.0))*395)+0.5)+5;
	      temp.total_cpu = 0;
	      temp.total_io = 0;
	      temp.current_cpu = 0;
	      active_arr.push(temp);
	      cout << "[" << clock <<"] <"<<start_arr.top().pid<<"> Enters ready queue (Priority: "
		   <<temp.priority <<", TimeSlice: "<<temp.timeslice<< ")" << endl;
	      start_arr.pop();
	
	    }
      /*----------------------------------------------------------------------*/
      if(cpu_empty== true && !active_arr.empty() ) //if cpu is empty put lowest priority in active queue
	    {
	      	      cpu = active_arr.top();	      
	      	      cout <<"[" << clock <<"] <"<<cpu.pid<<"> Enters the CPU" << endl;
		      cpu.in_cpu = true;
		      cpu_empty = false;
		     
		      if(!active_arr.empty()){
		      active_arr.pop();
	    }
	    }
	  /*---------------------------------------------------------------*/
	  if(!cpu_empty)
	    {
	      if(active_arr.top().priority < cpu.priority) //if active queue priority is less then cpu then preempt
	    {
	    cpu.in_cpu = false;
	    temp = cpu;
	    cpu = active_arr.top();
	    cpu.in_cpu = true;
	    active_arr.pop();
	    active_arr.push(temp);
	    cout<<"["<<clock<<"] <"<<cpu.pid<<"> Preempts Process " << temp.pid << endl;
	    }
	    /*-----------------------------------------------------------------*/	
	      if(cpu.in_cpu == true){ // decrement cpu and io
	  cpu.total_cpu++;  
	  }    
	  cpu.cpu_burst[cpu.current_cpu]--;
	  cpu.timeslice--;
	   }	  
	  if(!io_arr.empty()){
	   
	    while(!io_arr.empty()){
	     
	      temp = io_arr.top();
	      temp.total_io++;
	      
	      for(int j = 0; j < temp.no_io; j++)
		{
		  temp.io_burst[j]--;
		  if(temp.io_burst[j] == 0)
		    temp.empty == true;
		}
	      io_arr.pop(); 
	      temp_io.push(temp);
	    }
	   while(!temp_io.empty())
	     {
	       io_arr.push(temp_io.top());
	       temp_io.pop();
	     }
	  }
	    /*----------------------------------------------------------------*/
	  if(!cpu_empty) //if there is a process in the cpu 
	    {
	      if(cpu.cpu_burst[cpu.current_cpu] == 0) //if current cpu burst is exhausted
		  {	  
		    cpu.current_cpu++; 
		  for(int i = 0; i < cpu.no_cpu; i++)		 
		     {
		    if(cpu.cpu_burst[i] == 0)
		      exhausted_burst =  true;
		    else
		      {
			second = true;
		      exhausted_burst = false;
		      }}
		  /*------------------------------------------------------------------*/
		  if(exhausted_burst == true){ // if all cpu burst is done then send to finish queue
		cout<<"["<<clock<<"] <" <<cpu.pid<<"> Finishes and moves to the Finished Queue" << endl; 
		cpu.finish_time = clock;
		finish.push(cpu);
		exhausted_burst = false;
		cpu_empty = true;
		second = false;
	       
	      }	      
	      /*---------------------------------------------------*/
	      else if(second== true & exhausted_burst == false){ //if not done with cpu burst then move to IO queue
      		cout <<"["<< clock<<"] <" << cpu.pid <<"> Moves to the IO Queue"<< endl;
		cpu.in_io = true;
		cpu.in_cpu = false;
		if(cpu.current_io < cpu.no_cpu-1)
		cpu.current_io ++;
		io_arr.push(cpu);
		io_empty = false;
		cpu_empty = true;
	      }
		  }
		  /*-----------------------------------------------------*/
	      if(cpu.timeslice == 0){	//if timeslice is exhausted send to expired queue and recalculate priority and timeslice	 
		cpu.in_cpu = false;
		cpu.total_cpu = cpu.total_cpu + cpu.cpu_burst[cpu.no_cpu];
		if(cpu.no_cpu == 1){
		  cpu.total_io = 0;
		  cpu.total_cpu = cpu.cpu_burst[0];
		  }
		if(cpu.total_cpu < cpu.total_io)
		  cpu.bonus = (((1-(cpu.total_cpu/cpu.total_io))*(-5))-0.5);
		else
		cpu.bonus = (((1-(cpu.total_io/cpu.total_cpu))*(5))+0.5);
		cpu.priority = cpu.original + cpu.bonus;
		cpu.timeslice = (((1-(cpu.priority/150.0))*395)+0.5)+5;
		cout <<"["<< clock<<"] <"<< cpu.pid<<"> Finishes its time slice and moves to the Expired Queue (Priority: " << cpu.priority<<", TimeSlice: "<< cpu.timeslice<< ")" << endl;
		expired_arr.push(cpu);
		cpu_empty = true;
	      }
	    }
	      /*-------------------------------------------*/
	  if(!io_arr.empty()){ //if any process in IO is exhausted 
	       
		 if(io_arr.top().io_burst[io_arr.top().current_io-1] == 0){		    
		  {
		  
		    if(io_arr.top().timeslice == 0) //if timeslice is exhausted then recalculate and send to the expired queue
		      {
			temp2 = io_arr.top();
			if(temp2.total_cpu < temp2.total_io)
			  temp2.bonus = (((1-(temp2.total_cpu/temp2.total_io))*(-5))-0.5);
			else
			temp2.bonus = (((1-(temp2.total_io/temp2.total_cpu))*(5))+0.5);
			temp2.priority = temp2.original + temp2.bonus;
			temp2.timeslice = (((1-(temp2.priority/150.0))*395)+0.5)+5;
			cout << "[" <<clock << "] <" << temp2.pid << "> Finishes IO and moves to the Expired Queue (Priority: "<< temp2.priority <<", Timeslice: "<<temp2.timeslice<< ")" << endl;
			expired_arr.push(temp2);
			io_arr.pop();
			
		      }
		    else{ //if timeslice is not exhausted then send to ready queue
		     active_arr.push(io_arr.top());		   
		     cout << "[" << clock << "] <" <<io_arr.top().pid <<"> Finishes IO and moves to the Ready Queue" << endl;
		    if(!io_arr.empty())
		    io_arr.pop();
		    }}}
	  }
	  //if everything is empty then break out of loop
		 if(start_arr.empty() && active_arr.empty() && io_arr.empty() && expired_arr.empty() && cpu_empty == true)
		   not_done = false; 
		
		 //if ready queue and cpu are empty but expired isnt then swap
	      if(active_arr.empty() && cpu_empty == true && !expired_arr.empty()){ 
		cout <<"["<<clock<<"] *** Queue Swap" << endl;
		while(!expired_arr.empty())
		  {
		    active_arr.push(expired_arr.top());
		    expired_arr.pop();
		  }   
	      }
	  clock++;   
    }

    cout << "========================================== Overall Performance Output" << endl;
    cout << "========================================== " << endl;
    while(!finish.empty()){
      tat = tat + (finish.top().finish_time - finish.top().arrival);
      waiting = waiting + (finish.top().finish_time - finish.top().arrival - finish.top().cpu_sum - finish.top().io_sum);
      tt = finish.top().finish_time - finish.top().arrival;
      wt = tt - finish.top().cpu_sum - finish.top().io_sum;
      ut = ((finish.top().cpu_sum/(tt)*100.0));
      cpu_ut = cpu_ut + (ut);
     
    cout << "PID: <" << finish.top().pid << "> Statistics:" << endl;
    cout << "1. Turnaround Time: " << fixed << setprecision(0) << tt << endl;
    cout << "2. Total CPU Time: " << finish.top().cpu_sum << endl;
    cout << "3. Waiting Time: " << finish.top().finish_time - finish.top().arrival - finish.top().cpu_sum - finish.top().io_sum << endl;
    cout << "4. Percentage of CPU Utilization Time: "<<fixed << setprecision(1) << ut << endl;
    cout << "----------------------------------------- " << endl;
    finish.pop();
    }

    cout << "OVERALL Statistics: " << endl;
    cout << "Average Waiting Time: " << fixed << setprecision(3) << waiting/total_pid << endl;
    cout << "Average Turnaround Time: " << tat/total_pid << endl;
    cout << "Average CPU Utilization: " << cpu_ut/total_pid << endl;
    
  return 0;
}
