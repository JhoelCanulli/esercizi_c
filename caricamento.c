/* crea un programma in C che simuli il loading grafico in movimento su terminale */ 

#include <time.h>
#include <unistd.h>
#include <curses.h>

void caricamentoOperazioni(){

  printf("\nCaricamento in corso: ");
  printf("\n");
  for(int i=0; i<=100; i++){
    printf("\r[ %d%% ]",i);
    fflush(stdout);   //
    usleep(10000);
  }
  printf("\n\n");
}

int main(){
    caricamentoOperazioni();
    return 0;
}
