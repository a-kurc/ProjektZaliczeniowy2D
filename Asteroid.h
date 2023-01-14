#pragma once

#include "projekt_zal.h"

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

    Asteroid(ID2D1Bitmap* bitmap, D2D1_POINT_2F center, int size)
    {
        this->bitmap = bitmap;
        this->center = center;
        this->size = size;
        this->left_end = center.x - size;
        this->right_end = center.x + size;
        this->top_end = center.y - size;
        this->bottom_end = center.y + size;
    }

    void set_center(D2D1_POINT_2F center, int size)
    {
        this->center = center;
        this->left_end = center.x - size;
        this->right_end = center.x + size;
        this->top_end = center.y - size;
        this->bottom_end = center.y + size;
        this->size = size;
    }

    void set_speed(int speed)
    {
        this->speed = speed;
    }
};

Asteroid asteroid(NULL, { 500, 500 }, 100);