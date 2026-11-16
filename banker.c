#include<stdio.h>
#include<stdlib.h>

struct client{
    int max_a;
    int max_b;
    int max_c;
    int res_a;
    int res_b;
    int res_c;
    int alocado_a;
    int alocado_b;
    int alocado_c;
    int eh_seguro;
};

struct bank{
    int a;
    int b;
    int c;
};

void verificar_resource_request(struct bank *banco, struct client *clientes[], int posicao){
    if(banco!= NULL && clientes[posicao != NULL]){

    clientes[posicao]->eh_seguro = 0;

        if (clientes[posicao]->res_a > banco->a || clientes[posicao]->res_a > clientes[posicao]->max_a || clientes[posicao]->res_a < 0){
    }else{
        clientes[posicao]->eh_seguro += 1;
    }

       if (clientes[posicao]->res_b > banco->b || clientes[posicao]->res_b > clientes[posicao]->max_b || clientes[posicao]->res_b < 0){
    }else{
        clientes[posicao]->eh_seguro += 1;
    }

       if (clientes[posicao]->res_c > banco->c || clientes[posicao]->res_c > clientes[posicao]->max_c || clientes[posicao]->res_c < 0){
    }else{
        clientes[posicao]->eh_seguro += 1;
    }

    if(clientes[posicao]->eh_seguro == 3){
        request_resource(&banco, &clientes[posicao], posicao);
    }

    }
}

void request_resource(struct bank *banco, struct client *clientes[], int posicao){
    if (banco != NULL && clientes[posicao] != NULL){
        if(clientes[posicao]->eh_seguro == 3){

            if (clientes[posicao]->res_a != 0){}
            clientes[posicao]->alocado_a = clientes[posicao]->res_a;
            banco->a -= clientes[posicao]->alocado_a;
            clientes[posicao]->eh_seguro +=1;
        }

        if (clientes[posicao]->res_b != 0){
            clientes[posicao]->alocado_b = clientes[posicao]->res_b;
            banco->b -= clientes[posicao]->alocado_b;
            clientes[posicao]->eh_seguro +=1;
        }

        if (clientes[posicao]->res_c != 0){
            clientes[posicao]->alocado_c = clientes[posicao]->res_c;
            banco->c -= clientes[posicao]->alocado_c;
            clientes[posicao]->eh_seguro +=1;
        }
    
    }
}

void release_resource(struct bank *banco, struct client *clientes[], int posicao, int rel_a, int rel_b, int rel_c){
    if(rel_a > 0){
        clientes[posicao]->alocado_a -= rel_a;
        banco->a += rel_a;
    }

    if(rel_b > 0){
        clientes[posicao]->alocado_b -= rel_b;
        banco->b += rel_b;
    }
    
    if(rel_c > 0){
        clientes[posicao]->alocado_c -= rel_c;
        banco->c += rel_c;
    }

}


void verificador_release_resource(struct bank *banco, struct client *clientes[], int posicao, int rel_a, int rel_b, int rel_c){

    int verificador_a = 0, verificador_b = 0 , verificador_c = 0;
    if (banco!= NULL && clientes[posicao] != NULL){
        if (rel_a > 0){
            if (clientes[posicao]->alocado_a < rel_a){
                verificador_a +=1;
                clientes[posicao]->eh_seguro += 1;
            }
        }else{
            verificador_a += 2;
            clientes[posicao]->eh_seguro += 1;
        }

        if (rel_b > 0){
            if (clientes[posicao]->alocado_b < rel_b){
                verificador_b +=1;
                clientes[posicao]->eh_seguro += 1;
            }
        }else{
            verificador_b += 2;
            clientes[posicao]->eh_seguro += 1;
        }
    
        if (rel_c > 0){
            if (clientes[posicao]->alocado_c < rel_c){
                verificador_c +=1;
                clientes[posicao]->eh_seguro += 1;
            }
        }else{
            verificador_c += 2;
            clientes[posicao]->eh_seguro += 1;
        }

        if (verificador_a == 0 && verificador_b == 0 && verificador_c == 0){
            release_resource(banco, clientes ,posicao, rel_a, rel_b, rel_c );
        }else{

        }
    }  
}

void printar_resultados(struct bank *banco, struct client *clientes[], int n_clientes, FILE *resultado){
    if(clientes != NULL){

        fprintf(resultado,"MAXIMUM | ALLOCATION | NEED\n");

        for (int i = 0; i<n_clientes; i++){
            int need_a = clientes[i]->max_a - clientes[i]->alocado_a;
            int need_b = clientes[i]->max_b - clientes[i]->alocado_b;
            int need_c = clientes[i]->max_c - clientes[i]->alocado_c;

            fprintf(resultado,"%d %d %d | %d %d %d | %d %d %d\n", clientes[i]->max_a, clientes[i]->max_b, clientes[i]->max_c, clientes[i]->alocado_a, clientes[i]->alocado_b, clientes[i]->alocado_c, need_a, need_b, need_c);
        }
        fprintf(resultado,"AVAILABLE %d %d %d", banco->a, banco->b, banco->c);
    }
}


void iniciar_cliente(struct client *clientes[], int posicao, int unidade_a, int unidade_b, int unidade_c){
        clientes[posicao]->max_a = unidade_a;
        clientes[posicao]->max_b = unidade_b;
        clientes[posicao]->max_c = unidade_c;
        
        clientes[posicao]->alocado_a = 0;
        clientes[posicao]->alocado_b = 0;
        clientes[posicao]->alocado_c = 0;  
}

void iniciar_banco(struct bank *banco, int unidade_a, int unidade_b, int unidade_c){
    if (banco != NULL){
        banco->a = unidade_a;
        banco->b = unidade_b;
        banco->c = unidade_c;
    }
}



int main(int argc, char *argv[]){
    int a,b,c;

    if(argc !=2){
        return 0;
    }

    int quantidade = sscanf(argv[1], "%d,%d%,d", &a, &b, &c);
    struct bank *banco = malloc(sizeof(struct bank));

    if (banco == NULL){
        return 0;
    }
    
    if (quantidade == 3){
    iniciar_banco(&banco,a,b,c);
    }else{
        return 0;
    }

    FILE *customer_file  = fopen("customer.txt", "r");

    
    if (customer_file != NULL){
        char linha[1000];
        char *line;
        int a,b,c;
        int i = 0;
        line = fgets(linha, sizeof(linha), customer_file);

        while(line != NULL){
            i+=1;
            line = fgets(linha, sizeof(linha), customer_file);
        }

        struct client *clientes = malloc(i*sizeof(struct client));

        if (clientes != NULL){
            rewind(customer_file);
            line = fgets(linha, sizeof(linha), customer_file);

            int j = 0;

            while(line != NULL && j != i){
                int verificador = sscanf(linha, "%d,%d,%d", &a,&b,&c);

                if(verificador == 3){
                    iniciar_cliente(&clientes,j,a,b,c);
                }
                line = fgets(linha, sizeof(linha), customer_file);
                j+=1;
            }


        }
    }else{
        return 0;
    }

    FILE *resultado = fopen("result.txt","w");

    if (resultado != NULL){
        return 0;
    }
}