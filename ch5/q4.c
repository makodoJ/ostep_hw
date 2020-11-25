#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
	int rc = fork();

	if(rc < 0){ // fork failed, exit
		fprintf(stderr, "fork failed\n");
		exit(1);
	} else if(rc == 0){
		char *argvs[] = {"ls", "-l", "-a", "-h", NULL};
		char *envp[] = {NULL};

		execl("/bin/ls", "ls", "-l", "-a", "-h", NULL);
		execlp("ls", "ls", "-l", "-a", "-h", NULL);
		execle("/bin/ls", "ls", "-l", "-a", "-h", NULL, envp);

		execv("/bin/ls", argvs);
		execvp("ls", argvs);	
	}
	return 0;
}
