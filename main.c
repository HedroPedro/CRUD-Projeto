#include "operations.h"

#define FILEPATH "./estoque.txt"

int main(){
    remedio *remedios;
    uint opcao;
    FILE *file = initialize(remedios, FILEPATH);
    printf("-- Seja Bem-Vindo!! --\n");
    while(1){
        printf("O que deseja fazer agora?\n");
        printf("1 - Adicionar um remédio\n");
        printf("2 - Ver todos os produtos\n");
        printf("3 - Procurar um remédio\n");
        printf("4 - Renovar remedio\n");
        printf("5 - APAGAR UM REMEDIO DA EXISTENCIA\n");
        printf("6 - Nada mais a cer feito\n\n");    
        scanf("-> %d", &opcao);

        switch (opcao){
            case 1:
                addRemedio();
                break;
            case 2:
                showAll(remedios);
                break;
            case 3:
                showRemedioById(remedios);
                break;
            case 4:
                updateRemedio();
                break;
            case 5:
                removeRemedio();
                break;
            case 6:
                free(remedios);
                fclose(file);
                exit(1);
            default:
                printf("Essa opcao nao pode ser escolhida, escolha outra!\n\n");
                break;
        }
    }
}
