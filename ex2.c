/*
  Questão 2: Par ou Impar
  Igor Correa Domingues de Almeida, Guilherme Altmeyer Soares
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{ //Estrutura com o nome do jogador e a jogada dele
  char nome[11];
  short dedos;
} jogador;

int main(int argc, char* argv[]) {
  FILE *fIn, *fOut; //Arquivos de entrada e saida
  char fInName[30], fOutName[30]; //Nome dos arquivos
  jogador a, b; //Jogadores 
  int testes = 1, n; //Casos de teste e numero de rodadas por jogo

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
  while(fscanf(fIn, "%d", &n) == 1 && n){
    
    //Ler os nomes dos jogadores
    fscanf(fIn, "%s[a-z, A-Z]", a.nome); 
    fscanf(fIn, "%s[a-z, A-Z]", b.nome);
    
    //Imprimir o numero do teste
    fprintf(fOut, "Teste %d\n", testes);
    
    //Laco que repete no numero de rodadas
    for(int i = 0; i < n; i++){
      fscanf(fIn, "%hd %hd", &a.dedos, &b.dedos); //Ler as jogadas
      if((a.dedos + b.dedos) % 2 == 0){ //Se par
        fprintf(fOut, "%s\n", a.nome); //Imprimir o nome do primeiro
      } else{ //Senao
        fprintf(fOut, "%s\n", b.nome); //Imprimir o nome do segundo
      }
    }
    fprintf(fOut, "\n"); //Imprimir linha em branco
    testes++; //Incrementar testes
  }
  //Fechar os arquivos
  fclose(fIn);
  fclose(fOut);  
  
  return 0;
}
