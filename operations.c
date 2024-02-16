#include "operations.h"

    FILE *initialize(remedio *remedios, char *path){
        FILE *fp = fopen(path, "w+");

        int i = 1;
        remedios = (remedio *) malloc(sizeof(remedio));
        if(!fp){
        fprintf(stderr,"ERRO AO CRIAR ARQUIVO!");
        exit(EXIT_FAILURE);
        }

        while(!feof(fp)){
            remedios = (remedio *) realloc(remedios, sizeof(remedio) * i);
            fscanf(fp, "id: %u", &remedios[i-1].id);
            fscanf(fp, "nome: %s", &remedios[i-1].nome);
            fscanf(fp, "preco: %f", &remedios[i-1].preco);
            fscanf(fp, "");
            i++;
        }
    }
    void addRemedio(void){}
    void showAll(void){}
    void showRemedioById(void){}
    void updateRemedio(void){}
    void removeRemedio(void){}