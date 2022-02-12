#include <stdio.h>
#include <unistd.h>
int main() {
        int pid;
        pid = fork(); 

        if(pid == 0) {  
            // this is child
	    printf("\npid : %d\n", pid);
            printf("Hello, I am child! Now I'll run date \n");
            execlp("/bin/date", "/bin/date", (char *) 0);
        } else if (pid > 0) {   
            // this is parent
	    printf("\npid : %d\n", pid);
            printf("Hello, I am parent!\n");
        }   
}
