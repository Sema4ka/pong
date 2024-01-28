#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>


void update(int, int, int, int, int, int);
void horizonDraw();
void vierticalDraw(int, int, int, int);
int racketDraw(int, int, int, int);
int ballDraw(int, int, int, int);
void scoreDraw(int, int);

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
    int rocket1_x = 5;
    int rocket2_x = 73;

    int fScore = 0;  // score peram
    int sScore = 0;
    int winScore = 21;

    char input;

    initscr();
    while (flag) {
        nodelay(stdscr, true);
        ball_x += ball_velGor;  // skorost' mya4a
        ball_y += ball_velVer;

        tmp = checkBallRocket(ball_x, ball_y, rocket1_x, rocket1_y, rocket2_x,
                              rocket2_y);  // proverka na rocket
        ball_velGor *= tmp;
        
        if(ball_y == 24 || ball_y == 0)
            ball_velVer *=-1;

        clear();
        update(ball_x, ball_y, rocket1_y, rocket2_y, fScore, sScore);  // otrisovka kadra

        if (ball_x == 79) {  // score logic
            if (fScore <= winScore) {
                fScore++;
                ball_y = 25/2;
                ball_x = 40;
            } else {
                printw("Congratulations! LEFT player WIN!");
                flag = 0;
            }
        }
        if (ball_x == 1) {
            if (sScore <= winScore) {
                sScore++;
                ball_y = 25/2;
                ball_x = 40;
            } else {
                printw("Congratulations! RIGHT player WIN!");
                flag = 0;
            }
        }
        
        usleep(100*1000);
        input = getch();
        if(input == 'q')
            flag = 0;
        else if(input==' ')
            continue;
        else if(input=='a' || input=='A'){
            if(rocket1_y > 0)
                rocket1_y--;
        }

        else if(input=='z' || input=='Z'){
            if(rocket1_y < 25 -3)
            rocket1_y++;}

        else if(input=='k' || input=='K'){
            if(rocket2_y >0)
                rocket2_y--;}
        else if(input=='m' || input=='M'){
            if(rocket2_y < 25-3)
            rocket2_y++;}
        input = ' ';
    }
    endwin();
}

int checkBallRocket(int x, int y, int r1x, int r1y, int r2x, int r2y) {
    int checkR1 = (x == r1x && (y == r1y || y == r1y + 1 || y == r1y + 2));
    int checkR2 = (x == r2x && (y == r2y || y == r2y + 1 || y == r2y + 2));
    
    
    if (checkR1 == 1 || checkR2 == 1)
        return -1;

    else
        return 1;
}

void update(int ball_x, int ball_y, int rocket_1y, int rocket2_y, int fScore, int sScore) {
    horizonDraw();
    vierticalDraw(ball_x, ball_y, rocket_1y, rocket2_y);
    horizonDraw();
    scoreDraw(fScore, sScore);
}

void scoreDraw(int f, int s){
    printw("  %-75d %d", f, s);
}

void horizonDraw() {
    char viewGor = '-';
    for (int i = 0; i <= 80; ++i) {
        printw("%c", viewGor);
    }
    addch('\n');
}

void vierticalDraw(int ball_x, int ball_y, int rocket1_y, int rocket2_y) {
    int flag = 1;
    char viewVer = '|';
    int ballDrawFlag = 0;

    for (int i = 0; i < 25; ++i) {
        printw("%c", viewVer);
        for (int j = 0; j < 80 - 1; ++j) {
            if (ballDraw(i, j, ball_x, ball_y)) continue;

            if (!racketDraw(i, j, rocket1_y, rocket2_y)) addch(' ');
        }
        printw("%c", viewVer);
        addch('\n');
    }
}

int racketDraw(int row, int column, int y1, int y2) {
    int flag = 0;
    int firstCoordinate = y1;
    int leftOrRight = 0;

    if (column > 40)
        leftOrRight = 73;
    else
        leftOrRight = 5;

    if ((row == firstCoordinate && column == 5)) {
        addch('|');
        flag = 1;
    }
    if ((row == firstCoordinate + 1 && column == 5)) {
        addch('|');
        flag = 1;
    }
    if ((row == firstCoordinate + 2 && column == 5)) {
        addch('|');
        flag = 1;
    }

    if ((row == y2 && column == 73)) {
        addch('|');
        flag = 1;
    }
    if ((row == y2 + 1 && column == 73)) {
        addch('|');
        flag = 1;
    }
    if ((row == y2 + 2 && column == 73)) {
        addch('|');
        flag = 1;
    }

    return flag;
}

int ballDraw(int row, int column, int x, int y) {
    int flag = 0;
    if ((column == x) && (row == y)) {
        addch('*');
        flag = 1;
    }

    return flag;
}
