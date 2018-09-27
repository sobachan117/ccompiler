#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_QUEEN_N 8
#define MARK_QUEEN "Ｑ"
#define MARK_SQUARE "◾️"

typedef struct Position_ {
    int col, row;
} Position;

int N = DEFAULT_QUEEN_N;
int total;

int conflict(Position* queens, int currRow);
void solve(Position* queens, int row);
void printAnswer(Position* queens);

int main(int argc, char *argv[]) {

    if (argc == 2) {
        N = atoi(argv[1]);
    }

    Position queens[N];

    solve(queens, 0);

    printf("Queen N:%d total:%d\n", N, total);

    return 0;
}

int conflict(Position* queens, int currRow) {
    Position target = queens[currRow];
    for (int row = 0; row < currRow; row++) {
        if (target.col == queens[row].col) {
            return 1;
        }
        if (abs(target.row - queens[row].row) == abs(target.col - queens[row].col)) {
            return 1;
        }
    }
    return 0;
}

void solve(Position* queens, int row) {
    if (row == N) {
        printAnswer(queens);
        return;
    }
    for (int col = 0; col < N; col++) {
        Position newQueen = {col, row};
        queens[row] = newQueen;
        if (!conflict(queens, row)) {
            solve(queens, row + 1);
        }
    }
}

void printAnswer(Position* queens) {
    printf("No.%d\n", ++total);
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            if (row == queens[row].row && col == queens[row].col) {
                printf(MARK_QUEEN);
            } else {
                printf(MARK_SQUARE);
            }
        }
        printf("\n");
    }
    printf("\n");
}
