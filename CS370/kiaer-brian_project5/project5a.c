#include <semaphore.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct fork
{
  sem_t mutex;
};
struct philosopher
{ 
  int id;
  int count; //count up to 5.
  struct fork * left; //link forks with philosopher
  struct fork * right;
};
void algorithm1(void * ptr); //deadlock situation
void algorithm2(void * ptr); //room situation
void wait(struct  fork *forks); //wait 
void signal(struct  fork *forks); //signal
sem_t room; //global
int main(int argc, char * argv[])
{

int enable_room, i;
pthread_t threadIDs[5];
enable_room = atoi(argv[1]);

if(enable_room == 1)  //Deadlock
{
  struct fork forks[5];
  struct philosopher philosophers[5];
 for(i = 0; i < 5; i++)
 {
   philosophers[i].id = i;
   philosophers[i].count = 0;
   philosophers[i].left = &forks[i];
   if(i == 4)
     philosophers[i].right = &forks[0];
   else
   philosophers[i].right = &forks[i+1]; 
 }
 for(i = 0; i < 5; i++)
  {
    sem_init(&forks[i].mutex, 0, 1);
    pthread_create(&threadIDs[i], NULL, (void *) &algorithm1, (void*)&philosophers[i]);   
   
  }
 for(i = 0; i < 5; i++)
 {
   pthread_join(threadIDs[i], NULL);
 }
}
else 
if(enable_room == 0) //room 
{
 struct fork forks[5];
 struct philosopher philosophers[5];
 for(i = 0; i < 5; i++) //link right and left fork with each philosopher
  {
   philosophers[i].id = i;
   philosophers[i].count = 0;
   philosophers[i].left = &forks[i];
   if(i == 4)
     philosophers[i].right = &forks[0];
   else
   philosophers[i].right = &forks[i+1]; 
 }
  for(i = 0; i < 5; i++)
  {
    sem_init(&forks[i].mutex, 0, 1);
    sem_init(&room, 0, 4);
    pthread_create(&threadIDs[i], NULL, (void *) &algorithm2, (void*)&philosophers[i]);     
  }
 for(i = 0; i < 5; i++)
 {
   pthread_join(threadIDs[i], NULL);
 }
  
}
return 0;
}
/*--------------------------------------------------------------*/
void algorithm1(void*ptr)
{
struct philosopher * phil;
phil = (struct philosopher * ) ptr;
while((*phil).count < 5)
  {
  printf("Philosopher %d is done thinking and now ready to eat \n", (*phil).id);
  wait(phil->left);
  printf("Philosopher %d: taking left fork %d\n", (*phil).id, (*phil).id);
  sleep();
  wait(phil->right);
  printf("Philosopher %d: taking right for %d\n", (*phil).id, (*phil).id+1);
  printf("Philosopher %d: EATING.\n", (*phil).id);
  signal(phil->left);
  printf("Philosopher %d: putting down left fork %d\n", (*phil).id, (*phil).id);
  signal(phil->right);
  printf("Philosopher %d: putting down right fork %d\n", (*phil).id, (*phil).id+1);
  (*phil).count++;
  }
}
/*-----------------------------------------------------------------*/
void algorithm2(void * ptr)
{
  struct philosopher * phil;
  phil = (struct philosopher * ) ptr;
  while((*phil).count < 5)
  {
   printf("Philosopher %d is done thinking and now ready to eat \n", (*phil).id);
   sem_wait(&room);
   wait(phil->left);
   printf("Philosopher %d: taking left fork %d\n", (*phil).id, (*phil).id);
   wait(phil->right);
   printf("Philosopher %d: taking right for %d\n", (*phil).id, (*phil).id+1);
   printf("Philosopher %d: EATING.\n", (*phil).id);
   signal(phil->left);
   printf("Philosopher %d: putting down left fork %d\n", (*phil).id, (*phil).id);
   signal(phil->right);
   printf("Philosopher %d: putting down right fork %d\n", (*phil).id, (*phil).id+1);
   sem_post(&room);
   (*phil).count++;
  }
}
/*-----------------------------------------------------------------*/
void wait(struct fork * current)
{
  sem_wait(&current->mutex);
}
void signal(struct fork * current)
{
  sem_post(&current->mutex);
}
