//
// Created by Daniel on 15/03/2023.
//

#include "clientes.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int guardarClientes(Clientes* inicio)
{
    FILE* fp;
    fp = fopen("Clientes.bin","wb");
    if (fp!=NULL)
    {
        Clientes* aux= inicio;
        while (aux != NULL)
        {
            fprintf(fp,"%d;%s;%s;%d;%f\n", aux->numCl, aux->nome,
                    aux->email, aux->nif, aux->saldo);
            aux = aux->prox;
        }
        fclose(fp);
        return(1);
    }
    else return(0);
}

Clientes* lerClientes()
{
    FILE* fp;
    int numCl, nif;
    float saldo;
    char nome[50],email[50];
    Clientes* aux=NULL;
    fp = fopen("Clientes.txt","r");
    if (fp!=NULL)
    {
        while (!feof(fp))
        {
            fscanf(fp,"%d;%[^\n]s;%[^\n]s;%d;%f\n", &numCl, nome, email, &nif, &saldo);
            aux = inserirClientes(aux, numCl, nome, email, nif, saldo);
        }
        fclose(fp);
    }
    return(aux);
}

Clientes* inserirClientes(Clientes * inicio, int numCl, char name[], char mail[], int nif, float saldo)
{
    if (!existeClientes(inicio, numCl))
    {
        Clientes * novo = malloc(sizeof(struct Clientes));
        if (novo != NULL)
        {
            novo->numCl = numCl;
            strcpy(novo->nome,name);
            strcpy(novo->email,mail);
            novo->nif = nif;
            novo->saldo = saldo;
            novo->prox = inicio;
            return(novo);
        }
    }
    else return inicio;
}

void listarClientes(Clientes * inicio)
{
    while (inicio != NULL)
    {
        printf("%d %s %s %d %.2f\n",inicio->numCl,inicio->nome,
               inicio->email, inicio->nif, inicio->saldo);
        inicio = inicio->prox;
    }
}

int existeClientes(Clientes* inicio, int cod)
{
    while(inicio!=NULL)
    {
        if (inicio->numCl == cod) return(1);
        inicio = inicio->prox;
    }
    return(0);
}

void removerClientes(Clientes* inicio, int numCl)
{
    Clientes *anterior=inicio, *atual=inicio;

    if (atual == inicio) {
        inicio = inicio->prox;
        free(atual);
    } else {
        while ((atual != NULL) && (atual->numCl != numCl)) {
            anterior = atual;
            atual = atual->prox;
        }
        if (atual != NULL) {
            anterior->prox = atual->prox;
            free(atual);
        }
    }
}

// Função para alterar o saldo de um cliente com base no número do cliente
void alterarSaldo(Clientes * inicio, int numCl, float novoSaldo)
{
    Clientes *cliente = procurarClientes(inicio, numCl);
    if (cliente != NULL) {
        cliente->saldo = novoSaldo;
    }
}

// Função para procurar um cliente com base no número do cliente
Clientes *procurarClientes(Clientes * inicio, int numCl)
{
    Clientes *cliente = inicio;
    while (cliente != NULL) {
        if (cliente->numCl == numCl) {
            return cliente;
        }
        cliente = cliente->prox;
    }
    return NULL;
}
