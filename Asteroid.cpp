#include "Asteroid.h"


Asteroid::Asteroid(ID2D1Bitmap* bitmap, D2D1_POINT_2F center, int size)
{
    this->bitmap = bitmap;
    this->center = center;
    this->size = size;
    this->left_end = center.x - size;
    this->right_end = center.x + size;
    this->top_end = center.y - size;
    this->bottom_end = center.y + size;
}

void Asteroid::set_center(D2D1_POINT_2F center, int size)
{
    this->center = center;
    this->left_end = center.x - size;
    this->right_end = center.x + size;
    this->top_end = center.y - size;
    this->bottom_end = center.y + size;
    this->size = size;
}

void Asteroid::set_speed(int speed)
{
    this->speed = speed;
}

bool IsPointCloseToPoint(D2D1_POINT_2F a, D2D1_POINT_2F b, float d)
{
    // Calculate the distance from point a to point b.
    float dx = a.x - b.x;
    float dy = a.y - b.y;
    float distance = sqrt(dx * dx + dy * dy);

    // Check if the distance is smaller than d.
    return distance < d;
}

bool DidRocketHitRock(Rocket rocket, Asteroid astr)
{
    if (IsPointCloseToPoint(astr.center, { (float)rocket.top_end_x + rocket.center.x,
            (float)rocket.center.y }, astr.size)
        || IsPointCloseToPoint(astr.center, { (float)rocket.body_r_end_x + rocket.center.x,
            (float)rocket.center.y + (float)rocket.body_ends_y }, astr.size)
        || IsPointCloseToPoint(astr.center, { (float)rocket.body_r_end_x + rocket.center.x,
            (float)rocket.center.y - (float)rocket.body_ends_y }, astr.size)
        || IsPointCloseToPoint(astr.center, { (float)rocket.center.x + rocket.body_r_point_x,
            (float)rocket.center.y - (float)rocket.body_r_point_y }, astr.size - 18)
        || IsPointCloseToPoint(astr.center, { (float)rocket.center.x + rocket.body_r_point_x,
            (float)rocket.center.y + (float)rocket.body_r_point_y }, astr.size - 18)
        || IsPointCloseToPoint(astr.center, { (float)rocket.center.x - rocket.eng_ur_point_x,
            (float)rocket.center.y + (float)rocket.eng_ur_point_y }, astr.size - 26)
        || IsPointCloseToPoint(astr.center, { (float)rocket.center.x - rocket.eng_ur_point_x,
            (float)rocket.center.y - (float)rocket.eng_ur_point_y }, astr.size - 26)
        )
        return true;
}