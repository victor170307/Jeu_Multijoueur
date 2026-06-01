#ifndef BALL_H
#define BALL_H

typedef struct
{
    float x;
    float y;

    float vx;
    float vy;

    int radius;

} Ball;

void updateBall(Ball *ball);

#endif