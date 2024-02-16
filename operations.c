#include "operations.h"

    uint qtdItens;

    FILE *initialize(remedio *remedios, char *path){
        FILE *fp = fopen(path, "w+");
        remedio remedioTmp;
        char str[MAXSIZE];
        int size = 0;
        if(!fp){
            fprintf(stderr,"ERRO AO CRIAR ARQUIVO!");
            exit(EXIT_FAILURE);
        }
        
        remedios = (remedio *) malloc(sizeof(remedio) * size);

        while(!feof(fp)){
            fscanf(fp, "id: %u\n", &remedioTmp.id);
            fscanf(fp, "nome: %s\n", str);
            remedioTmp.nome = (char *) malloc(sizeof(char) * strlen(str));
            fscanf(fp, "preco: %f\n", &remedioTmp.preco);
            fscanf(fp, "generico: %d\n", &remedioTmp.ehGenerico);
            fscanf(fp, "quantidade: %u\n", &remedioTmp.qtd);
            fscanf(fp, "categoria: %u\n", &remedioTmp.categoria);
            fscanf(fp, "fabricante: %s\n", &remedioTmp.fabricante);
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
        fseek(fp, 0, SEEK_END);
        for(uint i = 0; i < qtdItens; i++){
            fprintf(fp, "id: %u\n", qtdItens);
            fprintf(fp, "nome: %s\n", remedios[i].nome);
            fprintf(fp, "preco: %f\n", remedios[i].preco);
            fprintf(fp, "generico: %d\n", remedios[i].ehGenerico);
            fprintf(fp, "quantidade: %u\n", remedios[i].qtd);
            fprintf(fp, "categoria: %u\n", remedios[i].categoria);
            fprintf(fp, "fabricante: %s\n", remedios[i].fabricante);
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