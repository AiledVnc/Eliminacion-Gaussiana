#include<stdio.h>
#include<stdlib.h>
void intercambia(double*** , int, int, int);
void imprimirMatriz(double** matriz, int filas, int columnas);
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
  matriz = (double**) malloc(columnas * sizeof(double*));
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
      scanf("%f", &matriz[i][j]);
    }
    j++;
    printf("Dame b%d:\t", i);
    scanf("%f", &matriz[i][j]);
  }

  for( i = 0; i < filas; i++)
  {
    for(j = 0; j < columnas; j++)
    {
      printf("\t%2f", matriz[i][j]);
    }
    printf("\n");
  }

  printf("\n");
  //Ver matriz
  imprimirMatriz(matriz, filas, columnas);

  //Respuesta
  intercambia(&matriz, 0, 1, columnas);
  imprimirMatriz(matriz, filas, columnas);
  return 0;
}




void imprimirMatriz(double** matriz, int filas, int columnas)
{
  int i, j;
  for (i = 0; i < filas; i++)
  {
    for (j = 0; j < columnas-1; j++)
    {
      printf("\t%.1f", matriz[i][j]);
    }
    j++;
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
    temp = *matriz[fila1][k];
    *matriz[fila1][k] = *matriz[fila2][k];
    *matriz[fila2][k] = temp;
  }
}
