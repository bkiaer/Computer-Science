#include <stdio.h> 
#include <pthread.h>
#include <stdlib.h>
#include <semaphore.h>

struct channel //structure for channel 
{
  sem_t rc;
  sem_t synch;
  int *queue;
  int head; 
  int size;
  int tail;
  int index;
};
struct node //structure for each node.
{
  int leader;
  int uid;
  int temp_uid;
  int one_uid;
  int two_uid;
  int phase;
  int status; //if 1 it is active if 0 it is relay
  
  struct channel * left;
  struct channel * right;
};

void push(struct channel * , int); //push values into queue
int  pop(struct channel *); //pop and return values from queue
void algorithm(void *ptr); //main algorithm
void write(struct channel * channels, int); //write function 
int read (struct channel * channels); //read function

int main()
{
  int i, n;
  scanf("%d", &n); //read initial size of nodes
  struct channel channels[n];
  struct node nodes[n];
  pthread_t threadID[n]; 
  for(i = 0; i < n; i++) //puts initial ids into nodes.
    {
      if(i == n-1){
	nodes[i].left = &channels[n-1];
	nodes[i].right = &channels[0];
      }
      else
	{
	nodes[i].left = &channels[i];
	nodes[i].right = &channels[i+1];
	}
      channels[i].tail =channels[i].head =  0;
      channels[i].queue = (int *) calloc ( (2*n), sizeof(int));
    scanf("%d", &nodes[i].uid);
    nodes[i].phase = n; //number of nodes.
    nodes[i].temp_uid = nodes[i].uid;
    nodes[i].status = 1; //initialize bool to make node active when first made
    }
  for(i = 0; i < n; i++)
    {
      sem_init(&channels[i].rc, 0, 1); //initialize rc and synch
      sem_init(&channels[i].synch, 0, 0);
      pthread_create(&threadID[i], NULL, (void *) &algorithm, (void *) &nodes[i]); //create threads.
    }
  for(i = 0; i < n; i++)
    pthread_join(threadID[i], NULL); // join threads after they exit
  return 0;
}
void push(struct channel * current, int value) //push value in queue
{
  current->queue[current->tail] = value; 
  current->tail ++;
  current->size ++; 
}
int pop(struct channel * current) //pop and return value off of queue
{  
  int temp;
  temp = current->queue[current->head];
  current->head ++;
  current->size --;
  return temp;
}
void algorithm(void *ptr) //Peterson's Algorithm
{
   struct node * nodes;
   nodes = (struct node *) ptr;
   int start;
   int i, end;
   end =0;
      start = (*nodes).uid;
     for(i = 1; i < (*nodes).phase; i++){ 
      if((*nodes).status == 1 ) //if status is active and leader has not been found.
     {
       write((nodes->right), (*nodes).temp_uid);
       if(end == 0)
       (*nodes).one_uid = read(nodes->left);
       write((nodes->right), (*nodes).one_uid);
       if(end == 0)
       (*nodes).two_uid = read(nodes->left); 
       if(end == 0)
       printf("[%d][%d][%d]\n",i, (*nodes).uid, (*nodes).temp_uid); //print node id and temp id
       if(end == 0)
       if((*nodes).one_uid == (*nodes).temp_uid){
	 write(nodes->right, 0);
	 write(nodes->right,0);
      	 (*nodes).leader = 1; //mark which one was the leader.
	 end = 1;
	 printf("leader is: %d\n", (*nodes).uid); //print the leader
	 write((nodes->right), 0);
	 write((nodes->right), 0);
       }
       else{ 
	 if((*nodes).one_uid > (*nodes).two_uid && (*nodes).one_uid > (*nodes).temp_uid){
	   (*nodes).status = 1; // status to active
	   (*nodes).temp_uid = (*nodes).one_uid;
	   (*nodes).leader = 0;
	   end = 0;
	 }
	 else
	   (*nodes).status = 0; //change status to relay
       } 
     }
  else{
     if((*nodes).status == 0 && end == 0) //if relay and leader not found yet
     {
       (*nodes).temp_uid = read(nodes->left);
       write((nodes->right), (*nodes).temp_uid);
       (*nodes).temp_uid = read(nodes->left);
       write((nodes->right), (*nodes).temp_uid);
     }
   }   
    }  	
   pthread_exit(NULL);     //exit thread after to loop so they can join
}
void write(struct channel * current, int value) //write function
{
  sem_wait(&current->rc);
  push(current,value);
  sem_post(&current->rc);
  sem_post(&current->synch);
  }
int read(struct channel* current) //read function
{
  sem_wait(&current->synch);
  sem_wait(&current->rc);
  int value = pop(current);
  sem_post(&current->rc);
  return value;
    }

