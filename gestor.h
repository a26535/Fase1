//
// Created by Daniel on 15/03/2023.
//

#ifndef TESTE_GESTOR_H
#define TESTE_GESTOR_H

// Estrutura para representar um gestor
typedef struct Gestores {
    int numGest;
    char nome[50];
    char email[50];
    int nif;
    struct Gestores* prox;
} Gestores;

Gestores* inserirGestores(Gestores* inicio, int numGest, char name[], char mail[], int nif);
void listarGestores(Gestores* inicio);
int existeGestores(Gestores* inicio, int cod);
void removerGestores(Gestores* inicio, int numGest);


#endif //TESTE_GESTOR_H
