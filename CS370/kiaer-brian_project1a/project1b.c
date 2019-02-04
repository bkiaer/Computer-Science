#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>


int main() 
{

  int i = 0;
  int check = 0;
  int fd[2];
  int pid, pid2, status;


  char array1[200], array2[200],ch;
  char * argv1[200];
  char * argv2[200];
  char * argv0[200];

  char * buffer = (char*) calloc(256, sizeof(char));


	printf("Enter Command ");
  
      while(( ch  = getchar()) != '\n' && ch != EOF)
	{
	  
	  array1[i] = ch;
	
	i++;
	
      }
   
       argv1[0] = strtok(array1, " ");

       i = 0;
       
       while(argv1[i] != NULL && argv1[i] != "\n")
	 {
	   
	   if(strcmp(argv1[i], "|")==0)
	     {
	       check = 1;
	       argv1[i] = NULL;
	       i = 0;
	       argv2[0] = strtok(NULL, " ");
	      
	       while(argv2[i] != NULL)
		 {
		   i++;
		   argv2[i] = strtok(NULL, " ");
		   
		 }
	     }
	   
	   else  if(check == 0 && argv1[i] != "\n");
	   {
	    
	     i++;
	   argv1[i] = strtok(NULL, " ");
	   }
	   

	 }
       

       if(check == 0)
	 {
	   pipe(fd);
	   pid = fork();

	   if(pid > 0)
	     {

	       waitpid(pid, &status, WUNTRACED);
	       
	       dup(fd[0]);
	       close(fd[1]);
	     }
	   else if(pid == 0)
	     {
	       dup(fd[1]);
	       close(fd[0]);



	       char*argv3[200];
	       argv3[0] = "cat";
	       argv3[1] = "project2a.c";
	       
	       execvp(argv1[0], argv1);
	       perror(NULL);
	       exit(0);
	     }

	 }

      
       else if(check == 1)
	 {
      pipe(fd); 
      pid = fork();

      if(pid < 0)
	{
	  perror("Failed to create fork");
	  return 1;
	}

      if(pid > 0) //parent
	{
	  waitpid(pid, &status, WUNTRACED);
       	  close(0);
	  dup(fd[0]);
	  close(fd[1]);
	}
      else if (pid == 0) // child
	{
	
	   close(1);
	  dup(fd[1]);
	  close(fd[0]);
	  
      
	 
	  execvp(argv1[0], argv1);
	  perror(NULL);
	  exit(0);
	  
    }
      pid2 = fork();
      
      if(pid2 > 0)
	{

	  waitpid(pid2, &status, WUNTRACED);
	}
      else if(pid2 == 0)
	{

	  execvp(argv2[0], argv2);
	  
	  perror(NULL);
	  exit(0);
	}
	 }

      return 0;

}
