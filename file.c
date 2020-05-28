#include <stdio.h>
#include <stdlib.h>
int main(int argc, char* argv[])
{
	int i;
	char user[100];
	int pid[10000];
	FILE* users;
	FILE* pids;
	users=popen(" ps -Ao user", "r");
	pids=popen(" ps -Ao pid", "r");
	while(fgets(user,100,users) != NULL && fgets(pid,10000,pids) != NULL)
	{
		for(i=0;i<argc;i++)
			if(user == argv[i])
				system("kill pid ");
	}	
	pclose(users);
	pclose(pids);
	return 0;
}
