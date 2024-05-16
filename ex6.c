/*
  Questão 2: Par ou Impar
  Igor Correa Domingues de Almeida, Guilherme Altmeyer Soares
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{ //Estrutura com o nome do jogador e a jogada dele
  char nome;
  int dinheiro;
} jogador;

int main(int argc, char* argv[]) {
  FILE *fIn, *fOut; //Arquivos de entrada e saida
  char fInName[30], fOutName[30], op, player, player2, numeros[6]; //Nome dos arquivos
  jogador a, b, c; //Jogadores 
  int  n, din, numero; //Casos de teste e numero de rodadas por jogo

  strcpy(fInName, argv[1]);
  strcpy(fOutName, argv[2]);


  fIn = fopen(fInName, "r"); //Abre o fIn em modo read
  fOut = fopen(fOutName, "w"); //Abre o fOut em modo write

//Caso nao consiga abrir os arquivos, sair do codigo
  if(!fIn){
    printf("Erro ao abrir o arquivo de entrada\n");
    exit(1);
  }

  if(!fOut){
    printf("Erro ao abrir o arquivo de saida\n");
    exit(1);
  }

//Enquanto conseguir ler as rodadas e n for diferente de 0
  fscanf(fIn, "%d", &din);
  fscanf(fIn, "%d", &n);
  a.nome = 'D'; a.dinheiro = din;
  b.nome = 'E'; b.dinheiro = din;
  c.nome = 'F'; c.dinheiro = din;

  for(int i = 0; i < n; i++){
    while(fscanf(fIn, "%c", &op) == 1 && !(op == 'C' || op== 'V' || op == 'A'));
    while(fscanf(fIn, "%c", &player) == 1 && !(player == 'D' || player == 'E' || player == 'F'));

    if(op == 'C'){
      while(fscanf(fIn, "%d", &numero) == 1);
      if(player == 'D')
        a.dinheiro -= numero;
      else if(player == 'E')
        b.dinheiro -= numero;
      else if(player == 'F')
        c.dinheiro -= numero;
    }
    else if(op == 'V'){
      while(fscanf(fIn, "%d", &numero) == 1);
      if(player == 'D')
        a.dinheiro += numero;
      else if(player == 'E')
        b.dinheiro += numero;
      else if(player == 'F')
        c.dinheiro += numero;
    } else if(op == 'A'){
      while(fscanf(fIn, "%c", &player2) == 1 && !(player2 == 'D' || player2 == 'E' || player2 == 'F'));
      while(fscanf(fIn, "%d", &numero) == 1);
      if(player == 'D'){
        a.dinheiro += numero;
        if(player2 == 'E')
          b.dinheiro -= numero;
        else if(player2 == 'F')
          c.dinheiro -= numero;
      }
      else if(player == 'E'){
        b.dinheiro += numero;
        if(player2 == 'D')
          a.dinheiro -= numero;
        else if(player2 == 'F')
          c.dinheiro -= numero;
      }
      else if(player == 'F'){
        c.dinheiro += numero;
        if(player2 == 'E')
          b.dinheiro -= numero;
        else if(player2 == 'D')
          a.dinheiro -= numero;
      }
    }
  }
  
  fprintf(fOut, "%d %d %d\n", a.dinheiro, b.dinheiro, c.dinheiro);
  //Fechar os arquivos
  fclose(fIn);
  fclose(fOut);  

  return 0;
}
