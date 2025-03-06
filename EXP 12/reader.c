#include<stdio.h>
#include<stdlib.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<string.h>
#include<unistd.h>
void main()
{
  int id;
  void *sm;
  char buf[100];
  id=shmget((key_t)1222,1024,0666);
  printf("Key of shared memory is %d\n",id);
  sm=shmat(id,NULL,0);
  printf("Process attached at %p\n",sm);
  printf("Date read from memory:\n%s",(char*)sm);
  strcpy(buf,sm);
  int a=buf[0]-'0';
  int b=buf[2]-'0';
  printf("sum is %d\n",a+b);
  }
