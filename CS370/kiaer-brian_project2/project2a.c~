#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <termios.h>
#include <fcntl.h>
#include <sys/stat.h>

int main() 
{

  int stdin1;
  int stdout1;
  int check = 0;
  int first_check = 1;
  int second_check = 1;  
  int backspace = 0; 
  int left_right= 0;
  int character_count= 0;
  int arrow;  
  int up = 0;
  int i = 0; 
  int k= 0;
  int fd[2];
  int new_file;
  int pid, pid2, status;
  char  ch;
  char temp;
  int cd_error;
  char * quit;
  FILE *fp;
  
  char current_array[200];
  char array2[200];
  char  history_array[5][200];
 
  char * argv1[200];
  char * argv2[200];
  char * prompt = (char*) malloc(100);
  char * home = (char*) malloc(100);
  char * buffer = (char*) calloc(256, sizeof(char));

  struct termios origConfig;
  tcgetattr(0, &origConfig);

  struct termios newConfig = origConfig; 

  newConfig.c_lflag &= ~(ICANON|ECHO);
  newConfig.c_cc[VMIN] = 3;
  newConfig.c_cc[VTIME] = 2;

  tcsetattr(0, TCSANOW, &newConfig);
  
  
  getcwd(home,100);
  while(second_check != 0)
    { 
    
      char array1[200] = {0}; //reintialize array1
      getcwd(prompt, 100); //retrieve prompt and print prompt
      printf("%s> ", prompt); 
      i = 0;
      
      backspace = 0;
      
      while(( ch  = getchar()) != '\n' && ch != EOF)
	{
	  
	  arrow = 0;
	  if(ch == 27){ //check bool if arrow key has been pressed
	    arrow = 1;
	    ch = getchar();
	  }
	  if(arrow == 1&& ch == 91){ //double check to see if arrow key has been pressed.
	     
	    arrow = 2;
	    ch = getchar();
	    }
	    /*----------------------------------------------*/
	    if(arrow == 2 && ch == 65){ //up
	   
	      if(up ==5 || up == k)
		backspace = 0;
	      if(up == -1)
		up = 0;
	    
	      while(backspace != 0){ //delete command line until prompt to replace with new command
		printf("\b \b");
		backspace --;
	      }
	    
	     
	      strcpy(array1, history_array[up]);
	      if( up < 5){
	      printf("%s", history_array[up]);
	     
	      character_count = strlen(history_array[up]);
	      left_right = strlen(history_array[up]);
	      if(up < 5&& up < k)
	      up++;
	      }
	      else if(up >= 4){
	     
		up = 5;
	      }
	       if(up <= 5&& up <= k)
	       backspace = strlen(history_array[up-1]);
	      
		strcpy(current_array, array1);
	    }
	    /*-----------------------------------------------------*/
	    else  if(arrow == 2 && ch == 66){//down
	      

	
	      if(up == 5)
		up--;
	   
	     
	      if(up == -1)
		backspace = 0;
	      
	      while(backspace != 0){ //delete until prompt
	       
	       	printf("\b \b");
		backspace --;
		
	      }
	    	     	      
	      if(up >= 0)
		up--;
	      
	     
	     
	     if(up>=0)
	    strcpy(array1, history_array[up]);
	    if(up >= 0 )
	      { //print unless up key as not been pressed prior
	    printf("%s", history_array[up]);
	    
	    backspace = strlen(history_array[up]);
	    
	      }
	    strcpy(current_array, array1);
	    }
	    /*-----------------------------------------------------*/
	    else if(arrow == 2 && ch == 68)//left
	      {
	    
		if(left_right > 0 && left_right <= character_count){
	       
		  printf("\b"); //move cursor to the left when left key is pressed.
		  left_right--;
			}
	      }
	    /*--------------------------------------------------*/
	    else if(arrow == 2&& ch == 67) //right
	      {
	    
		if(left_right < character_count  ){	     //print current char in array to move cursor to the right
       		      putchar(current_array[left_right]);
		      left_right++;
		    }
	    }
	    /*---------------------------------------------------*/   		     
	    else if(ch == 127 || ch== 8)//backspace or delete
	    {
	     
	      if(backspace != 0)
		{
		  printf("\b \b"); //backspace one char at a time on command line.
	    backspace--;
	    i--;
      	    array1[i] = '\0'; //clear input char
		}
	    }
	    /*-----------------------------------------------------*/
	    else if(ch != 27) //print command
	    {
	      if(arrow != 1 && arrow != 2 && ch != 27)
		{
	       
		  putchar(ch); //output onto command line
		  character_count++; //number of characters in command line for arrow keys.
	       
		  left_right++; //moves cursor to the right most to implement left and right arrow keys.
		}
	  if(ch != 127 ) 
	    {
	      array1[i] = ch; //stores ch into array
	      current_array[i] = ch; //stores into current array
	  
	    }
	  i++;

	  backspace++;
      
	    }
	   	    
	}
      /*----------------------------------------------------------------*/
      character_count = 0; //reset counts
      left_right = 0;
     
      //history
      //copy previous content of last 5 history and replace index 0 with new instruction
      strcpy(history_array[4], history_array[3]);
      strcpy(history_array[3], history_array[2]);
      strcpy(history_array[2], history_array[1]);
      strcpy(history_array[1], history_array[0]);
      strcpy(history_array[0], array1);
           
      strtok(array1, "\n");
      /*-------------------------------------------------------------------*/
      printf("\n"); //quit command
       argv1[0] = strtok(array1, " ");
       first_check = strcmp(argv1[0], "quit");
       if(first_check == 0)
	 {
	   printf("Are you sure you want to quit? [y/n] ");
	   array2[0] = getchar();
	   putchar(array2[0]);
	   argv2[0] = strtok(array2, " ");
	   second_check = strcmp(argv2[0], "y");
      	   printf("\n");
	   
	   if(second_check == 0)
	     break;
	 }
       /*------------------------------------------------------*/
       else{
       i = 0;
       
       while(argv1[i] != NULL)
	 {
	   
	   if(strcmp(argv1[i], "|")==0) //tokenize array
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
       /*----------------------------------------*/
       //cd command
       if(strcmp(argv1[0], "cd") == 0 && argv1[1] == NULL)
	 {
	   
	   cd_error = chdir(home); 
	   if(cd_error< 0)
	     perror("Failed to change directory");
	 }
       /*_-------------------------------------*/
       //merge
       if(strcmp(argv1[0], "merge") == 0)
	 {
	   argv1[0] = "cat";
	   if(strcmp(argv1[3], ">") == 0)
	     {
	     argv1[3] = NULL;
	     
	       new_file = open(argv1[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	       if(new_file == 1)
		 perror("Could not open file");
	       stdout1 = dup(1);
	       close(1);
	       dup2(new_file, 1);
	      
	     }

	 }
       /*-------------------------------------------*/
       if(k < 6)
       k++;
       
       if(strcmp(argv1[0], "pause") == 0) //pause
	 {

	   printf("Press Enter to Continue\n");
	   printf("%s> ", prompt); 
	   while(temp = getchar() != '\n') //wont move anything into the array until \n is pressed.
	     {
	     }
	   check = 2;
	   printf("\n");
	 }
       /*------------------------------------------*/
       //dir command
       if(strcmp(argv1[0], "cd")== 0 && argv1[1] != NULL)
	 {

	   
	   cd_error = chdir(argv1[1]); //change dir 
	   if(cd_error < 0)
	   perror("Failed to change directory");
	     
	   
	     
	 }
       /*----------------------------------------------*/
       else if(check == 0) //regular command
	 {
	   pipe(fd);
	   pid = fork();

	   if(pid > 0)
	     {

	       waitpid(pid, &status, WUNTRACED);
	       
	       dup(fd[0]);
	       close(fd[1]);
	       dup2(stdout1, 1);
	     }
	   else if(pid == 0)
	     {
	       dup(fd[1]);
	       close(fd[0]);
	       
	       execvp(argv1[0], argv1);
	       perror(NULL);
	       exit(0);
	     }

	 }
       /*------------------------------------------------------*/
      
       else if(check == 1) //pipe command
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
	  stdin1 = dup(0);
	  close(0);
	  dup(fd[0]);
	  close(fd[1]);
	  close(fd[0]);
	  dup2(fd[0], 0);
      
	}
      else if (pid == 0) // child
	{
	  stdout1 = dup(1);
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
	  check = 0; 
	  i = 0;
	}
      else if(pid2 == 0)
	{
	  execvp(argv2[0], argv2);	  
	  perror(NULL);
	  exit(0);
	}
	 }
        check = 0;
	dup2(stdin1, 0);
	i = 0;
       
       }
       up = 0;
      
    }
   tcsetattr(0,TCSANOW, &origConfig);
      return 0;

}
