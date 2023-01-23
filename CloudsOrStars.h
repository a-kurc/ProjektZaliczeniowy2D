#pragma once
#ifndef CLOUDSORSTARS
#define CLOUDSORSTARS

#include <d2d1.h>


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

    CloudsOrStars(ID2D1Bitmap* bitmap);

    void set_bitmap(ID2D1Bitmap* bitmap);

    void set_center(D2D1_POINT_2F center, int size_x, int size_y);
};

#endif