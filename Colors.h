#pragma once
#ifndef COLORS
#define COLORS

#include <d2d1.h>


ID2D1SolidColorBrush* brush = nullptr;
ID2D1SolidColorBrush* brush_dark_grey = nullptr;
ID2D1SolidColorBrush* brush_red = nullptr;
ID2D1SolidColorBrush* brush_white = nullptr;
ID2D1SolidColorBrush* brush_blue = nullptr;
ID2D1SolidColorBrush* brush_yellow = nullptr;
ID2D1SolidColorBrush* brush_light_orange = nullptr;
ID2D1SolidColorBrush* brush_orange = nullptr;
ID2D1SolidColorBrush* brush_navy = nullptr;

// Sta³e z kolorami
D2D1_COLOR_F const brush_color_white = { .r = 1.0f, .g = 1.0f, .b = 1.0f, .a = 1.0f };
D2D1_COLOR_F const brush_color_black = { .r = 0, .g = 0, .b = 0, .a = 1 };
D2D1_COLOR_F const brush_dark_grey_color = { .r = 0.2f, .g = 0.2f, .b = 0.2f, .a = 1.0f };
D2D1_COLOR_F const brush_color_red = { .r = 1, .g = 0, .b = 0, .a = 1 };
D2D1_COLOR_F const brush_color_blue = { .r = 0, .g = 0.6, .b = 1, .a = 1 };
D2D1_COLOR_F const brush_color_yellow = { .r = 1, .g = 1, .b = 0, .a = 1 };
D2D1_COLOR_F const brush_color_light_orange = { .r = 255 / 255.0f, .g = 209 / 255.0f, .b = 50 / 255.0f, .a = 1 };
D2D1_COLOR_F const brush_color_orange = { .r = 255 / 255.0f, .g = 189 / 255.0f, .b = 0 / 255.0f, .a = 1 };
D2D1_COLOR_F const navy = D2D1::ColorF(0.0f, 0.0f, 0.15f, 1.0f);


//Pêdzel gradient (linear) do cia³a rakiety
ID2D1LinearGradientBrush* rocket_lin_grad_brush = nullptr;
ID2D1LinearGradientBrush* top_rocket_lin_grad_brush = nullptr;
ID2D1LinearGradientBrush* window_rocket_lin_grad_brush = nullptr;

//Kolory do gradientu linearnego dla rakiety
D2D1_COLOR_F const grey_for_gradient = { .r = 0.2f, .g = 0.2f, .b = 0.2f, .a = 1.0f };
D2D1_COLOR_F const light_grey_for_gradient = { .r = 0.98f, .g = 0.98f, .b = 0.98f, .a = 1.0f };

#endif //!COLORS