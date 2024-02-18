#ifndef OPERATIONS_H_

#define OPERATIONS_H_
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

    #define MAXSIZE 128
    
    typedef unsigned int uint;

    typedef struct remedio{
        uint id;
        char *nome;
        float preco;
        uint qtd;
        bool ehGenerico;
        uint categoria;
        char *fabricante;
    } remedio;

    remedio* initialize(remedio *remedios, char *path, uint *qtd);
    
    void addRemedio(remedio *remedios, char *path);
    void showAll(remedio *remedios);
    void showRemedioById(remedio *remedios);
    void updateRemedio(remedio *remedios, char *path);
    void removeRemedio(remedio *remedios, char *path);

    void salvarDados(remedio *remedios, char *path);

#endif