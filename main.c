#include <stdio.h>
#include <stdlib.h>
#include "lista.h"


void adiciona_musica(Lista li, Musica m) {
    inserir_final(li, m);
}

void adiciona_musica_posicao(Lista li, Musica m, int posicao) {
    inserir_posicao(li, m, posicao);
}

void remove_musica(Lista li, int posicao) {
    remover_posicao(li, posicao);
}

int tempo_restante(Lista li, int pos_atual) {
    int total_restante = 0;
    int qtd = quantidade_musicas(li);
    
    for (int i = pos_atual; i < qtd; i++) {
        Musica m = consultar_posicao(li, i);
        if (m != NULL) {
            char titulo[100], artista[100];
            int duracao;
            consultar_musica(m, titulo, artista, &duracao);
            total_restante += duracao;
        }
    }
    return total_restante;
}

void play(Lista li, int *pos_atual) {
    int qtd = quantidade_musicas(li);
    if (*pos_atual >= qtd) {
        printf("A playlist chegou ao fim.\n");
        return;
    }
    
    Musica atual = consultar_posicao(li, *pos_atual);
    printf(">> TOCANDO AGORA: ");
    imprimir_musica(atual);
    
    (*pos_atual)++; 
}

int musicas_reproduzidas(int pos_atual) {
    return pos_atual;
}

int main() {
    Lista playlist = criar_lista();
    int pos_atual = 0; // Controla qual música será tocada

    // Criando as 10 músicas diretamente no código
    Musica m1 = criar_musica("Foi assim", "Sotam", 147);
    Musica m2 = criar_musica("Beatriz", "2zDinizz", 247);
    Musica m3 = criar_musica("Músicas de amor nunca mais", "Bk", 202);
    Musica m4 = criar_musica("Planos", "Bk", 219);
    Musica m5 = criar_musica("Te encontrar na lapa", "2zDinizz", 195);
    Musica m6 = criar_musica("Samba in paris", "Baco", 266);
    Musica m7 = criar_musica("Solto", "Djonga", 219);
    Musica m8 = criar_musica("Confissões", "Dfideliz", 213);
    Musica m9 = criar_musica("O mundo é nosso", "Djonga", 223);
    Musica m10 = criar_musica("20 ligações", "Baco", 193);

    adiciona_musica(playlist, m1);
    adiciona_musica(playlist, m2);
    adiciona_musica(playlist, m3);
    adiciona_musica(playlist, m4);
    adiciona_musica(playlist, m5);
    adiciona_musica(playlist, m6);
    adiciona_musica(playlist, m7);
    adiciona_musica(playlist, m8);
    adiciona_musica(playlist, m9);
    
    adiciona_musica_posicao(playlist, m10, 2);

    remove_musica(playlist, 5);

    printf("--- INICIANDO A PLAYLIST ---\n");
    play(playlist, &pos_atual);
    play(playlist, &pos_atual);
    play(playlist, &pos_atual);
    
    printf("\n--- STATUS DA PLAYLIST ---\n");
    printf("Musicas ja reproduzidas: %d\n", musicas_reproduzidas(pos_atual));
    printf("Tempo restante: %d segundos\n", tempo_restante(playlist, pos_atual));
    
    printf("\n--- RESUMO FINAL ---\n");
    printf("Quantidade total de musicas na playlist: %d\n", quantidade_musicas(playlist));
    printf("Posicao da proxima musica a ser reproduzida: %d\n", pos_atual);

    destruir_lista(playlist);

    return 0;
}