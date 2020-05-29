#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int main(int argc, char* argv[])
{
	while(1)
	{
	sleep(3);
	printf("running..\n");
	int i;
	char user[100];
	char pid[10000];
	FILE* users;
	FILE* pids;
	users=popen(" ps -Ao user", "r");
	pids=popen(" ps -Ao pid", "r");
	while(fgets(user,100,users) != NULL && fgets(pid,10000,pids) != NULL)
	{
		user[strlen(user)-1]=0;
		for(i=1;i<argc;i++)
		{
			if(strcmp(user,argv[i])==0)
			{
				char command[100];
				strcat(command,"kill ");
				strcat(command,pid);
				printf("%s \n",command);
				system(command);
			}
		}
	}	
	pclose(users);
	pclose(pids);
	}
	return 0;
}
