//Swaliha_59
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
void main()
  {
     int status,pid,child_pid;
     pid=fork();
	     if(pid==-1)
		     { 
		     	printf("ERROR!");
		     	exit(0);
		     }
	     
		     else if(pid==0)
			     {
			      printf("inside child process with id:%d\n",getpid());
			      execl("/bin/date","date",NULL);
			      exit(0);
			     }
		     	
		     	else
		     		{
		     		child_pid=wait(&status);
		     		printf("inside parent process with id:%d\n",getppid());
		     		printf("child process successfull");
		     		}
  }	   
		     	
