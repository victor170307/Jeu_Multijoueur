#include "balle.h"

void updateBall(Ball *ball)
{
    ball->x += ball->vx;
    ball->y += ball->vy;
}