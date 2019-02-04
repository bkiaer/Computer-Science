#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main()
{

  printf("Enter Command: ");
  
  char * buffer = (char*)calloc(256, sizeof(char));
  fgets(buffer, 256, stdin);
 
  if(strlen(buffer) == 1) //check if user just presses enter and no command
    {
      printf("Invalid Command");
      return 1;
    }

  char * argv1[10]; //first command
  char * argv2[10]; //second command
 
  int fd[2];
  int pid, pid2, status;

  pipe(fd); //pipe
  pid = fork(); //fork
  

 
  if(pid < 0) //check for successful forking
    {    
    perror("Failed to create fork");
    return 1;
    }
  if(pid > 0)  //parent for command 1
    {
    waitpid(pid, &status, WUNTRACED);
    close(0); //closes stdin 
    dup(fd[0]); //replaces stdin with fd[0] which is pipe read
    close(fd[1]); //closes other side of pipe which is pipe write
    
    }
  else if (pid == 0)  //child for command 1
    {
     
      close(1); //closes stdout
      dup(fd[1]);//duplicates fd[1] into the stdout file descriptor with pipe write
      close(fd[0]); //closes pipe read because its not being used.
       
   
      int i = 0;
      strtok(buffer, "|"); //isolates first command
      argv1[0] = strtok(buffer, " "); //isolates first word in command
      
      while(argv1[i] != NULL)
	{
	  i++;
	  argv1[i] = strtok(NULL, " ");
	  }
   
  
      execvp(argv1[0],argv1); //execute first command.
      
      perror(NULL);
      exit(0);  //kill process to avoid being a zombie
    }

  pid2 = fork(); //create another fork
  
  if(pid2 < 0) //check if fork was successfully created.
    {
      perror("Failed to creat fork");
      return 1;
      }
  
  if(pid2 >0) //parent waits for child
    {
    waitpid(pid2, &status, WUNTRACED);
    }
  else if(pid2 == 0) //child 
    {
      
      int i = 0;
      
      strtok(buffer, "|"); // isolates first command
      argv2[0] =  strtok(NULL, "\n"); //isolates and saves second command
      
      argv2[0] = strtok(argv2[0], " "); //isolates first word of second command
      while(argv2[i] != NULL)
	{
	  i++;
	  argv2[i] = strtok(NULL, " ");
	  }
      
        execvp(argv2[0], argv2);
	
       	perror(NULL);
		  
	exit(0); //kill process to avoid being a zombie
    }

  return 0;
}
