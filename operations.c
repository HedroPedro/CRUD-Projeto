#include "operations.h"

    uint qtdItens;

    remedio* initialize(remedio *remedios, char *path){
        FILE *fp = fopen(path, "r");
        remedio remedioTmp;
        char strTmpNome[MAXSIZE], strTmpFab[MAXSIZE];
        uint size = 0;
        if(!fp){
            fprintf(stderr,"ERRO AO CRIAR ARQUIVO!");
            exit(EXIT_FAILURE);
        }
        
        remedios = (remedio *) malloc(sizeof(remedio));

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
            strcpy(remedios[size-1].fabricante, strTmpFab);
        }

        qtdItens = size;
        fclose(fp);

        return remedios;
    }


    void addRemedio(remedio *remedios, char *path){
        remedio remedioTmp;
        char strTmpNome[MAXSIZE+1], strTmpFab[MAXSIZE+1];
        uint eGenerico;
        FILE *fp = fopen(path, "a");
        printf("Digite o id: ");
        scanf("%u", &remedioTmp.id);
        setbuf(stdin, NULL);
        printf("Digite o nome: ");
        fgets(strTmpNome, MAXSIZE+1, stdin);
        printf("Digite o preco: ");
        scanf("%f", &remedioTmp.preco);
        printf("Digite a quantidade: ");
        scanf("%u", &remedioTmp.qtd);
        printf("Digite a categoria: ");
        scanf("%u", &remedioTmp.categoria);
        printf("Digite se e generico: (0 para caso nao for)");
        scanf("%u", &eGenerico);
        if(!eGenerico){
            remedioTmp.ehGenerico = true; 
        }else{
            remedioTmp.ehGenerico = false;
        }
        printf("Digite o fabricante: ");
        setbuf(stdin, NULL);
        fgets(strTmpFab, MAXSIZE+1, stdin);
        qtdItens++;
        remedios = (remedio *) realloc(remedios, sizeof(remedio) * qtdItens);

        strTmpNome[strcspn(strTmpNome, "\n")] = 0;
        strTmpFab[strcspn(strTmpFab, "\n")] = 0;
        remedios[qtdItens-1] = remedioTmp;
        remedios[qtdItens-1].nome = (char *) malloc(sizeof(char) * strlen(strTmpNome));
        remedios[qtdItens-1].fabricante = (char *) malloc(sizeof(char) * strlen(strTmpFab)); 

        strcpy(remedios[qtdItens-1].nome, strTmpNome);
        strcpy(remedios[qtdItens-1].fabricante, strTmpFab);


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
            printf("generico? ");
            if(remedios[i].ehGenerico)
                printf("Verdadeiro\n");
            else
                printf("Falso\n");
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
                printf("| id: %u\n", remedios[i].id);
                printf("| nome: %s\n", remedios[i].nome);
                printf("| preco: %f\n", remedios[i].preco);
                printf("| generico? ");
                if(remedios[i].ehGenerico)
                    printf("Verdadeiro\n");
                else
                    printf("Falso\n");
                printf("| quantidade: %u\n", remedios[i].qtd);
                printf("| categoria: %u\n", remedios[i].categoria);
                printf("| fabricante: %s\n\n", remedios[i].fabricante);
                return;
            }
        }
        printf("Id não foi encontrado.\n\n");
    }


    void updateRemedio(remedio *remedios, char *path){
        FILE *fp = fopen(path, "w");
        char strTmp[MAXSIZE+1];
        bool achouId = 0;
        uint idNumero;
        uint i;
        uint eGenerico;

        printf("Digite o ID do remedio que voce quer alterar dados: ");
        scanf("%u", &idNumero);

        for (i = 0; i < qtdItens; i++){
            if(idNumero == remedios[i].id){
                remedios[i].qtd = 0;
                achouId = 1;
                break;
            }
        }

        if(!achouId){
            printf("Id não foi encontrado.\n\n");
            fclose(fp);
            return;
        }    

        printf("Alterar dados: \n");
        printf("Digite o nome: ");
        setbuf(stdin, NULL);
        fgets(strTmp, MAXSIZE+1, stdin);
        strTmp[strcspn(strTmp, "\n")] = 0;
        remedios[i].nome = realloc(remedios[i].nome, sizeof(char) * strlen(strTmp));
        strcpy(remedios[i].nome, strTmp);
        printf("Digite o preco: ");
        scanf("%f", &remedios[i].preco);
        printf("Digite a quantidade: ");
        scanf("%u", &remedios[i].qtd);
        printf("Digite a categoria: ");
        scanf("%u", &remedios[i].categoria);
        printf("Digite se e generico: (0 para caso nao for):");
        scanf("%u", &eGenerico);
        if(eGenerico){
            remedios[i].ehGenerico = true; 
        }else{
            remedios[i].ehGenerico = false;
        }

        printf("Digite o fabricante: ");
        setbuf(stdin, NULL);
        fgets(strTmp, MAXSIZE+1, stdin);
        remedios[i].fabricante = realloc(remedios[i].fabricante, sizeof(char) * strlen(strTmp));
        strcpy(remedios[i].fabricante, strTmp);

        salvarDados(remedios, path);

        fclose(fp);
    }
    

    void removeRemedio(remedio *remedios, char *path){

        FILE *fp = fopen(path, "w");

        bool achouId = 0;
        uint idNumero;

        printf("Digite o ID do remedio que voce quer remover: ");
        scanf("%u", &idNumero);

        for (uint i = 0; i < qtdItens; i++){
            if(idNumero == remedios[i].id){
                remedios[i].qtd = 0;
                achouId = 1;
                break;
            }
        }
        if(!achouId){
            printf("Id não foi encontrado.\n\n");
            return;
        }

        salvarDados(remedios, path);

        fclose(fp);
    }

    void salvarDados(remedio *remedios, char *path){

        FILE *fp = fopen(path, "w");

        for(uint i = 0; i < qtdItens; i++){
            fprintf(fp, "id: %u\n", remedios[i].id);
            fprintf(fp, "nome: %s\n", remedios[i].nome);
            fprintf(fp, "preco: %f\n", remedios[i].preco);
            fprintf(fp, "generico: %d\n", remedios[i].ehGenerico);
            fprintf(fp, "quantidade: %u\n", remedios[i].qtd);
            fprintf(fp, "categoria: %u\n", remedios[i].categoria);
            fprintf(fp, "fabricante: %s\n", remedios[i].fabricante);
        }

        fclose(fp);
    }