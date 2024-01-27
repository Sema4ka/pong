#include <stdio.h>

//void logic();
void update();
void horizonDraw();
void vierticalDraw();
int racketDraw(int, int);
int ballDraw(int, int);

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
    //while (flag) {
        //logic();
        update();
    //}
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
    int ballDrawFlag = 0;
    
    for (int i = 0; i < 25; ++i) {
        printf("%c", viewVer);
        for (int j = 0; j < 80 - 1; ++j)
        {
            if( ! racketDraw(i, j))
                printf(".");
            
            if( ! ballDraw(i, j))
                printf("#");
          
        }
        printf("%c", viewVer);
        printf("\n");
    }

}

int racketDraw(int row, int column){
    int flag = 0;
    int firstCoordinate = 11;
    int leftOrRight = 0;
    
    if(column > 40)
        leftOrRight = 77;
    else
        leftOrRight = 1;
        
    
    if((row == firstCoordinate && column == leftOrRight))
    {
        printf("|");
        flag = 1;
    }
    if((row == firstCoordinate + 1 && column == leftOrRight))
    {
        printf("|");
        flag = 1;
    }
    if((row == firstCoordinate + 2 && column == leftOrRight))
    {
        printf("|");
        flag = 1;
    }
    
    return flag;
}

int ballDraw(int row, int column)
{
    int flag = 0;
    if((row == 10) && (column == 10))
    {
        printf("*");
        flag = 1;
    }
    
    return flag;
    
}
