#include <stdio.h>
#include <unistd.h>
int main() 
{
	int pid;
	pid = fork(); 
	
	printf("\npid : %d\n", pid);
	if(pid == 0) {
		printf("Hello, I am child!\n");
	} else if (pid > 0) {
		printf("Hello, I am parent!\n");
	}
}
