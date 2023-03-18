//
// Created by Daniel on 15/03/2023.
//
#include "stdlib.h"
#include "meios.h"
#include "string.h"
#include "stdio.h"
#define MAXSTR 50
#define MAXTP 20

//Insdere meios diretamente na lista
MeiosMobilidade* inserirMeioMobilidade(MeiosMobilidade * inicio, int numSerie, char tipo[], char loc[], int bateria, int autonomia)
{
    if (!existeMeioMobilidade(inicio, numSerie))
    {
        MeiosMobilidade * novo = malloc(sizeof(MeiosMobilidade));
        if (novo != NULL)
        {
            novo->numSerie = numSerie;
            strcpy(novo->tipo,tipo);
            strcpy(novo->loc,loc);
            novo->bateria = bateria;
            novo->autonomia = autonomia;
            return(novo);
        }
    } else return inicio;
}
//lista todos sos meios de mobilidade
void listarMeiosMobilidade(MeiosMobilidade * inicio)
{
    while (inicio != NULL)
    {
        printf("%d %s %s %d %d\n",inicio->numSerie,inicio->tipo,inicio->loc,inicio->bateria,inicio->autonomia);
        inicio = inicio->prox;
    }
}
//função que vê se existe um meio de mobilidade baseado no num de serie
int existeMeioMobilidade(MeiosMobilidade* inicio, int numSerie)
{
    while(inicio!=NULL)
    {
        if (inicio->numSerie == numSerie) return(1);
        inicio = inicio->prox;
    }
    return(0);
}
//Função para remover um meio de mobilidade mas apenas da lista ligada
void removerMeioMobilidade(MeiosMobilidade* inicio, int numSerie)
{
    MeiosMobilidade *anterior=inicio, *atual=inicio;

    if (atual == inicio) {
        inicio = inicio->prox;
        free(atual);
    } else {
        while ((atual != NULL) && (atual->numSerie != numSerie)) {
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
int guardarMeiosMobilidade(MeiosMobilidade* inicio)
{
    FILE* fp;
    fp = fopen("MeiosMobilidade.bin","wb");
    if (fp!=NULL)
    {
        MeiosMobilidade* aux= inicio;
        while (aux != NULL)
        {
            fprintf(fp,"%d;%s;%s;%d;%d\n", aux->numSerie, aux->tipo,aux->loc, aux->bateria, aux->autonomia);
            aux = aux->prox;
        }
        fclose(fp);
        return(1);
    }
    else return(0);
}

//Lê as linhas do ficheiro MeiosMobilidade.txt e guarda como meios de mobilidade
Clientes* lerMeios()
{
    FILE* fp;
    int numSerie, bateria, autonomia;
    char loc[MAXSTR],tipo[MAXTP];

    Clientes* aux=NULL;
    fp = fopen("MeiosMobilidade.txt","r");
    if (fp!=NULL)
    {
        while (!feof(fp))
        {
            fscanf(fp,"%d;%[^;]s;%[^;]s;%d;%d\n", &numSerie, tipo, loc, &bateria, &autonomia);
            aux = inserirClientes(aux, numSerie, tipo, loc, bateria, autonomia);
        }
        fclose(fp);
    }
    return(aux);
}

// Função para alterar a bateria junto com a autonomia de um meio de mobilidade com base no número de serie
void alterarBateria(MeiosMobilidade * inicio, int numSerie, int novaBateria, int novaAutonomia)
{
    MeiosMobilidade *meios = procurarMeios(inicio, numSerie);
    if (meios != NULL) {
        meios->bateria = novaBateria;
        meios->autonomia = novaAutonomia;
    }
}

// Função para procurar um meio de mobilidade elétrica com base no número de série
MeiosMobilidade *procurarMeios(MeiosMobilidade * inicio, int numSerie)
{
    MeiosMobilidade *meios = inicio;
    while (meios != NULL) {
        if (meios->numSerie == numSerie) {
            return meios;
        }
        meios = meios->prox;
    }
    return NULL;
}

//Função para listar os meios de mobilidade elétrica por ordem decrescente de autonomia
void listarAutonomia(MeiosMobilidade *meiosMobilidade, int numMeiosMobilidade) {
    void listaPorAutonomiaDecrescente(MeiosMobilidade *lista) {
        // Cria um array auxiliar para guardar os ponteiros para os nós da lista
        MeiosMobilidade **aux = malloc(sizeof(MeiosMobilidade*) * 1000);
        int i = 0;
        // Percorre a lista e guarda os ponteiros para os nós no array auxiliar
        while (lista != NULL) {
            aux[i++] = lista;
            lista = lista->prox;
        }
        // Ordena o array de ponteiros por ordem decrescente de autonomia usando um algoritmo de bubble sort
        int j, trocou;
        do {
            trocou = 0;
            for (j = 0; j < i-1; j++) {
                if (aux[j]->autonomia < aux[j+1]->autonomia) {
                    MeiosMobilidade *temp = aux[j];
                    aux[j] = aux[j+1];
                    aux[j+1] = temp;
                    trocou = 1;
                }
            }
        } while (trocou);
        // Imprime os elementos da lista na ordem do array ordenado
        printf("Lista por ordem decrescente de autonomia:\n");
        for (j = 0; j < i; j++) {
            printf("%d %s %s %d %d\n", aux[j]->numSerie, aux[j]->tipo, aux[j]->loc, aux[j]->bateria, aux[j]->autonomia);
        }
        free(aux);
    }

}

// Função para procurar um meio de mobilidade elétrica com base no número de série
MeiosMobilidade *procurarLoc(MeiosMobilidade * inicio, char novaLoc[])
{
    MeiosMobilidade *meios = inicio;
    while (meios != NULL) {
        if (meios->loc == novaLoc) {
            printf("Número de série: %d\n", meios->numSerie);
            return meios;
        }
        meios = meios->prox;
    }
    return NULL;
}
