//
// Created by Daniel on 18/03/2023.
//

#include "aluguer.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
//Inserir Alugueres na lista
Aluguer * inserirAluguer(Aluguer * inicio, int numCl, int numSerie, char locIn[], char locFi[])
{
        Aluguer * novo = malloc(sizeof(struct Aluguer));
        if (novo != NULL)
        {
            novo->numCl = numCl;
            novo->numSerie = numSerie;
            strcpy(novo->locIn,locIn);
            strcpy(novo->locFi,locFi);
            return(novo);
        }
}

//Preservar os dados
int guardarAluguer(Aluguer* inicio)
{
    FILE* fp;
    fp = fopen("Aluguer.bin","wb");
    if (fp!=NULL)
    {
        Aluguer * aux= inicio;
        while (aux != NULL)
        {
            fprintf(fp,"%d;%d;%s;%s\n", aux->numCl, aux->numSerie,
                    aux->locIn, aux->locFi);
            aux = aux->prox;
        }
        fclose(fp);
        return(1);
    }
    else return(0);
}