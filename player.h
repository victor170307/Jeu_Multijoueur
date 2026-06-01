#ifndef PLAYER_H
#define PLAYER_H

typedef struct
{
    float x;
    float y;

    int width;
    int height;

    float speed;

    int alive;

} Player;

void movePlayerLeft(Player *player);
void movePlayerRight(Player *player);

#endif