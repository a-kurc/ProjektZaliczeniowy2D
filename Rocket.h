#pragma once

#ifndef ROCKET
#define ROCKET

#include <d2d1.h>

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

    void set_center(UINT32 x, UINT32 y);
    void move_right();
    void move_left();
    void move_up();
    void move_down();

    void set_attributes(int body_l_end_x, int body_r_end_x, int body_ends_y, int body_l_point_x, int body_r_point_x, int body_l_point_y,
        int body_r_point_y, int body_rounding_x, int top_end_x, int top_rounding_x, int top_rounding_y, int bot_r_end_x,
        int bot_l_end_x, int bot_ends_y, int centr_windw_x, int window_r, int eng_start_x, int eng_ur_point_x, int eng_ul_point_x,
        int eng_l_end_x, int eng_dl_point_x, int eng_dr_point_x, int eng_mid_point_x, int eng_ur_point_y, int eng_ul_point_y,
        int eng_ul_end_y, int eng_dl_end_y, int eng_dr_point_y, int eng_dl_point_y);

    void set_fire(int t_end_line_x, int t_top_end_x, int m_end_line_x, int m_top_end_x, int b_end_line_x,
        int b_top_end_x, int tt_end_line_y, int t_topt_end_y, int t_topb_end_y, int tb_end_line_y,
        int mt_end_line_y, int m_topt_end_y, int m_topb_end_y, int mb_end_line_y, int bt_end_line_y,
        int b_topt_end_y, int b_topb_end_y, int bb_end_line_y);
};

#endif // !ROCKET