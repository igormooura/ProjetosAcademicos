#include <stdio.h>
#include <stdlib.h>
#include "../include/logicalops.h"

//espécies de booleano 
int beq(int reg[], int rx, int ry)
{
   if (reg[rx] == reg[ry]) {
        return 1; 
    } else {
        return 0; 
    }
}

int blt(int reg[], int rx, int ry)
{
    if (reg[rx] < reg[ry]) { 
        return 1; 
    } else {
        return 0; 
    }
}
void jmp(int reg[], int endereco, int *i) {
    *i = endereco - 1;
}
