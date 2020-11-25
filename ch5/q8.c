#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){
	int pipefd[2];
	char buf;

	if(pipe(pipefd) == -1){
		perror("pipe");
		exit(EXIT_FAILURE);
	}

	pid_t rc[2];
	rc[0] = fork();

	if(rc[0] < 0){ // fork failed, exit
		fprintf(stderr, "fork failed\n");
		exit(1);
	} else if(rc[0] == 0){
		close(pipefd[0]); // close unused read end
		char str[] = "The first child writes: I'm the first child.";
		write(pipefd[1], str, strlen(str));
		close(pipefd[1]); // reader will see EOF
		waitpid(rc[1], NULL, 0); // wait for the second child
	} else {
		rc[1] = fork();
		if(rc[1] < 0){ // fork failed, exit
			fprintf(stderr, "fork failed\n");
			exit(1);
		} else if(rc[1] == 0){
			close(pipefd[1]); // close unused write end
			// read this string a byte at a time from the pipe and echoes it on 
			// standard output
			while(read(pipefd[0], &buf, 1) > 0){
				write(STDOUT_FILENO, &buf, 1);
			}
			write(STDOUT_FILENO, "\n", 1);
			close(pipefd[0]);
		}
	}
	return 0;
}
