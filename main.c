#include "operations.h"

#define FILEPATH "./estoque.txt"

int main(){
    uint opcao, qtd;
    remedio *remedios = initialize(remedios, FILEPATH, &qtd);
    printf("-- Bem-Vindo ao estoque! --\n");

    while(1){
        printf("O que deseja fazer agora?\n");
        printf("1 - Adicionar um produto\n");
        printf("2 - Ver todos os produtos\n");
        printf("3 - Procurar um produto\n");
        printf("4 - Atualizar um produto\n");
        printf("5 - Remover um produto\n");
        printf("6 - Sair do estoque\n -> ");    
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
                salvarDados(remedios, FILEPATH);
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
