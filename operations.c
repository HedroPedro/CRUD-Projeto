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


    void showAll(remedio *remedios){
        for (uint i = 0; i < qtdItens; i++){
            if(remedios[i].qtd == 0){
                continue;
            }
            printf("id: %u\n", remedios[i].id);
            printf("nome: %s\n", remedios[i].nome);
            printf("preco: %f\n", remedios[i].preco);
            printf("generico: %d\n", remedios[i].ehGenerico);
            printf("quantidade: %u\n", remedios[i].qtd);
            printf("categoria: %u\n", remedios[i].categoria);
            printf("fabricante: %s\n\n", remedios[i].fabricante);
        }
    }
    
    void showRemedioById(remedio *remedios){
        uint procuraID;

        printf("Digite o ID do produto que deseja encopntrar: ");
        scanf("%u", &procuraID);

        for (uint i = 0; i < qtdItens; i++){
            if(procuraID == remedios[i].id){
                printf("id: %u\n", remedios[i].id);
                printf("nome: %s\n", remedios[i].nome);
                printf("preco: %f\n", remedios[i].preco);
                printf("generico: %d\n", remedios[i].ehGenerico);
                printf("quantidade: %u\n", remedios[i].qtd);
                printf("categoria: %u\n", remedios[i].categoria);
                printf("fabricante: %s\n\n", remedios[i].fabricante);
                return;
            }
        }
        printf("Id não foi encontrado.\n\n");
    }

    void updateRemedio(void){}
    void removeRemedio(void){}