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

void request_resource(struct bank *banco, struct client *cliente){
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

void release_resource(struct bank *banco, struct client *cliente, int rel_a, int rel_b, int rel_c){
    if (banco!= NULL && cliente != NULL){
        if (rel_a != 0 || rel_a < 0){
            if (cliente->alocado_a == rel_a || cliente->alocado_a > rel_a){
                cliente->alocado_a -= rel_a;
                banco->a += rel_a;
            }
        }

         if (rel_b != 0 || rel_b < 0){
            if (cliente->alocado_b == rel_b || cliente->alocado_b > rel_b){
                cliente->alocado_b -= rel_b;
                banco->b += rel_b;
            }
        }

         if (rel_c != 0 || rel_c < 0){
            if (cliente->alocado_c == rel_c || cliente->alocado_c > rel_c){
                cliente->alocado_c -= rel_c;
                banco->c += rel_c;
            }
        }
    }
}

void iniciar_cliente(struct client **head, int unidade_a, int unidade_b, int unidade_c){
    struct client *cliente = malloc(sizeof(struct client));

    if(cliente != NULL){
        cliente->res_a = unidade_a;
        cliente->res_b = unidade_b;
        cliente->res_c = unidade_c;
        cliente->next = NULL;

        if ((*head) == NULL){
            (*head) = cliente;
        }else{
            struct client *temp = (*head);

            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = cliente;
        }
    }
}
