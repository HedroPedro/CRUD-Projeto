#ifndef OPERATIONS_H_
#define OPERATIONS_H_
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

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

    FILE *initialize(remedio *remedios, char *path);
    void addRemedio(remedio *remedios, FILE *fp);
    void showAll(void);
    void showRemedioById(void);
    void updateRemedio(void);
    void removeRemedio(void);

#endif