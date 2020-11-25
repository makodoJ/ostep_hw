#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]){
	int x = 100;
	printf("hello world (pid:%d)\n", (int) getpid());
	int rc = fork();
	if (rc < 0){ // fork failed; exit
		fprintf(stderr, "fork failed\n");
		exit(1);
	} else if(rc == 0){ // child (new process)
		x = 200;
		printf("hello, I am child (pid: %d), x = %d\n", (int) getpid(), x);
	}else { // parent goes down this path (main)
		printf("hello, I am parent of %d (pid: %d), x = %d\n", rc, (int) getpid(), 
									x);
	}
	return 0;
}
