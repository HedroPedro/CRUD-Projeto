#include <stdio.h>
#include <stdlib.h>
#include "operations.h"

#define FILEPATH "./estoque.txt"

int main(){
    remedio *remedios;
    FILE *fp = fopen(FILEPATH, "w+");
    if(!fp){
        printf("A");
        exit(EXIT_FAILURE);
    } 
}