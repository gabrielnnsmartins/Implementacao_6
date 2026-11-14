#include<stdio.h>
#include<stdlib.h>

struct client{
    int res_a;
    int res_b;
    int res_c;
    int alocado_a;
    int alocado_b;
    int alocado_c;
    struct client *next;
};

struct bank{
    int a;
    int b;
    int c;
};

