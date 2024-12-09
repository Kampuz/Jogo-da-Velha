#include "jogo.h"
#include "menu.h"

#include <stdio.h>

int turnoParOuImpar(int turno)
{
  return ((turno % 2) + 1);
}

PLAYER turnoJogador(int ordem, int turno, PLAYER player1, PLAYER player2)
{
  int tipoTurno = turnoParOuImpar(turno);
  if (ordem != tipoTurno)
    return player1;
  else if (ordem == tipoTurno)
    return player2;
}

char conversaoFormaChar(FORMA forma)
{
  if (forma == circulo)
    return 'O';
  if (forma == xis)
    return 'X';
  return ' ';
}

FORMA conversaoCharForma(char input)
{
  switch (input)
  {
  case 'X':
    return xis;
  case 'O':
    return circulo;
  case '\0':
    return 0;
  }
}

void limparTabuleiro(TABULEIRO *tabuleiro)
{
  tabuleiro->turno = 0;
  tabuleiro->sd = '1';
  tabuleiro->sm = '2';
  tabuleiro->se = '3';
  tabuleiro->cd = '4';
  tabuleiro->cm = '5';
  tabuleiro->ce = '6';
  tabuleiro->id = '7';
  tabuleiro->im = '8';
  tabuleiro->ie = '9';
}

void imprimirTabuleiro(TABULEIRO tabuleiro)
{
  limparConsole();

  printf("TURNO: %d"
         "\n"
         "\033[4m" // faz as linhas horizontais
         "%c|%c|%c\n"
         "%c|%c|%c\n"
         "\033[0m" // para de fazer as linhas horizontais
         "%c|%c|%c\n"
         "\n",
         tabuleiro.turno,
         tabuleiro.sd, tabuleiro.sm, tabuleiro.se,
         tabuleiro.cd, tabuleiro.cm, tabuleiro.ce,
         tabuleiro.id, tabuleiro.im, tabuleiro.ie);
}

void fazerJogada(int ordem, TABULEIRO *tabuleiro, PLAYER jogador1, PLAYER jogador2)
{
  int jogada;

  printf("%s, faça sua jogada: ", turnoJogador(ordem, tabuleiro->turno, jogador1, jogador2).nome);
  scanf("%d", &jogada);
  
  realizarMovimento(tabuleiro, jogada, turnoJogador(ordem, tabuleiro->turno, jogador1, jogador2));
}

void realizarMovimento(TABULEIRO *tabuleiro, int jogada, PLAYER jogador)
{
  switch (jogada)
  {
  case 1:
    if (tabuleiro->sd == '1')
      tabuleiro->sd = formaSimbolo(jogador.forma);
    break;
  case 2:
    if (tabuleiro->sm == '2')
      tabuleiro->sm = formaSimbolo(jogador.forma);
    break;
  case 3:
    if (tabuleiro->se == '3')
      tabuleiro->se = formaSimbolo(jogador.forma);
    break;
  case 4:
    if (tabuleiro->cd == '4')
      tabuleiro->cd = formaSimbolo(jogador.forma);
    break;
  case 5:
    if (tabuleiro->cm == '5')
      tabuleiro->cm = formaSimbolo(jogador.forma);
    break;
  case 6:
    if (tabuleiro->ce == '6')
      tabuleiro->ce = formaSimbolo(jogador.forma);
    break;
  case 7:
    if (tabuleiro->id == '7')
      tabuleiro->id = formaSimbolo(jogador.forma);
    break;
  case 8:
    if (tabuleiro->im == '8')
      tabuleiro->im = formaSimbolo(jogador.forma);
    break;
  case 9:
    if (tabuleiro->ie == '9')
      tabuleiro->ie = formaSimbolo(jogador.forma);
    break;
  default:
    printf("JOGADA INVÁLIDA");
    tabuleiro->turno--;
    break;
  }
}

FORMA linhaFeita(TABULEIRO tabuleiro)
{
  char vitorioso = '\0';

  if ((tabuleiro.sd == tabuleiro.sm) && (tabuleiro.sd == tabuleiro.se))
    vitorioso = tabuleiro.sd;
  else if ((tabuleiro.cd == tabuleiro.cm) && (tabuleiro.cd == tabuleiro.ce))
    vitorioso = tabuleiro.cd;
  else if ((tabuleiro.id == tabuleiro.im) && (tabuleiro.id == tabuleiro.ie))
    vitorioso = tabuleiro.id;

  return conversaoCharForma(vitorioso);
}

FORMA colunaFeita(TABULEIRO tabuleiro)
{
  char vitorioso = '\0';

  if ((tabuleiro.sd == tabuleiro.cd) && (tabuleiro.sd == tabuleiro.id))
    vitorioso = tabuleiro.sd;
  else if ((tabuleiro.sm == tabuleiro.cm) && (tabuleiro.sm == tabuleiro.im))
    vitorioso = tabuleiro.sm;
  else if ((tabuleiro.se == tabuleiro.ce) && (tabuleiro.se == tabuleiro.ie))
    vitorioso = tabuleiro.se;

  return conversaoCharForma(vitorioso);
}

FORMA diagonalFeita(TABULEIRO tabuleiro)
{
  char vitorioso = '\0';

  if ((tabuleiro.cm == tabuleiro.sd) && (tabuleiro.cm == tabuleiro.ie))
    vitorioso = tabuleiro.cm;
  else if ((tabuleiro.cm == tabuleiro.se) && (tabuleiro.cm == tabuleiro.id))
    vitorioso == tabuleiro.cm;

  return conversaoCharForma(vitorioso);
}

FORMA vitoria(TABULEIRO tabuleiro)
{
  FORMA resultado;

  resultado = linhaFeita(tabuleiro);
  if (resultado != 0)
    return resultado;

  resultado = colunaFeita(tabuleiro);
  if (resultado != 0)
    return resultado;

  resultado = diagonalFeita(tabuleiro);
  if (resultado != 0)
    return resultado;
  return 0;
}

void telaFinal(TABULEIRO tabuleiro, PLAYER jogador1, PLAYER jogador2)
{
  FORMA resultado = vitoria(tabuleiro);

  if (resultado == jogador1.forma)
  {
    limparConsole();
    imprimirTabuleiro(tabuleiro);
    printf("Parabéns %s, você ganhou!!!!\n\n", jogador1.nome);
  }
  else if (resultado == jogador2.forma)
  {
    limparConsole();
    imprimirTabuleiro(tabuleiro);
    printf("Parabéns %s, você ganhou!!!!\n\n", jogador2.nome);
  }
}

void velha(TABULEIRO tabuleiro)
{
  if (!vitoria(tabuleiro))
  {
    limparConsole();
    imprimirTabuleiro(tabuleiro);
    printf("Que pena, deu velha!!!\n\n");
  }
}