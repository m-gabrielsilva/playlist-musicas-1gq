#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct no {
    Musica m;
    struct no* prox;
};
typedef struct no No;

struct lista {
    int qtd;
    No* inicio;
};

Lista criar_lista() {
    Lista li = malloc(sizeof(struct lista));
    if (li != NULL) {
        li->qtd = 0;
        li->inicio = NULL;
    }
    return li;
}

int inserir_inicio(Lista li, Musica m) {
    if (li == NULL) return 0;
    No* novo = malloc(sizeof(No));
    if (novo == NULL) return 0;
    
    novo->m = m;
    novo->prox = li->inicio;
    li->inicio = novo;
    li->qtd++;
    return 1;
}

int inserir_final(Lista li, Musica m) {
    if (li == NULL) return 0;
    if (li->inicio == NULL) return inserir_inicio(li, m);
    
    No* novo = malloc(sizeof(No));
    if (novo == NULL) return 0;
    novo->m = m;
    novo->prox = NULL;
    
    No* aux = li->inicio;
    while (aux->prox != NULL) {
        aux = aux->prox;
    }
    aux->prox = novo;
    li->qtd++;
    return 1;
}

int inserir_posicao(Lista li, Musica m, int posicao) {
    if (li == NULL || posicao < 0 || posicao > li->qtd) return 0;
    if (posicao == 0) return inserir_inicio(li, m);
    if (posicao == li->qtd) return inserir_final(li, m);
    
    No* novo = malloc(sizeof(No));
    if (novo == NULL) return 0;
    novo->m = m;
    
    No* aux = li->inicio;
    for (int i = 0; i < posicao - 1; i++) {
        aux = aux->prox;
    }
    novo->prox = aux->prox;
    aux->prox = novo;
    li->qtd++;
    return 1;
}

int remover_primeira(Lista li) {
    if (li == NULL || li->inicio == NULL) return 0;
    No* aux = li->inicio;
    li->inicio = aux->prox;
    free(aux);
    li->qtd--;
    return 1;
}

int remover_ultima(Lista li) {
    if (li == NULL || li->inicio == NULL) return 0;
    if (li->inicio->prox == NULL) return remover_primeira(li);
    
    No* aux = li->inicio;
    No* ant = NULL;
    while (aux->prox != NULL) {
        ant = aux;
        aux = aux->prox;
    }
    ant->prox = NULL;
    free(aux);
    li->qtd--;
    return 1;
}

int remover_posicao(Lista li, int posicao) {
    if (li == NULL || li->inicio == NULL || posicao < 0 || posicao >= li->qtd) return 0;
    if (posicao == 0) return remover_primeira(li);
    
    No* aux = li->inicio;
    No* ant = NULL;
    for (int i = 0; i < posicao; i++) {
        ant = aux;
        aux = aux->prox;
    }
    ant->prox = aux->prox;
    free(aux);
    li->qtd--;
    return 1;
}

Musica consultar_primeira(Lista li) {
    if (li == NULL || li->inicio == NULL) return NULL;
    return li->inicio->m;
}

Musica consultar_posicao(Lista li, int posicao) {
    if (li == NULL || li->inicio == NULL || posicao < 0 || posicao >= li->qtd) return NULL;
    No* aux = li->inicio;
    for (int i = 0; i < posicao; i++) {
        aux = aux->prox;
    }
    return aux->m;
}

int quantidade_musicas(Lista li) {
    if (li == NULL) return 0;
    return li->qtd;
}

void destruir_lista(Lista li) {
    if (li != NULL) {
        No* aux = li->inicio;
        while (aux != NULL) {
            No* apagar = aux;
            aux = aux->prox;
            free(apagar);
        }
        free(li);
    }
}