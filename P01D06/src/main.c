#include <stdio.h>

void logic();
void update();

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
    }
}
