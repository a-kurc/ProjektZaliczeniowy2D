#pragma once

#include "projekt_zal.h"

class CloudsOrStars
{
public:
    ID2D1Bitmap* bitmap;
    D2D1_POINT_2F center;
    float left_end;
    float right_end;
    float top_end;
    float bottom_end;
    int size_x;
    int size_y;

    CloudsOrStars(ID2D1Bitmap* bitmap) : bitmap(bitmap) {};

    void set_bitmap(ID2D1Bitmap* bitmap)
    {
        this->bitmap = bitmap;
    }

    void set_center(D2D1_POINT_2F center, int size_x, int size_y)
    {
        this->center = center;
        this->left_end = center.x - size_x;
        this->right_end = center.x + size_x;
        this->top_end = center.y - size_y;
        this->bottom_end = center.y + size_y;
        this->size_x = size_x;
        this->size_y - size_y;
    }
};

CloudsOrStars clouds(NULL);
CloudsOrStars stars1(NULL);
CloudsOrStars stars2(NULL);
CloudsOrStars stars_bck(NULL);