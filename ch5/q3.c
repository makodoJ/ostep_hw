#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h> 

static void sigcont_handler() { printf("goodbye\n"); }

int main(int argc, char *argv[]){
	int parent_pid = getpid();
	int rc = fork();
	struct sigaction act;
	act.sa_handler = sigcont_handler;

	if(rc < 0){ // fork filed; exit
		fprintf(stderr, "fork failed\n");
		exit(1);
	}else if(rc == 0){ // child
		kill(parent_pid, SIGCONT);
		printf("hello\n");
	}else{ // parent
		sigaction(SIGCONT, &act, NULL);
		pause();
	}

	return 0;

}
