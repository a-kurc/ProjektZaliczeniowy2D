#pragma once

#ifndef ROCKET
#define ROCKET


#include "projekt_zal.h"

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
        center.x += 6;
    }
    void move_left() {
        center.x -= 6;
    }
    void move_up() {
        center.y -= 6;
    }
    void move_down() {
        center.y += 6;
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

Rocket rocket;

#endif // !ROCKET