#pragma once

#include "projekt_zal.h"

class Planet
{
public:
    ID2D1Bitmap* bitmap;
    D2D1_POINT_2F center;
    float left_end;
    float right_end;
    float top_end;
    float bottom_end;
    int size;

    Planet(ID2D1Bitmap* bitmap) : bitmap(bitmap) {};

    void set_bitmap(ID2D1Bitmap* bitmap)
    {
        this->bitmap = bitmap;
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
};

Planet planet_saturn_pink(NULL);