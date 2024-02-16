#ifndef OPERATIONS_H_
#define OPERATIONS_H_
#include <stdbool.h>

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

    void initialize(void);
    void addRemedio(void);
    void showAll(void);
    void showRemedioById(void);
    void updateRemedio(void);
    void removeRemedio(void);

#endif