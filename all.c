#include <stdio.h>

void playground(int racket1, int racket2, int ballX, int ballY, int score1, int score2) {
    printf("Scoreboard: %d | %d\n", score1, score2);
    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 80; j++) {
            if (i == 0 || i == 24) {
                printf("X");
            } else if (j == 0 || j == 79) {
                printf("|");
            } else if (j == 1 && (i >= racket1 && i < racket1 + 3)) {
                printf("|");
            } else if (j == 78 && (i >= racket2 && i < racket2 + 3)) {
                printf("|");
            } else if (i == ballY && j == ballX) {
                printf("o");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    int racket1 = 10, racket2 = 10;
    int ballX = 40, ballY = 12;
    int dx = 1, dy = 1;
    int score1 = 0, score2 = 0;
    char c;

    while (1) {
        printf("\033[H\033[2J");

        playground(racket1, racket2, ballX, ballY, score1, score2);

        scanf(" %c", &c);
        if (c == 'A' && racket1 > 1) racket1--;
        if (c == 'Z' && racket1 + 2 < 23) racket1++;
        if (c == 'K' && racket2 > 1) racket2--;
        if (c == 'M' && racket2 + 2 < 23) racket2++;
        if (c == ' ') {}

        ballX += dx;
        ballY += dy;

        if (ballY == 1 || ballY == 23) dy = -dy;

        if (ballX == 2 && racket1 <= ballY && ballY < racket1 + 3) dx = -dx;
        if (ballX == 77 && racket2 <= ballY && ballY < racket2 + 3) dx = -dx;

        if (ballX == 1) {
            score2++;
            ballX = 40;
            ballY = 12;
        }
        if (ballX == 78) {
            score1++;
            ballX = 40;
            ballY = 12;
        }

        if (score1 == 21 || score2 == 21) break;
    }

    if (score1 > score2)
        printf("First wins!\n");
    else
        printf("Second wins!\n");

    return 0;
}