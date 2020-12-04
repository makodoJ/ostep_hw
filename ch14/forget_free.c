//
// Created by makodo on 2020/12/4.
//

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]){
    int* p_int = (int *)malloc(sizeof(int));
    *p_int = 10;
    printf("%d\n", *p_int);
    return 0;
}