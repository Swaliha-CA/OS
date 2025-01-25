//Swaliha_59
#include<stdio.h>
#include<sys/types.h>
#include<sys/types.h>
#include<dirent.h>
void main()
	{
	 DIR *dir;
	 struct dirent *ptr;
	 char dir_name [100];
	 printf("Enter the directory:");
	 scanf("%s",dir_name);
	 dir=opendir(dir_name);
	 while((ptr=readdir(dir))!=NULL)
	 	{
	 		printf("%ldID\t%s",ptr->d_ino,ptr->d_name);
	        }
	        closedir(dir);
	 }
