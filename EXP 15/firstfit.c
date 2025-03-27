#include<stdio.h>
void main(){
int m,n,choice;

printf("Enter the number of memrory blocks:");
scanf("%d",&m);

printf("Enter the size of memory blocks:");
int blocksize[m];
for(int i=0;i<m;i++){
scanf("%d",&blocksize[i]);
}
printf("Enter the number of processes:");
scanf("%d",&n);

int processsize[n],allocation[n];
printf("Enter the size of each processes:");
for(int i=0;i<n;i++){
scanf("%d",&processsize[i]);
allocation[i]=-1;
}

for(int i=0;i<n;i++){
   for(int j=0;j<m;j++){
if(blocksize[j]>=processsize[i]){
  allocation[i]=j;
  blocksize[j]-=processsize[i];
  break;
  }
  }
  }
  
  printf("\n processno\t process size\t block no\t\tblock size after allocation\n");
  for(int i=0;i<n;i++){
  printf("%d\t\t%d\t\t",i+1,processsize[i]);
  if(allocation[i]!=-1){
  printf("%d\t\t\t%d\t\t\n",allocation[i]+1,blocksize[allocation[i]]);
  }
  else{
  printf("Not allocated\n");
  }
 }
}
  
