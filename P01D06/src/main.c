#include <stdio.h>

int fScore = 0;
int sScore = 0;
int winScore = 21;

void logic();
void update();
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
        logic();
        update();
    

        if (ball_x == 79) {
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

void update() {
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