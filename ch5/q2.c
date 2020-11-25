#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[]){
	open("/Users/jiangrenjie/Documents/os/part1/ch5/q2.output", O_CREAT | O_WRONLY|O_TRUNC,S_IRWXU);

	char *myargs[3];
	myargs[0] = strdup("wc"); // program: "wc" (word count)
	myargs[1] = strdup("p4.c"); // argument: file to count
	myargs[2] = NULL; // marks end of array
	
	int rc = fork();
	if(rc < 0){
		fprintf(stderr, "fork failed\n");
		exit(1);
	}else if(rc == 0){
		execvp(myargs[0], myargs); 
	} else{
		printf("I am father");
		execvp(myargs[0], myargs);
	}
}
	
