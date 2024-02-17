#include "operations.h"

#define FILEPATH "./estoque.txt"

int main(){
    remedio *remedios = initialize(remedios, FILEPATH);
    uint opcao, qtd;
    //qtd = initialize(remedios, FILEPATH);
    printf("-- Seja Bem-Vindo!! --\n");

    while(1){
        printf("O que deseja fazer agora?\n");
        printf("1 - Adicionar um remédio\n");
        printf("2 - Ver todos os produtos\n");
        printf("3 - Procurar um remédio\n");
        printf("4 - Renovar remedio\n");
        printf("5 - APAGAR UM REMEDIO DA EXISTENCIA\n");
        printf("6 - Nada mais a cer feito\n\n");    
        scanf("%d", &opcao);

        switch (opcao){
            case 1:
                addRemedio(remedios, FILEPATH);
                break;
            case 2:
                showAll(remedios);
                break;
            case 3:
                showRemedioById(remedios);
                break;
            case 4:
                updateRemedio(remedios, FILEPATH);
                break;
            case 5:
                removeRemedio(remedios, FILEPATH);
                break;
            case 6:
                for(uint i = 0; i < qtd; i++){
                    free(remedios[i].nome);
                    free(remedios[i].fabricante);
                }
                free(remedios);
                exit(1);
            default:
                printf("Essa opcao nao pode ser escolhida, escolha outra!\n\n");
                break;
        }
    }
}
