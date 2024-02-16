#include "operations.h"

    uint qtdItens;

    FILE *initialize(remedio *remedios, char *path){
        FILE *fp = fopen(path, "w+");
        remedio remedioTmp;
        int size = 0;
        if(!fp){
            fprintf(stderr,"ERRO AO CRIAR ARQUIVO!");
            exit(EXIT_FAILURE);
        }
        
        remedios = (remedio *) malloc(sizeof(remedio) * size);

        while(!feof(fp)){
            fscanf(fp, "id: %u", &remedioTmp.id);
            fscanf(fp, "nome: %s", &remedioTmp.nome);
            fscanf(fp, "preco: %f", &remedioTmp.preco);
            fscanf(fp, "generico: %d", &remedioTmp.ehGenerico);
            fscanf(fp, "quantidade: %u", &remedioTmp.qtd);
            fscanf(fp, "categoria: %u", &remedioTmp.categoria);
            fscanf(fp, "fabricante: %s", &remedioTmp.fabricante);
            size++;
            remedios = (remedio *) realloc(remedios, sizeof(remedio) * size);
            remedios[size-1] = remedioTmp;
        }
        qtdItens = size;
        return fp;
    }

    void addRemedio(remedio *remedios, FILE *fp){
        remedio remedioTmp;
        printf("Digite o nome: ");
        scanf("%s");
        printf("Digite o preco: ");
        scanf("%f");
        printf("Digite a quantidade: ");
        scanf("%u");
        printf("Digite a categoria: ");
        scanf("%u");
        scanf("Digite o fabricante: ");
        qtdItens++;
        remedios = (remedio *) realloc(remedios, sizeof(remedio) * qtdItens);
        remedios[qtdItens-1] = remedioTmp;
        for(uint i = 0; i < qtdItens; i++){
            fprintf(fp, "id: %u", &remedios[i].id);
            fprintf(fp, "nome: %s", &remedios[i].nome);
            fprintf(fp, "preco: %f", &remedios[i].preco);
            fprintf(fp, "generico: %d", &remedios[i].ehGenerico);
            fprintf(fp, "quantidade: %u", &remedios[i].qtd);
            fprintf(fp, "categoria: %u", &remedios[i].categoria);
            fprintf(fp, "fabricante: %s", &remedios[i].fabricante);
        }
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

        printf("Digite o ID do produto que deseja encontrar: ");
        scanf("%u", &procuraID);

        for (uint i = 0; i < qtdItens; i++){
            if(procuraID == remedios[i].id){
                if(remedios[i].qtd == 0){
                    printf("O remedio nao esta em estoque.\n\n");
                    return;
                }
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
    
    void removeRemedio(remedio *remedios){
        uint idNumero;

        printf("Digite o ID do remedio que voce quer remover: ");
        scanf("%u", idNumero);

        for (uint i = 0; i < qtdItens; i++){
            if(idNumero == remedios[i].id){
                remedios[i].qtd = 0;
            }
        }
        printf("Id não foi encontrado.\n\n");
    }