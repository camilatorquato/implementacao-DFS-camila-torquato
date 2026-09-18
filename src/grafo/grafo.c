#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

Grafo *criarGrafo() {
    Grafo *g = (Grafo *) malloc(sizeof(Grafo));
    if (g == NULL) return NULL;
    for (int i = 0; i < MAX_VERTICES; i++) {
        g->listaAdj[i] = NULL;
        for (int j = 0; j < MAX_VERTICES; j++) {
            g->matrizAdj[i][j] = false;
        }
    }
    return g;
}
bool inserirAresta(Grafo *g, int origem, int destino) {
    if (g == NULL || origem < 0 || origem >= MAX_VERTICES || destino < 0 || destino >= MAX_VERTICES) {
        return false;
    }
    g->matrizAdj[origem][destino] = true;
    No *novo = (No *) malloc(sizeof(No));
    if (novo == NULL) return false;
    novo->vertice = destino;
    novo->prox = g->listaAdj[origem];
    g->listaAdj[origem] = novo;
    return true;
}
bool existeAresta(Grafo *g, int origem, int destino) {
    if (g == NULL || origem < 0 || origem >= MAX_VERTICES || destino < 0 || destino >= MAX_VERTICES) {
        return false;
    }
    return g->matrizAdj[origem][destino];
}
void destruirGrafo(Grafo *g) {
    if (g == NULL) return;
    for (int i = 0; i < MAX_VERTICES; i++) {
        No *atual = g->listaAdj[i];
        while (atual != NULL) {
            No *temp = atual;
            atual = atual->prox;
            free(temp);
        }
    }
    free(g);
}
