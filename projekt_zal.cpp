﻿#ifndef UNICODE
#define UNICODE
#endif 

#include "projekt_zal.h"
using namespace globals;

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);


class Rocket
{
public:
    D2D1_POINT_2F center = { .x = 0, .y = 0 };
    int body_l_end_x;
    int body_r_end_x;
    int body_ends_y;
    int body_l_point_x;
    int body_r_point_x;
    int body_l_point_y;
    int body_r_point_y;
    int body_rounding_x;
    int top_end_x;
    int top_rounding_x;
    int top_rounding_y;
    int bot_r_end_x;
    int bot_l_end_x;
    int bot_ends_y;
    int centr_windw_x;
    int window_r;
    int eng_start_x;
    int eng_ur_point_x;
    int eng_ul_point_x;
    int eng_l_end_x;
    int eng_dl_point_x;
    int eng_dr_point_x;
    int eng_mid_point_x;
    int eng_ur_point_y;
    int eng_ul_point_y;
    int eng_ul_end_y;
    int eng_dl_end_y;
    int eng_dr_point_y;
    int eng_dl_point_y;
    int t_end_line_x;
    int t_top_end_x;
    int m_end_line_x;
    int m_top_end_x;
    int b_end_line_x;
    int b_top_end_x;
    int tt_end_line_y;
    int t_topt_end_y;
    int t_topb_end_y;
    int tb_end_line_y;
    int mt_end_line_y;
    int m_topt_end_y;
    int m_topb_end_y;
    int mb_end_line_y;
    int bt_end_line_y;
    int b_topt_end_y;
    int b_topb_end_y;
    int bb_end_line_y;

    void set_center(UINT32 x, UINT32 y) {
        center.x = x;
        center.y = y;
    }
    void move_right() {
        center.x += 5;
    }
    void move_left() {
        center.x -= 5;
    }
    void move_up() {
        center.y -= 5;
    }
    void move_down() {
        center.y += 5;
    }

    void set_attributes(int body_l_end_x, int body_r_end_x, int body_ends_y, int body_l_point_x, int body_r_point_x, int body_l_point_y,
        int body_r_point_y, int body_rounding_x, int top_end_x, int top_rounding_x, int top_rounding_y, int bot_r_end_x,
        int bot_l_end_x, int bot_ends_y, int centr_windw_x, int window_r, int eng_start_x, int eng_ur_point_x, int eng_ul_point_x,
        int eng_l_end_x, int eng_dl_point_x, int eng_dr_point_x, int eng_mid_point_x, int eng_ur_point_y, int eng_ul_point_y,
        int eng_ul_end_y, int eng_dl_end_y, int eng_dr_point_y, int eng_dl_point_y)
    {
        this->body_l_end_x = body_l_end_x;
        this->body_r_end_x = body_r_end_x;
        this->body_ends_y = body_ends_y;
        this->body_l_point_x = body_l_point_x;
        this->body_r_point_x = body_r_point_x;
        this->body_l_point_y = body_l_point_y;
        this->body_r_point_y = body_r_point_y;
        this->body_rounding_x = body_rounding_x;
        this->top_end_x = top_end_x;
        this->top_rounding_x = top_rounding_x;
        this->top_rounding_y = top_rounding_y;
        this->bot_r_end_x = bot_r_end_x;
        this->bot_l_end_x = bot_l_end_x;
        this->bot_ends_y = bot_ends_y;
        this->centr_windw_x = centr_windw_x;
        this->window_r = window_r;
        this->eng_start_x = eng_start_x;
        this->eng_ur_point_x = eng_ur_point_x;
        this->eng_ul_point_x = eng_ul_point_x;
        this->eng_l_end_x = eng_l_end_x;
        this->eng_dl_point_x = eng_dl_point_x;
        this->eng_dr_point_x = eng_dr_point_x;
        this->eng_mid_point_x = eng_mid_point_x;
        this->eng_ur_point_y = eng_ur_point_y;
        this->eng_ul_point_y = eng_ul_point_y;
        this->eng_ul_end_y = eng_ul_end_y;
        this->eng_dl_end_y = eng_dl_end_y;
        this->eng_dr_point_y = eng_dr_point_y;
        this->eng_dl_point_y = eng_dl_point_y;
    }

    void set_fire(int t_end_line_x, int t_top_end_x, int m_end_line_x, int m_top_end_x, int b_end_line_x, 
        int b_top_end_x, int tt_end_line_y, int t_topt_end_y, int t_topb_end_y, int tb_end_line_y, 
        int mt_end_line_y, int m_topt_end_y, int m_topb_end_y, int mb_end_line_y, int bt_end_line_y, 
        int b_topt_end_y, int b_topb_end_y, int bb_end_line_y) 
    {
        this->t_end_line_x = t_end_line_x;
        this->t_top_end_x = t_top_end_x;
        this->m_end_line_x = m_end_line_x;
        this->m_top_end_x = m_top_end_x;
        this->b_end_line_x = b_end_line_x;
        this->b_top_end_x = b_top_end_x;
        this->tt_end_line_y = tt_end_line_y;
        this->t_topt_end_y = t_topt_end_y;
        this->t_topb_end_y = t_topb_end_y;
        this->tb_end_line_y = tb_end_line_y;
        this->mt_end_line_y = mt_end_line_y;
        this->m_topt_end_y = m_topt_end_y;
        this->m_topb_end_y = m_topb_end_y;
        this->mb_end_line_y = mb_end_line_y;
        this->bt_end_line_y = bt_end_line_y;
        this->b_topt_end_y = b_topt_end_y;
        this->b_topb_end_y = b_topb_end_y;
        this->bb_end_line_y = bb_end_line_y;
    }
};

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


class Clouds
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

    Clouds(ID2D1Bitmap* bitmap) : bitmap(bitmap) {};

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

Rocket rocket;

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
    // Register the window class.
    const wchar_t CLASS_NAME[] = L"Sample Window Class";

    WNDCLASS wc = { };

    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hIcon = NULL;
    wc.hCursor = NULL;

    RegisterClass(&wc);

    HRESULT hr = DWriteCreateFactory(
        DWRITE_FACTORY_TYPE_SHARED,
        __uuidof(IDWriteFactory),
        reinterpret_cast<IUnknown**>(&write_factory)
    );
    write_factory->CreateTextFormat(
        L"Calibri",
        nullptr,
        DWRITE_FONT_WEIGHT_BOLD,
        DWRITE_FONT_STYLE_NORMAL,
        DWRITE_FONT_STRETCH_NORMAL,
        100.0f,
        L"en-us",
        &text_format
    );

    // Create the window.
    HWND hwnd = CreateWindowEx(
        0,                              // Optional window styles.
        CLASS_NAME,                     // Window class
        L"Learn to Program Windows",    // Window text
        WS_OVERLAPPEDWINDOW,            // Window style

        // Size and position
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

        NULL,       // Parent window    
        NULL,       // Menu
        hInstance,  // Instance handle
        NULL        // Additional application data
    );

    if (hwnd == NULL)
        return 0;

    ShowWindow(hwnd, nCmdShow);

    // Run the message loop.
    MSG msg = { };
    while (GetMessage(&msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }


    return 0;
}

Asteroid asteroid(NULL, { 500, 500 }, 100);
Planet planet_saturn_pink(NULL);
Clouds clouds(NULL);
Clouds stars1(NULL);
Clouds stars2(NULL);
Clouds stars_bck(NULL);

bool IsPointCloseToPoint(D2D1_POINT_2F a, D2D1_POINT_2F b, float d)
{
    // Calculate the distance from point a to point b.
    float dx = a.x - b.x;
    float dy = a.y - b.y;
    float distance = sqrt(dx * dx + dy * dy);


    // Check if the distance is smaller than d.
    return distance < d;
}

bool DidRocketHitRock(Rocket rocket, Asteroid astr) {

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

ID2D1Bitmap* load_bitmap(HWND hwnd, HRESULT hr, const LPCWSTR name, ID2D1Bitmap* lbitmap, IWICImagingFactory* pWICFactory)
{
    // Load bitmap from file
    IWICBitmapDecoder* pDecoder = NULL;
    hr = pWICFactory->CreateDecoderFromFilename(name, NULL, GENERIC_READ, WICDecodeMetadataCacheOnLoad, &pDecoder);
    if (FAILED(hr))
    {
        MessageBox(hwnd, L"Error loading bitmap from file.", L"Error", MB_ICONERROR);
    }
    IWICBitmapFrameDecode* pFrame = NULL;

    hr = pDecoder->GetFrame(0, &pFrame);
    if (FAILED(hr))
    {
        MessageBox(hwnd, L"Error getting frame from bitmap decoder.", L"Error", MB_ICONERROR);
    }
    IWICFormatConverter* pConverter = NULL;
    hr = pWICFactory->CreateFormatConverter(&pConverter);
    if (FAILED(hr))
    {
        MessageBox(hwnd, L"Error creating format converter.", L"Error", MB_ICONERROR);
    }
    hr = pConverter->Initialize(pFrame, GUID_WICPixelFormat32bppPBGRA, WICBitmapDitherTypeNone, NULL, 0.0, WICBitmapPaletteTypeCustom);
    if (FAILED(hr))
    {
        MessageBox(hwnd, L"Error initializing format converter.", L"Error", MB_ICONERROR);
    }

    hr = d2d_render_target->CreateBitmapFromWicBitmap(pConverter, NULL, &lbitmap);
    if (FAILED(hr))
    {
        MessageBox(hwnd, L"Error creating Direct2D bitmap from WIC bitmap.", L"Error", MB_ICONERROR);
    }

    d2d_render_target->SetDpi(96.0f, 96.0f);

    return lbitmap;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    GetClientRect(hwnd, &rc);
    half_y = (rc.bottom - rc.top) / 2;
    half_x = (rc.right - rc.left) / 2;


    switch (uMsg)
    {
    case WM_CREATE:
    {
        D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED,
            &d2d_factory);

        GetClientRect(hwnd, &rc);

        d2d_factory->CreateHwndRenderTarget(
            RenderTargetProperties(),
            HwndRenderTargetProperties(hwnd,
                SizeU(static_cast<UINT32>(rc.right) -
                    static_cast<UINT32>(rc.left),
                    static_cast<UINT32>(rc.bottom) -
                    static_cast<UINT32>(rc.top))),
            &d2d_render_target);

        int size = 100;
        srand(time(NULL));
        int offset = rc.top + size;
        int range = rc.bottom - size - size/2 - rc.top;
        float random = offset + (rand() % range);

        asteroid.set_center({ (float)rc.right + size, random }, size);
        asteroid.set_speed(4);

        rocket.set_center(half_x - 400, half_y);

        if (!rc_initiated_already)
        {
            initial_higth = rc.bottom - rc.top;
            initial_width = rc.right - rc.left;
        }

        CoInitializeEx(nullptr, COINIT_APARTMENTTHREADED);

        HRESULT hr = CoCreateInstance(CLSID_WICImagingFactory, NULL, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&pWICFactory));
        if (FAILED(hr))
        {
            MessageBox(hwnd, L"Error creating WIC imaging factory.", L"Error", MB_ICONERROR);
            return -1;
        }

        LPCWSTR name = L"asteroida.png";
        asteroid.bitmap = load_bitmap(hwnd, hr, name, asteroid.bitmap, pWICFactory);

        name = L"saturn_pink_3.png";
        planet_saturn_pink.bitmap = load_bitmap(hwnd, hr, name, planet_saturn_pink.bitmap, pWICFactory);

        name = L"clouds1.png";
        clouds.bitmap = load_bitmap(hwnd, hr, name, clouds.bitmap, pWICFactory);

        name = L"my_stars6.png";
        stars1.bitmap = load_bitmap(hwnd, hr, name, stars1.bitmap, pWICFactory);

        name = L"my_galaxy2.png";
        stars2.bitmap = load_bitmap(hwnd, hr, name, stars2.bitmap, pWICFactory);

        name = L"my_stars_background.png";
        stars_bck.bitmap = load_bitmap(hwnd, hr, name, stars2.bitmap, pWICFactory);

        return 0;
    }
    case WM_DESTROY:
    {
        if (d2d_render_target) d2d_render_target->Release();
        if (d2d_factory) d2d_factory->Release();

        PostQuitMessage(0);
        return 0;
    }
    case WM_PAINT:
    {
        //protrusions:
        int body_l_end_x = 120;
        int body_r_end_x = 135;
        int body_ends_y = 47;
        int eng_ul_end_y = 90;

        if (GetAsyncKeyState(VK_RIGHT) < 0)
            rocket.move_right();
        if (GetAsyncKeyState(VK_LEFT) < 0)
            rocket.move_left();
        if (GetAsyncKeyState(VK_UP) < 0)
            rocket.move_up();
        if (GetAsyncKeyState(VK_DOWN) < 0)
            rocket.move_down();


        if (asteroid.right_end < rc.left && !game_over) 
        {
            int random_size = 80 + (rand() % 60);
            int offset = rc.top + random_size;
            int range = rc.bottom - 3 * random_size - rc.top;
            float random_y = offset + (rand() % range);
            asteroid = Asteroid(asteroid.bitmap, { (float)rc.right + random_size , random_y }, random_size);
            srand(time(NULL));
            int random_speed = 5 + (rand() % 3);
            if (score == 0)
                random_speed = 5;
            asteroid.set_speed(random_speed);
            score += 1;
        }

        asteroid.set_center({ asteroid.center.x -= asteroid.speed, asteroid.center.y }, asteroid.size);

        Matrix3x2F scale = Matrix3x2F::Scale((initial_width) / (rc.right - rc.left),
            ((initial_higth) / (rc.bottom - rc.top)), Point2F(0, 0));
        d2d_render_target->SetTransform(scale);

        ID2D1SolidColorBrush* brush = nullptr;
        ID2D1SolidColorBrush* brush_dark_grey = nullptr;
        ID2D1SolidColorBrush* brush_red = nullptr;
        ID2D1SolidColorBrush* brush_white = nullptr;
        ID2D1SolidColorBrush* brush_blue = nullptr;
        ID2D1SolidColorBrush* brush_yellow = nullptr;
        ID2D1SolidColorBrush* brush_light_orange = nullptr;
        ID2D1SolidColorBrush* brush_orange = nullptr;

        // - Interfejsy do obs�ugi �cie�ki
        ID2D1PathGeometry* path_rocket_body = nullptr;
        ID2D1PathGeometry* path_rocket_top = nullptr;
        ID2D1PathGeometry* path_rocket_bottom = nullptr;
        ID2D1PathGeometry* engines_rocket_path = nullptr;
        ID2D1GeometrySink* path_sink_rocket_body = nullptr;
        ID2D1GeometrySink* path_sink_rocket_top = nullptr;
        ID2D1GeometrySink* path_sink_rocket_bottom = nullptr;
        ID2D1GeometrySink* engines_rocket_path_sink = nullptr;
        ID2D1PathGeometry* path_fire_t = nullptr;
        ID2D1PathGeometry* path_fire_m = nullptr;
        ID2D1PathGeometry* path_fire_b = nullptr;
        ID2D1GeometrySink* path_sink_fire_t = nullptr;
        ID2D1GeometrySink* path_sink_fire_m = nullptr;
        ID2D1GeometrySink* path_sink_fire_b = nullptr;


        // Stałe z kolorami
        D2D1_COLOR_F const brush_color_white = { .r = 1.0f, .g = 1.0f, .b = 1.0f, .a = 1.0f };
        D2D1_COLOR_F const brush_color_black = { .r = 0, .g = 0, .b = 0, .a = 1 };
        D2D1_COLOR_F const brush_dark_grey_color = { .r = 0.2f, .g = 0.2f, .b = 0.2f, .a = 1.0f };
        D2D1_COLOR_F const brush_color_red = { .r = 1, .g = 0, .b = 0, .a = 1 };
        D2D1_COLOR_F const brush_color_blue = { .r = 0, .g = 0.6, .b = 1, .a = 1 };
        D2D1_COLOR_F const brush_color_yellow = { .r = 1, .g = 1, .b = 0, .a = 1 };
        D2D1_COLOR_F const brush_color_light_orange = { .r = 255 / 255.0f, .g = 209 / 255.0f, .b = 50 / 255.0f, .a = 1 };
        D2D1_COLOR_F const brush_color_orange = { .r = 255 / 255.0f, .g = 189 / 255.0f, .b = 0 / 255.0f, .a = 1 };

        // Utworzenie pędzli
        d2d_render_target->CreateSolidColorBrush(brush_color_black, &brush);
        d2d_render_target->CreateSolidColorBrush(brush_dark_grey_color, &brush_dark_grey);
        d2d_render_target->CreateSolidColorBrush(brush_color_red, &brush_red);
        d2d_render_target->CreateSolidColorBrush(brush_color_white, &brush_white);
        d2d_render_target->CreateSolidColorBrush(brush_color_blue, &brush_blue);
        d2d_render_target->CreateSolidColorBrush(brush_color_yellow, &brush_yellow);
        d2d_render_target->CreateSolidColorBrush(brush_color_light_orange, &brush_light_orange);
        d2d_render_target->CreateSolidColorBrush(brush_color_orange, &brush_orange);


        //Pędzel gradient (linear) do ciała rakiety
        ID2D1LinearGradientBrush* rocket_lin_grad_brush = nullptr;
        ID2D1LinearGradientBrush* top_rocket_lin_grad_brush = nullptr;
        ID2D1LinearGradientBrush* window_rocket_lin_grad_brush = nullptr;


        //Kolory do gradientu linearnego dla rakiety
        D2D1_COLOR_F const grey_for_gradient = { .r = 0.2f, .g = 0.2f, .b = 0.2f, .a = 1.0f };
        D2D1_COLOR_F const light_grey_for_gradient = { .r = 0.98f, .g = 0.98f, .b = 0.98f, .a = 1.0f };


        ID2D1GradientStopCollection* rockt_lin_grad_stops = NULL;
        D2D1_GRADIENT_STOP rockt_grad_stops_arr[2];
        rockt_grad_stops_arr[0].color = light_grey_for_gradient;
        rockt_grad_stops_arr[0].position = 0.f;
        rockt_grad_stops_arr[1].color = grey_for_gradient;
        rockt_grad_stops_arr[1].position = 1.0f;
        // Create the ID2D1GradientStopCollection from a previously
        // declared array of D2D1_GRADIENT_STOP structs.
        d2d_render_target->CreateGradientStopCollection(
            rockt_grad_stops_arr,
            2,
            D2D1_GAMMA_2_2,
            D2D1_EXTEND_MODE_CLAMP,
            &rockt_lin_grad_stops
        );

        //Kolory do gradientu linearnego dla topu rakiety
        ID2D1GradientStopCollection* top_rockt_lin_grad_stops = NULL;
        D2D1_GRADIENT_STOP top_rockt_grad_stops_arr[2];
        top_rockt_grad_stops_arr[0].color = D2D1::ColorF(D2D1::ColorF::Red, 1);
        top_rockt_grad_stops_arr[0].position = 0.0f;
        top_rockt_grad_stops_arr[1].color = grey_for_gradient;
        top_rockt_grad_stops_arr[1].position = 1.0f;
        // Create the ID2D1GradientStopCollection from a previously
        // declared array of D2D1_GRADIENT_STOP structs.
        d2d_render_target->CreateGradientStopCollection(
            top_rockt_grad_stops_arr,
            2,
            D2D1_GAMMA_2_2,
            D2D1_EXTEND_MODE_CLAMP,
            &top_rockt_lin_grad_stops
        );

        //Kolory do gradientu linearnego dla okna rakiety
        ID2D1GradientStopCollection* window_rockt_lin_grad_stops = NULL;
        D2D1_GRADIENT_STOP window_rockt_grad_stops_arr[2];
        window_rockt_grad_stops_arr[0].color = brush_color_blue;
        window_rockt_grad_stops_arr[0].position = 0.0f;
        window_rockt_grad_stops_arr[1].color = grey_for_gradient;
        window_rockt_grad_stops_arr[1].position = 1.0f;
        // Create the ID2D1GradientStopCollection from a previously
        // declared array of D2D1_GRADIENT_STOP structs.
        d2d_render_target->CreateGradientStopCollection(
            window_rockt_grad_stops_arr,
            2,
            D2D1_GAMMA_2_2,
            D2D1_EXTEND_MODE_CLAMP,
            &window_rockt_lin_grad_stops
        );


        rocket.set_attributes(120, 135, 47, 20, 60, 90, 90, 20, body_r_end_x + 50, body_r_end_x + 20, 35, body_l_end_x, body_l_end_x + 15,
            body_ends_y, rocket.center.x + 40, 40, 12, 90, 95, 160, 100, 120, 90, 145, 125, 90, eng_ul_end_y - 10, 115, 95);

        d2d_factory->CreatePathGeometry(&path_rocket_body);
        path_rocket_body->Open(&path_sink_rocket_body);
        path_sink_rocket_body->BeginFigure(Point2F(rocket.center.x - body_l_end_x, rocket.center.y - body_ends_y), D2D1_FIGURE_BEGIN_FILLED);
        path_sink_rocket_body->AddBezier(BezierSegment(
            Point2F(rocket.center.x - rocket.body_l_point_x, rocket.center.y - rocket.body_l_point_y),
            Point2F(rocket.center.x + rocket.body_r_point_x, rocket.center.y - rocket.body_r_point_y), 
            Point2F(rocket.center.x + body_r_end_x, rocket.center.y - body_ends_y)));
        path_sink_rocket_body->AddQuadraticBezier(QuadraticBezierSegment(
            Point2F(rocket.center.x + body_r_end_x - rocket.body_rounding_x, rocket.center.y), 
            Point2F(rocket.center.x + body_r_end_x, rocket.center.y + body_ends_y)));
        path_sink_rocket_body->AddBezier(BezierSegment(Point2F(rocket.center.x + rocket.body_r_point_x, rocket.center.y + rocket.body_r_point_y),
            Point2F(rocket.center.x - rocket.body_l_point_x, rocket.center.y + rocket.body_l_point_y), 
            Point2F(rocket.center.x - body_l_end_x, rocket.center.y + body_ends_y)));
        path_sink_rocket_body->AddQuadraticBezier(QuadraticBezierSegment(
            Point2F(rocket.center.x - body_l_end_x - rocket.body_rounding_x, rocket.center.y), 
            Point2F(rocket.center.x - body_l_end_x, rocket.center.y - body_ends_y)));
        path_sink_rocket_body->EndFigure(D2D1_FIGURE_END_OPEN);
        path_sink_rocket_body->Close();

        d2d_factory->CreatePathGeometry(&path_rocket_top);
        path_rocket_top->Open(&path_sink_rocket_top);
        path_sink_rocket_top->BeginFigure(Point2F(rocket.center.x + body_r_end_x, rocket.center.y - body_ends_y), D2D1_FIGURE_BEGIN_FILLED);
        path_sink_rocket_top->AddQuadraticBezier(QuadraticBezierSegment(
            Point2F(rocket.center.x + rocket.top_rounding_x, rocket.center.y - rocket.top_rounding_y), Point2F(rocket.center.x + rocket.top_end_x, rocket.center.y)));
        path_sink_rocket_top->AddQuadraticBezier(QuadraticBezierSegment(
            Point2F(rocket.center.x + rocket.top_rounding_x, rocket.center.y + rocket.top_rounding_y), Point2F(rocket.center.x + body_r_end_x, rocket.center.y + body_ends_y)));
        path_sink_rocket_top->AddQuadraticBezier(QuadraticBezierSegment(
            Point2F(rocket.center.x + rocket.body_rounding_x, rocket.center.y), Point2F(rocket.center.x + body_r_end_x, rocket.center.y - body_ends_y)));
        path_sink_rocket_top->EndFigure(D2D1_FIGURE_END_OPEN);
        path_sink_rocket_top->Close();

        d2d_factory->CreatePathGeometry(&path_rocket_bottom);
        path_rocket_bottom->Open(&path_sink_rocket_bottom);
        path_sink_rocket_bottom->BeginFigure(Point2F(rocket.center.x - body_l_end_x, rocket.center.y - rocket.bot_ends_y), D2D1_FIGURE_BEGIN_FILLED);
        path_sink_rocket_bottom->AddQuadraticBezier(QuadraticBezierSegment(
            Point2F(rocket.center.x - body_l_end_x - rocket.body_rounding_x, rocket.center.y), Point2F(rocket.center.x - body_l_end_x, rocket.center.y + rocket.bot_ends_y)));
        path_sink_rocket_bottom->AddLine(Point2F(rocket.center.x - rocket.bot_l_end_x, rocket.center.y + rocket.bot_ends_y));
        path_sink_rocket_bottom->AddQuadraticBezier(QuadraticBezierSegment(
            Point2F(rocket.center.x - rocket.bot_l_end_x - rocket.body_rounding_x, rocket.center.y), Point2F(rocket.center.x - rocket.bot_l_end_x, rocket.center.y - rocket.bot_ends_y)));
        path_sink_rocket_bottom->AddLine(Point2F(rocket.center.x - rocket.bot_r_end_x, rocket.center.y - rocket.bot_ends_y));
        path_sink_rocket_bottom->EndFigure(D2D1_FIGURE_END_OPEN);
        path_sink_rocket_bottom->Close();

        
        if (t_protrusion < 70) t_protrusion +=2; else t_protrusion = 0;
        if (m_protrusion < 70) m_protrusion += 2; else m_protrusion = 0;
        if (b_protrusion < 70) b_protrusion += 2; else b_protrusion = 0;

        rocket.set_fire(150 + t_protrusion, 200 + t_protrusion, 160 + m_protrusion, 210 + m_protrusion, 140 + b_protrusion, 190 + b_protrusion,
            rocket.body_ends_y, rocket.body_ends_y - 6, rocket.body_ends_y - 34, rocket.body_ends_y - 40,
            rocket.body_ends_y - 28, rocket.body_ends_y - 28 - 6, rocket.body_ends_y - 28 - 34, rocket.body_ends_y - 28 - 40,
            rocket.body_ends_y - 56, rocket.body_ends_y - 56 - 6, rocket.body_ends_y - 56 - 34, rocket.body_ends_y - 56 - 40);

        d2d_factory->CreatePathGeometry(&path_fire_t);
        path_fire_t->Open(&path_sink_fire_t);
        path_sink_fire_t->BeginFigure(Point2F(rocket.center.x - rocket.bot_l_end_x, rocket.center.y - rocket.bot_ends_y), D2D1_FIGURE_BEGIN_FILLED);
        path_sink_fire_t->AddLine(Point2F(rocket.center.x - rocket.t_end_line_x, rocket.center.y - rocket.tt_end_line_y));
        path_sink_fire_t->AddBezier(BezierSegment(Point2F(rocket.center.x - rocket.t_top_end_x, rocket.center.y - rocket.t_topt_end_y),
            Point2F(rocket.center.x - rocket.t_top_end_x, rocket.center.y - rocket.t_topb_end_y), 
            Point2F(rocket.center.x - rocket.t_end_line_x, rocket.center.y - rocket.tb_end_line_y)));
        path_sink_fire_t->AddLine(Point2F(rocket.center.x - rocket.bot_l_end_x, rocket.center.y - rocket.tb_end_line_y));
        path_sink_fire_t->EndFigure(D2D1_FIGURE_END_OPEN);
        path_sink_fire_t->Close();

        d2d_factory->CreatePathGeometry(&path_fire_m);
        path_fire_m->Open(&path_sink_fire_m);
        path_sink_fire_m->BeginFigure(Point2F(rocket.center.x - rocket.bot_l_end_x, rocket.center.y - rocket.mt_end_line_y), D2D1_FIGURE_BEGIN_FILLED);
        path_sink_fire_m->AddLine(Point2F(rocket.center.x - rocket.m_end_line_x, rocket.center.y - rocket.mt_end_line_y));
        path_sink_fire_m->AddBezier(BezierSegment(Point2F(rocket.center.x - rocket.m_top_end_x, rocket.center.y - rocket.m_topt_end_y),
            Point2F(rocket.center.x - rocket.m_top_end_x, rocket.center.y - rocket.m_topb_end_y), 
            Point2F(rocket.center.x - rocket.m_end_line_x, rocket.center.y - rocket.mb_end_line_y)));
        path_sink_fire_m->AddLine(Point2F(rocket.center.x - rocket.bot_l_end_x, rocket.center.y - rocket.mb_end_line_y));
        path_sink_fire_m->EndFigure(D2D1_FIGURE_END_OPEN);
        path_sink_fire_m->Close();

        d2d_factory->CreatePathGeometry(&path_fire_b);
        path_fire_b->Open(&path_sink_fire_b);
        path_sink_fire_b->BeginFigure(Point2F(rocket.center.x - rocket.bot_l_end_x, rocket.center.y - rocket.bt_end_line_y), D2D1_FIGURE_BEGIN_FILLED);
        path_sink_fire_b->AddLine(Point2F(rocket.center.x - rocket.b_end_line_x, rocket.center.y - rocket.bt_end_line_y));
        path_sink_fire_b->AddBezier(BezierSegment(Point2F(rocket.center.x - rocket.b_top_end_x, rocket.center.y - rocket.b_topt_end_y),
            Point2F(rocket.center.x - rocket.b_top_end_x, rocket.center.y - rocket.b_topb_end_y), 
            Point2F(rocket.center.x - rocket.b_end_line_x, rocket.center.y - rocket.bb_end_line_y)));
        path_sink_fire_b->AddLine(Point2F(rocket.center.x - rocket.bot_l_end_x, rocket.center.y - rocket.bb_end_line_y));
        path_sink_fire_b->EndFigure(D2D1_FIGURE_END_OPEN);
        path_sink_fire_b->Close();


        const D2D1_ELLIPSE ell = Ellipse(Point2F(rocket.centr_windw_x, rocket.center.y), rocket.window_r, rocket.window_r);


        d2d_factory->CreatePathGeometry(&engines_rocket_path);
        engines_rocket_path->Open(&engines_rocket_path_sink);
        engines_rocket_path_sink->BeginFigure(Point2F(rocket.center.x - rocket.eng_start_x, rocket.center.y), D2D1_FIGURE_BEGIN_FILLED);
        engines_rocket_path_sink->AddBezier(BezierSegment(
            Point2F(rocket.center.x - rocket.eng_ur_point_x, rocket.center.y - rocket.eng_ur_point_y),
            Point2F(rocket.center.x - rocket.eng_ul_point_x, rocket.center.y - rocket.eng_ul_point_y), 
            Point2F(rocket.center.x - rocket.eng_l_end_x, rocket.center.y - eng_ul_end_y)));
        engines_rocket_path_sink->AddLine(Point2F(rocket.center.x - rocket.eng_l_end_x, rocket.center.y - rocket.eng_dl_end_y));
        engines_rocket_path_sink->AddBezier(BezierSegment(
            Point2F(rocket.center.x - rocket.eng_dl_point_x, rocket.center.y - rocket.eng_dl_point_y),
            Point2F(rocket.center.x - rocket.eng_dr_point_x, rocket.center.y - rocket.eng_dr_point_y), 
            Point2F(rocket.center.x - rocket.eng_mid_point_x, rocket.center.y)));
        engines_rocket_path_sink->AddBezier(BezierSegment(
            Point2F(rocket.center.x - rocket.eng_dr_point_x, rocket.center.y + rocket.eng_dr_point_y),
            Point2F(rocket.center.x - rocket.eng_dl_point_x, rocket.center.y + rocket.eng_dl_point_y), 
            Point2F(rocket.center.x - rocket.eng_l_end_x, rocket.center.y + rocket.eng_dl_end_y)));
        engines_rocket_path_sink->AddLine(Point2F(rocket.center.x - rocket.eng_l_end_x, rocket.center.y + eng_ul_end_y));
        engines_rocket_path_sink->AddBezier(BezierSegment(
            Point2F(rocket.center.x - rocket.eng_ul_point_x, rocket.center.y + rocket.eng_ul_point_y),
            Point2F(rocket.center.x - rocket.eng_ur_point_x, rocket.center.y + rocket.eng_ur_point_y), 
            Point2F(rocket.center.x - rocket.eng_start_x, rocket.center.y)));
        engines_rocket_path_sink->EndFigure(D2D1_FIGURE_END_OPEN);
        engines_rocket_path_sink->Close();


        //Tworzenie gradientu linearnego dla rakiety
        d2d_render_target->CreateLinearGradientBrush(
            D2D1::LinearGradientBrushProperties(
                D2D1::Point2F(rocket.center.x, rocket.center.y + 15),
                D2D1::Point2F(rocket.center.x, rocket.center.y + 85)),
            rockt_lin_grad_stops,
            &rocket_lin_grad_brush
        );

        d2d_render_target->CreateLinearGradientBrush(
            D2D1::LinearGradientBrushProperties(
                D2D1::Point2F(rocket.center.x + body_r_end_x, rocket.center.y + 15),
                D2D1::Point2F(rocket.center.x + body_r_end_x, rocket.center.y + 85)),
            top_rockt_lin_grad_stops,
            &top_rocket_lin_grad_brush
        );

        d2d_render_target->CreateLinearGradientBrush(
            D2D1::LinearGradientBrushProperties(
                D2D1::Point2F(rocket.center.x + body_r_end_x, rocket.center.y + 15),
                D2D1::Point2F(rocket.center.x + body_r_end_x, rocket.center.y + 85)),
            window_rockt_lin_grad_stops,
            &window_rocket_lin_grad_brush
        );


        D2D1_COLOR_F const navy = D2D1::ColorF(0.0f, 0.0f, 0.15f, 1.0f);
        ID2D1SolidColorBrush* brush_navy;
        d2d_render_target->CreateSolidColorBrush(navy, &brush_navy);

        planet_saturn_pink.set_center({ (float)rc.right - 200, (float)rc.top + 200 }, 125);
        clouds.set_center({ (float)rc.right - 400, (float)rc.top + 200 }, 335, 200);
        stars1.set_center({ (float)rc.right - 210, (float)rc.top + 200 }, 335, 200);
        stars2.set_center({ (float)rc.left + 300, (float)rc.bottom - 100 }, 305, 120);
        stars_bck.set_center({ half_x, half_y }, half_x + 70 , half_y + 60);


        float brush_body_width = 5.0f;
        float brush_eye_width = 3.0f;
        float brush_mouth_width = 9.0f;
        float brush_rocket_width = 3.5f;

        // Rysowanie
        d2d_render_target->BeginDraw();
        d2d_render_target->Clear(brush_color_white);

        d2d_render_target->FillRectangle(D2D1::RectF(0, 0, rc.right, rc.bottom), brush_navy);
        d2d_render_target->DrawBitmap(stars_bck.bitmap, D2D1::RectF(stars_bck.left_end, stars_bck.top_end,
            stars_bck.right_end, stars_bck.bottom_end));

        if (DidRocketHitRock(rocket, asteroid) || game_over)
        {
            game_over = true;

            asteroid.set_center({ (float) rc.left,0 }, 0);

            int width_click_info = 415;
            int button_rect_left = half_x - width_click_info;
            int button_rect_up = half_y;
            int button_rect_right = half_x + width_click_info;
            int button_rect_bot = half_y + 125;

            d2d_render_target->FillRectangle(
                D2D1::RectF(button_rect_left, button_rect_up, button_rect_right, button_rect_bot),
                brush_red
            );
            d2d_render_target->DrawText(
                L"Game Over",
                wcslen(L"Game Over"),
                text_format,
                D2D1::RectF(half_x - 240, half_y - 300, half_x + 240, half_y - 170),
                brush_white
            );
            d2d_render_target->DrawText(
                L"Click here to restart",
                wcslen(L"Click here to restart"),
                text_format,
                D2D1::RectF(button_rect_left, button_rect_up, button_rect_right, button_rect_bot),
                brush_white
            );
            

            POINT cursor_pos;
            GetCursorPos(&cursor_pos);

            // Convert the cursor position to client coordinates
            ScreenToClient(hwnd, &cursor_pos);

            int mouse_x = cursor_pos.x;
            int mouse_y = cursor_pos.y;
            
            if (GetAsyncKeyState(VK_LBUTTON) < 0) {
                if (mouse_x >= button_rect_left && mouse_x <= button_rect_right &&
                    mouse_y >= button_rect_up && mouse_y <= button_rect_bot)
                {
                    score = -1;
                    rocket.center.y = half_y;
                    rocket.center.x = half_x - 400;
                    game_over = false;
                }
            }
        }

        
        if (!game_over) {            
            std::wstringstream ss;
            ss << L"Score: " << score;
            std::wstring result = ss.str();
            wchar_t NAPIS[13];
            for (int i = 0; i < 13; i++) {
                NAPIS[i] = ' ';
            }
            result.copy(NAPIS, result.size());
            NAPIS[result.size()] = 0;

            d2d_render_target->DrawText(
                NAPIS,
                sizeof(NAPIS) / sizeof(NAPIS[0]),
                text_format,
                RectF(
                    150.0f, 80.0f,
                    static_cast<FLOAT>(rc.right),
                    static_cast<FLOAT>(rc.bottom)
                ),
                brush_white
            );
            
            
            d2d_render_target->DrawBitmap(stars1.bitmap, D2D1::RectF(stars1.left_end, stars1.top_end,
                stars1.right_end, stars1.bottom_end));
            d2d_render_target->DrawBitmap(stars2.bitmap, D2D1::RectF(stars2.left_end, stars2.top_end,
                stars2.right_end, stars2.bottom_end));
            d2d_render_target->DrawBitmap(planet_saturn_pink.bitmap, D2D1::RectF(planet_saturn_pink.left_end, planet_saturn_pink.top_end,
                planet_saturn_pink.right_end, planet_saturn_pink.bottom_end));
            d2d_render_target->DrawBitmap(asteroid.bitmap, D2D1::RectF(asteroid.left_end, asteroid.top_end,
                asteroid.right_end, asteroid.bottom_end));
            d2d_render_target->DrawBitmap(clouds.bitmap, D2D1::RectF(clouds.left_end, clouds.top_end,
                clouds.right_end, clouds.bottom_end));

            d2d_render_target->DrawGeometry(path_rocket_top, brush, brush_rocket_width);
            d2d_render_target->FillGeometry(path_rocket_top, top_rocket_lin_grad_brush);
            
            d2d_render_target->DrawGeometry(path_fire_t, brush_orange, brush_rocket_width);
            d2d_render_target->FillGeometry(path_fire_t, brush_orange);
            d2d_render_target->DrawGeometry(path_fire_b, brush_light_orange, brush_rocket_width);
            d2d_render_target->FillGeometry(path_fire_b, brush_light_orange);
            d2d_render_target->DrawGeometry(path_fire_m, brush_yellow, brush_rocket_width);
            d2d_render_target->FillGeometry(path_fire_m, brush_yellow);
            
            d2d_render_target->DrawGeometry(path_rocket_bottom, brush, brush_rocket_width);
            d2d_render_target->FillGeometry(path_rocket_bottom, brush_dark_grey);

            d2d_render_target->DrawGeometry(engines_rocket_path, brush, brush_rocket_width);
            d2d_render_target->FillGeometry(engines_rocket_path, brush_red);

            d2d_render_target->DrawGeometry(path_rocket_body, brush, brush_rocket_width);
            d2d_render_target->FillGeometry(path_rocket_body, rocket_lin_grad_brush);
            d2d_render_target->DrawEllipse(ell, brush, brush_rocket_width, nullptr);
            d2d_render_target->FillEllipse(ell, window_rocket_lin_grad_brush);
        }


        d2d_render_target->EndDraw();

        if (brush) brush->Release();
        if (brush_dark_grey) brush_dark_grey->Release();
        if (path_rocket_body) path_rocket_body->Release();
        if (path_rocket_top) path_rocket_top->Release();
        if (path_rocket_bottom) path_rocket_bottom->Release();
        if (path_sink_rocket_body) path_sink_rocket_body->Release();
        if (path_sink_rocket_top) path_sink_rocket_top->Release();
        if (path_sink_rocket_bottom) path_sink_rocket_bottom->Release();
        if (rocket_lin_grad_brush) rocket_lin_grad_brush->Release();
        if (engines_rocket_path) engines_rocket_path->Release();
        if (engines_rocket_path_sink) engines_rocket_path_sink->Release();
        if (brush_blue) brush_blue->Release();
        if (brush_red) brush_red->Release();
        if (brush_yellow) brush_yellow->Release();
        if (brush_light_orange) brush_light_orange->Release();
        if (brush_orange) brush_orange->Release();
        if (brush_white) brush_white->Release();
        if (rockt_lin_grad_stops) rockt_lin_grad_stops->Release();
        if (top_rocket_lin_grad_brush) top_rocket_lin_grad_brush->Release();
        if (top_rockt_lin_grad_stops) top_rockt_lin_grad_stops->Release();
        if (window_rocket_lin_grad_brush) window_rocket_lin_grad_brush->Release();
        if (window_rockt_grad_stops_arr) window_rockt_lin_grad_stops->Release();
        if (path_fire_t) path_fire_t->Release();
        if (path_sink_fire_t) path_sink_fire_t->Release();
        if (path_fire_m) path_fire_m->Release();
        if (path_sink_fire_m) path_sink_fire_m->Release();
        if (path_fire_b) path_fire_b->Release();
        if (path_sink_fire_b) path_sink_fire_b->Release();
    }

    return 0;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}