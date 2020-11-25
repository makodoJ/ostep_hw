#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int main(int argc, char *argv[]){
	int rc = fork();
	if(rc < 0){ // fork failed, exit
		fprintf(stderr, "fork failed\n");
		exit(1);
	} else if(rc == 0){
		close(STDOUT_FILENO);
		printf("I am child\n");
	} else {
		printf("I am parent\n");
	}
	return 0;
}
