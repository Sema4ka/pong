# include <stdio.h>

void logic();
void update();

struct Ball
{
    int transform;
    int velUp;
    int velForward;
    char view ='*';
} ball;

struct Rocket{
    int transform;
    char view = "|";
}

struct PlayGround
{
    char coord[80][25];
    struct Ball ball;
    struct Rocket rocket1;
    struct Rocket rocket2;
    char viewVer ='|';
    char viewGor ='-';
}

int main(){
    int flag = 1;
    while(flag){
        logic();
        update();
    }
}
