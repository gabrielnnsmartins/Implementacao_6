#include<stdio.h>
#include<stdlib.h>

struct client{
    int res_a;
    int res_b;
    int res_c;
    int alocado_a;
    int alocado_b;
    int alocado_c;
};

struct bank{
    int a;
    int b;
    int c;
};

void request_resource(struct bank *banco, struct client *clientes[], int posicao){
    if (banco != NULL && clientes[posicao] != NULL){
        if(clientes[posicao]->res_a != 0 && banco->a > clientes[posicao]->res_a){
            clientes[posicao]->alocado_a = clientes[posicao]->res_a;
            banco->a -= clientes[posicao]->alocado_a;
        }

        if(clientes[posicao]->res_b != 0 && banco->b > clientes[posicao]->res_b){
            clientes[posicao]->alocado_b = clientes[posicao]->res_b;
            banco->b -= clientes[posicao]->alocado_b;
        }

        if(clientes[posicao]->res_c != 0 && banco->c > clientes[posicao]->res_c){
            clientes[posicao]->alocado_c = clientes[posicao]->res_c;
            banco->c -= clientes[posicao]->alocado_c;
        }
    }
}

void release_resource(struct bank *banco, struct client *clientes[], int posicao, int rel_a, int rel_b, int rel_c){
    if (banco!= NULL && clientes[posicao] != NULL){
        if (rel_a != 0 || rel_a < 0){
            if (clientes[posicao]->alocado_a == rel_a || clientes[posicao]->alocado_a > rel_a){
                clientes[posicao]->alocado_a -= rel_a;
                banco->a += rel_a;
            }
        }

         if (rel_b != 0 || rel_b < 0){
            if (clientes[posicao]->alocado_b == rel_b || clientes[posicao]->alocado_b > rel_b){
                clientes[posicao]->alocado_b -= rel_b;
                banco->b += rel_b;
            }
        }

         if (rel_c != 0 || rel_c < 0){
            if (clientes[posicao]->alocado_c == rel_c || clientes[posicao]->alocado_c > rel_c){
                clientes[posicao]->alocado_c -= rel_c;
                banco->c += rel_c;
            }
        }
    }
}

void iniciar_cliente(struct client *clientes[], int posicao, int unidade_a, int unidade_b, int unidade_c){
    struct client *cliente = malloc(sizeof(struct client));

    if(clientes[posicao] != NULL){
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

void verificar_seguranca(struct bank *banco, struct client *cliente){
    
}