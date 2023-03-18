//
// Created by Daniel on 15/03/2023.
//
#include "stdlib.h"
#include "string.h"
#include "stdio.h"
#include "gestor.h"

// Inserção de um novo registo
Gestores* inserirGestores(Gestores* inicio, int numGest, char name[], char mail[], int nif) {
    if (!existeGestores(inicio, numGest)) {
        Gestores* novo = malloc(sizeof(Gestores));
        if (novo != NULL) {
            novo->numGest = numGest;
            strcpy(novo->nome, name);
            strcpy(novo->email, mail);
            novo->nif = nif;
            novo->prox = inicio;
            return novo;
        }
    } else {
        printf("Já existe um gestor com este número.\n");
        return inicio;
    }
}

// listar na consola o conteúdo da lista ligada
void listarGestores(Gestores* inicio) {
    while (inicio != NULL) {
        printf("%d %s %s %d\n", inicio->numGest, inicio->nome, inicio->email, inicio->nif);
        inicio = inicio->prox;
    }
}

// Determinar existência do 'numGest' na lista ligada 'inicio'
// devolve 1 se existir ou 0 caso contrário
int existeGestores(Gestores* inicio, int cod) {
    while (inicio != NULL) {
        if (inicio->numGest == cod)
            return 1;
        inicio = inicio->prox;
    }
    return 0;
}

// Remover um gestor a partir do seu código
void removerGestores(Gestores* inicio, int numGest) {
    Gestores* anterior = inicio, *atual = inicio;

    if (atual == inicio) {
        inicio = inicio->prox;
        free(atual);
    } else {
        while ((atual != NULL) && (atual->numGest != numGest)) {
            anterior = atual;
            atual = atual->prox;
        }
        if (atual != NULL) {
            anterior->prox = atual->prox;
            free(atual);
        }
    }
}

//Função para preservar dados
int guardarGestores(Gestores* inicio)
{
    FILE* fp;
    fp = fopen("Gestores.bin","wb");
    if (fp!=NULL)
    {
        Gestores* aux= inicio;
        while (aux != NULL)
        {
            fprintf(fp,"%d;%s;%s;%d\n", aux->numGest, aux->nome,aux->email, aux->nif);
            aux = aux->prox;
        }
        fclose(fp);
        return(1);
    }
    else return(0);
}