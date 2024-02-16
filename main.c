#include "operations.h"

#define FILEPATH "./estoque.txt"

int main(){
    remedio *remedios;
    uint opcao;
    FILE *file = initialize(remedios, FILEPATH);
    while(1){
        printf("1 - Mostrar");
        switch (opcao)
        {
        case 1:
            showAll();
            break;
        
        default:
            break;
        }
    }
}