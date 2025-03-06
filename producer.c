#include<stdio.h>
#include<stdlib.h>
int mutex=1,full=0,empty=5,x=0;
int signal(int s)
{
  return(++s);
 }
 int wait(int s)
 {
  return(--s);
 }

 int producer()
 {
   empty=wait(empty);
   mutex=wait(mutex);
   x++;
   printf("\n Producer produces the item %d",x);
   mutex=signal(mutex);
   full=signal(full);
  }
 
  int consumer()
 {
   full=wait(full);
   mutex=wait(mutex);
   printf("\n consumer consumes  the item %d",x);
   x--;
   mutex=signal(mutex);
   empty=signal(empty);
  }
  void main()
  {
   int n;
   while(1)
   {
     printf("\n 1.Producer\n 2.Consumer\n 3.Exit\n");
     printf("Enter your choice:");
     scanf("%d",&n);
     
     switch(n)
     {
       case 1:
       if((mutex==1)&&(empty!=0))
       producer();
       else
       printf("\n Buffer is full\n");
       break;
       
       case 2:
       if((mutex==1)&&(full!=0))
       consumer();
       else
       printf("\n Buffer is empty\n");
       break;
       
       case 3:
       exit(0);
       break;
       }
     }  
       }
       
