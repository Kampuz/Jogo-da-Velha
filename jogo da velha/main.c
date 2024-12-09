
#include "jogo.h"
#include "menu.h"

int main() {
  PLAYER player1, player2;
  TABULEIRO tabuleiro;
  int ordem, continuar;

  bemVindo();

  criarJogador(&player1, &player2);

  do {

    limparTabuleiro(&tabuleiro);

    definirOrdem(player1, player2, &ordem);

    for (tabuleiro.turno = 1; tabuleiro.turno <= MAX_TURNOS;
         tabuleiro.turno++) {

      imprimirTabuleiro(tabuleiro);

      fazerJogada(ordem, &tabuleiro, player1, player2);

      telaFinal(tabuleiro, player1, player2);

      if (vitoria(tabuleiro))
        break;
    }
    velha(tabuleiro);
    desejaContinuar(&continuar);
  } while (continuar);
}