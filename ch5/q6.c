#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){
	int wstatus;
	pid_t rc = fork();
	if(rc < 0){ // fork failed, exit
		fprintf(stderr, "fork failed\n");
		exit(1);
	} else if(rc == 0){
		pid_t waitpid_return = waitpid(-1, NULL, WUNTRACED | WCONTINUED);
		printf("child wait return: %d\n", waitpid_return);
	} else {
		pid_t waitpid_return = waitpid(rc, &wstatus, WUNTRACED | WCONTINUED);
		printf("parent wait return: %d\n", waitpid_return);
		printf("if the child terminated normally: %s\n", WIFEXITED(wstatus) 
				? "true" : "false");
	}

	return 0;
}
