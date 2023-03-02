#include <stdio.h>
#include <stdbool.h>

#define SIZE 3

// Funzione che stampa la griglia di gioco
void print_board(char board[][SIZE]) {
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      printf("%c", board[i][j]);
      if (j < SIZE - 1) {
        printf("|");
      }
    }
    printf("\n");
    if (i < SIZE - 1) {
      printf("-+-+-\n");
    }
  }
}

// Funzione che controlla se c'è una vittoria per il giocatore "player"
bool check_win(char board[][SIZE], char player) {
  // Controllo delle righe
  for (int i = 0; i < SIZE; i++) {
    bool win = true;
    for (int j = 0; j < SIZE; j++) {
      if (board[i][j] != player) {
        win = false;
        break;
      }
    }
    if (win) {
      return true;
    }
  }

  // Controllo delle colonne
  for (int i = 0; i < SIZE; i++) {
    bool win = true;
    for (int j = 0; j < SIZE; j++) {
      if (board[j][i] != player) {
        win = false;
        break;
      }
    }
    if (win) {
      return true;
    }
  }

  // Controllo delle diagonali
  bool win = true;
  for (int i = 0; i < SIZE; i++) {
    if (board[i][i] != player) {
      win = false;
      break;
    }
  }
  if (win) {
    return true;
  }

  win = true;
  for (int i = 0; i < SIZE; i++) {
    if (board[i][SIZE - 1 - i] != player) {
      win = false;
      break;
    }
  }
  if (win) {
    return true;
  }

  // Nessuna vittoria trovata
  return false;
}

int main() {
  // Inizializziamo la griglia di gioco vuota
  char board[SIZE][SIZE];
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      board[i][j] = ' ';
    }
  }

  // Giocatore iniziale (X)
  char current_player = 'X';

  // Ciclo di gioco
  while (true) {
    // Stampa la griglia di gioco
    print_board(board);

    // Chiedi al giocatore corrente di fare una mossa
    int row, col;
    printf("Turno del giocatore %c\n", current_player);
    printf("Inserisci riga e colonna (es. 1 2): ");
    scanf("%d %d", &row, &col);

    // Verifica che la mossa sia valida
    if (row < 1 || row > SIZE || col < 1 || col > SIZE) {
      printf("Mossa non valida, inserisci riga e colonna tra 1 e %d\n", SIZE);
      continue;
    }
    if (board[row - 1][col - 1] != ' ') {
        printf("Mossa non valida, la casella è già occupata\n");
        continue;
    }

    // Esegui la mossa
    board[row - 1][col - 1] = current_player;

    // Verifica se il giocatore ha vinto
    if (check_win(board, current_player)) {
        printf("Il giocatore %c ha vinto!\n", current_player);
        break;
    }

    // Verifica se c'è un pareggio
    bool full_board = true;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') {
                full_board = false;
                break;
            }
        }
        if (!full_board) {
        break;
        }
    }

    if (full_board) {
        printf("Pareggio!\n");
        break;
    }

    // Passa al giocatore successivo
    if (current_player == 'X') {
        current_player = 'O';
    } else {
        current_player = 'X';
    }
  }

return 0;
}
