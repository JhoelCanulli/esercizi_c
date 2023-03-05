/* gioco del tris pvp */

#include <stdio.h>
#include <stdbool.h>

#define SIZE 3

void print_board(char board[][SIZE]);
bool check_win(char board[][SIZE], char player);
void count_win(char board[][SIZE], int *x_wins, int *o_wins);

int main(){
    
    char player = 'X';  //Inizializzazione giocatore

    // Inizializzazione numero vincite dei giocatori
    int x_wins = 0;
    int o_wins = 0;
    char input;

    printf("*-----------*\n");
    printf("|   TRIS    |\n");
    printf("*-----------*\n\n");
    
    while(true){

        // Inizializzazione griglia di gioco vuota 
        char board[SIZE][SIZE];
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    board[i][j] = ' ';
                }
            }
        printf("\n[digitare q per uscire dal gioco, qualsiasi altro carattere per continuare]\n");
        scanf("%c",&input);
        while (getchar() != '\n');

        if(input == 'q'){
            break;
        }

        while(true){
            
            print_board(board);

            // Giocatore muove
            int row, col;
            printf("Turno del giocatore %c\n", player);
            printf("Inserire riga e colonna (es. 1 2): ");
            scanf("%d %d", &row, &col);

            // Verifica validità mossa
            if (row < 1 || row > SIZE || col < 1 || col > SIZE) {
                printf("Mossa non valida, inserisci riga e colonna tra 1 e %d\n", SIZE);
                continue;
            }
            if (board[row - 1][col - 1] != ' ') {
                printf("Mossa non valida, la casella è già occupata\n");
                continue;
            }

            board[row - 1][col -1] = player;  // Esecuzione mossa giocatore

            //Verifica se il giocatore ha vinto
            bool win = check_win(board, player);
            if(win){
                // Aggiornamento conteggio vittorie
                count_win(board, &x_wins, &o_wins);
                printf("\nIl giocatore %c ha vinto!!!!!\n", player);
                break;
            }

            //Verifica se si ha un pareggio
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
                printf("\nPareggio!\n");
                break;
            }

            //Tocca al giocatore successivo
            if (player == 'X') {
                player = 'O';
            } else {
                player = 'X';
            }

        }
      
        // Stampa dei risultati
        printf("\nNumero di vittorie di X: %d", x_wins);
        printf("\nNumero di vittorie di O: %d\n\n", o_wins);

    }

    return 0;
}


void print_board(char board[][SIZE]){

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

bool check_win(char board[][SIZE], char player){
    
    // Vincita su riga
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

    // Vincita su colonna
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

    // Vincita su diagonale principale
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

    // Vincita su diagonale secondaria
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

void count_win(char board[][SIZE], int *x_wins, int *o_wins)
{
    bool x_won = check_win(board, 'X');
    bool o_won = check_win(board, 'O');
    
    if (x_won || o_won) {
        if (x_won) {
            (*x_wins)++;
        } else if (o_won) {
            (*o_wins)++;
        }
    }
}
