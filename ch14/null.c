//
// Created by Banana on 2020/12/4.
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    int *p_int = (int *)calloc(1, sizeof(int));
    p_int = NULL;
    printf("%d\n", *p_int);
    free(p_int);
    return 0;
}