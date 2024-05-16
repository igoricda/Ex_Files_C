/*
  Questão 3: Tv da vó
  Igor Correa Domingues de Almeida, Guilherme Altmeyer Soares
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef short dado;

typedef struct {
  int rows, cols; // Tamanho do vetor
  dado **data;
} Matrix;

short initMatrix(Matrix *M, int rows, int cols) {
  M->data = (dado **)malloc(cols * sizeof(dado )); //Alocar no tamanho maximo
  if (!M->data) {
    return -1;
  } else {
    for (int i = 0; i < rows; i++) {
      M->data[i] = (dado *)malloc(rows* sizeof(dado));
      if (!M->data[i]) {
        return -2;
      }
    }
    M->rows = rows;
    M->cols = cols;
    return 0;
  }
}

void freeMatrix(Matrix *M) {
  for (int i = 0; i < M->rows; i++) {
    free(M->data[i]);
  }
  free(M->data);
}

void shiftright(Matrix *M){
  for (int i = 0; i < M->rows; i++) {
      int lastElement = M->data[i][M->rows- 1]; // Armazena o último elemento da linha
      // Desloca os elementos da linha para a direita
      for (int j = M->cols - 1; j > 0; j--) {
            M->data[i][j] = M->data[i][j - 1];
      }
      // Coloca o último elemento no início da linha
        M->data[i][0] = lastElement;
  }
}

void shiftleft(Matrix *M){
  for (int i = 0; i < M->rows; i++) {
      int firstElement = M->data[i][0]; // Armazena o último elemento da linha
      // Desloca os elementos da linha para a direita
      for (int j = 0; j < M->cols - 1; j++) {
            M->data[i][j] = M->data[i][j+1];
      }
      // Coloca o último elemento no início da linha
        M->data[i][M->cols - 1] = firstElement;
  }
}
// Função para deslocar os elementos das colunas para cima
void shiftup(Matrix *m) {
    for (int j = 0; j < m->cols; j++) {
        // Armazena o primeiro elemento da coluna
        int firstElement = m->data[0][j];
        // Desloca os elementos da coluna para cima
        for (int i = 0; i < m->rows - 1; i++) {
            m->data[i][j] = m->data[i + 1][j];
        }
        // Coloca o primeiro elemento no final da coluna
      m->data[m->rows - 1][j] = firstElement;
    }
}

// Função para deslocar os elementos das colunas para baixo
void shiftdown(Matrix *m) {
    for (int j = 0; j < m->cols; j++) {
        // Armazena o último elemento da coluna
        int lastElement = m->data[m->rows - 1][j];
        // Desloca os elementos da coluna para baixo
        for (int i = m->rows - 1; i > 0; i--) {
            m->data[i][j] = m->data[i - 1][j];
        }
        // Coloca o último elemento no início da coluna
        m->data[0][j] = lastElement;
    }
}

int main(int argc, char* argv[]) {
  FILE *fIn, *fOut;
  char fInName[30], fOutName[30];
  int testes = 1, x = 1, y = 1, r, c;

  strcpy(fInName, argv[1]);
  strcpy(fOutName, argv[2]);

  fIn = fopen(fInName, "r");
  fOut = fopen(fOutName, "w");

  if (!fIn) {
    printf("Erro ao abrir o arquivo de entrada\n");
    return 1;
  }

  if (!fOut) {
    printf("Erro ao abrir o arquivo de saída\n");
    return 1;
  }

  while (!feof(fIn)) { //enquanto o arquivo nao acaba
    Matrix a;
    if(feof(fIn)){
      break;
    }
    fscanf(fIn, "%d %d", &r, &c); //ler linhas e colunas
    if(!(r || c)){
      break;
    }
    if (initMatrix(&a, r, c)<0) { //alocar matriz
      printf("Erro 1: Nao foi possivel alocar a matriz \n\n");
      exit(1);
    }
    for (int i = 0; i < a.rows; i++) { //ler matriz
      for (int j = 0; j < a.cols; j++) {
        fscanf(fIn, "%hd", &a.data[i][j]);
      }
      fscanf(fIn, "\n");
    }
    while (x || y) { //Fazer os deslocamentos
      fscanf(fIn, "%d %d", &x, &y); 
      if(!(x || y)){
        break;
      }

      if(x>0){
        int aux = x;
        while(aux--){
          shiftright(&a);
        }
      } 
      if(x < 0){
        int aux = x;
        while(aux++){
          shiftleft(&a);
        }
      }
      if(y > 0){
        int aux = y;
        while(aux--){
          shiftup(&a);
        }
      }
      if(y < 0){
        int aux = y;
        while(aux++){
          shiftdown(&a);
        }
      }
    }
    x = 1; y = 1;
    fprintf(fOut, "Teste %d\n", testes); //fprintf dos testes
  for (int i = 0; i < a.rows; i++) {
    for (int j = 0; j < a.cols; j++) {
      fprintf(fOut, "%3hd", a.data[i][j]);
    }
    fprintf(fOut, "\n");
  }
    fprintf(fOut, "\n");
    testes++;
    freeMatrix(&a);
}
  fclose(fIn); //fechar
  fclose(fOut);
  return 0;
}
