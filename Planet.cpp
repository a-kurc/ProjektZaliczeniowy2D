#include "Planet.h"


void Planet::set_bitmap(ID2D1Bitmap* bitmap)
{
	this->bitmap = bitmap;
}

void Planet::set_center(D2D1_POINT_2F center, int size)
{
    this->center = center;
    this->left_end = center.x - size;
    this->right_end = center.x + size;
    this->top_end = center.y - size;
    this->bottom_end = center.y + size;
    this->size = size;
}

Planet::Planet(ID2D1Bitmap* bitmap) : bitmap(bitmap) {};