//
// Created by makodo on 2020/12/4.
//

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]){
    int* data = (int *) malloc(sizeof(int) * 100);
    data[100] = 0;
    printf("%d\n", data[100]);
    free(data);
    return 0;
}
