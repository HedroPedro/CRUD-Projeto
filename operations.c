#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "operations.h"

    typedef unsigned int uint;

    typedef struct remedio{
        uint id;
        char *nome;
        float preco;
        uint qtd;
        bool ehGenerico;
        uint categoria;
        char *fabricante;
    };

    void initialize(void){}
    void addRemedio(void);
    void showAll(void);
    void showRemedioById(void);
    void updateRemedio(void);
    void removeRemedio(void);