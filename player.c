#include "player.h"

void movePlayerLeft(Player *player)
{
    player->x -= player->speed;
}

void movePlayerRight(Player *player)
{
    player->x += player->speed;
}