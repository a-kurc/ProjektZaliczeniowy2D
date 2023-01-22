#include "CloudsOrStars.h"

CloudsOrStars::CloudsOrStars(ID2D1Bitmap* bitmap) : bitmap(bitmap) {};

void CloudsOrStars::set_bitmap(ID2D1Bitmap* bitmap)
{
    this->bitmap = bitmap;
}

void CloudsOrStars::set_center(D2D1_POINT_2F center, int size_x, int size_y)
{
    this->center = center;
    this->left_end = center.x - size_x;
    this->right_end = center.x + size_x;
    this->top_end = center.y - size_y;
    this->bottom_end = center.y + size_y;
    this->size_x = size_x;
    this->size_y - size_y;
}