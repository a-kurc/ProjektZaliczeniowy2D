#pragma once

#ifndef ZAD4STWOREK_H
#define ZAD4STWOREK_H

#include <windows.h>
#include <d2d1_3.h>
#include <d2d1.h>
#include <math.h>
#include <stdio.h>
#include <windowsx.h>
#include <cmath>
#include <cstdlib>
#include <array>
#include <windows.h>
#include <wincodec.h>
#include <objbase.h>
#include <chrono>
#include <thread>
#include <iostream>
#include <ctime>
#include <d2d1_1.h>
#include <dwrite_3.h>	// i do��czy� dwrite.lib do projektu
#include <dwrite.h>
#include <sstream>
#include <cstdio>
#pragma comment(lib, "windowscodecs.lib")
#pragma comment(lib, "d2d1")
#pragma comment(lib, "windowscodecs")
#pragma comment(lib, "Dwrite")
#pragma comment(lib, "d2d1")

using D2D1::RenderTargetProperties;
using D2D1::HwndRenderTargetProperties;
using D2D1::SizeU;
using D2D1::Point2F;
using D2D1::StrokeStyleProperties;
using D2D1::ColorF;
using D2D1::BezierSegment;
using D2D1::QuadraticBezierSegment;
using D2D1::Matrix3x2F;
using D2D1::LinearGradientBrushProperties;
using D2D1::RadialGradientBrushProperties;
using D2D1::RectF;
using D2D1::Ellipse;
using D2D1::BitmapProperties;
using D2D1::PixelFormat;
using std::sin;
using std::array;


int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow);
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

namespace globals
{
	ID2D1Factory7* d2d_factory = nullptr;
	ID2D1HwndRenderTarget* d2d_render_target = nullptr;
	RECT rc{};
	bool rc_initiated_already = false;
	float half_y;
	float half_x;
	float r_eye = 95;
	float r_pupil = 35;
	D2D1_POINT_2F ellipse_center_pupil1 = { 0, 0 };
	D2D1_POINT_2F ellipse_center_pupil2 = { 0, 0 };
	float radius_of_middleeye_squared = pow((r_eye - r_pupil), 2);
	float radius_of_middleeye = r_eye - r_pupil;
	float initial_width = 0;
	float initial_higth = 0;
	IWICImagingFactory* pWICFactory = NULL;
	IDWriteFactory* write_factory = nullptr;
	IDWriteTextFormat* text_format = nullptr;
	int score = 0;
	bool game_over = false;
	int t_protrusion = 30;
	int m_protrusion = 0;
	int b_protrusion = 50;
	//float time = 0;
	float brush_body_width = 5.0f;
	float brush_eye_width = 3.0f;
	float brush_mouth_width = 9.0f;
	float brush_rocket_width = 3.5f;
	int body_l_end_x = 120;
	int body_r_end_x = 135;
	int body_ends_y = 47;
	int eng_ul_end_y = 90;
}

#endif