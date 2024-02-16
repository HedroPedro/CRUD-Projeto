#include "operations.h"

    uint qtdItens;

    FILE *initialize(remedio *remedios, char *path){
        FILE *fp = fopen(path, "w+");
        remedio remedioTmp;
        int i = 0;
        remedios = (remedio *) malloc(sizeof(remedio));
        if(!fp){
        fprintf(stderr,"ERRO AO CRIAR ARQUIVO!");
        exit(EXIT_FAILURE);
        }

        while(!feof(fp)){
            fscanf(fp, "id: %u", &remedioTmp.id);
            fscanf(fp, "nome: %s", &remedioTmp.nome);
            fscanf(fp, "preco: %f", &remedioTmp.preco);
            fscanf(fp, "generico: %d", &remedioTmp.ehGenerico);
            fscanf(fp, "quantidade: %u", &remedioTmp.qtd);
            fscanf(fp, "categoria: %u", &remedioTmp.categoria);
            fscanf(fp, "fabricante: %s", &remedioTmp.fabricante);
            i++;
            remedios = (remedio *) realloc(remedios, sizeof(remedio) * i);
            remedios[i-1] = remedioTmp;
        }
        qtdItens = i;
        return fp;
    }

    void addRemedio(void){
        remedio remedioTmp;
        printf("Digite ");
    }


    void showAll(void){}
    void showRemedioById(void){}
    void updateRemedio(void){}
    void removeRemedio(void){}