//
// Created by Daniel on 15/03/2023.
//

#ifndef TESTE_CLIENTES_H
#define TESTE_CLIENTES_H

// Estrutura para representar um cliente
typedef struct Cliente {
    int numCl;
    char nome[50];
    char email[50];
    int nif;
    float saldo;
    struct Cliente *prox;
} Clientes;

#pragma region Funcs
int guardarClientes(Clientes* inicio);
Clientes* lerClientes();
Clientes* inserirClientes(Clientes * inicio, int numCl, char name[], char mail[], int nif, float saldo);
void listarClientes(Clientes * inicio);
int existeClientes(Clientes* inicio, int cod);
void removerClientes(Clientes* inicio, int numCl);
void alterarSaldo(Clientes * inicio, int numCl, float novoSaldo);
Clientes *procurarClientes(Clientes * inicio, int numCl);
#pragma endregion Funcs

#endif //TESTE_CLIENTES_H
