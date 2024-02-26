#include "operations.h"

    uint qtdItens;

    remedio* initialize(remedio *remedios, char *path, uint *qtd){
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
            remedios[size-1].nome = (char * ) malloc(sizeof(char) * (strlen(strTmpNome)+1));
            remedios[size-1].fabricante = (char * ) malloc(sizeof(char) * (strlen(strTmpFab)+1));
            strcpy(remedios[size-1].nome, strTmpNome);
            strcpy(remedios[size-1].fabricante, strTmpFab);
        }

        qtdItens = size;
        fclose(fp);

        (*qtd) = size;

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
        printf("Digite a categoria:\n");
        while(true){
            printf(" 1 - Analgesico\n");
            printf(" 2 - Anti-inflamatorio\n");
            printf(" 3 - Calmantes\n");
            printf(" 4 - Sedativos\n");
            printf(" 5 - Diureticos\n");
            scanf("%u", &remedioTmp.categoria);
            if (remedioTmp.categoria < 6 && remedioTmp.categoria > 0){
                break;
            }
            printf("Esse valor nao esta disponivel. Escolha outro: \n");
        }
        
        printf("Digite se e generico: (0 para caso nao for)");
        scanf("%u", &eGenerico);
        if(eGenerico){
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
        remedios[qtdItens-1].nome = (char *) malloc(sizeof(char) * (strlen(strTmpNome)+1));
        remedios[qtdItens-1].fabricante = (char *) malloc(sizeof(char) * (strlen(strTmpFab)+1)); 

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
            printf("generico: ");
            if(remedios[i].ehGenerico)
                printf("Verdadeiro\n");
            else
                printf("Falso\n");
            printf("quantidade: %u\n", remedios[i].qtd);
            printf("categoria: ");
                switch (remedios[i].categoria){
                case 1:
                    printf("analgesico\n");
                    break;                
                case 2:
                    printf("anti-inflamatorio\n");
                    break;
                case 3:
                    printf("calmante\n");
                    break;
                case 4:
                    printf("sedativo\n");
                    break;
                case 5:
                    printf("diruetico\n");
                    break;
                default:
                    break;
                }
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
                printf("generico? ");
                if(remedios[i].ehGenerico)
                    printf("Verdadeiro\n");
                else
                    printf("Falso\n");
                printf("quantidade: %u\n", remedios[i].qtd);
                printf("categoria: ");
                switch (remedios[i].categoria){
                case 1:
                    printf("analgesico\n");
                    break;                
                case 2:
                    printf("anti-inflamatorio\n");
                    break;
                case 3:
                    printf("calmante\n");
                    break;
                case 4:
                    printf("sedativo\n");
                    break;
                case 5:
                    printf("diruetico\n");
                    break;
                default:
                    break;
                }
                printf("fabricante: %s\n\n", remedios[i].fabricante);
                return;
            }
        }
        printf("Id nao foi encontrado.\n\n");
    }


    void updateRemedio(remedio *remedios, char *path){
        char strTmp[MAXSIZE+1];
        bool achouId = false;
        uint idNumero;
        uint i;
        uint eGenerico;

        printf("Digite o ID do remedio que voce quer alterar dados: ");
        scanf("%u", &idNumero);

        for (i = 0; i < qtdItens; i++){
           if(idNumero == remedios[i].id){
                achouId = true;
                break;
           }
        }
        if(!achouId){
            printf("Id não foi encontrado.\n\n");
            salvarDados(remedios, path);
            return;
        }    

        printf("Alterar dados: \n");
        printf("Digite o nome: ");
        setbuf(stdin, NULL);
        fgets(strTmp, MAXSIZE+1, stdin);
        strTmp[strcspn(strTmp, "\n")] = 0;
        remedios[i].nome = realloc(remedios[i].nome, sizeof(char) * (strlen(strTmp)+1));
        strcpy(remedios[i].nome, strTmp);
        printf("Digite o preco: ");
        scanf("%f", &remedios[i].preco);
        printf("Digite a quantidade: ");
        scanf("%u", &remedios[i].qtd);
        while(true){
            printf(" 1 - Analgesico\n");
            printf(" 2 - Anti-inflamatorio\n");
            printf(" 3 - Calmantes\n");
            printf(" 4 - Sedativos\n");
            printf(" 5 - Diureticos\n");
            scanf("%u", &remedios[i].categoria);
            if (remedios[i].categoria < 6 && remedios[i].categoria > 0){
                break;
            }
            printf("Esse valor nao esta disponivel. Escolha outro: \n");
        }
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
        remedios[i].fabricante = realloc(remedios[i].fabricante, sizeof(char) * (strlen(strTmp)+1));
        strTmp[strcspn(strTmp, "\n")] = 0;
        strcpy(remedios[i].fabricante, strTmp);

        salvarDados(remedios, path);
    }
    

    void removeRemedio(remedio *remedios, char *path){
        bool achouId = false;
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
        }

        salvarDados(remedios, path);
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