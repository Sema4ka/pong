#include <stdio.h>

void gameLogic();
void gameUpdate();
void horizonDraw();
void vierticalDraw();

int main() {
    int flag = 1;

    int ball_velVer = 1;  // parametru mya4a
    int ball_velGor = 1;
    int ball_x = 42;
    int ball_y = 10;

    int rocket1_y = 10;
    int rocket2_y = 10;
    int rocket1_x = 20;
    int rocket2_x = 60;
    while (flag) {
        gameLogic();
        gameUpdate();
    }
}

void gameLogic(){}

void gameUpdate() {
    horizonDraw();
    vierticalDraw();
    horizonDraw();
}

void horizonDraw() {
    char viewGor = '-';
    for (int i = 0; i <= 80; ++i) {
        printf("%c", viewGor);
    }
    printf("\n");
}

void vierticalDraw() {
    char viewVer = '|';
    for (int i = 0; i < 25; ++i) {
        printf("%c", viewVer);
        for (int j = 0; j < 80 - 1; ++j) printf(" ");
        printf("%c", viewVer);
        printf("\n");
    }
}
