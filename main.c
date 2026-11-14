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

void release_resource(struct bank *banco, struct client *cliente){
    if (banco != NULL && cliente != NULL){
        if(cliente->res_a != 0 && banco->a > cliente->res_a){
            cliente->alocado_a = cliente->res_a;
            banco->a -= cliente->alocado_a;
        }

        if(cliente->res_b != 0 && banco->b > cliente->res_b){
            cliente->alocado_b = cliente->res_b;
            banco->b -= cliente->alocado_b;
        }

        if(cliente->res_c != 0 && banco->c > cliente->res_c){
            cliente->alocado_c = cliente->res_c;
            banco->c -= cliente->alocado_c;
        }
    }
}
