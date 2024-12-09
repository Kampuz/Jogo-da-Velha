#include "menu.h"
#include "jogo.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// QUALIDADES DE VIDA:

void limparBuffer() { getchar(); }
void limparConsole() { system("clear"); }

void arrumarNome(char *nome) {
  int tamanho = strlen(nome);

  if ((tamanho > 0) && (nome[tamanho - 1] == '\n'))
    nome[tamanho - 1] = '\0';
}

int inputInvalido(int input) {
  if ((input == 1) || (input == 2))
    return 0;
  else
    return 1;
}

// MENUS:

void bemVindo() {
  limparConsole();
  printf("Bem-Vindo ao jogo da velha feito por Miguel.\n");
  printf("Aperte [ENTER] para continuar.\n");
  limparBuffer();
  limparConsole();
}

void criarJogador(PLAYER *jogador1, PLAYER *jogador2) {
  limparConsole();
  printf("[NOME]:\n");
  printf("Digite o nome do player 1: ");
  fgets(jogador1->nome, TAMANHO_NOME, stdin);
  printf("Digite o nome do player 2: ");
  fgets(jogador2->nome, TAMANHO_NOME, stdin);
  arrumarNome(jogador1->nome);
  arrumarNome(jogador2->nome);
  limparConsole();

  printf("[FORMA]:\n");
  printf("1. O.\n2. X.\n\n");
  printf("Digite a forma que %s usará: ", jogador1->nome);
  scanf("%d", &jogador1->forma);
  printf("Digite a forma que %s usará: ", jogador2->nome);
  scanf("%d", &jogador2->forma);
  limparBuffer();
  limparConsole();
}

void definirOrdem(PLAYER player1, PLAYER player2, int *primeiro) {
  limparConsole();
  do {
    printf("[JOGADORES]:\n");
    printf("1. %s (%s)\n", player1.nome, formaSimbolo(player1.forma));
    printf("2. %s (%s)\n", player2.nome, formaSimbolo(player2.forma));
    printf("Primeiro a jogar (número): ");
    scanf("%d", primeiro);
  } while (inputInvalido(*primeiro));
  limparConsole();
}

void desejaContinuar(int *continuar) {
  printf("Deseja jogar novamente?\n1. sim.\n0. não.\nDigite: ");
  scanf("%d", continuar);
}