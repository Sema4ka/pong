#include <stdio.h>


void gameLogic();
void gameUpdate();

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

    int rocket1_y = 10;
    int rocket2_y = 10;
    int rocket1_x = 20;
    int rocket2_x = 60;

    int tmp;
    while (flag) {
        int fScore = 0;
        int sScore = 0;
        int winScore = 21;
      
        ball_x = ballMoveX(ball_velGor, ball_x);
        ball_y = ballMoveY(ball_velVer, ball_y);
        tmp = checkBallRocket(ball_x, ball_y, rocket1_x, rocket1_y, rocket2_x, rocket2_y);
        ball_velVer *= tmp;
        ball_velGor *= tmp;
        gameUpdate();

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

int ballMoveX(int velG, int x){
   return (velG + x);
};


int ballMoveY(int velV, int y){
   return (velV + y);
};

int checkBallRocket(int x, int y, int r1x, int r1y, int r2x, int r2y){
    int checkR1 = (x == r1x && (y == r1y || y ==r1y-1 || y == r1y-2));
    int checkR2 = (x == r2x && (y == r2y || y ==r2y-1 || y == r2y-2));

    if(checkR1==0 || checkR2==0)
        return -1;

    else 
        return 1;
}

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

