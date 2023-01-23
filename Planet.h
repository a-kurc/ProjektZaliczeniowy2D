#pragma once
#ifndef PLANET
#define PLANET

#include <d2d1.h>


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

    Planet(ID2D1Bitmap* bitmap);

    void set_bitmap(ID2D1Bitmap* bitmap);

    void set_center(D2D1_POINT_2F center, int size);
};

#endif // !PLANET