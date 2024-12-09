#ifndef JOGO_
#define JOGO_

#define TAMANHO_NOME 20
#define MAX_TURNOS 9

typedef enum forma
{
  circulo = 1,
  xis
} FORMA;

typedef struct player
{
  char nome[TAMANHO_NOME];
  FORMA forma;
  int vitorias;
  int derrotas;
  int empates;
} PLAYER;

typedef struct tabuleiro
{
  int turno;
  char se;
  char sm;
  char sd;
  char ce;
  char cm;
  char cd;
  char ie;
  char im;
  char id;

} TABULEIRO;

// QUALIDADES DE VIDA:
int turnoParOuImpar(int turno);
PLAYER turnoJogador(int ordem, int turno, PLAYER player1, PLAYER player2);
char conversaoFormaChar(FORMA forma);
FORMA conversaoCharForma(char input);

// TABULEIRO:
void limparTabuleiro(TABULEIRO *tabuleiro);
void imprimirTabuleiro(TABULEIRO tabuleiro);

// JOGADA:
void fazerJogada(int ordem, TABULEIRO *tabuleiro, PLAYER jogador1, PLAYER jogador2);
void realizarMovimento(TABULEIRO *tabuleiro, int jogada, PLAYER jogador);

// VITÓRIA:
FORMA linhaFeita(TABULEIRO tabuleiro);
FORMA colunaFeita(TABULEIRO tabuleiro);
FORMA diagonalFeita(TABULEIRO tabuleiro);
FORMA vitoria(TABULEIRO tabuleiro);

void telaFinal(TABULEIRO tabuleiro, PLAYER jogador1, PLAYER jogador2);
void velha(TABULEIRO tabuleiro);

#endif