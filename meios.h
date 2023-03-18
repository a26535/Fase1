//
// Created by Daniel on 15/03/2023.
//
#ifndef MEIOSMOBILIDADE_H
#define MEIOSMOBILIDADE_H
#define MAXSTR 50
#define MAXTP 20
#include "stdlib.h"
#include "string.h"
#include "stdio.h"

typedef struct dadosMeiosMobilidade{
    int numSerie;
    char tipo[MAXTP];
    char loc[MAXSTR];
    int bateria;
    int autonomia;
} MeiosMobilidade;


MeiosMobilidade* inserirMeioMobilidade(MeiosMobilidade * inicio, int numSerie, char tipo[], char loc[], int bateria, int autonomia);
void listarMeiosMobilidade(MeiosMobilidade * inicio);
int existeMeioMobilidade(MeiosMobilidade* inicio, int numSerie);
void removerMeioMobilidade(MeiosMobilidade* inicio, int numSerie);
int guardarMeiosMobilidade(MeiosMobilidade* inicio);
MeiosMobilidade* lerMeiosMobilidade();
void alterarBateria(MeiosMobilidade * inicio, int numSerie, int novaBateria, int novaAutonomia);
MeiosMobilidade *procurarMeios(MeiosMobilidade * inicio, int numSerie);
void listarAutonomia(MeiosMobilidade *meiosMobilidade, int numMeiosMobilidade);

#endif /* MEIOSMOBILIDADE_H */
