#ifndef MENU_
#define MENU_

#include "jogo.h"

// QUALIDADES DE VIDA:
void limparBuffer();
void limparConsole();
void arrumarNome(char *nome);
int inputInvalido(int input);

// MENUS:
void bemVindo();
void criarJogador(PLAYER *jogador1, PLAYER *jogador2);
void definirOrdem(PLAYER player1, PLAYER player2, int *primeiro);
void desejaContinuar(int *continuar);
#endif