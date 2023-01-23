#ifndef UNICODE
#define UNICODE
#endif 

#include "Rocket.h"
#include "Asteroid.h"
#include "Planet.h"
#include "CloudsOrStars.h"
#include "Colors.h"
#include "Paths.h"
#include "main.h"

using namespace globals;


Asteroid asteroid(NULL, { 500, 500 }, 100);
Planet planet_saturn_pink(NULL);
Rocket rocket;
CloudsOrStars clouds(NULL);
CloudsOrStars stars1(NULL);
CloudsOrStars stars2(NULL);
CloudsOrStars stars_bck(NULL);


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


void create_brushes()
{
    d2d_render_target->CreateSolidColorBrush(brush_color_black, &brush);
    d2d_render_target->CreateSolidColorBrush(brush_dark_grey_color, &brush_dark_grey);
    d2d_render_target->CreateSolidColorBrush(brush_color_blue, &brush_blue);
    d2d_render_target->CreateSolidColorBrush(brush_color_yellow, &brush_yellow);
    d2d_render_target->CreateSolidColorBrush(brush_color_red, &brush_red);
    d2d_render_target->CreateSolidColorBrush(brush_color_white, &brush_white);
    d2d_render_target->CreateSolidColorBrush(brush_color_light_orange, &brush_light_orange);
    d2d_render_target->CreateSolidColorBrush(brush_color_orange, &brush_orange);
    d2d_render_target->CreateSolidColorBrush(navy, &brush_navy);
}


void release_rendertarget_factory_and_brushes()
{
    if (d2d_render_target) d2d_render_target->Release();
    if (d2d_factory) d2d_factory->Release();
    if (brush) brush->Release();
    if (brush_dark_grey) brush_dark_grey->Release();
    if (brush_blue) brush_blue->Release();
    if (brush_red) brush_red->Release();
    if (brush_yellow) brush_yellow->Release();
    if (brush_light_orange) brush_light_orange->Release();
    if (brush_orange) brush_orange->Release();
    if (brush_white) brush_white->Release();
    if (brush_navy) brush_navy->Release();
}


void create_rocket_paths()
{
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

    if (t_protrusion < 70) t_protrusion += 4; else t_protrusion = 0;
    if (m_protrusion < 70) m_protrusion += 4; else m_protrusion = 0;
    if (b_protrusion < 70) b_protrusion += 4; else b_protrusion = 0;

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

    ell = Ellipse(Point2F(rocket.centr_windw_x, rocket.center.y), rocket.window_r, rocket.window_r);

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

    if (rockt_lin_grad_stops) rockt_lin_grad_stops->Release();
    if (top_rockt_lin_grad_stops) top_rockt_lin_grad_stops->Release();
    if (window_rockt_grad_stops_arr) window_rockt_lin_grad_stops->Release();
}


void release_paths()
{
    if (path_rocket_body) path_rocket_body->Release();
    if (path_rocket_top) path_rocket_top->Release();
    if (path_rocket_bottom) path_rocket_bottom->Release();
    if (path_sink_rocket_body) path_sink_rocket_body->Release();
    if (path_sink_rocket_top) path_sink_rocket_top->Release();
    if (path_sink_rocket_bottom) path_sink_rocket_bottom->Release();
    if (rocket_lin_grad_brush) rocket_lin_grad_brush->Release();
    if (engines_rocket_path) engines_rocket_path->Release();
    if (engines_rocket_path_sink) engines_rocket_path_sink->Release();
    if (top_rocket_lin_grad_brush) top_rocket_lin_grad_brush->Release();
    if (window_rocket_lin_grad_brush) window_rocket_lin_grad_brush->Release();
    if (path_fire_t) path_fire_t->Release();
    if (path_sink_fire_t) path_sink_fire_t->Release();
    if (path_fire_m) path_fire_m->Release();
    if (path_sink_fire_m) path_sink_fire_m->Release();
    if (path_fire_b) path_fire_b->Release();
    if (path_sink_fire_b) path_sink_fire_b->Release();
}


void asteroid_out_of_window()
{
    int random_size = 80 + (rand() % 60);
    int offset = rc.top + random_size;
    int range = rc.bottom - 3 * random_size - rc.top;
    float random_y = offset + (rand() % range);
    asteroid = Asteroid(asteroid.bitmap, { (float)rc.right + random_size , random_y }, random_size);
    srand(time(NULL));
    int random_speed = 7 + (rand() % 3);
    if (score == 0 || score == -1)
        random_speed = 5;
    asteroid.set_speed(random_speed);
    score += 1;
}


void handle_rocket_moves() 
{
    if (GetAsyncKeyState(VK_RIGHT) < 0)
        rocket.move_right();
    if (GetAsyncKeyState(VK_LEFT) < 0)
        rocket.move_left();
    if (GetAsyncKeyState(VK_UP) < 0)
        rocket.move_up();
    if (GetAsyncKeyState(VK_DOWN) < 0)
        rocket.move_down();
}


void set_size_of_window()
{
    Matrix3x2F scale = Matrix3x2F::Scale((initial_width) / (rc.right - rc.left),
        ((initial_higth) / (rc.bottom - rc.top)), Point2F(0, 0));
    d2d_render_target->SetTransform(scale);
}


void set_centers_of_bitmaps()
{
    planet_saturn_pink.set_center({ (float)rc.right - 200, (float)rc.top + 200 }, 125);
    clouds.set_center({ (float)rc.right - 400, (float)rc.top + 200 }, 335, 200);
    stars1.set_center({ (float)rc.right - 210, (float)rc.top + 200 }, 335, 200);
    stars2.set_center({ (float)rc.left + 300, (float)rc.bottom - 100 }, 305, 120);
    stars_bck.set_center({ half_x, half_y }, half_x + 70, half_y + 60);
}


void handle_game_over(HWND hwnd)
{
    game_over = true;
    asteroid.set_center({ (float)rc.left,0 }, 0);

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


void write_score()
{
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
}


void draw_background()
{
    d2d_render_target->FillRectangle(D2D1::RectF(0, 0, rc.right, rc.bottom), brush_navy);
    d2d_render_target->DrawBitmap(stars_bck.bitmap, D2D1::RectF(stars_bck.left_end, stars_bck.top_end,
        stars_bck.right_end, stars_bck.bottom_end));
}


void draw_everything()
{
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


int load_bitmaps(HWND hwnd)
{
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
}


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


LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    GetClientRect(hwnd, &rc);
    half_y = (rc.bottom - rc.top) / 2;
    half_x = (rc.right - rc.left) / 2;

    switch (uMsg)
    {
    case WM_CREATE:
    {
        D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &d2d_factory);
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
        int range = rc.bottom - 2*size - rc.top;
        float random = offset + (rand() % range);

        asteroid.set_center({ (float)rc.right + size, random }, size);
        asteroid.set_speed(4);
        rocket.set_center(half_x - 400, half_y);

        if (!rc_initiated_already)
        {
            initial_higth = rc.bottom - rc.top;
            initial_width = rc.right - rc.left;
        }

        create_brushes();
        load_bitmaps(hwnd);
        return 0;
    }
    case WM_DESTROY:
    {
        release_rendertarget_factory_and_brushes();
        PostQuitMessage(0);
        return 0;
    }
    case WM_PAINT:
    {
        handle_rocket_moves();
        if (asteroid.right_end < rc.left && !game_over) //asteroida wyleciała już poza okno
            asteroid_out_of_window();
        asteroid.set_center({ asteroid.center.x -= asteroid.speed, asteroid.center.y }, asteroid.size);
        set_size_of_window();
        create_rocket_paths();
        set_centers_of_bitmaps();
        // Rysowanie
        d2d_render_target->BeginDraw();
        d2d_render_target->Clear(brush_color_white);
        draw_background();
        if (DidRocketHitRock(rocket, asteroid) || game_over)
            handle_game_over(hwnd);
        if (!game_over) {            
            write_score();
            draw_everything();
        }
        d2d_render_target->EndDraw();
        release_paths();
        return 0;
    }
    return 0;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
