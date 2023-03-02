/* crea una matrice magica, o quadrato magico, in C.
 * Un quadrato magico è una tabella di forma quadrata (una matrice quadrata, sostanzialmente) 
 * contenente tutti numeri distinti, tale per cui la somma degli elementi presenti su 
 * ciascuna riga, ciascuna colonna e ciascuna diagonale sia sempre pari allo stesso numero.
 */

#include <stdio.h>

int main(void)
{
  
  int N;  //dimensione matrice

  printf(" |----------------|\n");
  printf(" | MATRICE MAGICA | \n");
  printf(" |----------------| \n\n");

  do{
    printf("Inserire la dimensione della matrice quadrata: ");
    scanf("%d", &N);

    if(N<2){
      printf("La dimensione di una matrice deve essere minimo di 2 unità\n\n");
    }
  }
  while(N < 2);

  int matrix[N][N];

  int i, j;

  printf("Inserire gli elementi di una matrice di interi %dx%d\n", N, N);
  for (i = 0; i < N; i++){
    for (j = 0; j < N; j++){
      printf("cella [%d, %d] : ",i+1,j+1);
      scanf("%d", &matrix[i][j]);
    }
  }

  printf("La matrice\n");

  /* stampo a video la matrice */
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++){
      printf("%5d", matrix[i][j]);
    }
    printf("\n");
  }

  int sommaDiagPrinc;
  int sommaDiagSec;
  int sommaRighe[N];
  int sommaCol[N];
  int sommaAux = 0;
  int costante;

  /* Somma diagonale principale */
  for(i = 0; i < N; i++){ 
    sommaAux = sommaAux + matrix[i][i];
  }
  sommaDiagPrinc = sommaAux;

  sommaAux = 0;
  /* Somma diagonale secondaria */
  for(i = 0; i < N; i++){
    sommaAux = sommaAux + matrix[i][N-i-1];
  }
  sommaDiagSec = sommaAux;

  sommaAux = 0;
    
  /* Somma riga */
  for(i=0; i<N; i++){
    for(j=0; j<N; j++){
      sommaAux = sommaAux + matrix[i][j];
    }
    sommaRighe[i] = sommaAux;
    sommaAux = 0;
  }

  sommaAux = 0;
  /* Somma colonna */
  for(j=0; j<N; j++){
    for (i = 0; i < N; i++){
      sommaAux = sommaAux + matrix[i][j];
    }
    sommaCol[j] = sommaAux;
    sommaAux = 0;
  }
  
  /* visualizzo la somma delle righe e la somma delle colonne */
  for (i = 0; i < N; i++) {
    printf("\nsomma riga %d: %d", i, sommaRighe[i]);
    printf("\nsomma colonna %d: %d", i, sommaCol[i]);
  }
  printf("\nsomma diagonale principale: %d", sommaDiagPrinc);
  printf("\nsomma diagonale secondaria: %d", sommaDiagSec);

  int magica = 1;
  i=0;

  while(magica && i<N){
    if((sommaRighe[i] == sommaCol[i]) && (sommaCol[i] == sommaDiagSec) && (sommaDiagSec == sommaDiagPrinc)){
      i++;
    }
    else{
      magica = 0;
    }
  }

  if(magica){
    costante = sommaDiagPrinc;
    printf("\n\nLa matrice è magica con costante: %d\n\n",costante);
  }
  else{
    printf("\nMatrice non magica\n\n");
  }

  return 0;
}
