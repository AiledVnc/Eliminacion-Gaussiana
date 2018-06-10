#include<stdio.h>
#include<stdlib.h>
void intercambia(double*** , int, int, int); //(matriz, fila, fila a intercambiar, tamaño)
void imprimirMatriz(double**, int, int);
void suma(double***, int, int, double, int);
void multiplica(double***, int, double, int);
void algoritmo(double***, int, int);
int main()
{
  int variable, i , j;
  printf("\nELIMINACION GAUSSIANA\n");
  printf("\nCuantas variables tiene el sistema de ecuaciones lineales?\t");
  scanf("%d", &variable);
  int filas = variable;
  int columnas = variable + 1;
  //Arreglo para pedir al usuario
  double **matriz;
  matriz = (double**) malloc(filas * sizeof(double*));
  for(i = 0; i < columnas ; i ++)
  {
    matriz[i] = (double*) malloc(filas * sizeof(double));
  }
  //Pedir valores de la matriz
  for (i = 0; i < filas; i++)
  {
    printf("\n");
    for (j = 0; j < columnas - 1; j++)
    {
      printf("Dame a%d%d:\t", i, j);
      scanf("%lf", &matriz[i][j]);
    }
    printf("Dame b%d:\t", i);
    scanf("%lf", &matriz[i][j]);
  }

  //Ver matriz

  imprimirMatriz(matriz, filas, columnas);
  //Validacion
  for (i = 0; i < filas; i++)
  {
    if (matriz[i][filas - 1] == 0)
    {
      intercambia(&matriz, filas - 1, 0, columnas);
    }
    else if (matriz[i][i] == 0)
    {
      intercambia(&matriz, i, i + 1, columnas);
    }
  }
  //Respuesta
  multiplica(&matriz, 1, 1.0/6.0, columnas);
  algoritmo(&matriz, filas, columnas);

  imprimirMatriz(matriz, filas, columnas);
  //Liberar memoria
  for (i = 0; i < filas; i++)
  {
    free(matriz[i]);
  }
  free(matriz);
  return 0;
}




void imprimirMatriz(double** matriz, int filas, int columnas)
{
  int i, j;
  printf("\n");
  for (i = 0; i < filas; i++)
  {
    for (j = 0; j < columnas-1; j++)
    {
      printf("\t%.1f", matriz[i][j]);
    }
    printf("\t|  %.1f  |", matriz[i][j]);
    printf("\n");
  }
  printf("\n");
}
void intercambia(double*** matriz, int fila1, int fila2, int size)
{
  int k, temp;
  for (k = 0; k < size; k++)
  {
    temp = (*matriz)[fila1][k];
    (*matriz)[fila1][k] = (*matriz)[fila2][k];
    (*matriz)[fila2][k] = temp;
  }
}

//M[i][j] = M[i][j] + CM[k][j]
//f1 = f1 + Cf2
void suma(double*** matriz, int fila1, int fila2, double constante, int numColums)
{
  int j;
  for (j = 0; j < numColums; j++)
  {
    (*matriz)[fila1][j] = (*matriz)[fila1][j] + (*matriz)[fila2][j] * constante;
  }
}

void multiplica(double*** matriz, int fila, double constante, int numColums)
{
  int j;
  for (j = 0; j < numColums; j++)
  {
    (*matriz)[fila][j] = (*matriz)[fila][j] * constante;
  }
}

void algoritmo(double*** matriz, int filas, int numColums)
{
  int i, j;
  for (i = 0; i < filas; i++)
  {
    multiplica(matriz, i, 1.0 / (*matriz)[i][i], numColums);
    for (j = 0; j < filas; j++)
    {
      if (j == i)
      {
        continue;
      }
      suma(matriz, j, i, - 1.0 * (*matriz)[j][i], numColums);
    }
  }
}
