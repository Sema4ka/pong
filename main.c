#include <stdio.h>

void update();
void horizonDraw();
void vierticalDraw();

int main() {
    int flag = 1;
    while (flag) update();
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
