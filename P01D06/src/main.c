#include <stdio.h>

// void logic();
void update(int, int, int, int);
void horizonDraw();
void vierticalDraw(int, int, int, int);
int racketDraw(int, int, int, int);
int ballDraw(int, int, int, int);

void gameLogic();
void horizonDraw();
void vierticalDraw();
int ballMoveX(int, int);
int ballMoveY(int, int);
int checkBallRocket(int, int, int, int, int, int);

int main() {
    int flag = 1;

    int ball_velVer = 1;  // parametru mya4a
    int ball_velGor = 1;
    int ball_x = 42;
    int ball_y = 10;

    int tmp;

    int rocket1_y = 10;  // rocket param
    int rocket2_y = 10;
    int rocket1_x = 1;
    int rocket2_x = 77;

    int fScore = 0;  // score peram
    int sScore = 0;
    int winScore = 21;
    while (flag) {
        ball_x = ballMoveX(ball_velGor, ball_x);  // skorost' mya4a
        ball_y = ballMoveY(ball_velVer, ball_y);

        tmp = checkBallRocket(ball_x, ball_y, rocket1_x, rocket1_y, rocket2_x,
                              rocket2_y);  // proverka na rocket
        ball_velVer *= tmp;
        ball_velGor *= tmp;

        update(ball_x, ball_y, rocket1_y, rocket2_y);  // otrisovka kadra

        if (ball_x == 79) {  // score logic
            if (fScore < winScore) {
                fScore++;
            } else {
                printf("Congratulations! LEFT player WIN!");
                break;
            }
            flag = 0;
        }
        if (ball_x == 1) {
            if (sScore < winScore) {
                sScore++;
            } else {
                printf("Congratulations! RIGHT player WIN!");
                break;
            }
            flag = 0;
        }
    }
}

int ballMoveX(int velG, int x) { return (velG + x); };

int ballMoveY(int velV, int y) { return (velV + y); };

int checkBallRocket(int x, int y, int r1x, int r1y, int r2x, int r2y) {
    int checkR1 = (x == r1x && (y == r1y || y == r1y - 1 || y == r1y - 2));
    int checkR2 = (x == r2x && (y == r2y || y == r2y - 1 || y == r2y - 2));

    if (checkR1 == 0 || checkR2 == 0)
        return -1;

    else
        return 1;
}

void update(int ball_x, int ball_y, int rocket_1y, int rocket2_y) {
    horizonDraw();
    vierticalDraw(ball_x, ball_y, rocket_1y, rocket2_y);
    horizonDraw();
}

void horizonDraw() {
    char viewGor = '-';
    for (int i = 0; i <= 80; ++i) {
        printf("%c", viewGor);
    }
    printf("\n");
}

void vierticalDraw(int ball_x, int ball_y, int rocket1_y, int rocket2_y) {
    int flag = 1;
    char viewVer = '|';
    int ballDrawFlag = 0;

    for (int i = 0; i < 25; ++i) {
        printf("%c", viewVer);
        for (int j = 0; j < 80 - 1; ++j) {
            if (ballDraw(i, j, ball_x, ball_y)) continue;

            if (!racketDraw(i, j, rocket1_y, rocket2_y)) printf(" ");
        }
        printf("%c", viewVer);
        printf("\n");
    }
}

int racketDraw(int row, int column, int y1, int y2) {
    int flag = 0;
    int firstCoordinate = y1;
    int leftOrRight = 0;

    if (column > 40)
        leftOrRight = 77;
    else
        leftOrRight = 1;

    if ((row == firstCoordinate && column == 1)) {
        printf("|");
        flag = 1;
    }
    if ((row == firstCoordinate + 1 && column == 1)) {
        printf("|");
        flag = 1;
    }
    if ((row == firstCoordinate + 2 && column == 1)) {
        printf("|");
        flag = 1;
    }

    if ((row == y2 && column == 77)) {
        printf("|");
        flag = 1;
    }
    if ((row == y2 + 1 && column == 77)) {
        printf("|");
        flag = 1;
    }
    if ((row == y2 + 2 && column == 77)) {
        printf("|");
        flag = 1;
    }

    return flag;
}

int ballDraw(int row, int column, int x, int y) {
    int flag = 0;
    if ((column == x) && (row == y)) {
        printf("*");
        flag = 1;
    }

    return flag;
}
