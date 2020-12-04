//
// Created by makodo on 2020/12/4.
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    int* array = (int *)malloc(sizeof(int) * 10);
    for(int i = 0; i < 10; i++){
        array[i] = i;
    }
    free(array);
    for(int i = 0; i < 10; i++)
        printf("%d", array[i]);
    return 0;
}