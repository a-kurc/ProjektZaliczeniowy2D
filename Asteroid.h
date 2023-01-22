#pragma once

#ifndef ASTEROID
#define ASTEROID

#include "Rocket.h"
#include <d2d1.h>
#include <cmath>


class Asteroid
{
public:
    ID2D1Bitmap* bitmap;
    D2D1_POINT_2F center;
    float left_end;
    float right_end;
    float top_end;
    float bottom_end;
    int size;
    int speed;

    Asteroid(ID2D1Bitmap* bitmap, D2D1_POINT_2F center, int size);

    void set_center(D2D1_POINT_2F center, int size);

    void set_speed(int speed);
};

bool IsPointCloseToPoint(D2D1_POINT_2F a, D2D1_POINT_2F b, float d);

bool DidRocketHitRock(Rocket rocket, Asteroid astr);

#endif //ASTEROID