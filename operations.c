#include "operations.h"

    FILE *initialize(remedio *remedios, char *path){
        FILE *fp = fopen(path, "r");
        remedio remedioTmp;
        char strTmpNome[MAXSIZE], strTmpFab[MAXSIZE];
        int size = 0;
        if(!fp){
            fprintf(stderr,"ERRO AO CRIAR ARQUIVO!");
            exit(EXIT_FAILURE);
        }
        
        remedios = (remedio *) malloc(sizeof(remedio) * size);

        while(!feof(fp)){
            fscanf(fp, "id: %u\n", &remedioTmp.id);
            fscanf(fp, "nome: %s\n", strTmpNome);
            fscanf(fp, "preco: %f\n", &remedioTmp.preco);
            fscanf(fp, "generico: %d\n", &remedioTmp.ehGenerico);
            fscanf(fp, "quantidade: %u\n", &remedioTmp.qtd);
            fscanf(fp, "categoria: %u\n", &remedioTmp.categoria);
            fscanf(fp, "fabricante: %s\n", strTmpFab);
            size++;
            remedios = (remedio *) realloc(remedios, sizeof(remedio) * size);
            remedios[size-1] = remedioTmp;
            remedios[size-1].nome = (char * ) malloc(sizeof(char) * strlen(strTmpNome));
            remedios[size-1].fabricante = (char * ) malloc(sizeof(char) * strlen(strTmpFab));
            strcpy(remedios[size-1].nome, strTmpNome);
            strcpy(remedios[size-1].nome, strTmpFab);
        }
        qtdItens = size;
        fclose(fp);
    }

    void addRemedio(remedio *remedios, char *path){
        remedio remedioTmp;
        char strTmpNome[MAXSIZE], strTmpFab[MAXSIZE];
        FILE *fp = fopen(path, "a");
        printf("Digite o id");
        printf("%u");
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
        remedios[qtdItens-1].nome = (char *) malloc(sizeof(strTmpNome));
        remedios[qtdItens-1].fabricante = (char *) malloc(sizeof(strTmpFab)); 

        strcpy(remedios[qtdItens-1].nome, strTmpNome);
        strcpy(remedios[qtdItens-1].nome, strTmpNome);


        fprintf(fp, "id: %u\n", remedios[qtdItens-1].id);
        fprintf(fp, "nome: %s\n", remedios[qtdItens-1].nome);
        fprintf(fp, "preco: %f\n", remedios[qtdItens-1].preco);
        fprintf(fp, "generico: %d\n", remedios[qtdItens-1].ehGenerico);
        fprintf(fp, "quantidade: %u\n", remedios[qtdItens-1].qtd);
        fprintf(fp, "categoria: %u\n", remedios[qtdItens-1].categoria);
        fprintf(fp, "fabricante: %s\n", remedios[qtdItens-1].fabricante);

        fclose(fp);
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