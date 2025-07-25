// Copyright (C) 2024 Paul Johnson
// Copyright (C) 2024-2025 Maxim Nesterov

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Affero General Public License as
// published by the Free Software Foundation, either version 3 of the
// License, or (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Affero General Public License for more details.

// You should have received a copy of the GNU Affero General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

#include <Client/Assets/RenderFunctions.h>

#include <math.h>

#include <Client/Assets/Render.h>
#include <Client/Renderer/Renderer.h>
#include <Shared/StaticData.h>

#define IMAGE_SIZE (256.0f)
struct rr_renderer petal_cache;

void rr_renderer_draw_petal(struct rr_renderer *renderer, uint8_t id,
                            uint8_t rarity, uint8_t flags)
{
    if (flags & 1)
    {
        if (id == rr_petal_id_clover && rarity >= rr_rarity_id_exotic)
            id = rr_petal_id_max;
        rr_renderer_scale(renderer, 50 / IMAGE_SIZE);
        rr_renderer_draw_clipped_image(
            renderer, &petal_cache, IMAGE_SIZE / 2 + IMAGE_SIZE * id,
            IMAGE_SIZE / 2, IMAGE_SIZE, IMAGE_SIZE, 0, 0);
        rr_renderer_scale(renderer, IMAGE_SIZE / 50);
    }
    else
    {
        switch (id)
        {
        case rr_petal_id_none:
            break;
        case rr_petal_id_basic:
            rr_renderer_set_stroke(renderer, 0xffcfcfcf);
            rr_renderer_set_fill(renderer, 0xffffffff);
            rr_renderer_set_line_width(renderer, 3.0f);
            rr_renderer_begin_path(renderer);
            rr_renderer_arc(renderer, 0.0f, 0.0f, 10.0f);
            rr_renderer_fill(renderer);
            rr_renderer_stroke(renderer);
            break;
        case rr_petal_id_pellet:
            rr_renderer_set_stroke(renderer, 0xffcfcfcf);
            rr_renderer_set_fill(renderer, 0xffffffff);
            rr_renderer_set_line_width(renderer, 3.0f);
            rr_renderer_begin_path(renderer);
            rr_renderer_arc(renderer, 0.0f, 0.0f, 7.0f);
            rr_renderer_fill(renderer);
            rr_renderer_stroke(renderer);
            break;
        case rr_petal_id_fossil:
            rr_renderer_scale(renderer, 0.2);
            rr_renderer_set_fill(renderer, 0xff95896a);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, -51.08, -54.77);
            rr_renderer_line_to(renderer, 13.74, -69.95);
            rr_renderer_line_to(renderer, 72.00, -25.23);
            rr_renderer_line_to(renderer, 66.26, 33.85);
            rr_renderer_line_to(renderer, 19.49, 69.95);
            rr_renderer_line_to(renderer, -42.26, 56.50);
            rr_renderer_line_to(renderer, -72.00, 6.36);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xffa49776);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, -32.09, 42.41);
            rr_renderer_line_to(renderer, -55.97, 5.87);
            rr_renderer_line_to(renderer, -40.75, -41.54);
            rr_renderer_line_to(renderer, 11.02, -54.16);
            rr_renderer_line_to(renderer, 57.56, -18.49);
            rr_renderer_line_to(renderer, 51.47, 28.05);
            rr_renderer_line_to(renderer, 14.93, 54.15);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xff9a8d6d);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, -38.27, -7.08);
            rr_renderer_line_to(renderer, -19.24, 10.28);
            rr_renderer_line_to(renderer, -8.56, 34.66);
            rr_renderer_line_to(renderer, 19.49, 33.99);
            rr_renderer_line_to(renderer, 38.18, 8.28);
            rr_renderer_line_to(renderer, 31.17, -23.44);
            rr_renderer_line_to(renderer, 3.46, -37.46);
            rr_renderer_line_to(renderer, -24.25, -29.78);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xff84785c);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, 8.77, -10.99);
            rr_renderer_bezier_curve_to(renderer, 16.89, -8.95, 22.59, -1.65,
                                        22.59, 6.73);
            rr_renderer_line_to(renderer, 13.45, 6.73);
            rr_renderer_bezier_curve_to(renderer, 13.45, 2.54, 10.60, -1.11,
                                        6.54, -2.13);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xff84785c);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, 22.59, 6.73);
            rr_renderer_bezier_curve_to(renderer, 22.59, 14.64, 16.77, 21.36,
                                        8.93, 22.48);
            rr_renderer_line_to(renderer, 7.63, 13.40);
            rr_renderer_bezier_curve_to(renderer, 10.95, 12.92, 13.41, 10.08,
                                        13.41, 6.73);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xff84785c);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, -10.35, -6.86);
            rr_renderer_bezier_curve_to(renderer, -4.90, -11.07, 2.17, -12.58,
                                        8.87, -10.98);
            rr_renderer_line_to(renderer, 6.73, -2.05);
            rr_renderer_bezier_curve_to(renderer, 2.73, -3.01, -1.49, -2.11,
                                        -4.75, 0.41);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xff84785c);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, -21.80, 11.22);
            rr_renderer_bezier_curve_to(renderer, -20.07, 3.98, -15.93, -2.45,
                                        -10.05, -7.02);
            rr_renderer_line_to(renderer, -4.43, 0.23);
            rr_renderer_bezier_curve_to(renderer, -8.66, 3.51, -11.64, 8.14,
                                        -12.89, 13.35);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xff84785c);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, 3.56, 17.93);
            rr_renderer_bezier_curve_to(renderer, 3.56, 15.42, 5.59, 13.38,
                                        8.10, 13.38);
            rr_renderer_bezier_curve_to(renderer, 9.31, 13.38, 10.47, 13.86,
                                        11.32, 14.71);
            rr_renderer_bezier_curve_to(renderer, 12.17, 15.56, 12.65, 16.72,
                                        12.65, 17.93);
            rr_renderer_bezier_curve_to(renderer, 12.65, 20.44, 10.61, 22.47,
                                        8.10, 22.47);
            rr_renderer_bezier_curve_to(renderer, 5.59, 22.47, 3.56, 20.44,
                                        3.56, 17.93);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xff84785c);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, -12.76, 35.16);
            rr_renderer_bezier_curve_to(renderer, -20.42, 29.74, -23.98, 20.18,
                                        -21.72, 11.07);
            rr_renderer_line_to(renderer, -12.81, 13.28);
            rr_renderer_bezier_curve_to(renderer, -14.16, 18.72, -12.04, 24.43,
                                        -7.46, 27.67);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xff84785c);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, 24.80, 35.10);
            rr_renderer_bezier_curve_to(renderer, 13.52, 43.02, -1.51, 43.02,
                                        -12.79, 35.11);
            rr_renderer_line_to(renderer, -7.53, 27.60);
            rr_renderer_bezier_curve_to(renderer, 0.59, 33.30, 11.41, 33.30,
                                        19.54, 27.60);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xff84785c);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, -41.90, -10.06);
            rr_renderer_bezier_curve_to(renderer, -37.14, -28.29, -20.98,
                                        -41.24, -2.15, -41.92);
            rr_renderer_bezier_curve_to(renderer, 16.68, -42.61, 33.73, -30.85,
                                        39.79, -13.01);
            rr_renderer_bezier_curve_to(renderer, 45.86, 4.83, 39.50, 24.53,
                                        24.16, 35.47);
            rr_renderer_line_to(renderer, 18.83, 27.99);
            rr_renderer_bezier_curve_to(renderer, 30.87, 19.41, 35.85, 3.94,
                                        31.09, -10.06);
            rr_renderer_bezier_curve_to(renderer, 26.33, -24.06, 12.96, -33.28,
                                        -1.82, -32.74);
            rr_renderer_bezier_curve_to(renderer, -16.60, -32.21, -29.27,
                                        -22.04, -33.01, -7.73);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xff84785c);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, -17.42, 13.73);
            rr_renderer_bezier_curve_to(renderer, -29.24, 13.71, -39.48, 5.52,
                                        -42.08, -6.01);
            rr_renderer_line_to(renderer, -32.93, -8.08);
            rr_renderer_bezier_curve_to(renderer, -31.29, -0.82, -24.85, 4.34,
                                        -17.41, 4.35);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xff84785c);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, -42.48, -8.00);
            rr_renderer_bezier_curve_to(renderer, -42.48, -10.51, -40.44,
                                        -12.54, -37.93, -12.54);
            rr_renderer_bezier_curve_to(renderer, -36.73, -12.54, -35.57,
                                        -12.07, -34.72, -11.21);
            rr_renderer_bezier_curve_to(renderer, -33.87, -10.36, -33.39, -9.20,
                                        -33.39, -8.00);
            rr_renderer_bezier_curve_to(renderer, -33.39, -5.49, -35.42, -3.45,
                                        -37.93, -3.45);
            rr_renderer_bezier_curve_to(renderer, -40.44, -3.45, -42.48, -5.49,
                                        -42.48, -8.00);
            rr_renderer_fill(renderer);
            rr_renderer_scale(renderer, 1 / 0.2);
            break;
        case rr_petal_id_stinger:
            rr_renderer_set_fill(renderer, 0xff333333);
            rr_renderer_set_stroke(renderer, 0xff292929);
            rr_renderer_set_line_width(renderer, 3.0f);
            rr_renderer_set_line_join(renderer, 1.0f);
            rr_renderer_set_line_cap(renderer, 1.0f);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, 7.00, 0.00);
            rr_renderer_line_to(renderer, -3.50, 6.06);
            rr_renderer_line_to(renderer, -3.50, -6.06);
            rr_renderer_line_to(renderer, 7.00, 0.00);
            rr_renderer_fill(renderer);
            rr_renderer_stroke(renderer);
            break;
        case rr_petal_id_berry:
            rr_renderer_set_stroke(renderer, 0xffb8250b);
            rr_renderer_set_fill(renderer, 0xffe62e0e);
            rr_renderer_set_line_width(renderer, 3.0f);
            rr_renderer_begin_path(renderer);
            rr_renderer_arc(renderer, 0.0f, 0.0f, 7.0f);
            rr_renderer_fill(renderer);
            rr_renderer_stroke(renderer);
            break;
        case rr_petal_id_shell:
            rr_renderer_scale(renderer, 0.15f);
            rr_renderer_set_fill(renderer, 0xffd2c6a7);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, -64.46, -11.54);
            rr_renderer_line_to(renderer, -32.45, 17.66);
            rr_renderer_line_to(renderer, -14.48, 58.65);
            rr_renderer_line_to(renderer, 32.69, 57.52);
            rr_renderer_line_to(renderer, 64.14, 14.29);
            rr_renderer_line_to(renderer, 52.35, -39.05);
            rr_renderer_line_to(renderer, 5.73, -62.64);
            rr_renderer_line_to(renderer, -40.88, -49.72);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xffaa9e80);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, 14.67, -18.12);
            rr_renderer_bezier_curve_to(renderer, 28.33, -14.69, 37.91, -2.41,
                                        37.91, 11.68);
            rr_renderer_line_to(renderer, 22.55, 11.68);
            rr_renderer_bezier_curve_to(renderer, 22.55, 4.63, 17.76, -1.51,
                                        10.93, -3.22);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xffaa9e80);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, 37.91, 11.68);
            rr_renderer_bezier_curve_to(renderer, 37.91, 24.99, 28.12, 36.28,
                                        14.94, 38.17);
            rr_renderer_line_to(renderer, 12.75, 22.89);
            rr_renderer_bezier_curve_to(renderer, 18.34, 22.09, 22.48, 17.31,
                                        22.48, 11.68);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xffaa9e80);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, -17.49, -11.18);
            rr_renderer_bezier_curve_to(renderer, -8.31, -18.25, 3.57, -20.80,
                                        14.84, -18.10);
            rr_renderer_line_to(renderer, 11.25, -3.09);
            rr_renderer_bezier_curve_to(renderer, 4.51, -4.70, -2.58, -3.18,
                                        -8.07, 1.05);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xffaa9e80);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, -36.75, 19.23);
            rr_renderer_bezier_curve_to(renderer, -33.84, 7.06, -26.87, -3.76,
                                        -16.98, -11.44);
            rr_renderer_line_to(renderer, -7.52, 0.74);
            rr_renderer_bezier_curve_to(renderer, -14.64, 6.27, -19.66, 14.05,
                                        -21.75, 22.81);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xffaa9e80);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, 5.91, 30.51);
            rr_renderer_bezier_curve_to(renderer, 5.91, 26.29, 9.33, 22.87,
                                        13.55, 22.87);
            rr_renderer_bezier_curve_to(renderer, 15.58, 22.87, 17.53, 23.67,
                                        18.96, 25.10);
            rr_renderer_bezier_curve_to(renderer, 20.39, 26.54, 21.20, 28.48,
                                        21.20, 30.51);
            rr_renderer_bezier_curve_to(renderer, 21.20, 34.73, 17.78, 38.15,
                                        13.55, 38.15);
            rr_renderer_bezier_curve_to(renderer, 9.33, 38.15, 5.91, 34.73,
                                        5.91, 30.51);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xffaa9e80);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, -21.54, 59.49);
            rr_renderer_bezier_curve_to(renderer, -34.43, 50.38, -40.41, 34.30,
                                        -36.62, 18.99);
            rr_renderer_line_to(renderer, -21.63, 22.70);
            rr_renderer_bezier_curve_to(renderer, -23.90, 31.84, -20.32, 41.45,
                                        -12.63, 46.89);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xffaa9e80);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, 41.64, 59.40);
            rr_renderer_bezier_curve_to(renderer, 22.66, 72.71, -2.62, 72.72,
                                        -21.60, 59.40);
            rr_renderer_line_to(renderer, -12.74, 46.78);
            rr_renderer_bezier_curve_to(renderer, 0.92, 56.36, 19.12, 56.36,
                                        32.78, 46.78);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xffaa9e80);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, -70.55, -16.55);
            rr_renderer_bezier_curve_to(renderer, -62.55, -47.21, -35.37,
                                        -69.00, -3.70, -70.14);
            rr_renderer_bezier_curve_to(renderer, 27.98, -71.29, 56.66, -51.52,
                                        66.86, -21.52);
            rr_renderer_bezier_curve_to(renderer, 77.06, 8.49, 66.36, 41.63,
                                        40.55, 60.02);
            rr_renderer_line_to(renderer, 31.58, 47.44);
            rr_renderer_bezier_curve_to(renderer, 51.84, 33.01, 60.23, 7.00,
                                        52.23, -16.54);
            rr_renderer_bezier_curve_to(renderer, 44.22, -40.09, 21.72, -55.60,
                                        -3.14, -54.70);
            rr_renderer_bezier_curve_to(renderer, -27.99, -53.80, -49.32,
                                        -36.71, -55.60, -12.65);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xffaa9e80);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, -29.38, 23.46);
            rr_renderer_bezier_curve_to(renderer, -49.26, 23.42, -66.48, 9.64,
                                        -70.86, -9.75);
            rr_renderer_line_to(renderer, -55.47, -13.22);
            rr_renderer_bezier_curve_to(renderer, -52.72, -1.01, -41.88, 7.67,
                                        -29.35, 7.69);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xffaa9e80);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, -71.53, -13.09);
            rr_renderer_bezier_curve_to(renderer, -71.53, -17.31, -68.11,
                                        -20.73, -63.89, -20.73);
            rr_renderer_bezier_curve_to(renderer, -61.86, -20.73, -59.91,
                                        -19.93, -58.48, -18.49);
            rr_renderer_bezier_curve_to(renderer, -57.05, -17.06, -56.24,
                                        -15.12, -56.24, -13.09);
            rr_renderer_bezier_curve_to(renderer, -56.24, -8.87, -59.66, -5.45,
                                        -63.89, -5.45);
            rr_renderer_bezier_curve_to(renderer, -68.11, -5.45, -71.53, -8.87,
                                        -71.53, -13.09);
            rr_renderer_fill(renderer);
            rr_renderer_scale(renderer, 1 / 0.15f);
            break;
        case rr_petal_id_peas:
            rr_renderer_set_stroke(renderer, 0xff709d45);
            rr_renderer_set_fill(renderer, 0xff8ac255);
            rr_renderer_set_line_width(renderer, 3.0f);
            rr_renderer_begin_path(renderer);
            rr_renderer_arc(renderer, 0.0f, 0.0f, 7.0f);
            rr_renderer_fill(renderer);
            rr_renderer_stroke(renderer);
            break;
        case rr_petal_id_leaf:
            rr_renderer_scale(renderer, 0.2);
            rr_renderer_rotate(renderer, M_PI * 3 / 4);
            rr_renderer_set_fill(renderer, 0xff2e8513);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, -42.50, 42.73);
            rr_renderer_bezier_curve_to(renderer, -66.06, 19.17, -66.06, -19.02,
                                        -42.50, -42.58);
            rr_renderer_bezier_curve_to(renderer, -31.19, -53.89, -15.85,
                                        -60.24, 0.15, -60.24);
            rr_renderer_bezier_curve_to(renderer, 16.15, -60.24, 31.49, -53.89,
                                        42.80, -42.58);
            rr_renderer_bezier_curve_to(renderer, 66.36, -19.02, 66.36, 19.17,
                                        42.80, 42.73);
            rr_renderer_bezier_curve_to(renderer, 19.25, 66.28, -18.94, 66.28,
                                        -42.50, 42.73);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xff2e8513);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, -59.02, -30.14);
            rr_renderer_bezier_curve_to(renderer, -67.01, -38.14, -67.01,
                                        -51.09, -59.02, -59.09);
            rr_renderer_bezier_curve_to(renderer, -55.18, -62.93, -49.97,
                                        -65.08, -44.55, -65.08);
            rr_renderer_bezier_curve_to(renderer, -39.12, -65.08, -33.91,
                                        -62.93, -30.07, -59.09);
            rr_renderer_bezier_curve_to(renderer, -22.08, -51.09, -22.08,
                                        -38.14, -30.07, -30.14);
            rr_renderer_bezier_curve_to(renderer, -38.07, -22.15, -51.03,
                                        -22.15, -59.02, -30.14);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xff2e8513);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, 4.38, -59.34);
            rr_renderer_line_to(renderer, -41.83, -64.86);
            rr_renderer_line_to(renderer, -29.53, -48.03);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xff3db11c);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, 0.06, 42.80);
            rr_renderer_bezier_curve_to(renderer, -23.49, 42.80, -42.58, 23.71,
                                        -42.58, 0.16);
            rr_renderer_quadratic_curve_to(renderer, -42.58, -23.57, -47.40,
                                           -47.29);
            rr_renderer_quadratic_curve_to(renderer, -23.67, -42.47, 0.06,
                                           -42.47);
            rr_renderer_bezier_curve_to(renderer, 23.61, -42.47, 42.69, -23.39,
                                        42.69, 0.16);
            rr_renderer_bezier_curve_to(renderer, 42.69, 23.71, 23.61, 42.80,
                                        0.06, 42.80);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xff2e8513);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, -17.00, -3.60);
            rr_renderer_bezier_curve_to(renderer, -20.72, -7.33, -20.72, -13.36,
                                        -17.00, -17.08);
            rr_renderer_bezier_curve_to(renderer, -15.22, -18.87, -12.79,
                                        -19.87, -10.27, -19.87);
            rr_renderer_bezier_curve_to(renderer, -7.74, -19.87, -5.32, -18.87,
                                        -3.53, -17.08);
            rr_renderer_line_to(renderer, 59.09, 45.54);
            rr_renderer_bezier_curve_to(renderer, 62.81, 49.26, 62.81, 55.29,
                                        59.09, 59.02);
            rr_renderer_bezier_curve_to(renderer, 55.37, 62.74, 49.34, 62.74,
                                        45.62, 59.02);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xff2e8513);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, -59.44, 4.49);
            rr_renderer_line_to(renderer, -64.96, -41.73);
            rr_renderer_line_to(renderer, -48.13, -29.42);
            rr_renderer_fill(renderer);
            rr_renderer_scale(renderer, 1 / 0.2);
            break;
        case rr_petal_id_egg:
            rr_renderer_set_stroke(renderer, 0xffb08a48);
            rr_renderer_set_fill(renderer, 0xffddad5a);
            rr_renderer_set_line_width(renderer, 3);
            rr_renderer_begin_path(renderer);
            rr_renderer_arc(renderer, 0, 0, 12);
            rr_renderer_fill(renderer);
            rr_renderer_stroke(renderer);
            break;
        case rr_petal_id_magnet:
            rr_renderer_scale(renderer, 0.5);
            rr_renderer_translate(renderer, -20.00, 0.00);
            rr_renderer_set_line_cap(renderer, 1);
            rr_renderer_set_stroke(renderer, 0xff363685);
            rr_renderer_set_line_width(renderer, 28);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, 39.50, 18.00);
            rr_renderer_quadratic_curve_to(renderer, 0.00, 30.00, 0.00, 0.00);
            rr_renderer_stroke(renderer);
            rr_renderer_set_stroke(renderer, 0xff4343a4);
            rr_renderer_set_line_width(renderer, 16.8);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, 40.00, 18.00);
            rr_renderer_quadratic_curve_to(renderer, 0.00, 30.00, 0.00, 0.00);
            rr_renderer_stroke(renderer);
            rr_renderer_set_stroke(renderer, 0xff853636);
            rr_renderer_set_line_width(renderer, 28);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, 39.50, -18.00);
            rr_renderer_quadratic_curve_to(renderer, 0.00, -30.00, 0.00, 0.00);
            rr_renderer_stroke(renderer);
            rr_renderer_set_stroke(renderer, 0xffa44343);
            rr_renderer_set_line_width(renderer, 16.8);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, 40.00, -18.00);
            rr_renderer_quadratic_curve_to(renderer, 0.00, -30.00, 0.00, 0.00);
            rr_renderer_stroke(renderer);
            rr_renderer_begin_path(renderer);
            rr_renderer_set_stroke(renderer, 0xff363685);
            rr_renderer_set_line_width(renderer, 28);
            rr_renderer_move_to(renderer, 39.50, 18.00);
            rr_renderer_quadratic_curve_to(renderer, 0.00, 30.00, 0.00, 0.00);
            rr_renderer_stroke(renderer);
            rr_renderer_set_stroke(renderer, 0xff4343a4);
            rr_renderer_set_line_width(renderer, 16.8);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, 40.00, 18.00);
            rr_renderer_quadratic_curve_to(renderer, 0.00, 30.00, 0.00, 0.00);
            rr_renderer_stroke(renderer);
            rr_renderer_set_line_cap(renderer, 0);
            rr_renderer_set_stroke(renderer, 0xff853636);
            rr_renderer_set_line_width(renderer, 28);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, 39.50, -18.00);
            rr_renderer_quadratic_curve_to(renderer, 0.00, -30.00, 0.00, 0.00);
            rr_renderer_stroke(renderer);
            rr_renderer_set_stroke(renderer, 0xffa44343);
            rr_renderer_set_line_width(renderer, 16.8);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, 40.00, -18.00);
            rr_renderer_quadratic_curve_to(renderer, 0.00, -30.00, 0.00, 0.00);
            rr_renderer_stroke(renderer);
            rr_renderer_scale(renderer, 1 / 0.5);
            break;
        case rr_petal_id_uranium: 
            rr_renderer_set_fill(renderer, 0xff63bf2e);
            rr_renderer_set_stroke(renderer, 0xff509b25);
            rr_renderer_set_line_cap(renderer, 1);
            rr_renderer_set_line_join(renderer, 1);
            rr_renderer_set_line_width(renderer, 3);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, -7.00, -5.00);
            rr_renderer_line_to(renderer, -1.00, -9.00);
            rr_renderer_line_to(renderer, 7.00, -6.00);
            rr_renderer_line_to(renderer, 9.00, 3.00);
            rr_renderer_line_to(renderer, 2.00, 9.00);
            rr_renderer_line_to(renderer, -5.00, 6.00);
            rr_renderer_line_to(renderer, -8.00, 2.00);
            rr_renderer_line_to(renderer, -7.00, -5.00);
            rr_renderer_fill(renderer);
            rr_renderer_stroke(renderer);
            break;
        case rr_petal_id_feather:
            rr_renderer_scale(renderer, 0.1);
            rr_renderer_set_fill(renderer, 0xffcccccc);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, -42.33, 139.47);
            rr_renderer_bezier_curve_to(renderer, -56.51, 129.03, -69.45,
                                        114.44, -77.90, 101.65);
            rr_renderer_bezier_curve_to(renderer, -86.35, 88.87, -91.18, 72.53,
                                        -93.03, 62.77);
            rr_renderer_bezier_curve_to(renderer, -94.88, 53.01, -88.68, 51.02,
                                        -89.00, 43.11);
            rr_renderer_bezier_curve_to(renderer, -89.33, 35.19, -94.17, 24.62,
                                        -94.99, 15.27);
            rr_renderer_bezier_curve_to(renderer, -95.82, 5.92, -95.50, -5.64,
                                        -93.96, -12.99);
            rr_renderer_bezier_curve_to(renderer, -92.41, -20.33, -87.61,
                                        -22.66, -85.72, -28.81);
            rr_renderer_bezier_curve_to(renderer, -83.82, -34.95, -84.83,
                                        -41.96, -82.60, -49.86);
            rr_renderer_bezier_curve_to(renderer, -80.37, -57.76, -75.83,
                                        -69.96, -72.35, -76.22);
            rr_renderer_bezier_curve_to(renderer, -68.87, -82.48, -66.51,
                                        -80.84, -61.70, -87.41);
            rr_renderer_bezier_curve_to(renderer, -56.90, -93.98, -53.12,
                                        -103.21, -43.51, -115.65);
            rr_renderer_bezier_curve_to(renderer, -33.89, -128.08, -14.04,
                                        -155.20, -4.01, -162.01);
            rr_renderer_bezier_curve_to(renderer, 6.02, -168.82, 11.78, -160.87,
                                        16.68, -156.51);
            rr_renderer_bezier_curve_to(renderer, 21.58, -152.16, 22.73,
                                        -141.98, 25.38, -135.87);
            rr_renderer_bezier_curve_to(renderer, 28.03, -129.76, 29.60,
                                        -125.06, 32.59, -119.88);
            rr_renderer_bezier_curve_to(renderer, 35.58, -114.70, 41.09,
                                        -108.95, 43.32, -104.81);
            rr_renderer_bezier_curve_to(renderer, 45.55, -100.67, 44.18, -97.56,
                                        45.96, -95.05);
            rr_renderer_bezier_curve_to(renderer, 47.75, -92.54, 49.94, -94.21,
                                        54.05, -89.74);
            rr_renderer_bezier_curve_to(renderer, 58.15, -85.26, 66.64, -76.70,
                                        70.59, -68.21);
            rr_renderer_bezier_curve_to(renderer, 74.54, -59.73, 76.44, -44.85,
                                        77.73, -38.82);
            rr_renderer_bezier_curve_to(renderer, 79.02, -32.78, 76.95, -34.44,
                                        78.32, -32.00);
            rr_renderer_bezier_curve_to(renderer, 79.69, -29.57, 83.28, -29.96,
                                        85.95, -24.19);
            rr_renderer_bezier_curve_to(renderer, 88.62, -18.43, 93.09, -6.37,
                                        94.33, 2.59);
            rr_renderer_bezier_curve_to(renderer, 95.57, 11.54, 94.76, 23.09,
                                        93.40, 29.51);
            rr_renderer_bezier_curve_to(renderer, 92.04, 35.93, 86.61, 37.67,
                                        86.17, 41.12);
            rr_renderer_bezier_curve_to(renderer, 85.72, 44.57, 91.06, 44.53,
                                        90.74, 50.19);
            rr_renderer_bezier_curve_to(renderer, 90.42, 55.85, 91.87, 61.19,
                                        84.23, 75.09);
            rr_renderer_bezier_curve_to(renderer, 76.59, 88.99, 57.74, 118.74,
                                        44.89, 133.61);
            rr_renderer_bezier_curve_to(renderer, 32.05, 148.47, 21.70, 163.31,
                                        7.16, 164.29);
            rr_renderer_bezier_curve_to(renderer, -7.37, 165.27, -28.16, 149.91,
                                        -42.33, 139.47);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xffe1e1e1);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, -4.14, 148.08);
            rr_renderer_bezier_curve_to(renderer, -19.45, 143.29, -47.24,
                                        114.21, -58.71, 99.66);
            rr_renderer_bezier_curve_to(renderer, -70.17, 85.10, -75.27, 65.96,
                                        -72.92, 60.74);
            rr_renderer_bezier_curve_to(renderer, -70.57, 55.53, -44.85, 71.38,
                                        -44.61, 68.37);
            rr_renderer_bezier_curve_to(renderer, -44.37, 65.36, -66.01, 55.27,
                                        -71.50, 42.68);
            rr_renderer_bezier_curve_to(renderer, -77.00, 30.09, -83.54, -2.64,
                                        -77.57, -7.17);
            rr_renderer_bezier_curve_to(renderer, -71.61, -11.69, -36.99, 18.22,
                                        -35.69, 15.52);
            rr_renderer_bezier_curve_to(renderer, -34.40, 12.83, -65.96, -9.61,
                                        -69.79, -23.32);
            rr_renderer_bezier_curve_to(renderer, -73.62, -37.03, -65.90,
                                        -61.50, -58.68, -66.75);
            rr_renderer_bezier_curve_to(renderer, -51.47, -72.00, -28.78,
                                        -51.91, -26.49, -54.82);
            rr_renderer_bezier_curve_to(renderer, -24.21, -57.72, -49.36,
                                        -68.65, -45.00, -84.17);
            rr_renderer_bezier_curve_to(renderer, -40.63, -99.69, -10.73,
                                        -142.22, -0.33, -147.94);
            rr_renderer_bezier_curve_to(renderer, 10.06, -153.65, 12.10,
                                        -128.18, 17.37, -118.46);
            rr_renderer_bezier_curve_to(renderer, 22.65, -108.75, 31.75, -99.73,
                                        31.33, -89.66);
            rr_renderer_bezier_curve_to(renderer, 30.90, -79.59, 12.93, -59.57,
                                        14.84, -58.03);
            rr_renderer_bezier_curve_to(renderer, 16.76, -56.48, 34.75, -84.75,
                                        42.83, -80.38);
            rr_renderer_bezier_curve_to(renderer, 50.91, -76.02, 66.54, -45.50,
                                        63.32, -31.84);
            rr_renderer_bezier_curve_to(renderer, 60.11, -18.18, 21.87, -0.75,
                                        23.56, 1.58);
            rr_renderer_bezier_curve_to(renderer, 25.25, 3.90, 64.32, -23.19,
                                        73.48, -17.90);
            rr_renderer_bezier_curve_to(renderer, 82.64, -12.61, 83.96, 21.42,
                                        78.53, 33.31);
            rr_renderer_bezier_curve_to(renderer, 73.10, 45.20, 41.02, 49.75,
                                        40.88, 53.43);
            rr_renderer_bezier_curve_to(renderer, 40.74, 57.10, 78.98, 42.85,
                                        77.69, 55.35);
            rr_renderer_bezier_curve_to(renderer, 76.41, 67.85, 46.81, 112.96,
                                        33.18, 128.42);
            rr_renderer_bezier_curve_to(renderer, 19.54, 143.88, 11.18, 152.88,
                                        -4.14, 148.08);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xffcccccc);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, 5.32, 157.96);
            rr_renderer_bezier_curve_to(renderer, 0.54, 151.69, -8.43, 129.67,
                                        -13.46, 112.82);
            rr_renderer_bezier_curve_to(renderer, -18.49, 95.97, -22.89, 76.05,
                                        -24.89, 56.86);
            rr_renderer_bezier_curve_to(renderer, -26.88, 37.67, -28.15, 19.25,
                                        -25.42, -2.32);
            rr_renderer_bezier_curve_to(renderer, -22.69, -23.89, -11.36,
                                        -72.22, -8.50, -72.57);
            rr_renderer_bezier_curve_to(renderer, -5.64, -72.92, -8.77, -22.61,
                                        -8.28, -4.42);
            rr_renderer_bezier_curve_to(renderer, -7.78, 13.77, -7.61, 19.09,
                                        -5.53, 36.57);
            rr_renderer_bezier_curve_to(renderer, -3.45, 54.06, -0.52, 81.50,
                                        4.22, 100.49);
            rr_renderer_bezier_curve_to(renderer, 8.96, 119.48, 21.08, 142.20,
                                        22.90, 150.52);
            rr_renderer_bezier_curve_to(renderer, 24.73, 158.84, 18.11, 149.19,
                                        15.18, 150.43);
            rr_renderer_bezier_curve_to(renderer, 12.25, 151.67, 10.09, 164.23,
                                        5.32, 157.96);
            rr_renderer_fill(renderer);
            rr_renderer_scale(renderer, 1 / 0.1);
            break;
        case rr_petal_id_azalea:
            rr_renderer_set_fill(renderer, 0xfff686bd);
            rr_renderer_set_stroke(renderer, 0xffc46b97);
            rr_renderer_set_line_cap(renderer, 1);
            rr_renderer_set_line_join(renderer, 1);
            rr_renderer_set_line_width(renderer, 3);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, -8.00, 0.00);
            rr_renderer_quadratic_curve_to(renderer, -12.94, -9.40, -2.47,
                                           -7.61);
            rr_renderer_quadratic_curve_to(renderer, 4.94, -15.22, 6.47, -4.70);
            rr_renderer_quadratic_curve_to(renderer, 16.00, -0.00, 6.47, 4.70);
            rr_renderer_quadratic_curve_to(renderer, 4.94, 15.22, -2.47, 7.61);
            rr_renderer_quadratic_curve_to(renderer, -12.94, 9.40, -8.00, 0.00);
            rr_renderer_fill(renderer);
            rr_renderer_stroke(renderer);
            break;
        case rr_petal_id_bone:
            rr_renderer_scale(renderer, 0.1);
            rr_renderer_set_fill(renderer, 0xffa19a84);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, -52.31, 37.23);
            rr_renderer_bezier_curve_to(renderer, -52.33, 60.77, -46.34, 134.50,
                                        -40.29, 154.89);
            rr_renderer_bezier_curve_to(renderer, -34.24, 175.28, -24.57,
                                        167.82, -16.01, 159.56);
            rr_renderer_bezier_curve_to(renderer, -7.44, 151.30, 0.76, 120.55,
                                        11.09, 105.34);
            rr_renderer_bezier_curve_to(renderer, 21.42, 90.13, 40.78, 85.41,
                                        45.97, 68.28);
            rr_renderer_bezier_curve_to(renderer, 51.16, 51.15, 56.59, 11.68,
                                        42.23, 2.57);
            rr_renderer_bezier_curve_to(renderer, 27.87, -6.54, -24.43, 7.86,
                                        -40.19, 13.63);
            rr_renderer_bezier_curve_to(renderer, -55.94, 19.41, -52.29, 13.69,
                                        -52.31, 37.23);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xffa19a84);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, -52.68, -69.82);
            rr_renderer_bezier_curve_to(renderer, -52.68, -98.60, -29.35,
                                        -121.92, -0.58, -121.92);
            rr_renderer_bezier_curve_to(renderer, 13.24, -121.92, 26.49,
                                        -116.43, 36.26, -106.66);
            rr_renderer_bezier_curve_to(renderer, 46.03, -96.89, 51.52, -83.64,
                                        51.52, -69.82);
            rr_renderer_line_to(renderer, 51.52, 25.05);
            rr_renderer_bezier_curve_to(renderer, 51.52, 53.82, 28.19, 77.15,
                                        -0.58, 77.15);
            rr_renderer_bezier_curve_to(renderer, -29.35, 77.15, -52.68, 53.82,
                                        -52.68, 25.05);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xffa19a84);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, -22.68, -92.50);
            rr_renderer_bezier_curve_to(renderer, -22.68, -123.86, 2.74,
                                        -149.28, 34.09, -149.28);
            rr_renderer_bezier_curve_to(renderer, 49.15, -149.28, 63.60,
                                        -143.29, 74.24, -132.65);
            rr_renderer_bezier_curve_to(renderer, 84.89, -122.00, 90.87,
                                        -107.56, 90.87, -92.50);
            rr_renderer_bezier_curve_to(renderer, 90.87, -61.14, 65.45, -35.72,
                                        34.09, -35.72);
            rr_renderer_bezier_curve_to(renderer, 2.74, -35.72, -22.68, -61.14,
                                        -22.68, -92.50);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xffa19a84);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, -90.87, -105.73);
            rr_renderer_bezier_curve_to(renderer, -90.87, -140.11, -63.00,
                                        -167.99, -28.61, -167.99);
            rr_renderer_bezier_curve_to(renderer, -12.10, -167.99, 3.73,
                                        -161.43, 15.41, -149.75);
            rr_renderer_bezier_curve_to(renderer, 27.09, -138.08, 33.64,
                                        -122.24, 33.64, -105.73);
            rr_renderer_bezier_curve_to(renderer, 33.64, -71.34, 5.77, -43.47,
                                        -28.61, -43.47);
            rr_renderer_bezier_curve_to(renderer, -63.00, -43.47, -90.87,
                                        -71.34, -90.87, -105.73);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xffa19a84);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, -68.82, -58.24);
            rr_renderer_bezier_curve_to(renderer, -60.60, -62.02, -50.32,
                                        -57.21, -45.87, -47.49);
            rr_renderer_bezier_curve_to(renderer, -41.41, -37.77, -44.46,
                                        -26.82, -52.68, -23.04);
            rr_renderer_bezier_curve_to(renderer, -51.65, -36.45, -57.99,
                                        -50.28, -68.82, -58.24);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xffa19a84);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, 51.52, -11.06);
            rr_renderer_bezier_curve_to(renderer, 43.60, -14.45, 40.50, -24.97,
                                        44.60, -34.56);
            rr_renderer_bezier_curve_to(renderer, 48.70, -44.16, 58.44, -49.19,
                                        66.37, -45.81);
            rr_renderer_bezier_curve_to(renderer, 56.03, -37.81, 50.16, -24.06,
                                        51.52, -11.06);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xffccc3a8);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, -73.96, -105.73);
            rr_renderer_bezier_curve_to(renderer, -73.96, -130.77, -53.66,
                                        -151.07, -28.62, -151.07);
            rr_renderer_bezier_curve_to(renderer, -16.59, -151.07, -5.06,
                                        -146.30, 3.45, -137.79);
            rr_renderer_bezier_curve_to(renderer, 11.95, -129.29, 16.73,
                                        -117.76, 16.73, -105.73);
            rr_renderer_bezier_curve_to(renderer, 16.73, -80.69, -3.57, -60.39,
                                        -28.62, -60.39);
            rr_renderer_bezier_curve_to(renderer, -53.66, -60.39, -73.96,
                                        -80.69, -73.96, -105.73);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xffccc3a8);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, -7.20, -92.50);
            rr_renderer_bezier_curve_to(renderer, -7.20, -114.65, 10.76,
                                        -132.61, 32.91, -132.61);
            rr_renderer_bezier_curve_to(renderer, 43.55, -132.61, 53.75,
                                        -128.38, 61.28, -120.86);
            rr_renderer_bezier_curve_to(renderer, 68.80, -113.34, 73.02,
                                        -103.13, 73.02, -92.50);
            rr_renderer_bezier_curve_to(renderer, 73.02, -70.34, 55.07, -52.38,
                                        32.91, -52.38);
            rr_renderer_bezier_curve_to(renderer, 10.76, -52.38, -7.20, -70.34,
                                        -7.20, -92.50);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xffccc3a8);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, -34.91, -65.73);
            rr_renderer_bezier_curve_to(renderer, -34.91, -84.69, -19.54,
                                        -100.05, -0.58, -100.05);
            rr_renderer_bezier_curve_to(renderer, 8.52, -100.05, 17.26, -96.44,
                                        23.69, -90.00);
            rr_renderer_bezier_curve_to(renderer, 30.13, -83.56, 33.75, -74.83,
                                        33.75, -65.73);
            rr_renderer_line_to(renderer, 33.75, 27.85);
            rr_renderer_bezier_curve_to(renderer, 33.75, 46.81, 18.38, 62.18,
                                        -0.58, 62.18);
            rr_renderer_bezier_curve_to(renderer, -19.54, 62.18, -34.91, 46.81,
                                        -34.91, 27.85);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xffccc3a8);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, -58.03, -70.99);
            rr_renderer_bezier_curve_to(renderer, -46.22, -76.41, -31.45,
                                        -69.48, -25.05, -55.50);
            rr_renderer_bezier_curve_to(renderer, -18.65, -41.52, -23.04,
                                        -25.80, -34.85, -20.37);
            rr_renderer_bezier_curve_to(renderer, -33.37, -39.65, -42.47,
                                        -59.53, -58.03, -70.99);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xffccc3a8);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, 33.68, -7.44);
            rr_renderer_bezier_curve_to(renderer, 21.74, -12.55, 17.08, -28.42,
                                        23.27, -42.89);
            rr_renderer_bezier_curve_to(renderer, 29.46, -57.36, 44.16, -64.95,
                                        56.10, -59.84);
            rr_renderer_bezier_curve_to(renderer, 40.51, -47.78, 31.65, -27.05,
                                        33.68, -7.44);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xffccc3a8);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, -34.86, 32.84);
            rr_renderer_bezier_curve_to(renderer, -34.78, 55.20, -32.89, 134.49,
                                        -27.27, 144.72);
            rr_renderer_bezier_curve_to(renderer, -21.65, 154.94, -10.65,
                                        107.64, -1.11, 94.20);
            rr_renderer_bezier_curve_to(renderer, 8.43, 80.76, 24.32, 77.14,
                                        29.98, 64.07);
            rr_renderer_bezier_curve_to(renderer, 35.63, 51.01, 34.39, 25.98,
                                        32.81, 15.80);
            rr_renderer_bezier_curve_to(renderer, 31.24, 5.63, 30.61, 3.90,
                                        20.51, 3.03);
            rr_renderer_bezier_curve_to(renderer, 10.42, 2.16, -18.53, 5.63,
                                        -27.76, 10.60);
            rr_renderer_bezier_curve_to(renderer, -36.98, 15.57, -34.94, 10.49,
                                        -34.86, 32.84);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xffa19a84);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, 7.47, -143.30);
            rr_renderer_bezier_curve_to(renderer, 1.81, -142.27, -5.01, -135.42,
                                        -8.75, -128.12);
            rr_renderer_bezier_curve_to(renderer, -12.48, -120.82, -14.33,
                                        -108.01, -14.95, -99.50);
            rr_renderer_bezier_curve_to(renderer, -15.58, -90.99, -15.91,
                                        -73.74, -12.48, -77.05);
            rr_renderer_bezier_curve_to(renderer, -9.06, -80.37, -0.70, -109.86,
                                        5.58, -119.41);
            rr_renderer_bezier_curve_to(renderer, 11.86, -128.95, 24.90,
                                        -130.32, 25.22, -134.30);
            rr_renderer_bezier_curve_to(renderer, 25.53, -138.28, 13.13,
                                        -144.33, 7.47, -143.30);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xffa19a84);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, -1.89, 81.84);
            rr_renderer_bezier_curve_to(renderer, -1.17, 64.91, -2.93, 2.25,
                                        -1.27, 3.29);
            rr_renderer_bezier_curve_to(renderer, 0.39, 4.33, 8.80, 71.13, 8.07,
                                        88.07);
            rr_renderer_bezier_curve_to(renderer, 7.34, 105.00, -3.97, 105.92,
                                        -5.63, 104.88);
            rr_renderer_bezier_curve_to(renderer, -7.29, 103.84, -2.62, 98.77,
                                        -1.89, 81.84);
            rr_renderer_fill(renderer);
            rr_renderer_scale(renderer, 1 / 0.1);
            break;
        case rr_petal_id_web:
            rr_renderer_set_fill(renderer, 0xffffffff);
            rr_renderer_set_stroke(renderer, 0xffcfcfcf);
            rr_renderer_set_line_cap(renderer, 1);
            rr_renderer_set_line_join(renderer, 1);
            rr_renderer_set_line_width(renderer, 3);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, 11.00, 0.00);
            rr_renderer_quadratic_curve_to(renderer, 4.32, 3.14, 3.40, 10.46);
            rr_renderer_quadratic_curve_to(renderer, -1.65, 5.08, -8.90, 6.47);
            rr_renderer_quadratic_curve_to(renderer, -5.34, -0.00, -8.90,
                                           -6.47);
            rr_renderer_quadratic_curve_to(renderer, -1.65, -5.08, 3.40,
                                           -10.46);
            rr_renderer_quadratic_curve_to(renderer, 4.32, -3.14, 11.00, 0.00);
            rr_renderer_fill(renderer);
            rr_renderer_stroke(renderer);
            break;
        case rr_petal_id_seed:
            rr_renderer_scale(renderer, 0.1);
            rr_renderer_set_fill(renderer, 0xffb07200);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, 80.90, -82.33);
            rr_renderer_bezier_curve_to(renderer, 125.72, -37.51, 125.72, 35.15,
                                        80.90, 79.97);
            rr_renderer_bezier_curve_to(renderer, 59.38, 101.49, 30.19, 113.58,
                                        -0.25, 113.58);
            rr_renderer_bezier_curve_to(renderer, -30.68, 113.58, -59.87,
                                        101.49, -81.40, 79.97);
            rr_renderer_bezier_curve_to(renderer, -126.21, 35.15, -126.21,
                                        -37.51, -81.40, -82.33);
            rr_renderer_bezier_curve_to(renderer, -36.58, -127.15, 36.08,
                                        -127.15, 80.90, -82.33);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xffb07200);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, 95.58, 39.57);
            rr_renderer_bezier_curve_to(renderer, 110.79, 54.78, 110.79, 79.44,
                                        95.58, 94.65);
            rr_renderer_bezier_curve_to(renderer, 88.27, 101.95, 78.37, 106.05,
                                        68.04, 106.05);
            rr_renderer_bezier_curve_to(renderer, 57.71, 106.05, 47.80, 101.95,
                                        40.50, 94.65);
            rr_renderer_bezier_curve_to(renderer, 25.29, 79.44, 25.29, 54.78,
                                        40.50, 39.57);
            rr_renderer_bezier_curve_to(renderer, 55.71, 24.36, 80.37, 24.36,
                                        95.58, 39.57);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xffc98200);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, -0.25, -82.33);
            rr_renderer_bezier_curve_to(renderer, 44.57, -82.33, 80.90, -46.00,
                                        80.90, -1.18);
            rr_renderer_quadratic_curve_to(renderer, 80.90, 34.64, 71.39,
                                           70.45);
            rr_renderer_quadratic_curve_to(renderer, 35.57, 79.97, -0.25,
                                           79.97);
            rr_renderer_bezier_curve_to(renderer, -45.07, 79.97, -81.40, 43.64,
                                        -81.40, -1.18);
            rr_renderer_bezier_curve_to(renderer, -81.40, -46.00, -45.07,
                                        -82.33, -0.25, -82.33);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xffb07200);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, -74.23, -77.81);
            rr_renderer_bezier_curve_to(renderer, -15.66, -81.51, 35.64, -38.94,
                                        42.81, 19.30);
            rr_renderer_line_to(renderer, 6.68, 23.75);
            rr_renderer_bezier_curve_to(renderer, 1.86, -15.37, -32.60, -43.96,
                                        -71.93, -41.48);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xffb07200);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, 37.65, 9.86);
            rr_renderer_bezier_curve_to(renderer, 44.74, 16.95, 44.74, 28.44,
                                        37.65, 35.53);
            rr_renderer_bezier_curve_to(renderer, 34.25, 38.93, 29.63, 40.84,
                                        24.82, 40.84);
            rr_renderer_bezier_curve_to(renderer, 20.00, 40.84, 15.39, 38.93,
                                        11.98, 35.53);
            rr_renderer_bezier_curve_to(renderer, 4.89, 28.44, 4.89, 16.95,
                                        11.98, 9.86);
            rr_renderer_bezier_curve_to(renderer, 19.07, 2.77, 30.56, 2.77,
                                        37.65, 9.86);
            rr_renderer_fill(renderer);
            rr_renderer_scale(renderer, 1 / 0.1);
            break;
        case rr_petal_id_gravel:
            rr_renderer_set_stroke(renderer, 0xff606060);
            rr_renderer_set_fill(renderer, 0xff777777);
            rr_renderer_set_line_width(renderer, 3.0f);
            rr_renderer_begin_path(renderer);
            rr_renderer_arc(renderer, 0.0f, 0.0f, 7.0f);
            rr_renderer_fill(renderer);
            rr_renderer_stroke(renderer);
            break;
        case rr_petal_id_club:
            rr_renderer_scale(renderer, 0.2);
            rr_renderer_set_fill(renderer, 0xff7d6c64);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, 72.00, 2.38);
            rr_renderer_bezier_curve_to(renderer, 72.00, 31.37, 48.94, 54.87,
                                        20.50, 54.87);
            rr_renderer_bezier_curve_to(renderer, 6.84, 54.87, -6.26, 49.34,
                                        -15.92, 39.49);
            rr_renderer_bezier_curve_to(renderer, -25.58, 29.65, -31.00, 16.30,
                                        -31.00, 2.38);
            rr_renderer_bezier_curve_to(renderer, -31.00, -26.61, -7.94, -50.12,
                                        20.50, -50.12);
            rr_renderer_bezier_curve_to(renderer, 48.94, -50.12, 72.00, -26.61,
                                        72.00, 2.38);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xff7d6c64);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, 33.82, 37.00);
            rr_renderer_bezier_curve_to(renderer, 33.82, 56.04, 18.68, 71.48,
                                        0.00, 71.48);
            rr_renderer_bezier_curve_to(renderer, -8.97, 71.48, -17.57, 67.84,
                                        -23.92, 61.38);
            rr_renderer_bezier_curve_to(renderer, -30.26, 54.91, -33.82, 46.14,
                                        -33.82, 37.00);
            rr_renderer_bezier_curve_to(renderer, -33.82, 17.96, -18.68, 2.52,
                                        0.00, 2.52);
            rr_renderer_bezier_curve_to(renderer, 18.68, 2.52, 33.82, 17.96,
                                        33.82, 37.00);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xff7d6c64);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, 31.00, 2.38);
            rr_renderer_bezier_curve_to(renderer, 31.00, 31.37, 7.95, 54.87,
                                        -20.50, 54.87);
            rr_renderer_bezier_curve_to(renderer, -34.16, 54.87, -47.26, 49.34,
                                        -56.92, 39.49);
            rr_renderer_bezier_curve_to(renderer, -66.58, 29.65, -72.00, 16.30,
                                        -72.00, 2.38);
            rr_renderer_bezier_curve_to(renderer, -72.00, -26.61, -48.94,
                                        -50.12, -20.50, -50.12);
            rr_renderer_bezier_curve_to(renderer, 7.95, -50.12, 31.00, -26.61,
                                        31.00, 2.38);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xff917d73);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, 58.38, 3.81);
            rr_renderer_bezier_curve_to(renderer, 58.38, 25.13, 41.42, 42.41,
                                        20.50, 42.41);
            rr_renderer_bezier_curve_to(renderer, 10.45, 42.41, 0.82, 38.34,
                                        -6.28, 31.10);
            rr_renderer_bezier_curve_to(renderer, -13.39, 23.86, -17.38, 14.05,
                                        -17.38, 3.81);
            rr_renderer_bezier_curve_to(renderer, -17.38, -17.51, -0.42, -34.79,
                                        20.50, -34.79);
            rr_renderer_bezier_curve_to(renderer, 41.42, -34.79, 58.38, -17.51,
                                        58.38, 3.81);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xff917d73);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, 17.38, 3.81);
            rr_renderer_bezier_curve_to(renderer, 17.38, 25.13, 0.42, 42.41,
                                        -20.50, 42.41);
            rr_renderer_bezier_curve_to(renderer, -30.54, 42.41, -40.18, 38.34,
                                        -47.28, 31.10);
            rr_renderer_bezier_curve_to(renderer, -54.38, 23.86, -58.37, 14.05,
                                        -58.37, 3.81);
            rr_renderer_bezier_curve_to(renderer, -58.37, -17.51, -41.42,
                                        -34.79, -20.50, -34.79);
            rr_renderer_bezier_curve_to(renderer, 0.42, -34.79, 17.38, -17.51,
                                        17.38, 3.81);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xff917d73);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, 20.88, 37.00);
            rr_renderer_bezier_curve_to(renderer, 20.88, 48.75, 11.53, 58.28,
                                        0.00, 58.28);
            rr_renderer_bezier_curve_to(renderer, -5.54, 58.28, -10.85, 56.04,
                                        -14.76, 52.05);
            rr_renderer_bezier_curve_to(renderer, -18.68, 48.06, -20.88, 42.64,
                                        -20.88, 37.00);
            rr_renderer_bezier_curve_to(renderer, -20.88, 25.24, -11.53, 15.72,
                                        0.00, 15.72);
            rr_renderer_bezier_curve_to(renderer, 11.53, 15.72, 20.88, 25.24,
                                        20.88, 37.00);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xff6a5045);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, -22.82, -44.69);
            rr_renderer_line_to(renderer, -13.86, 4.25);
            rr_renderer_line_to(renderer, 1.65, 4.76);
            rr_renderer_line_to(renderer, -5.59, -38.66);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xff6a5045);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, 22.84, -44.69);
            rr_renderer_line_to(renderer, 13.88, 4.25);
            rr_renderer_line_to(renderer, -1.62, 4.76);
            rr_renderer_line_to(renderer, 5.61, -38.66);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xff6a5045);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, -14.10, 1.74);
            rr_renderer_bezier_curve_to(renderer, -14.10, -6.08, -7.78, -12.42,
                                        0.01, -12.42);
            rr_renderer_bezier_curve_to(renderer, 3.75, -12.42, 7.34, -10.92,
                                        9.99, -8.27);
            rr_renderer_bezier_curve_to(renderer, 12.64, -5.62, 14.12, -2.02,
                                        14.12, 1.74);
            rr_renderer_bezier_curve_to(renderer, 14.12, 9.55, 7.81, 15.89,
                                        0.01, 15.89);
            rr_renderer_bezier_curve_to(renderer, -7.78, 15.89, -14.10, 9.55,
                                        -14.10, 1.74);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xff6a5045);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, -23.10, -48.31);
            rr_renderer_bezier_curve_to(renderer, -23.10, -61.10, -12.75,
                                        -71.48, 0.01, -71.48);
            rr_renderer_bezier_curve_to(renderer, 6.14, -71.48, 12.02, -69.04,
                                        16.36, -64.69);
            rr_renderer_bezier_curve_to(renderer, 20.69, -60.34, 23.13, -54.45,
                                        23.13, -48.31);
            rr_renderer_bezier_curve_to(renderer, 23.13, -35.51, 12.78, -25.13,
                                        0.01, -25.13);
            rr_renderer_bezier_curve_to(renderer, -12.75, -25.13, -23.10,
                                        -35.51, -23.10, -48.31);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xff856456);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, 9.73, -47.69);
            rr_renderer_line_to(renderer, 0.01, 2.01);
            rr_renderer_line_to(renderer, -9.71, -47.69);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xff856456);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, -9.71, -48.30);
            rr_renderer_bezier_curve_to(renderer, -9.71, -53.68, -5.36, -58.04,
                                        0.01, -58.04);
            rr_renderer_bezier_curve_to(renderer, 2.59, -58.04, 5.06, -57.02,
                                        6.88, -55.19);
            rr_renderer_bezier_curve_to(renderer, 8.71, -53.36, 9.73, -50.89,
                                        9.73, -48.30);
            rr_renderer_bezier_curve_to(renderer, 9.73, -42.92, 5.38, -38.56,
                                        0.01, -38.56);
            rr_renderer_bezier_curve_to(renderer, -5.36, -38.56, -9.71, -42.92,
                                        -9.71, -48.30);
            rr_renderer_fill(renderer);
            rr_renderer_scale(renderer, 1 / 0.2);
            break;
        case rr_petal_id_crest:
            rr_renderer_scale(renderer, 0.25);
            rr_renderer_set_fill(renderer, 0xff46555e);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, -71.19, -49.99);
            rr_renderer_bezier_curve_to(renderer, -61.70, -54.48, -41.04,
                                        -34.08, -25.06, -4.44);
            rr_renderer_bezier_curve_to(renderer, -9.07, 25.20, -3.81, 52.86,
                                        -13.30, 57.34);
            rr_renderer_bezier_curve_to(renderer, -12.07, 44.28, -19.12, 21.45,
                                        -31.46, -1.42);
            rr_renderer_bezier_curve_to(renderer, -43.79, -24.29, -59.23,
                                        -43.16, -71.19, -49.99);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xff46555e);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, -71.02, -45.90);
            rr_renderer_bezier_curve_to(renderer, -72.01, -47.74, -71.74,
                                        -49.74, -70.40, -50.37);
            rr_renderer_bezier_curve_to(renderer, -69.77, -50.67, -68.96,
                                        -50.61, -68.17, -50.20);
            rr_renderer_bezier_curve_to(renderer, -67.38, -49.79, -66.67,
                                        -49.06, -66.20, -48.18);
            rr_renderer_bezier_curve_to(renderer, -65.20, -46.33, -65.48,
                                        -44.33, -66.81, -43.70);
            rr_renderer_bezier_curve_to(renderer, -68.14, -43.07, -70.03,
                                        -44.05, -71.02, -45.90);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xff46555e);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, -16.73, 54.78);
            rr_renderer_bezier_curve_to(renderer, -17.72, 52.94, -17.45, 50.94,
                                        -16.12, 50.31);
            rr_renderer_bezier_curve_to(renderer, -15.48, 50.00, -14.67, 50.06,
                                        -13.89, 50.48);
            rr_renderer_bezier_curve_to(renderer, -13.10, 50.89, -12.38, 51.61,
                                        -11.91, 52.50);
            rr_renderer_bezier_curve_to(renderer, -10.92, 54.34, -11.19, 56.34,
                                        -12.52, 56.97);
            rr_renderer_bezier_curve_to(renderer, -13.85, 57.60, -15.74, 56.62,
                                        -16.73, 54.78);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xff46555e);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, -70.77, -45.61);
            rr_renderer_bezier_curve_to(renderer, -60.36, -50.52, -39.89,
                                        -32.21, -25.06, -4.71);
            rr_renderer_bezier_curve_to(renderer, -10.24, 22.79, -6.66, 49.07,
                                        -17.07, 53.98);
            rr_renderer_bezier_curve_to(renderer, -31.55, 19.82, -50.01, -14.41,
                                        -70.77, -45.61);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xff46555e);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, -69.85, -47.54);
            rr_renderer_bezier_curve_to(renderer, -60.46, -51.98, -40.55,
                                        -32.78, -25.39, -4.65);
            rr_renderer_bezier_curve_to(renderer, -10.22, 23.47, -5.54, 49.87,
                                        -14.93, 54.31);
            rr_renderer_bezier_curve_to(renderer, -16.66, 39.34, -23.80, 19.30,
                                        -34.42, -0.38);
            rr_renderer_bezier_curve_to(renderer, -45.03, -20.06, -58.01,
                                        -37.34, -69.85, -47.54);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xff46555e);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, 71.19, -49.99);
            rr_renderer_bezier_curve_to(renderer, 61.70, -54.48, 41.04, -34.08,
                                        25.06, -4.44);
            rr_renderer_bezier_curve_to(renderer, 9.07, 25.20, 3.81, 52.86,
                                        13.30, 57.34);
            rr_renderer_bezier_curve_to(renderer, 12.07, 44.28, 19.13, 21.45,
                                        31.46, -1.42);
            rr_renderer_bezier_curve_to(renderer, 43.79, -24.29, 59.23, -43.16,
                                        71.19, -49.99);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xff46555e);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, 71.02, -45.90);
            rr_renderer_bezier_curve_to(renderer, 72.01, -47.74, 71.74, -49.74,
                                        70.41, -50.37);
            rr_renderer_bezier_curve_to(renderer, 69.77, -50.67, 68.97, -50.61,
                                        68.18, -50.20);
            rr_renderer_bezier_curve_to(renderer, 67.39, -49.79, 66.68, -49.06,
                                        66.20, -48.18);
            rr_renderer_bezier_curve_to(renderer, 65.21, -46.34, 65.48, -44.33,
                                        66.81, -43.70);
            rr_renderer_bezier_curve_to(renderer, 68.14, -43.07, 70.03, -44.05,
                                        71.02, -45.90);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xff46555e);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, 16.73, 54.78);
            rr_renderer_bezier_curve_to(renderer, 17.72, 52.94, 17.45, 50.94,
                                        16.12, 50.31);
            rr_renderer_bezier_curve_to(renderer, 15.48, 50.00, 14.68, 50.06,
                                        13.89, 50.48);
            rr_renderer_bezier_curve_to(renderer, 13.10, 50.89, 12.39, 51.61,
                                        11.91, 52.50);
            rr_renderer_bezier_curve_to(renderer, 10.92, 54.34, 11.19, 56.34,
                                        12.52, 56.97);
            rr_renderer_bezier_curve_to(renderer, 13.86, 57.60, 15.74, 56.62,
                                        16.73, 54.78);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xff46555e);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, 70.77, -45.61);
            rr_renderer_bezier_curve_to(renderer, 60.36, -50.52, 39.89, -32.21,
                                        25.07, -4.71);
            rr_renderer_bezier_curve_to(renderer, 10.24, 22.79, 6.66, 49.07,
                                        17.08, 53.98);
            rr_renderer_bezier_curve_to(renderer, 31.55, 19.82, 50.01, -14.41,
                                        70.77, -45.61);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xff46555e);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, 69.85, -47.54);
            rr_renderer_bezier_curve_to(renderer, 60.46, -51.98, 40.56, -32.78,
                                        25.39, -4.65);
            rr_renderer_bezier_curve_to(renderer, 10.22, 23.47, 5.54, 49.87,
                                        14.93, 54.31);
            rr_renderer_bezier_curve_to(renderer, 16.66, 39.34, 23.80, 19.30,
                                        34.42, -0.38);
            rr_renderer_bezier_curve_to(renderer, 45.03, -20.07, 58.02, -37.35,
                                        69.85, -47.54);
            rr_renderer_fill(renderer);
            rr_renderer_scale(renderer, 1 / 0.25);
            break;
        case rr_petal_id_droplet:
            rr_renderer_scale(renderer, 0.2);
            rr_renderer_set_fill(renderer, 0xff308eb0);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, -63.56, 6.62);
            rr_renderer_bezier_curve_to(renderer, -63.56, -29.24, -34.46,
                                        -58.32, 1.44, -58.32);
            rr_renderer_bezier_curve_to(renderer, 18.67, -58.32, 35.21, -51.47,
                                        47.39, -39.30);
            rr_renderer_bezier_curve_to(renderer, 59.58, -27.12, 66.43, -10.60,
                                        66.43, 6.62);
            rr_renderer_bezier_curve_to(renderer, 66.43, 42.49, 37.33, 71.56,
                                        1.44, 71.56);
            rr_renderer_bezier_curve_to(renderer, -34.46, 71.56, -63.56, 42.49,
                                        -63.56, 6.62);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xff308eb0);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, -21.97, -48.36);
            rr_renderer_bezier_curve_to(renderer, -21.97, -61.28, -11.49,
                                        -71.74, 1.44, -71.74);
            rr_renderer_bezier_curve_to(renderer, 7.64, -71.74, 13.59, -69.28,
                                        17.98, -64.90);
            rr_renderer_bezier_curve_to(renderer, 22.37, -60.51, 24.84, -54.56,
                                        24.84, -48.36);
            rr_renderer_bezier_curve_to(renderer, 24.84, -35.45, 14.36, -24.98,
                                        1.44, -24.98);
            rr_renderer_bezier_curve_to(renderer, -11.49, -24.98, -21.97,
                                        -35.45, -21.97, -48.36);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xff308eb0);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, -39.79, -43.45);
            rr_renderer_line_to(renderer, -12.95, -66.93);
            rr_renderer_line_to(renderer, -14.86, -50.15);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xff308eb0);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, 42.66, -43.45);
            rr_renderer_line_to(renderer, 15.82, -66.93);
            rr_renderer_line_to(renderer, 17.73, -50.15);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xff43a6c9);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, -31.06, 39.12);
            rr_renderer_bezier_curve_to(renderer, -49.01, 21.17, -49.01, -7.93,
                                        -31.06, -25.88);
            rr_renderer_quadratic_curve_to(renderer, -16.50, -40.43, 1.44,
                                           -51.61);
            rr_renderer_quadratic_curve_to(renderer, 19.38, -40.43, 33.93,
                                           -25.88);
            rr_renderer_bezier_curve_to(renderer, 51.88, -7.93, 51.88, 21.17,
                                        33.93, 39.12);
            rr_renderer_bezier_curve_to(renderer, 15.99, 57.07, -13.11, 57.07,
                                        -31.06, 39.12);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xff97d7ed);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, -48.69, 27.06);
            rr_renderer_bezier_curve_to(renderer, -57.95, 5.00, -51.21, -20.54,
                                        -32.27, -35.16);
            rr_renderer_line_to(renderer, -22.35, -22.32);
            rr_renderer_bezier_curve_to(renderer, -35.48, -12.19, -40.14, 5.50,
                                        -33.73, 20.79);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xff97d7ed);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, -34.85, -31.57);
            rr_renderer_bezier_curve_to(renderer, -33.18, -35.66, -28.52,
                                        -37.62, -24.43, -35.95);
            rr_renderer_bezier_curve_to(renderer, -22.47, -35.15, -20.91,
                                        -33.60, -20.09, -31.64);
            rr_renderer_bezier_curve_to(renderer, -19.27, -29.69, -19.26,
                                        -27.49, -20.06, -25.53);
            rr_renderer_bezier_curve_to(renderer, -21.73, -21.44, -26.39,
                                        -19.49, -30.48, -21.16);
            rr_renderer_bezier_curve_to(renderer, -34.56, -22.83, -36.52,
                                        -27.49, -34.85, -31.57);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xff97d7ed);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, -48.63, 20.85);
            rr_renderer_bezier_curve_to(renderer, -46.96, 16.77, -42.30, 14.81,
                                        -38.21, 16.48);
            rr_renderer_bezier_curve_to(renderer, -36.25, 17.28, -34.69, 18.83,
                                        -33.87, 20.78);
            rr_renderer_bezier_curve_to(renderer, -33.05, 22.74, -33.04, 24.94,
                                        -33.84, 26.90);
            rr_renderer_bezier_curve_to(renderer, -35.51, 30.98, -40.17, 32.94,
                                        -44.26, 31.27);
            rr_renderer_bezier_curve_to(renderer, -48.34, 29.60, -50.30, 24.94,
                                        -48.63, 20.85);
            rr_renderer_fill(renderer);
            rr_renderer_scale(renderer, 1 / 0.2);
            break;
        case rr_petal_id_beak:
            rr_renderer_scale(renderer, 0.1);
            rr_renderer_set_fill(renderer, 0xff6e6054);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, -63.37, -16.61);
            rr_renderer_bezier_curve_to(renderer, -53.28, -50.39, -43.09,
                                        -80.60, -33.69, -102.36);
            rr_renderer_bezier_curve_to(renderer, -24.29, -124.13, -14.99,
                                        -141.61, -6.98, -147.21);
            rr_renderer_bezier_curve_to(renderer, 1.04, -152.80, 6.58, -148.00,
                                        14.39, -135.93);
            rr_renderer_bezier_curve_to(renderer, 22.21, -123.86, 31.81, -95.76,
                                        39.92, -74.79);
            rr_renderer_bezier_curve_to(renderer, 48.03, -53.81, 53.97, -35.11,
                                        63.07, -10.08);
            rr_renderer_bezier_curve_to(renderer, 72.17, 14.95, 90.77, 54.72,
                                        94.53, 75.40);
            rr_renderer_bezier_curve_to(renderer, 98.29, 96.08, 94.63, 105.97,
                                        85.63, 113.98);
            rr_renderer_bezier_curve_to(renderer, 76.63, 122.00, 53.77, 122.79,
                                        40.51, 123.48);
            rr_renderer_bezier_curve_to(renderer, 27.25, 124.17, 14.89, 117.50,
                                        6.08, 118.14);
            rr_renderer_bezier_curve_to(renderer, -2.72, 118.78, -3.81, 122.96,
                                        -12.32, 127.32);
            rr_renderer_bezier_curve_to(renderer, -20.83, 131.67, -32.50,
                                        141.14, -44.97, 144.26);
            rr_renderer_bezier_curve_to(renderer, -57.43, 147.38, -78.90,
                                        153.36, -87.12, 146.04);
            rr_renderer_bezier_curve_to(renderer, -95.33, 138.72, -98.20,
                                        127.44, -94.24, 100.33);
            rr_renderer_bezier_curve_to(renderer, -90.28, 73.22, -73.46, 17.17,
                                        -63.37, -16.61);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xff7d6e62);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, 77.90, 96.01);
            rr_renderer_bezier_curve_to(renderer, 85.82, 79.37, 52.18, 17.16,
                                        40.01, -19.07);
            rr_renderer_bezier_curve_to(renderer, 27.83, -55.30, 11.81, -108.44,
                                        4.83, -121.36);
            rr_renderer_bezier_curve_to(renderer, -2.16, -134.29, 0.15, -130.33,
                                        -1.91, -96.63);
            rr_renderer_bezier_curve_to(renderer, -3.97, -62.94, -20.83, 48.69,
                                        -7.53, 80.80);
            rr_renderer_bezier_curve_to(renderer, 5.77, 112.91, 69.98, 112.66,
                                        77.90, 96.01);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xff938479);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, -76.43, 127.36);
            rr_renderer_bezier_curve_to(renderer, -84.26, 111.31, -52.73, 22.38,
                                        -40.95, -19.07);
            rr_renderer_bezier_curve_to(renderer, -29.17, -60.53, -13.02,
                                        -108.17, -5.77, -121.36);
            rr_renderer_bezier_curve_to(renderer, 1.48, -134.55, 0.55, -131.31,
                                        2.52, -98.21);
            rr_renderer_bezier_curve_to(renderer, 4.50, -65.11, 19.24, 39.65,
                                        6.08, 77.24);
            rr_renderer_bezier_curve_to(renderer, -7.07, 114.84, -68.59, 143.42,
                                        -76.43, 127.36);
            rr_renderer_fill(renderer);
            rr_renderer_scale(renderer, 1 / 0.1);
            break;
        case rr_petal_id_lightning:
            rr_renderer_scale(renderer, 0.18f);
            rr_renderer_set_fill(renderer, 0xffcbdce8);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, -71.99, 13.19);
            rr_renderer_line_to(renderer, -41.80, 3.64);
            rr_renderer_line_to(renderer, -43.33, 20.46);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xffcbdce8);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, 71.61, -17.58);
            rr_renderer_line_to(renderer, 55.94, -16.82);
            rr_renderer_line_to(renderer, 62.06, -1.91);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xffcbdce8);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, -6.39, 66.20);
            rr_renderer_line_to(renderer, 16.48, 53.14);
            rr_renderer_line_to(renderer, 39.07, 47.38);
            rr_renderer_line_to(renderer, 58.99, 24.95);
            rr_renderer_line_to(renderer, 2.16, 40.33);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xffcbdce8);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, 46.56, -66.51);
            rr_renderer_line_to(renderer, 24.39, -49.69);
            rr_renderer_line_to(renderer, 39.68, -37.08);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xffcbdce8);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, 5.66, -44.72);
            rr_renderer_line_to(renderer, 11.39, -56.57);
            rr_renderer_line_to(renderer, -34.47, -62.30);
            rr_renderer_line_to(renderer, -57.41, -42.81);
            rr_renderer_line_to(renderer, -51.67, -2.29);
            rr_renderer_line_to(renderer, -34.15, -30.00);
            rr_renderer_line_to(renderer, -18.80, -44.72);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xff95a4ad);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, -54.03, -16.24);
            rr_renderer_line_to(renderer, -20.39, -49.11);
            rr_renderer_line_to(renderer, 23.18, -59.05);
            rr_renderer_line_to(renderer, 66.76, -32.67);
            rr_renderer_line_to(renderer, 50.70, 19.69);
            rr_renderer_line_to(renderer, -4.34, 60.59);
            rr_renderer_line_to(renderer, -49.82, 51.80);
            rr_renderer_line_to(renderer, -50.21, 16.63);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xffabbbc5);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, -36.83, -12.03);
            rr_renderer_line_to(renderer, -11.73, -35.29);
            rr_renderer_line_to(renderer, 19.36, -42.38);
            rr_renderer_line_to(renderer, 45.35, -25.79);
            rr_renderer_line_to(renderer, 35.80, 11.67);
            rr_renderer_line_to(renderer, -8.54, 43.39);
            rr_renderer_line_to(renderer, -33.39, 39.19);
            rr_renderer_line_to(renderer, -33.01, 13.96);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xffe5f5ff);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, -14.98, 25.80);
            rr_renderer_line_to(renderer, -6.57, -12.43);
            rr_renderer_line_to(renderer, 28.59, -34.21);
            rr_renderer_line_to(renderer, 46.56, -66.32);
            rr_renderer_line_to(renderer, 45.41, -22.37);
            rr_renderer_line_to(renderer, 7.19, 0.19);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xffe5f5ff);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, 41.97, 22.17);
            rr_renderer_line_to(renderer, 11.78, 20.64);
            rr_renderer_line_to(renderer, -12.37, 45.30);
            rr_renderer_line_to(renderer, -35.30, 54.86);
            rr_renderer_line_to(renderer, -20.01, 60.21);
            rr_renderer_line_to(renderer, -6.19, 66.51);
            rr_renderer_line_to(renderer, 20.19, 33.64);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xffe5f5ff);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, -53.97, -15.67);
            rr_renderer_line_to(renderer, -36.00, -15.29);
            rr_renderer_line_to(renderer, -25.68, 5.35);
            rr_renderer_line_to(renderer, -21.10, -22.55);
            rr_renderer_line_to(renderer, -57.41, -43.19);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xffe5f5ff);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, 72.00, -17.58);
            rr_renderer_line_to(renderer, 52.59, -3.14);
            rr_renderer_line_to(renderer, 30.92, 5.26);
            rr_renderer_line_to(renderer, 54.14, 9.37);
            rr_renderer_line_to(renderer, 65.99, -0.57);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xffe5f5ff);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, -71.61, 13.19);
            rr_renderer_line_to(renderer, -49.89, 30.01);
            rr_renderer_line_to(renderer, -23.83, 18.28);
            rr_renderer_line_to(renderer, -48.16, 16.98);
            rr_renderer_fill(renderer);
            rr_renderer_scale(renderer, 1 / 0.18f);
            break;
        case rr_petal_id_third_eye:
            rr_renderer_scale(renderer, 0.6f);
            rr_renderer_draw_third_eye(renderer, 0, 0);
            break;
        case rr_petal_id_nest:
            for (uint8_t i = 0; i < 6; ++i)
            {
                rr_renderer_draw_nest_stick(renderer);
                rr_renderer_rotate(renderer, 2 * M_PI / 6);
            }
            break;
        case rr_petal_id_fireball:
            rr_renderer_scale(renderer, 0.25);
            rr_renderer_rotate(renderer, -0.75 * M_PI);
            rr_renderer_translate(renderer, -256, -224);
            rr_renderer_begin_path(renderer);
            rr_renderer_set_fill(renderer, 0xffbc0303);
            rr_renderer_set_stroke(renderer, 0xff941b1b);
            rr_renderer_set_line_width(renderer, 7.5);
            rr_renderer_set_line_join(renderer, 1);
            rr_renderer_move_to(renderer, 301.619, 212.623);
            rr_renderer_line_to(renderer, 286.054, 218.849);
            rr_renderer_line_to(renderer, 310.175, 182.669);
            rr_renderer_bezier_curve_to(renderer, 315.935, 174.028, 305.641, 163.734, 297, 169.494);
            rr_renderer_line_to(renderer, 260.82, 193.615);
            rr_renderer_line_to(renderer, 267.046, 178.05);
            rr_renderer_bezier_curve_to(renderer, 269.307, 172.398, 263.255, 167.018, 257.907, 169.925);
            rr_renderer_line_to(renderer, 233.236, 183.333);
            rr_renderer_bezier_curve_to(renderer, 215.603, 192.916, 203.54, 210.271, 200.702, 230.138);
            rr_renderer_bezier_curve_to(renderer, 196.632, 258.622, 221.047, 283.037, 249.532, 278.968);
            rr_renderer_bezier_curve_to(renderer, 269.398, 276.13, 286.754, 264.066, 296.336, 246.433);
            rr_renderer_line_to(renderer, 309.744, 221.762);
            rr_renderer_bezier_curve_to(renderer, 312.651, 216.414, 307.271, 210.363, 301.619, 212.623);
            rr_renderer_fill(renderer);
            rr_renderer_stroke(renderer);
            rr_renderer_begin_path(renderer);
            rr_renderer_set_fill(renderer, 0xffce5d0b);
            rr_renderer_move_to(renderer, 262.46, 232.915);
            rr_renderer_line_to(renderer, 279.725, 207.017);
            rr_renderer_bezier_curve_to(renderer, 282.817, 202.378, 277.291, 196.852, 272.653, 199.944);
            rr_renderer_line_to(renderer, 246.755, 217.21);
            rr_renderer_bezier_curve_to(renderer, 246, 217.713, 245.059, 216.909, 245.438, 216.085);
            rr_renderer_line_to(renderer, 250.494, 205.081);
            rr_renderer_bezier_curve_to(renderer, 252.157, 201.461, 248.202, 197.835, 244.74, 199.806);
            rr_renderer_line_to(renderer, 228.801, 208.879);
            rr_renderer_bezier_curve_to(renderer, 217.376, 215.382, 209.602, 226.804, 207.743, 239.818);
            rr_renderer_bezier_curve_to(renderer, 205.067, 258.548, 221.121, 274.602, 239.851, 271.926);
            rr_renderer_bezier_curve_to(renderer, 252.865, 270.067, 264.287, 262.293, 270.79, 250.869);
            rr_renderer_line_to(renderer, 279.863, 234.93);
            rr_renderer_bezier_curve_to(renderer, 281.834, 231.468, 278.208, 227.513, 274.588, 229.176);
            rr_renderer_line_to(renderer, 263.584, 234.232);
            rr_renderer_bezier_curve_to(renderer, 262.76, 234.611, 261.957, 233.67, 262.46, 232.915);
            rr_renderer_fill(renderer);
            rr_renderer_begin_path(renderer);
            rr_renderer_set_fill(renderer, 0xffd4cc08);
            rr_renderer_move_to(renderer, 248.755, 240.972);
            rr_renderer_line_to(renderer, 263.046, 219.536);
            rr_renderer_bezier_curve_to(renderer, 264.319, 217.626, 262.043, 215.351, 260.133, 216.624);
            rr_renderer_line_to(renderer, 238.697, 230.915);
            rr_renderer_bezier_curve_to(renderer, 237.984, 231.39, 237.073, 230.694, 237.344, 229.881);
            rr_renderer_line_to(renderer, 238.696, 225.825);
            rr_renderer_bezier_curve_to(renderer, 239.787, 222.553, 236.219, 219.691, 233.262, 221.465);
            rr_renderer_line_to(renderer, 228.369, 224.401);
            rr_renderer_bezier_curve_to(renderer, 219.772, 229.559, 213.958, 238.316, 212.54, 248.24);
            rr_renderer_bezier_curve_to(renderer, 210.966, 259.259, 220.41, 268.704, 231.429, 267.13);
            rr_renderer_bezier_curve_to(renderer, 241.354, 265.712, 250.111, 259.897, 255.269, 251.301);
            rr_renderer_line_to(renderer, 258.205, 246.408);
            rr_renderer_bezier_curve_to(renderer, 259.979, 243.451, 257.116, 239.883, 253.845, 240.973);
            rr_renderer_line_to(renderer, 249.788, 242.325);
            rr_renderer_bezier_curve_to(renderer, 248.975, 242.596, 248.279, 241.685, 248.755, 240.972);
            rr_renderer_fill(renderer);
            break;
        case rr_petal_id_meat:
            rr_renderer_scale(renderer, 0.12);
            rr_renderer_rotate(renderer, M_PI / 2);
            rr_renderer_translate(renderer, -219.82, -279.05);
            rr_renderer_set_fill(renderer, 0xfff06a55);
            rr_renderer_set_stroke(renderer, 0xffede3c3);
            rr_renderer_set_line_width(renderer, 10);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, 319.38, 312.19);
            rr_renderer_bezier_curve_to(renderer, 319.38, 312.19, 335.51, 179.19, 307.07, 154.59);
            rr_renderer_bezier_curve_to(renderer, 278.41, 129.80, 177.70, 143.87, 147.00, 165.26);
            rr_renderer_bezier_curve_to(renderer, 125.81, 180.02, 117.07, 212.26, 115.81, 235.03);
            rr_renderer_bezier_curve_to(renderer, 114.65, 255.96, 123.39, 281.38, 135.51, 296.59);
            rr_renderer_bezier_curve_to(renderer, 146.82, 310.79, 170.30, 310.11, 183.94, 325.32);
            rr_renderer_bezier_curve_to(renderer, 202.03, 345.50, 204.42, 408.39, 224.98, 415.61);
            rr_renderer_bezier_curve_to(renderer, 243.66, 422.18, 282.34, 397.06, 298.04, 378.68);
            rr_renderer_bezier_curve_to(renderer, 312.53, 361.69, 319.38, 312.19, 319.38, 312.19);
            rr_renderer_bezier_curve_to(renderer, 319.38, 312.19, 319.38, 312.19, 319.38, 312.19);
            rr_renderer_fill(renderer);
            rr_renderer_stroke(renderer);
            rr_renderer_set_fill(renderer, 0xfff2efe2);
            rr_renderer_begin_path(renderer);
            rr_renderer_ellipse(renderer, 224.57, 213.82, 28.32, 26.68);
            rr_renderer_fill(renderer);
            rr_renderer_stroke(renderer);
            rr_renderer_set_line_width(renderer, 11);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, 225.80, 244.15);
            rr_renderer_bezier_curve_to(renderer, 225.80, 244.15, 217.83, 276.24, 209.39, 288.47);
            rr_renderer_bezier_curve_to(renderer, 201.38, 300.06, 177.37, 316.38, 177.37, 316.38);
            rr_renderer_stroke(renderer);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, 215.54, 277.03);
            rr_renderer_bezier_curve_to(renderer, 215.54, 277.03, 234.86, 302.23, 249.19, 309.86);
            rr_renderer_bezier_curve_to(renderer, 265.99, 318.79, 312.40, 322.99, 312.40, 322.99);
            rr_renderer_stroke(renderer);
            break;
        case rr_petal_id_bubble:
            rr_renderer_scale(renderer, 12.0f / 928.0f);
            rr_renderer_translate(renderer, -1028, -1028);
            rr_renderer_set_fill(renderer, 0x80bce3ea);
            rr_renderer_begin_path(renderer);
            rr_renderer_arc(renderer, 1028, 1028, 828);
            rr_renderer_fill(renderer);
            rr_renderer_set_stroke(renderer, 0x99bfe4e2);
            rr_renderer_set_line_width(renderer, 200);
            rr_renderer_begin_path(renderer);
            rr_renderer_arc(renderer, 1028, 1028, 928);
            rr_renderer_stroke(renderer);
            rr_renderer_translate(renderer, 603.593, 728.503);
            rr_renderer_rotate(renderer, 0.726);
            rr_renderer_set_fill(renderer, 0xcce7edf0);
            rr_renderer_begin_path(renderer);
            rr_renderer_ellipse(renderer, 0, 0, 187, 314);
            rr_renderer_fill(renderer);
            break;
        case rr_petal_id_meteor:
            rr_renderer_scale(renderer, 0.2f);
            rr_meteor_draw(renderer);
            break;
        case rr_petal_id_clover:
            if (rarity < rr_rarity_id_exotic)
            {
                rr_renderer_scale(renderer, 0.3);
                rr_renderer_translate(renderer, -45, -45);
                rr_renderer_set_fill(renderer, 0xff3db11c);
                rr_renderer_begin_path(renderer);
                rr_renderer_move_to(renderer, 64.3581, 36.009);
                rr_renderer_bezier_curve_to(renderer, 67.0038, 31.8631, 68.8304, 27.6762, 68.8304, 24.0181);
                rr_renderer_bezier_curve_to(renderer, 68.8304, 10.7534, 58.0772, 0.000234062, 44.8125, 0.000234062);
                rr_renderer_bezier_curve_to(renderer, 31.5478, 0.000234062, 20.7946, 10.7534, 20.7946, 24.0181);
                rr_renderer_bezier_curve_to(renderer, 20.7946, 27.692, 22.6369, 31.8992, 25.3011, 36.0626);
                rr_renderer_bezier_curve_to(renderer, 20.1329, 35.7668, 15.324, 36.2393, 12.0131, 38.1509);
                rr_renderer_bezier_curve_to(renderer, 0.525463, 44.7833, -3.41048, 59.4724, 3.22189, 70.96);
                rr_renderer_bezier_curve_to(renderer, 9.85425, 82.4476, 24.5434, 86.3835, 36.031, 79.7512);
                rr_renderer_bezier_curve_to(renderer, 39.2306, 77.9039, 41.9658, 74.1732, 44.247, 69.7516);
                rr_renderer_bezier_curve_to(renderer, 46.5283, 74.1732, 49.2635, 77.9039, 52.4631, 79.7512);
                rr_renderer_bezier_curve_to(renderer, 63.9507, 86.3835, 78.6398, 82.4476, 85.2722, 70.96);
                rr_renderer_bezier_curve_to(renderer, 91.9045, 59.4724, 87.9686, 44.7833, 76.481, 38.1509);
                rr_renderer_bezier_curve_to(renderer, 73.4203, 36.3838, 69.0795, 35.8465, 64.3581, 36.009);
                rr_renderer_fill(renderer);
                rr_renderer_clip(renderer);
                rr_renderer_set_fill(renderer, 0xff2e8513);
                rr_renderer_begin_path(renderer);
                rr_renderer_move_to(renderer, 64.3581, 36.009);
                rr_renderer_line_to(renderer, 59.3002, 32.7813);
                rr_renderer_line_to(renderer, 53.1633, 42.3979);
                rr_renderer_line_to(renderer, 64.5645, 42.0054);
                rr_renderer_line_to(renderer, 64.3581, 36.009);
                rr_renderer_move_to(renderer, 25.3011, 36.0626);
                rr_renderer_line_to(renderer, 24.9583, 42.0528);
                rr_renderer_line_to(renderer, 36.6872, 42.7241);
                rr_renderer_line_to(renderer, 30.355, 32.8286);
                rr_renderer_line_to(renderer, 25.3011, 36.0626);
                rr_renderer_move_to(renderer, 12.0131, 38.1509);
                rr_renderer_line_to(renderer, 9.01306, 32.9548);
                rr_renderer_line_to(renderer, 12.0131, 38.1509);
                rr_renderer_move_to(renderer, 3.22189, 70.96);
                rr_renderer_line_to(renderer, -1.97427, 73.96);
                rr_renderer_line_to(renderer, 3.22189, 70.96);
                rr_renderer_move_to(renderer, 36.031, 79.7512);
                rr_renderer_line_to(renderer, 39.031, 84.9473);
                rr_renderer_line_to(renderer, 36.031, 79.7512);
                rr_renderer_move_to(renderer, 44.247, 69.7516);
                rr_renderer_line_to(renderer, 49.5792, 67.0005);
                rr_renderer_line_to(renderer, 44.247, 56.6656);
                rr_renderer_line_to(renderer, 38.9149, 67.0005);
                rr_renderer_line_to(renderer, 44.247, 69.7516);
                rr_renderer_move_to(renderer, 52.4631, 79.7512);
                rr_renderer_line_to(renderer, 49.4631, 84.9473);
                rr_renderer_line_to(renderer, 52.4631, 79.7512);
                rr_renderer_move_to(renderer, 85.2722, 70.96);
                rr_renderer_line_to(renderer, 90.4683, 73.96);
                rr_renderer_line_to(renderer, 85.2722, 70.96);
                rr_renderer_move_to(renderer, 76.481, 38.1509);
                rr_renderer_line_to(renderer, 79.481, 32.9548);
                rr_renderer_line_to(renderer, 76.481, 38.1509);
                rr_renderer_move_to(renderer, 69.416, 39.2367);
                rr_renderer_bezier_curve_to(renderer, 72.2276, 34.8308, 74.8304, 29.4378, 74.8304, 24.0181);
                rr_renderer_bezier_curve_to(renderer, 62.8304, 25.9146, 61.78, 28.8954, 59.3002, 32.7813);
                rr_renderer_line_to(renderer, 69.416, 39.2367);
                rr_renderer_move_to(renderer, 74.8304, 24.0181);
                rr_renderer_bezier_curve_to(renderer, 74.8304, 7.43971, 61.3909, -5.99977, 44.8125, -5.99977);
                rr_renderer_bezier_curve_to(renderer, 54.7635, 6.00023, 62.8304, 14.0671, 62.8304, 24.0181);
                rr_renderer_move_to(renderer, 44.8125, -5.99977);
                rr_renderer_bezier_curve_to(renderer, 28.2341, -5.99977, 14.7946, 7.43971, 14.7946, 24.0181);
                rr_renderer_bezier_curve_to(renderer, 26.7946, 14.0671, 34.8615, 6.00023, 44.8125, 6.00023);
                rr_renderer_move_to(renderer, 14.7946, 24.0181);
                rr_renderer_bezier_curve_to(renderer, 14.7946, 29.4594, 17.4184, 34.8759, 20.2473, 39.2966);
                rr_renderer_line_to(renderer, 30.355, 32.8286);
                rr_renderer_bezier_curve_to(renderer, 27.8555, 28.9226, 26.7946, 25.9245, 26.7946, 24.0181);
                rr_renderer_move_to(renderer, 25.644, 30.0724);
                rr_renderer_bezier_curve_to(renderer, 20.1986, 29.7607, 13.9022, 30.132, 9.01306, 32.9548);
                rr_renderer_line_to(renderer, 15.0131, 43.3471);
                rr_renderer_bezier_curve_to(renderer, 16.7458, 42.3467, 20.0672, 41.7729, 24.9583, 42.0528);
                rr_renderer_line_to(renderer, 25.644, 30.0724);
                rr_renderer_move_to(renderer, 9.01305, 32.9548);
                rr_renderer_bezier_curve_to(renderer, -5.34429, 41.244, -10.2635, 59.6027, -1.97427, 73.96);
                rr_renderer_line_to(renderer, 8.41804, 67.96);
                rr_renderer_bezier_curve_to(renderer, 3.44253, 59.3422, 6.39522, 48.3226, 15.0131, 43.3471);
                rr_renderer_line_to(renderer, 9.01305, 32.9548);
                rr_renderer_move_to(renderer, -1.97426, 73.96);
                rr_renderer_bezier_curve_to(renderer, 6.31496, 88.3174, 24.6736, 93.2365, 39.031, 84.9473);
                rr_renderer_line_to(renderer, 33.031, 74.555);
                rr_renderer_bezier_curve_to(renderer, 24.4131, 79.5305, 13.3935, 76.5778, 8.41804, 67.96);
                rr_renderer_line_to(renderer, -1.97426, 73.96);
                rr_renderer_move_to(renderer, 39.031, 84.9473);
                rr_renderer_bezier_curve_to(renderer, 43.7679, 82.2124, 47.1596, 77.1924, 49.5792, 72.5026);
                rr_renderer_line_to(renderer, 38.9149, 67.0005);
                rr_renderer_bezier_curve_to(renderer, 36.772, 71.154, 34.6933, 73.5953, 33.031, 74.555);
                rr_renderer_line_to(renderer, 39.031, 84.9473);
                rr_renderer_move_to(renderer, 38.9149, 72.5026);
                rr_renderer_bezier_curve_to(renderer, 41.3345, 77.1924, 44.7261, 82.2124, 49.4631, 84.9473);
                rr_renderer_line_to(renderer, 55.4631, 74.555);
                rr_renderer_bezier_curve_to(renderer, 53.8008, 73.5953, 51.7221, 71.154, 49.5792, 67.0005);
                rr_renderer_line_to(renderer, 38.9149, 72.5026);
                rr_renderer_move_to(renderer, 49.4631, 84.9473);
                rr_renderer_bezier_curve_to(renderer, 63.8205, 93.2365, 82.1791, 88.3174, 90.4683, 73.96);
                rr_renderer_line_to(renderer, 80.076, 67.96);
                rr_renderer_bezier_curve_to(renderer, 75.1005, 76.5778, 64.0809, 79.5305, 55.4631, 74.555);
                rr_renderer_line_to(renderer, 49.4631, 84.9473);
                rr_renderer_move_to(renderer, 90.4683, 73.96);
                rr_renderer_bezier_curve_to(renderer, 98.7576, 59.6027, 93.8384, 41.244, 79.481, 32.9548);
                rr_renderer_line_to(renderer, 73.481, 43.3471);
                rr_renderer_bezier_curve_to(renderer, 82.0989, 48.3226, 85.0515, 59.3422, 80.076, 67.96);
                rr_renderer_line_to(renderer, 90.4683, 73.96);
                rr_renderer_move_to(renderer, 79.481, 32.9548);
                rr_renderer_bezier_curve_to(renderer, 74.9352, 30.3303, 69.2034, 29.8386, 64.1517, 30.0125);
                rr_renderer_line_to(renderer, 64.5645, 42.0054);
                rr_renderer_bezier_curve_to(renderer, 68.9556, 41.8543, 71.9053, 42.4374, 73.481, 43.3471);
                rr_renderer_line_to(renderer, 79.481, 32.9548);
                rr_renderer_fill(renderer);
                rr_renderer_set_fill(renderer, 0xff49c425);
                rr_renderer_begin_path(renderer);
                rr_renderer_move_to(renderer, 54.5408, 41.5325);
                rr_renderer_bezier_curve_to(renderer, 55.8246, 39.5039, 56.7066, 37.459, 56.7066, 35.6695);
                rr_renderer_bezier_curve_to(renderer, 56.7066, 29.095, 51.3769, 23.7654, 44.8025, 23.7654);
                rr_renderer_bezier_curve_to(renderer, 38.228, 23.7654, 32.8983, 29.095, 32.8983, 35.6695);
                rr_renderer_bezier_curve_to(renderer, 32.8983, 37.5173, 33.8386, 39.6373, 35.1907, 41.7306);
                rr_renderer_bezier_curve_to(renderer, 32.4986, 41.5423, 29.9732, 41.7536, 28.2585, 42.7436);
                rr_renderer_bezier_curve_to(renderer, 22.5649, 46.0308, 20.6141, 53.3113, 23.9013, 59.0049);
                rr_renderer_bezier_curve_to(renderer, 27.1885, 64.6986, 34.469, 66.6494, 40.1627, 63.3622);
                rr_renderer_bezier_curve_to(renderer, 41.7654, 62.4368, 43.1331, 60.5579, 44.271, 58.3356);
                rr_renderer_bezier_curve_to(renderer, 45.3944, 60.4965, 46.738, 62.3161, 48.307, 63.222);
                rr_renderer_bezier_curve_to(renderer, 54.0007, 66.5092, 61.2811, 64.5584, 64.5684, 58.8647);
                rr_renderer_bezier_curve_to(renderer, 67.8556, 53.1711, 65.9048, 45.8906, 60.2111, 42.6034);
                rr_renderer_bezier_curve_to(renderer, 58.7675, 41.7699, 56.7494, 41.4884, 54.5408, 41.5325);
                rr_renderer_fill(renderer);
            }
            else
            {
                rr_renderer_scale(renderer, 0.3);
                rr_renderer_translate(renderer, -42.5, -42.5);
                rr_renderer_set_fill(renderer, 0xff3db11c);
                rr_renderer_begin_path(renderer);
                rr_renderer_move_to(renderer, 77.8897, 38.9005);
                rr_renderer_bezier_curve_to(renderer, 76.4498, 40.3404, 74.4574, 41.4759, 72.1331, 42.3682);
                rr_renderer_bezier_curve_to(renderer, 74.4574, 43.2605, 76.4498, 44.396, 77.8897, 45.8359);
                rr_renderer_bezier_curve_to(renderer, 86.6524, 54.5987, 86.6524, 68.8059, 77.8897, 77.5686);
                rr_renderer_bezier_curve_to(renderer, 69.127, 86.3314, 54.9198, 86.3314, 46.157, 77.5686);
                rr_renderer_bezier_curve_to(renderer, 44.7329, 76.1445, 43.6065, 74.1799, 42.7186, 71.8881);
                rr_renderer_bezier_curve_to(renderer, 41.7956, 74.4628, 40.5934, 76.6697, 39.0342, 78.2288);
                rr_renderer_bezier_curve_to(renderer, 30.2715, 86.9915, 16.0643, 86.9915, 7.30155, 78.2288);
                rr_renderer_bezier_curve_to(renderer, -1.46119, 69.466, -1.46119, 55.2588, 7.30155, 46.4961);
                rr_renderer_bezier_curve_to(renderer, 8.74146, 45.0562, 10.7338, 43.9207, 13.0582, 43.0283);
                rr_renderer_bezier_curve_to(renderer, 10.7338, 42.136, 8.74146, 41.0005, 7.30155, 39.5606);
                rr_renderer_bezier_curve_to(renderer, -1.46119, 30.7979, -1.46119, 16.5906, 7.30155, 7.8279);
                rr_renderer_bezier_curve_to(renderer, 16.0643, -0.934839, 30.2715, -0.934839, 39.0342, 7.8279);
                rr_renderer_bezier_curve_to(renderer, 40.4584, 9.25206, 41.5848, 11.2167, 42.4726, 13.5084);
                rr_renderer_bezier_curve_to(renderer, 43.3956, 10.9337, 44.5979, 8.72687, 46.157, 7.16776);
                rr_renderer_bezier_curve_to(renderer, 54.9198, -1.59498, 69.127, -1.59498, 77.8897, 7.16776);
                rr_renderer_bezier_curve_to(renderer, 86.6524, 15.9305, 86.6524, 30.1377, 77.8897, 38.9005);
                rr_renderer_fill(renderer);
                rr_renderer_clip(renderer);
                rr_renderer_set_fill(renderer, 0xff2e8513);
                rr_renderer_begin_path(renderer);
                rr_renderer_move_to(renderer, 72.1331, 42.3682);
                rr_renderer_line_to(renderer, 69.9827, 36.7668);
                rr_renderer_line_to(renderer, 55.3915, 42.3682);
                rr_renderer_line_to(renderer, 69.9827, 47.9696);
                rr_renderer_line_to(renderer, 72.1331, 42.3682);
                rr_renderer_move_to(renderer, 77.8897, 38.9005);
                rr_renderer_line_to(renderer, 73.6471, 34.6578);
                rr_renderer_line_to(renderer, 73.6471, 34.6578);
                rr_renderer_line_to(renderer, 77.8897, 38.9005);
                rr_renderer_move_to(renderer, 77.8897, 45.8359);
                rr_renderer_line_to(renderer, 73.6471, 50.0786);
                rr_renderer_line_to(renderer, 73.6471, 50.0786);
                rr_renderer_line_to(renderer, 77.8897, 45.8359);
                rr_renderer_move_to(renderer, 42.7186, 71.8881);
                rr_renderer_line_to(renderer, 48.3135, 69.7207);
                rr_renderer_line_to(renderer, 42.5008, 54.7164);
                rr_renderer_line_to(renderer, 37.0706, 69.8633);
                rr_renderer_line_to(renderer, 42.7186, 71.8881);
                rr_renderer_move_to(renderer, 39.0342, 78.2288);
                rr_renderer_line_to(renderer, 43.2769, 82.4714);
                rr_renderer_line_to(renderer, 39.0342, 78.2288);
                rr_renderer_move_to(renderer, 7.30155, 78.2288);
                rr_renderer_line_to(renderer, 3.05891, 82.4714);
                rr_renderer_line_to(renderer, 7.30155, 78.2288);
                rr_renderer_move_to(renderer, 7.30155, 46.4961);
                rr_renderer_line_to(renderer, 3.05891, 42.2534);
                rr_renderer_line_to(renderer, 7.30155, 46.4961);
                rr_renderer_move_to(renderer, 13.0582, 43.0283);
                rr_renderer_line_to(renderer, 15.2085, 48.6298);
                rr_renderer_line_to(renderer, 29.7998, 43.0283);
                rr_renderer_line_to(renderer, 15.2085, 37.4269);
                rr_renderer_line_to(renderer, 13.0582, 43.0283);
                rr_renderer_move_to(renderer, 7.30155, 39.5606);
                rr_renderer_line_to(renderer, 3.05891, 43.8032);
                rr_renderer_line_to(renderer, 3.05891, 43.8032);
                rr_renderer_line_to(renderer, 7.30155, 39.5606);
                rr_renderer_move_to(renderer, 7.30155, 7.8279);
                rr_renderer_line_to(renderer, 3.05891, 3.58526);
                rr_renderer_line_to(renderer, 7.30155, 7.8279);
                rr_renderer_move_to(renderer, 39.0342, 7.8279);
                rr_renderer_line_to(renderer, 43.2769, 3.58526);
                rr_renderer_line_to(renderer, 39.0342, 7.8279);
                rr_renderer_move_to(renderer, 42.4726, 13.5084);
                rr_renderer_line_to(renderer, 36.8778, 15.6758);
                rr_renderer_line_to(renderer, 42.6904, 30.6802);
                rr_renderer_line_to(renderer, 48.1206, 15.5332);
                rr_renderer_line_to(renderer, 42.4726, 13.5084);
                rr_renderer_move_to(renderer, 46.157, 7.16776);
                rr_renderer_line_to(renderer, 50.3996, 11.4104);
                rr_renderer_line_to(renderer, 50.3997, 11.4104);
                rr_renderer_line_to(renderer, 46.157, 7.16776);
                rr_renderer_move_to(renderer, 74.2834, 47.9696);
                rr_renderer_bezier_curve_to(renderer, 77.0592, 46.904, 79.8887, 45.3867, 82.1323, 43.1431);
                rr_renderer_line_to(renderer, 73.6471, 34.6578);
                rr_renderer_bezier_curve_to(renderer, 73.0109, 35.294, 71.8557, 36.0477, 69.9827, 36.7668);
                rr_renderer_line_to(renderer, 74.2834, 47.9696);
                rr_renderer_move_to(renderer, 82.1323, 41.5933);
                rr_renderer_bezier_curve_to(renderer, 79.8887, 39.3496, 77.0592, 37.8324, 74.2834, 36.7668);
                rr_renderer_line_to(renderer, 69.9827, 47.9696);
                rr_renderer_bezier_curve_to(renderer, 71.8557, 48.6886, 73.0109, 49.4424, 73.6471, 50.0786);
                rr_renderer_line_to(renderer, 82.1323, 41.5933);
                rr_renderer_move_to(renderer, 82.1323, 81.8113);
                rr_renderer_bezier_curve_to(renderer, 93.2382, 70.7054, 93.2382, 52.6992, 82.1323, 41.5933);
                rr_renderer_line_to(renderer, 73.6471, 50.0786);
                rr_renderer_bezier_curve_to(renderer, 80.0667, 56.4982, 80.0667, 66.9064, 73.6471, 73.326);
                rr_renderer_line_to(renderer, 82.1323, 81.8113);
                rr_renderer_move_to(renderer, 41.9144, 81.8113);
                rr_renderer_bezier_curve_to(renderer, 53.0203, 92.9172, 71.0265, 92.9172, 82.1323, 81.8113);
                rr_renderer_line_to(renderer, 73.6471, 73.326);
                rr_renderer_bezier_curve_to(renderer, 67.2275, 79.7456, 56.8192, 79.7456, 50.3997, 73.326);
                rr_renderer_line_to(renderer, 41.9144, 81.8113);
                rr_renderer_move_to(renderer, 37.1238, 74.0556);
                rr_renderer_bezier_curve_to(renderer, 38.1865, 76.7988, 39.6944, 79.5913, 41.9144, 81.8113);
                rr_renderer_line_to(renderer, 50.3997, 73.326);
                rr_renderer_bezier_curve_to(renderer, 49.7713, 72.6976, 49.0264, 71.561, 48.3135, 69.7207);
                rr_renderer_line_to(renderer, 37.1238, 74.0556);
                rr_renderer_move_to(renderer, 37.0706, 69.8633);
                rr_renderer_bezier_curve_to(renderer, 36.3081, 71.9903, 35.4875, 73.2902, 34.7916, 73.9861);
                rr_renderer_line_to(renderer, 43.2769, 82.4714);
                rr_renderer_bezier_curve_to(renderer, 45.6992, 80.0491, 47.2831, 76.9354, 48.3667, 73.913);
                rr_renderer_line_to(renderer, 37.0706, 69.8633);
                rr_renderer_move_to(renderer, 34.7916, 73.9861);
                rr_renderer_bezier_curve_to(renderer, 28.372, 80.4057, 17.9638, 80.4057, 11.5442, 73.9861);
                rr_renderer_line_to(renderer, 3.05891, 82.4714);
                rr_renderer_bezier_curve_to(renderer, 14.1648, 93.5773, 32.171, 93.5773, 43.2769, 82.4714);
                rr_renderer_line_to(renderer, 34.7916, 73.9861);
                rr_renderer_move_to(renderer, 11.5442, 73.9861);
                rr_renderer_bezier_curve_to(renderer, 5.12459, 67.5665, 5.12459, 57.1583, 11.5442, 50.7387);
                rr_renderer_line_to(renderer, 3.05891, 42.2534);
                rr_renderer_bezier_curve_to(renderer, -8.04698, 53.3593, -8.04698, 71.3655, 3.05891, 82.4714);
                rr_renderer_line_to(renderer, 11.5442, 73.9861);
                rr_renderer_move_to(renderer, 11.5442, 50.7387);
                rr_renderer_bezier_curve_to(renderer, 12.1804, 50.1026, 13.3356, 49.3488, 15.2085, 48.6298);
                rr_renderer_line_to(renderer, 10.9079, 37.4269);
                rr_renderer_bezier_curve_to(renderer, 8.13208, 38.4925, 5.30256, 40.0098, 3.05891, 42.2534);
                rr_renderer_line_to(renderer, 11.5442, 50.7387);
                rr_renderer_move_to(renderer, 3.05891, 43.8032);
                rr_renderer_bezier_curve_to(renderer, 5.30256, 46.0469, 8.13207, 47.5642, 10.9079, 48.6298);
                rr_renderer_line_to(renderer, 15.2085, 37.4269);
                rr_renderer_bezier_curve_to(renderer, 13.3356, 36.7079, 12.1804, 35.9541, 11.5442, 35.318);
                rr_renderer_line_to(renderer, 3.05891, 43.8032);
                rr_renderer_move_to(renderer, 3.05891, 3.58526);
                rr_renderer_bezier_curve_to(renderer, -8.04698, 14.6911, -8.04698, 32.6973, 3.05891, 43.8032);
                rr_renderer_line_to(renderer, 11.5442, 35.318);
                rr_renderer_bezier_curve_to(renderer, 5.12459, 28.8984, 5.12459, 18.4901, 11.5442, 12.0705);
                rr_renderer_line_to(renderer, 3.05891, 3.58526);
                rr_renderer_move_to(renderer, 43.2769, 3.58526);
                rr_renderer_bezier_curve_to(renderer, 32.171, -7.52063, 14.1648, -7.52063, 3.05891, 3.58526);
                rr_renderer_line_to(renderer, 11.5442, 12.0705);
                rr_renderer_bezier_curve_to(renderer, 17.9638, 5.65095, 28.372, 5.65095, 34.7916, 12.0705);
                rr_renderer_line_to(renderer, 43.2769, 3.58526);
                rr_renderer_move_to(renderer, 48.0675, 11.341);
                rr_renderer_bezier_curve_to(renderer, 47.0047, 8.59772, 45.4968, 5.8052, 43.2769, 3.58526);
                rr_renderer_line_to(renderer, 34.7916, 12.0705);
                rr_renderer_bezier_curve_to(renderer, 35.42, 12.6989, 36.1649, 13.8356, 36.8778, 15.6758);
                rr_renderer_line_to(renderer, 48.0675, 11.341);
                rr_renderer_move_to(renderer, 41.9144, 2.92512);
                rr_renderer_bezier_curve_to(renderer, 39.4921, 5.34741, 37.9081, 8.46117, 36.8246, 11.4836);
                rr_renderer_line_to(renderer, 48.1206, 15.5332);
                rr_renderer_bezier_curve_to(renderer, 48.8832, 13.4062, 49.7037, 12.1063, 50.3996, 11.4104);
                rr_renderer_line_to(renderer, 41.9144, 2.92512);
                rr_renderer_move_to(renderer, 82.1323, 2.92512);
                rr_renderer_bezier_curve_to(renderer, 71.0265, -8.18077, 53.0203, -8.18077, 41.9144, 2.92512);
                rr_renderer_line_to(renderer, 50.3997, 11.4104);
                rr_renderer_bezier_curve_to(renderer, 56.8192, 4.9908, 67.2275, 4.9908, 73.6471, 11.4104);
                rr_renderer_line_to(renderer, 82.1323, 2.92512);
                rr_renderer_move_to(renderer, 82.1323, 43.1431);
                rr_renderer_bezier_curve_to(renderer, 93.2382, 32.0372, 93.2382, 14.031, 82.1323, 2.92512);
                rr_renderer_line_to(renderer, 73.6471, 11.4104);
                rr_renderer_bezier_curve_to(renderer, 80.0667, 17.83, 80.0667, 28.2382, 73.6471, 34.6578);
                rr_renderer_line_to(renderer, 82.1323, 43.1431);
                rr_renderer_fill(renderer);
                rr_renderer_set_fill(renderer, 0xff49c425);
                rr_renderer_begin_path(renderer);
                rr_renderer_move_to(renderer, 60.0447, 40.8452);
                rr_renderer_bezier_curve_to(renderer, 59.3329, 41.557, 58.348, 42.1184, 57.1989, 42.5595);
                rr_renderer_bezier_curve_to(renderer, 58.348, 43.0006, 59.3329, 43.5619, 60.0447, 44.2737);
                rr_renderer_bezier_curve_to(renderer, 64.3765, 48.6055, 64.3765, 55.6287, 60.0447, 59.9604);
                rr_renderer_bezier_curve_to(renderer, 55.7129, 64.2922, 48.6897, 64.2922, 44.358, 59.9604);
                rr_renderer_bezier_curve_to(renderer, 43.654, 59.2564, 43.0971, 58.2852, 42.6582, 57.1523);
                rr_renderer_bezier_curve_to(renderer, 42.202, 58.4251, 41.6076, 59.516, 40.8369, 60.2867);
                rr_renderer_bezier_curve_to(renderer, 36.5051, 64.6185, 29.482, 64.6185, 25.1502, 60.2867);
                rr_renderer_bezier_curve_to(renderer, 20.8184, 55.955, 20.8184, 48.9318, 25.1502, 44.6);
                rr_renderer_bezier_curve_to(renderer, 25.862, 43.8882, 26.8469, 43.3269, 27.9959, 42.8858);
                rr_renderer_bezier_curve_to(renderer, 26.8469, 42.4447, 25.862, 41.8833, 25.1502, 41.1715);
                rr_renderer_bezier_curve_to(renderer, 20.8184, 36.8398, 20.8184, 29.8166, 25.1502, 25.4848);
                rr_renderer_bezier_curve_to(renderer, 29.482, 21.1531, 36.5051, 21.1531, 40.8369, 25.4848);
                rr_renderer_bezier_curve_to(renderer, 41.5409, 26.1888, 42.0977, 27.16, 42.5366, 28.2929);
                rr_renderer_bezier_curve_to(renderer, 42.9929, 27.0201, 43.5872, 25.9292, 44.358, 25.1585);
                rr_renderer_bezier_curve_to(renderer, 48.6897, 20.8267, 55.7129, 20.8267, 60.0447, 25.1585);
                rr_renderer_bezier_curve_to(renderer, 64.3765, 29.4903, 64.3765, 36.5134, 60.0447, 40.8452);
                rr_renderer_fill(renderer);
            }            
                break;
        case rr_petal_id_mandible:
            rr_renderer_scale(renderer, 0.09);
            rr_renderer_set_fill(renderer, 0xff171612);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, 90.08, 51.32);
            rr_renderer_bezier_curve_to(renderer, 89.87, 37.93, 86.16, 23.54,
                                        70.49, 4.15);
            rr_renderer_bezier_curve_to(renderer, 54.82, -15.23, 21.03, -50.36,
                                        -3.94, -65.00);
            rr_renderer_bezier_curve_to(renderer, -28.90, -79.63, -68.44,
                                        -91.72, -79.28, -83.66);
            rr_renderer_bezier_curve_to(renderer, -90.13, -75.60, -71.61,
                                        -37.86, -69.01, -16.64);
            rr_renderer_bezier_curve_to(renderer, -66.40, 4.57, -73.20, 31.43,
                                        -63.67, 43.64);
            rr_renderer_bezier_curve_to(renderer, -54.14, 55.85, -27.35, 48.78,
                                        -11.85, 56.62);
            rr_renderer_bezier_curve_to(renderer, 3.64, 64.47, 15.37, 86.06,
                                        29.30, 90.71);
            rr_renderer_bezier_curve_to(renderer, 43.23, 95.36, 61.60, 91.07,
                                        71.73, 84.50);
            rr_renderer_bezier_curve_to(renderer, 81.86, 77.94, 90.29, 64.71,
                                        90.08, 51.32);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xff2b2820);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, 67.91, 34.98);
            rr_renderer_bezier_curve_to(renderer, 64.36, 25.07, 55.54, 17.40,
                                        42.78, 4.24);
            rr_renderer_bezier_curve_to(renderer, 30.03, -8.92, 8.50, -32.65,
                                        -8.65, -43.98);
            rr_renderer_bezier_curve_to(renderer, -25.79, -55.30, -52.98,
                                        -68.08, -60.09, -63.71);
            rr_renderer_bezier_curve_to(renderer, -67.21, -59.34, -53.11,
                                        -33.24, -51.34, -17.75);
            rr_renderer_bezier_curve_to(renderer, -49.56, -2.25, -57.25, 20.24,
                                        -49.45, 29.27);
            rr_renderer_bezier_curve_to(renderer, -41.65, 38.30, -18.23, 29.59,
                                        -4.53, 36.45);
            rr_renderer_bezier_curve_to(renderer, 9.16, 43.31, 21.30, 65.88,
                                        32.73, 70.42);
            rr_renderer_bezier_curve_to(renderer, 44.17, 74.96, 58.21, 69.61,
                                        64.07, 63.70);
            rr_renderer_bezier_curve_to(renderer, 69.94, 57.79, 71.46, 44.89,
                                        67.91, 34.98);
            rr_renderer_fill(renderer);
            rr_renderer_scale(renderer, 1 / 0.09);
            break;
        case rr_petal_id_wax:
            rr_renderer_scale(renderer, 0.16);
            rr_renderer_set_fill(renderer, 0xffe1d5c3);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, -44.77, 0.00);
            rr_renderer_bezier_curve_to(renderer, -44.77, -24.72, -24.73,
                                        -44.77, -0.00, -44.77);
            rr_renderer_bezier_curve_to(renderer, 11.87, -44.77, 23.26, -40.05,
                                        31.65, -31.66);
            rr_renderer_bezier_curve_to(renderer, 40.05, -23.26, 44.77, -11.87,
                                        44.77, 0.00);
            rr_renderer_bezier_curve_to(renderer, 44.77, 24.72, 24.72, 44.77,
                                        -0.00, 44.77);
            rr_renderer_bezier_curve_to(renderer, -24.73, 44.77, -44.77, 24.72,
                                        -44.77, 0.00);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xffc9bdac);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, -26.72, -59.91);
            rr_renderer_line_to(renderer, 26.73, -59.91);
            rr_renderer_line_to(renderer, 26.73, -32.29);
            rr_renderer_line_to(renderer, -26.72, -32.29);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xffc9bdac);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, 26.72, 59.92);
            rr_renderer_line_to(renderer, -26.72, 59.92);
            rr_renderer_line_to(renderer, -26.72, 32.35);
            rr_renderer_line_to(renderer, 26.72, 32.35);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xffc9bdac);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, 19.82, -57.88);
            rr_renderer_bezier_curve_to(renderer, 26.43, -61.69, 34.88, -59.43,
                                        38.69, -52.82);
            rr_renderer_bezier_curve_to(renderer, 40.52, -49.65, 41.02, -45.88,
                                        40.07, -42.34);
            rr_renderer_bezier_curve_to(renderer, 39.12, -38.81, 36.80, -35.79,
                                        33.63, -33.96);
            rr_renderer_bezier_curve_to(renderer, 27.03, -30.15, 18.58, -32.41,
                                        14.77, -39.02);
            rr_renderer_bezier_curve_to(renderer, 10.95, -45.62, 13.22, -54.07,
                                        19.82, -57.88);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xffc9bdac);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, 38.53, -53.09);
            rr_renderer_line_to(renderer, 65.25, -6.80);
            rr_renderer_line_to(renderer, 41.28, 7.03);
            rr_renderer_line_to(renderer, 14.56, -39.26);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xffc9bdac);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, -19.83, 57.89);
            rr_renderer_bezier_curve_to(renderer, -26.43, 61.70, -34.88, 59.43,
                                        -38.69, 52.83);
            rr_renderer_bezier_curve_to(renderer, -40.52, 49.66, -41.02, 45.89,
                                        -40.07, 42.35);
            rr_renderer_bezier_curve_to(renderer, -39.12, 38.81, -36.81, 35.80,
                                        -33.63, 33.96);
            rr_renderer_bezier_curve_to(renderer, -27.03, 30.15, -18.58, 32.42,
                                        -14.77, 39.02);
            rr_renderer_bezier_curve_to(renderer, -10.96, 45.63, -13.22, 54.07,
                                        -19.83, 57.89);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xffc9bdac);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, -46.23, 12.14);
            rr_renderer_bezier_curve_to(renderer, -52.84, 15.95, -61.28, 13.69,
                                        -65.10, 7.08);
            rr_renderer_bezier_curve_to(renderer, -66.93, 3.91, -67.42, 0.14,
                                        -66.48, -3.40);
            rr_renderer_bezier_curve_to(renderer, -65.53, -6.94, -63.21, -9.95,
                                        -60.04, -11.78);
            rr_renderer_bezier_curve_to(renderer, -53.43, -15.60, -44.99,
                                        -13.33, -41.18, -6.73);
            rr_renderer_bezier_curve_to(renderer, -37.36, -0.12, -39.63, 8.32,
                                        -46.23, 12.14);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xffc9bdac);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, -38.54, 53.10);
            rr_renderer_line_to(renderer, -65.25, 6.81);
            rr_renderer_line_to(renderer, -41.35, -6.99);
            rr_renderer_line_to(renderer, -14.63, 39.30);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xffc9bdac);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, -33.63, -33.97);
            rr_renderer_bezier_curve_to(renderer, -40.24, -37.78, -42.50,
                                        -46.22, -38.69, -52.83);
            rr_renderer_bezier_curve_to(renderer, -36.86, -56.00, -33.84,
                                        -58.32, -30.30, -59.27);
            rr_renderer_bezier_curve_to(renderer, -26.77, -60.21, -23.00,
                                        -59.72, -19.83, -57.89);
            rr_renderer_bezier_curve_to(renderer, -13.22, -54.07, -10.96,
                                        -45.63, -14.77, -39.02);
            rr_renderer_bezier_curve_to(renderer, -18.58, -32.42, -27.03,
                                        -30.15, -33.63, -33.97);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xffc9bdac);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, -65.25, -6.81);
            rr_renderer_line_to(renderer, -38.53, -53.10);
            rr_renderer_line_to(renderer, -14.65, -39.32);
            rr_renderer_line_to(renderer, -41.37, 6.97);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xffc9bdac);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, 60.04, -11.79);
            rr_renderer_bezier_curve_to(renderer, 66.64, -7.98, 68.91, 0.47,
                                        65.10, 7.07);
            rr_renderer_bezier_curve_to(renderer, 63.27, 10.25, 60.25, 12.56,
                                        56.71, 13.51);
            rr_renderer_bezier_curve_to(renderer, 53.17, 14.46, 49.40, 13.96,
                                        46.23, 12.13);
            rr_renderer_bezier_curve_to(renderer, 39.63, 8.32, 37.36, -0.13,
                                        41.17, -6.73);
            rr_renderer_bezier_curve_to(renderer, 44.99, -13.34, 53.43, -15.60,
                                        60.04, -11.79);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xffc9bdac);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, 33.63, 33.96);
            rr_renderer_bezier_curve_to(renderer, 40.24, 37.77, 42.50, 46.22,
                                        38.69, 52.82);
            rr_renderer_bezier_curve_to(renderer, 36.86, 55.99, 33.84, 58.31,
                                        30.31, 59.26);
            rr_renderer_bezier_curve_to(renderer, 26.77, 60.21, 23.00, 59.71,
                                        19.83, 57.88);
            rr_renderer_bezier_curve_to(renderer, 13.22, 54.07, 10.96, 45.62,
                                        14.77, 39.02);
            rr_renderer_bezier_curve_to(renderer, 18.58, 32.41, 27.03, 30.15,
                                        33.63, 33.96);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xffc9bdac);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, 65.25, 6.80);
            rr_renderer_line_to(renderer, 38.53, 53.09);
            rr_renderer_line_to(renderer, 14.76, 39.37);
            rr_renderer_line_to(renderer, 41.48, -6.92);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xffc9bdac);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, -30.85, 11.25);
            rr_renderer_bezier_curve_to(renderer, -37.06, 11.25, -42.09, 6.21,
                                        -42.09, -0.00);
            rr_renderer_bezier_curve_to(renderer, -42.09, -6.21, -37.06, -11.25,
                                        -30.85, -11.25);
            rr_renderer_bezier_curve_to(renderer, -35.73, -4.55, -35.73, 4.55,
                                        -30.85, 11.25);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xffc9bdac);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, 30.85, -11.25);
            rr_renderer_bezier_curve_to(renderer, 37.06, -11.25, 42.09, -6.21,
                                        42.09, -0.00);
            rr_renderer_bezier_curve_to(renderer, 42.09, 6.21, 37.06, 11.25,
                                        30.85, 11.25);
            rr_renderer_bezier_curve_to(renderer, 35.73, 4.55, 35.73, -4.55,
                                        30.85, -11.25);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xffc9bdac);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, -5.67, 32.34);
            rr_renderer_bezier_curve_to(renderer, -8.78, 37.72, -15.66, 39.56,
                                        -21.04, 36.45);
            rr_renderer_bezier_curve_to(renderer, -26.42, 33.35, -28.27, 26.47,
                                        -25.17, 21.09);
            rr_renderer_bezier_curve_to(renderer, -21.80, 28.67, -13.92, 33.21,
                                        -5.67, 32.34);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xffc9bdac);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, 5.67, -32.34);
            rr_renderer_bezier_curve_to(renderer, 8.77, -37.72, 15.65, -39.56,
                                        21.04, -36.45);
            rr_renderer_bezier_curve_to(renderer, 26.42, -33.35, 28.27, -26.47,
                                        25.17, -21.09);
            rr_renderer_bezier_curve_to(renderer, 21.80, -28.67, 13.92, -33.21,
                                        5.67, -32.34);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xffc9bdac);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, -25.15, -21.10);
            rr_renderer_bezier_curve_to(renderer, -28.26, -26.49, -26.41,
                                        -33.37, -21.02, -36.47);
            rr_renderer_bezier_curve_to(renderer, -15.64, -39.57, -8.76, -37.72,
                                        -5.66, -32.34);
            rr_renderer_bezier_curve_to(renderer, -13.90, -33.22, -21.78,
                                        -28.68, -25.15, -21.10);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xffc9bdac);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, 25.15, 21.10);
            rr_renderer_bezier_curve_to(renderer, 28.25, 26.49, 26.40, 33.37,
                                        21.02, 36.47);
            rr_renderer_bezier_curve_to(renderer, 15.64, 39.57, 8.76, 37.72,
                                        5.65, 32.34);
            rr_renderer_bezier_curve_to(renderer, 13.90, 33.22, 21.78, 28.68,
                                        25.15, 21.10);
            rr_renderer_fill(renderer);
            rr_renderer_scale(renderer, 1 / 0.16);
            break;
        case rr_petal_id_sand:
            rr_renderer_set_line_cap(renderer, 1);
            rr_renderer_set_line_join(renderer, 1);
            rr_renderer_set_fill(renderer, 0xffe0c85c);
            rr_renderer_set_stroke(renderer, 0xffb5a24b);
            rr_renderer_set_line_width(renderer, 3);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, 7, 0);
            rr_renderer_line_to(renderer, 3.499999761581421, 6.062178134918213);
            rr_renderer_line_to(renderer, -3.500000476837158,
                                6.062177658081055);
            rr_renderer_line_to(renderer, -7, -6.119594218034763e-7);
            rr_renderer_line_to(renderer, -3.4999992847442627,
                                -6.062178134918213);
            rr_renderer_line_to(renderer, 3.4999992847442627,
                                -6.062178134918213);
            rr_renderer_line_to(renderer, 7, 0);
            rr_renderer_fill(renderer);
            rr_renderer_stroke(renderer);
            break;
        case rr_petal_id_mint:
            rr_renderer_scale(renderer, 0.2f);
            rr_renderer_set_fill(renderer, 0xff3eb114);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, -54.13, 0.77);
            rr_renderer_bezier_curve_to(renderer, -64.26, -16.45, -58.52,
                                        -38.62, -41.30, -48.75);
            rr_renderer_bezier_curve_to(renderer, -33.04, -53.61, -23.17,
                                        -54.99, -13.89, -52.59);
            rr_renderer_bezier_curve_to(renderer, -4.60, -50.18, 3.35, -44.18,
                                        8.21, -35.91);
            rr_renderer_bezier_curve_to(renderer, 18.34, -18.70, 12.60, 3.47,
                                        -4.62, 13.60);
            rr_renderer_bezier_curve_to(renderer, -21.84, 23.73, -44.00, 17.98,
                                        -54.13, 0.77);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xff3eb114);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, -53.89, -44.95);
            rr_renderer_bezier_curve_to(renderer, -57.47, -51.03, -55.44,
                                        -58.86, -49.36, -62.44);
            rr_renderer_bezier_curve_to(renderer, -46.44, -64.16, -42.96,
                                        -64.65, -39.68, -63.80);
            rr_renderer_bezier_curve_to(renderer, -36.40, -62.95, -33.59,
                                        -60.83, -31.87, -57.91);
            rr_renderer_bezier_curve_to(renderer, -28.30, -51.83, -30.32,
                                        -44.00, -36.41, -40.42);
            rr_renderer_bezier_curve_to(renderer, -42.49, -36.84, -50.32,
                                        -38.87, -53.89, -44.95);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xff3eb114);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, -59.61, -33.85);
            rr_renderer_bezier_curve_to(renderer, -58.42, -48.45, -54.66,
                                        -60.06, -51.21, -59.78);
            rr_renderer_bezier_curve_to(renderer, -49.55, -59.64, -48.19,
                                        -56.73, -47.42, -51.67);
            rr_renderer_bezier_curve_to(renderer, -46.65, -46.62, -46.54,
                                        -39.84, -47.11, -32.83);
            rr_renderer_bezier_curve_to(renderer, -48.30, -18.23, -52.07, -6.62,
                                        -55.52, -6.90);
            rr_renderer_bezier_curve_to(renderer, -57.17, -7.04, -58.54, -9.95,
                                        -59.30, -15.01);
            rr_renderer_bezier_curve_to(renderer, -60.07, -20.06, -60.18,
                                        -26.84, -59.61, -33.85);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xff3eb114);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, -19.60, -57.40);
            rr_renderer_bezier_curve_to(renderer, -32.94, -63.45, -44.91,
                                        -65.80, -46.34, -62.64);
            rr_renderer_bezier_curve_to(renderer, -47.03, -61.13, -45.14,
                                        -58.52, -41.10, -55.39);
            rr_renderer_bezier_curve_to(renderer, -37.05, -52.27, -31.18,
                                        -48.88, -24.77, -45.97);
            rr_renderer_bezier_curve_to(renderer, -11.43, -39.92, 0.55, -37.57,
                                        1.98, -40.73);
            rr_renderer_bezier_curve_to(renderer, 2.66, -42.24, 0.78, -44.85,
                                        -3.27, -47.98);
            rr_renderer_bezier_curve_to(renderer, -7.32, -51.10, -13.19, -54.49,
                                        -19.60, -57.40);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xff56d02a);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, -43.18, -5.68);
            rr_renderer_bezier_curve_to(renderer, -49.72, -16.79, -46.01,
                                        -31.10, -34.90, -37.64);
            rr_renderer_bezier_curve_to(renderer, -29.56, -40.78, -23.19,
                                        -41.67, -17.20, -40.12);
            rr_renderer_bezier_curve_to(renderer, -11.20, -38.57, -6.07, -34.70,
                                        -2.93, -29.36);
            rr_renderer_bezier_curve_to(renderer, 3.61, -18.24, -0.10, -3.93,
                                        -11.22, 2.61);
            rr_renderer_bezier_curve_to(renderer, -22.33, 9.15, -36.64, 5.44,
                                        -43.18, -5.68);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xff56d02a);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, -43.80, -6.99);
            rr_renderer_line_to(renderer, -44.42, -8.37);
            rr_renderer_line_to(renderer, -45.31, -10.28);
            rr_renderer_line_to(renderer, -46.14, -12.34);
            rr_renderer_line_to(renderer, -46.78, -14.27);
            rr_renderer_line_to(renderer, -47.41, -16.39);
            rr_renderer_line_to(renderer, -47.89, -18.47);
            rr_renderer_line_to(renderer, -48.28, -20.73);
            rr_renderer_line_to(renderer, -48.53, -22.95);
            rr_renderer_line_to(renderer, -48.65, -25.60);
            rr_renderer_line_to(renderer, -48.51, -28.54);
            rr_renderer_line_to(renderer, -48.26, -31.95);
            rr_renderer_line_to(renderer, -47.83, -35.54);
            rr_renderer_line_to(renderer, -47.30, -38.68);
            rr_renderer_line_to(renderer, -46.50, -42.06);
            rr_renderer_line_to(renderer, -45.15, -46.86);
            rr_renderer_line_to(renderer, -43.31, -51.68);
            rr_renderer_line_to(renderer, -20.50, -20.63);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xff56d02a);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, -3.98, -30.42);
            rr_renderer_line_to(renderer, -4.88, -31.63);
            rr_renderer_line_to(renderer, -6.12, -33.33);
            rr_renderer_line_to(renderer, -7.52, -35.06);
            rr_renderer_line_to(renderer, -8.90, -36.55);
            rr_renderer_line_to(renderer, -10.45, -38.14);
            rr_renderer_line_to(renderer, -12.04, -39.57);
            rr_renderer_line_to(renderer, -13.82, -41.01);
            rr_renderer_line_to(renderer, -15.64, -42.31);
            rr_renderer_line_to(renderer, -17.89, -43.69);
            rr_renderer_line_to(renderer, -20.53, -45.00);
            rr_renderer_line_to(renderer, -23.63, -46.44);
            rr_renderer_line_to(renderer, -26.98, -47.81);
            rr_renderer_line_to(renderer, -29.98, -48.87);
            rr_renderer_line_to(renderer, -33.33, -49.81);
            rr_renderer_line_to(renderer, -38.18, -50.96);
            rr_renderer_line_to(renderer, -43.28, -51.70);
            rr_renderer_line_to(renderer, -27.22, -16.67);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xff3eb114);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, -32.92, -21.67);
            rr_renderer_bezier_curve_to(renderer, -34.71, -24.72, -33.69,
                                        -28.63, -30.65, -30.42);
            rr_renderer_bezier_curve_to(renderer, -29.19, -31.28, -27.45,
                                        -31.52, -25.81, -31.10);
            rr_renderer_bezier_curve_to(renderer, -24.17, -30.67, -22.77,
                                        -29.61, -21.91, -28.15);
            rr_renderer_line_to(renderer, -4.72, 1.06);
            rr_renderer_bezier_curve_to(renderer, -2.93, 4.10, -3.95, 8.01,
                                        -6.99, 9.80);
            rr_renderer_bezier_curve_to(renderer, -10.03, 11.59, -13.94, 10.58,
                                        -15.73, 7.54);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xff3eb114);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, 37.60, -4.61);
            rr_renderer_bezier_curve_to(renderer, 54.34, 6.29, 59.09, 28.69,
                                        48.19, 45.43);
            rr_renderer_bezier_curve_to(renderer, 42.96, 53.47, 34.75, 59.11,
                                        25.36, 61.09);
            rr_renderer_bezier_curve_to(renderer, 15.98, 63.08, 6.19, 61.25,
                                        -1.85, 56.02);
            rr_renderer_bezier_curve_to(renderer, -18.59, 45.13, -23.33, 22.72,
                                        -12.44, 5.98);
            rr_renderer_bezier_curve_to(renderer, -1.54, -10.76, 20.86, -15.50,
                                        37.60, -4.61);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xff3eb114);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, 57.77, 36.43);
            rr_renderer_bezier_curve_to(renderer, 63.68, 40.27, 65.36, 48.19,
                                        61.51, 54.10);
            rr_renderer_bezier_curve_to(renderer, 59.66, 56.94, 56.76, 58.93,
                                        53.45, 59.63);
            rr_renderer_bezier_curve_to(renderer, 50.13, 60.33, 46.67, 59.69,
                                        43.84, 57.84);
            rr_renderer_bezier_curve_to(renderer, 37.92, 53.99, 36.25, 46.08,
                                        40.10, 40.17);
            rr_renderer_bezier_curve_to(renderer, 43.94, 34.25, 51.86, 32.58,
                                        57.77, 36.43);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xff3eb114);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, 57.94, 23.94);
            rr_renderer_bezier_curve_to(renderer, 63.38, 37.54, 65.19, 49.61,
                                        61.97, 50.90);
            rr_renderer_bezier_curve_to(renderer, 60.43, 51.51, 57.91, 49.51,
                                        54.97, 45.33);
            rr_renderer_bezier_curve_to(renderer, 52.03, 41.15, 48.91, 35.13,
                                        46.29, 28.60);
            rr_renderer_bezier_curve_to(renderer, 40.85, 14.99, 39.04, 2.93,
                                        42.26, 1.64);
            rr_renderer_bezier_curve_to(renderer, 43.80, 1.02, 46.32, 3.03,
                                        49.26, 7.21);
            rr_renderer_bezier_curve_to(renderer, 52.20, 11.39, 55.32, 17.41,
                                        57.94, 23.94);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xff3eb114);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, 32.62, 62.85);
            rr_renderer_bezier_curve_to(renderer, 47.26, 62.32, 59.02, 59.09,
                                        58.90, 55.63);
            rr_renderer_bezier_curve_to(renderer, 58.84, 53.96, 55.98, 52.47,
                                        50.97, 51.48);
            rr_renderer_bezier_curve_to(renderer, 45.95, 50.48, 39.19, 50.07,
                                        32.16, 50.32);
            rr_renderer_bezier_curve_to(renderer, 17.52, 50.85, 5.75, 54.09,
                                        5.88, 57.55);
            rr_renderer_bezier_curve_to(renderer, 5.94, 59.21, 8.79, 60.70,
                                        13.80, 61.70);
            rr_renderer_bezier_curve_to(renderer, 18.82, 62.69, 25.59, 63.11,
                                        32.62, 62.85);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xff56d02a);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, 30.67, 6.04);
            rr_renderer_bezier_curve_to(renderer, 41.48, 13.08, 44.54, 27.54,
                                        37.51, 38.35);
            rr_renderer_bezier_curve_to(renderer, 34.13, 43.54, 28.83, 47.18,
                                        22.77, 48.46);
            rr_renderer_bezier_curve_to(renderer, 16.71, 49.74, 10.39, 48.56,
                                        5.20, 45.19);
            rr_renderer_bezier_curve_to(renderer, -5.61, 38.15, -8.67, 23.69,
                                        -1.63, 12.88);
            rr_renderer_bezier_curve_to(renderer, 5.40, 2.07, 19.86, -0.99,
                                        30.67, 6.04);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xff56d02a);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, 31.81, 6.94);
            rr_renderer_line_to(renderer, 32.98, 7.90);
            rr_renderer_line_to(renderer, 34.62, 9.21);
            rr_renderer_line_to(renderer, 36.29, 10.69);
            rr_renderer_line_to(renderer, 37.72, 12.13);
            rr_renderer_line_to(renderer, 39.23, 13.75);
            rr_renderer_line_to(renderer, 40.59, 15.40);
            rr_renderer_line_to(renderer, 41.95, 17.25);
            rr_renderer_line_to(renderer, 43.16, 19.13);
            rr_renderer_line_to(renderer, 44.45, 21.44);
            rr_renderer_line_to(renderer, 45.64, 24.14);
            rr_renderer_line_to(renderer, 46.93, 27.29);
            rr_renderer_line_to(renderer, 48.15, 30.70);
            rr_renderer_line_to(renderer, 49.07, 33.75);
            rr_renderer_line_to(renderer, 49.86, 37.13);
            rr_renderer_line_to(renderer, 50.80, 42.03);
            rr_renderer_line_to(renderer, 51.30, 47.16);
            rr_renderer_line_to(renderer, 17.04, 29.54);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xff56d02a);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, 6.61, 45.67);
            rr_renderer_line_to(renderer, 7.96, 46.35);
            rr_renderer_line_to(renderer, 9.83, 47.32);
            rr_renderer_line_to(renderer, 11.85, 48.24);
            rr_renderer_line_to(renderer, 13.75, 48.97);
            rr_renderer_line_to(renderer, 15.84, 49.69);
            rr_renderer_line_to(renderer, 17.90, 50.27);
            rr_renderer_line_to(renderer, 20.14, 50.76);
            rr_renderer_line_to(renderer, 22.35, 51.11);
            rr_renderer_line_to(renderer, 24.98, 51.35);
            rr_renderer_line_to(renderer, 27.93, 51.34);
            rr_renderer_line_to(renderer, 31.34, 51.25);
            rr_renderer_line_to(renderer, 34.96, 50.98);
            rr_renderer_line_to(renderer, 38.11, 50.59);
            rr_renderer_line_to(renderer, 41.53, 49.94);
            rr_renderer_line_to(renderer, 46.38, 48.81);
            rr_renderer_line_to(renderer, 51.28, 47.19);
            rr_renderer_line_to(renderer, 21.29, 23.00);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xff3eb114);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, 28.62, 24.94);
            rr_renderer_bezier_curve_to(renderer, 31.58, 26.86, 32.41, 30.82,
                                        30.49, 33.78);
            rr_renderer_bezier_curve_to(renderer, 29.56, 35.20, 28.11, 36.19,
                                        26.46, 36.54);
            rr_renderer_bezier_curve_to(renderer, 24.80, 36.89, 23.07, 36.57,
                                        21.65, 35.65);
            rr_renderer_line_to(renderer, -6.76, 17.16);
            rr_renderer_bezier_curve_to(renderer, -9.71, 15.24, -10.55, 11.28,
                                        -8.63, 8.32);
            rr_renderer_bezier_curve_to(renderer, -6.70, 5.37, -2.75, 4.53,
                                        0.21, 6.45);
            rr_renderer_fill(renderer);
            rr_renderer_scale(renderer, 1 / 0.2f);
            break;
        case rr_petal_id_rice:
            rr_renderer_scale(renderer, 0.4);
            rr_renderer_translate(renderer, -26.5, -12.5);
            rr_renderer_set_fill(renderer, 0xffffffff);
            rr_renderer_set_stroke(renderer, 0xffcfcfcf);
            rr_renderer_set_line_width(renderer, 4.0f);
            rr_renderer_set_line_join(renderer, 1.0f);
            rr_renderer_set_line_cap(renderer, 1.0f);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, 39.1162, 2.37012);
            rr_renderer_bezier_curve_to(renderer, 42.5347, 1.70587, 45.1574, 1.77804, 47.6357, 3.87891);
            rr_renderer_line_to(renderer, 47.875, 4.08887);
            rr_renderer_bezier_curve_to(renderer, 49.4982, 5.5567, 50.771, 8.04982, 50.9727, 10.7334);
            rr_renderer_bezier_curve_to(renderer, 51.163, 13.2673, 50.3986, 15.8916, 48.1299, 17.9814);
            rr_renderer_line_to(renderer, 47.9053, 18.1816);
            rr_renderer_bezier_curve_to(renderer, 46.2446, 19.6236, 43.3061, 20.8604, 39.4336, 21.7207);
            rr_renderer_bezier_curve_to(renderer, 35.6205, 22.5678, 31.134, 23, 26.6016, 23);
            rr_renderer_bezier_curve_to(renderer, 22.0695, 23, 17.5545, 22.5681, 13.6855, 21.7197);
            rr_renderer_bezier_curve_to(renderer, 10.0085, 20.9134, 7.10781, 19.772, 5.29492, 18.4229);
            rr_renderer_line_to(renderer, 4.94629, 18.1504);
            rr_renderer_bezier_curve_to(renderer, 3.04385, 16.5789, 1.99995, 14.0296, 2, 11.292);
            rr_renderer_bezier_curve_to(renderer, 2.00011, 8.72881, 2.91899, 6.20495, 4.65625, 4.43262);
            rr_renderer_line_to(renderer, 5.01465, 4.08887);
            rr_renderer_bezier_curve_to(renderer, 7.56401, 1.78369, 10.2446, 1.68443, 13.7734, 2.37012);
            rr_renderer_bezier_curve_to(renderer, 15.6585, 2.7364, 17.3871, 3.2348, 19.6094, 3.73242);
            rr_renderer_bezier_curve_to(renderer, 21.7135, 4.20357, 24.0075, 4.60542, 26.4443, 4.60547);
            rr_renderer_bezier_curve_to(renderer, 28.8814, 4.60547, 31.1761, 4.2036, 33.2803, 3.73242);
            rr_renderer_bezier_curve_to(renderer, 35.5026, 3.2348, 37.2312, 2.7364, 39.1162, 2.37012);
            rr_renderer_fill(renderer);
            rr_renderer_stroke(renderer);
            break;
        case rr_petal_id_missile:
            rr_renderer_set_fill(renderer, 0xffcdb124);
            rr_renderer_set_stroke(renderer, 0xffa68e1a);
            rr_renderer_set_line_width(renderer, 3.0f);
            rr_renderer_set_line_join(renderer, 1.0f);
            rr_renderer_set_line_cap(renderer, 1.0f);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, 15.00, 0.00);
            rr_renderer_line_to(renderer, -10.50, 6.06);
            rr_renderer_line_to(renderer, -10.50, -6.06);
            rr_renderer_line_to(renderer, 15.00, 0.00);
            rr_renderer_fill(renderer);
            rr_renderer_stroke(renderer);
            break;
        case rr_petal_id_amber:
            rr_renderer_scale(renderer, 0.4);
            rr_renderer_translate(renderer, -27.5, -38);
            rr_renderer_set_fill(renderer, 0xddfc8a17);
            rr_renderer_set_stroke(renderer, 0xffff6d13);
            rr_renderer_set_line_width(renderer, 6.0f);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, 27.2744, 9.04883);
            rr_renderer_bezier_curve_to(renderer, 33.0948, 6.10089, 40.1494, 7.57218, 44.3125, 12.5244);
            rr_renderer_line_to(renderer, 44.7061, 13.0146);
            rr_renderer_line_to(renderer, 49.1064, 18.748);
            rr_renderer_bezier_curve_to(renderer, 50.9829, 21.1932, 52, 24.1893, 52, 27.2715);
            rr_renderer_bezier_curve_to(renderer, 52, 40.4718, 51.9043, 41.4134, 51.7148, 42.3379);
            rr_renderer_line_to(renderer, 51.6279, 42.7334);
            rr_renderer_line_to(renderer, 47.5508, 60.0605);
            rr_renderer_bezier_curve_to(renderer, 45.9216, 66.9839, 39.3602, 71.5855, 32.2959, 70.7588);
            rr_renderer_line_to(renderer, 15.373, 68.7783);
            rr_renderer_bezier_curve_to(renderer, 8.31868, 67.9528, 3, 61.9755, 3, 54.873);
            rr_renderer_bezier_curve_to(renderer, 3, 24.6697, 5.96659, 19.8403, 10.6738, 17.4561);
            rr_renderer_line_to(renderer, 27.2744, 9.04883);
            rr_renderer_fill(renderer);
            rr_renderer_stroke(renderer);
            rr_renderer_set_stroke(renderer, 0xffb06110);
            rr_renderer_set_line_width(renderer, 2.0f);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, 27.8564, 34.728);
            rr_renderer_line_to(renderer, 23.1277, 24.9998);
            rr_renderer_stroke(renderer);
            rr_renderer_set_stroke(renderer, 0xffb06110);
            rr_renderer_set_line_width(renderer, 2.0f);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, 27.4834, 34.4331);
            rr_renderer_line_to(renderer, 38.2821, 33.8097);
            rr_renderer_stroke(renderer);
            rr_renderer_set_stroke(renderer, 0xffb06110);
            rr_renderer_set_line_width(renderer, 2.0f);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, 22.7988, 43.3545);
            rr_renderer_line_to(renderer, 12.0002, 43.9779);
            rr_renderer_stroke(renderer);
            rr_renderer_set_stroke(renderer, 0xffb06110);
            rr_renderer_set_line_width(renderer, 2.0f);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, 22.9307, 42.1968);
            rr_renderer_line_to(renderer, 27.6594, 51.925);
            rr_renderer_stroke(renderer);
            rr_renderer_set_stroke(renderer, 0xffb06110);
            rr_renderer_set_line_width(renderer, 2.0f);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, 16.3447, 32.6143);
            rr_renderer_line_to(renderer, 25.6756, 38.0856);
            rr_renderer_stroke(renderer);
            rr_renderer_set_stroke(renderer, 0xffb06110);
            rr_renderer_set_line_width(renderer, 2.0f);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, 25.46, 37.8838);
            rr_renderer_line_to(renderer, 34.7908, 43.3551);
            rr_renderer_stroke(renderer);
            rr_renderer_set_fill(renderer, 0xffb06110);
            rr_renderer_set_stroke(renderer, 0xffb06110);
            rr_renderer_set_line_width(renderer, 2.0f);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, 19.4413, 52.3548);
            rr_renderer_bezier_curve_to(renderer, 19.9627, 51.831, 20.6265, 50.9689, 21.3894, 49.8014);
            rr_renderer_bezier_curve_to(renderer, 22.9063, 47.4798, 24.7137, 44.1039, 26.4397, 40.227);
            rr_renderer_bezier_curve_to(renderer, 28.1657, 36.35, 29.4649, 32.7478, 30.175, 30.0671);
            rr_renderer_bezier_curve_to(renderer, 30.5321, 28.719, 30.7285, 27.6488, 30.7688, 26.9108);
            rr_renderer_bezier_curve_to(renderer, 30.7707, 26.8754, 30.7704, 26.8412, 30.7716, 26.8084);
            rr_renderer_bezier_curve_to(renderer, 30.748, 26.8312, 30.7224, 26.8539, 30.6974, 26.879);
            rr_renderer_bezier_curve_to(renderer, 30.176, 27.4028, 29.5122, 28.2649, 28.7493, 29.4324);
            rr_renderer_bezier_curve_to(renderer, 27.2324, 31.754, 25.425, 35.1298, 23.699, 39.0068);
            rr_renderer_bezier_curve_to(renderer, 21.973, 42.8838, 20.6738, 46.4859, 19.9637, 49.1667);
            rr_renderer_bezier_curve_to(renderer, 19.6066, 50.5148, 19.4102, 51.585, 19.3699, 52.323);
            rr_renderer_bezier_curve_to(renderer, 19.368, 52.3588, 19.3678, 52.3932, 19.3667, 52.4263);
            rr_renderer_bezier_curve_to(renderer, 19.3905, 52.4033, 19.416, 52.3802, 19.4413, 52.3548);
            rr_renderer_fill(renderer);
            rr_renderer_stroke(renderer);
            rr_renderer_begin_path(renderer);
            rr_renderer_translate(renderer, 22.0194, 30.9936);
            rr_renderer_rotate(renderer, 45.2 / 180 * M_PI);
            rr_renderer_set_fill(renderer, 0xffffffff);
            rr_renderer_set_global_alpha(renderer, 0.2);
            rr_renderer_ellipse(renderer, 0, 0, 8.696484, 15.07392);
            rr_renderer_fill(renderer);
            break;
        case rr_petal_id_stick:
            rr_renderer_scale(renderer, 0.1);
            rr_renderer_set_fill(renderer, 0xff2f190b);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, -58.631, -32.99924999999999);
            rr_renderer_bezier_curve_to(renderer, -77.817943, -21.22031899999999, -83.809772, 3.8741800000000097, -72.014125, 23.05084500000001);
            rr_renderer_line_to(renderer, -14.385780000000004, 116.73968500000001);
            rr_renderer_bezier_curve_to(renderer, -8.721305500000003, 125.94863900000001, 0.37136899999999606, 132.53341700000001, 10.891959999999997, 135.04541);
            rr_renderer_bezier_curve_to(renderer, 21.412551999999998, 137.557434, 32.499266999999996, 135.79089340000002, 41.713165, 130.1344603);
            rr_renderer_bezier_curve_to(renderer, 60.900099999999995, 118.3555293, 66.891937, 93.2610473, 55.096283, 74.08435030000001);
            rr_renderer_line_to(renderer, -2.532057000000002, -19.604479699999985);
            rr_renderer_bezier_curve_to(renderer, -14.327704000000002, -38.78114569999998, -39.444057, -44.778200699999985, -58.630997, -32.99925469999998);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xff2f190b);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, 56.71646000000001, -141.013626);
            rr_renderer_bezier_curve_to(renderer, 36.47241000000001, -146.608389, 15.535796000000012, -134.73007199999998, 9.95320800000001, -114.48266199999999);
            rr_renderer_line_to(renderer, -24.440451999999986, 10.259312000000008);
            rr_renderer_bezier_curve_to(renderer, -27.121306799999985, 19.98245700000001, -25.830489499999985, 30.37465300000001, -20.851973999999988, 39.14973900000001);
            rr_renderer_bezier_curve_to(renderer, -15.873458399999988, 47.92484000000001, -7.615057999999987, 54.36400300000001, 2.1064760000000113, 57.05069400000001);
            rr_renderer_bezier_curve_to(renderer, 22.350526000000013, 62.64546630000001, 43.28715600000001, 50.767140000000005, 48.86973600000002, 30.519734000000007);
            rr_renderer_line_to(renderer, 83.26339600000001, -94.22223599999998);
            rr_renderer_bezier_curve_to(renderer, 88.84597660000001, -114.46964199999998, 76.96050900000002, -135.41886599999998, 56.71646000000001, -141.013626);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xff2f190b);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, -16.603480000000005, -163.065623);
            rr_renderer_bezier_curve_to(renderer, -40.80465600000001, -159.33266279999998, -57.395278000000005, -136.687899, -53.659667000000006, -112.48712799999998);
            rr_renderer_line_to(renderer, -16.846049000000008, 126.006032);
            rr_renderer_bezier_curve_to(renderer, -15.052141800000008, 137.627645, -8.714961000000008, 148.061147, 0.771382999999993, 155.011312);
            rr_renderer_bezier_curve_to(renderer, 10.257733999999994, 161.9614463, 22.116177999999994, 164.85890700000002, 33.73798899999999, 163.066274);
            rr_renderer_bezier_curve_to(renderer, 57.93917599999999, 159.3333333, 74.529799, 136.688558, 70.79418899999999, 112.48778399999999);
            rr_renderer_line_to(renderer, 33.980558999999985, -126.005376);
            rr_renderer_bezier_curve_to(renderer, 30.244947999999987, -150.206146, 7.597708999999984, -166.798586, -16.603479000000014, -163.065626);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xff4a2810);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, 51.41475, -121.752613);
            rr_renderer_bezier_curve_to(renderer, 41.517243, -124.4845046, 31.28051, -118.6752357, 28.550355, -108.777252);
            rr_renderer_line_to(renderer, -5.569326999999998, 14.921368000000001);
            rr_renderer_bezier_curve_to(renderer, -6.880392699999998, 19.674557, -6.2496553699999975, 24.754208, -3.8158784999999975, 29.0428585);
            rr_renderer_bezier_curve_to(renderer, -1.3820939999999977, 33.3315245, 2.655366500000002, 36.477886500000004, 7.408318500000003, 37.7897915);
            rr_renderer_bezier_curve_to(renderer, 17.3058255, 40.5216793, 27.542565500000002, 34.7124142, 30.272713500000002, 24.8144195);
            rr_renderer_line_to(renderer, 64.39239549999999, -98.8842005);
            rr_renderer_bezier_curve_to(renderer, 67.12254379999999, -108.7821845, 61.312256299999994, -119.02072050000001, 51.41474949999999, -121.7526125);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xff5b3316);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, -13.790999999999997, -144.907005);
            rr_renderer_bezier_curve_to(renderer, -28.300482999999996, -142.6709706, -38.247882, -129.096386, -36.009142999999995, -114.587322);
            rr_renderer_line_to(renderer, 0.6015170000000083, 122.682928);
            rr_renderer_bezier_curve_to(renderer, 1.6765979000000082, 129.650427, 5.475555700000008, 135.905981, 11.162659000000009, 140.07349200000002);
            rr_renderer_bezier_curve_to(renderer, 16.84976230000001, 144.24097250000003, 23.959160000000008, 145.9790096, 30.92685700000001, 144.90521800000002);
            rr_renderer_bezier_curve_to(renderer, 45.43634000000001, 142.66919500000003, 55.38374300000001, 129.09461000000002, 53.14500400000001, 114.58551600000001);
            rr_renderer_line_to(renderer, 16.534340000000007, -122.68471399999999);
            rr_renderer_bezier_curve_to(renderer, 14.295601000000008, -137.19377799999998, 0.718483000000008, -147.143034, -13.790999999999993, -144.90699999999998);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xff5b3316);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, -49.23036, -17.70284000000001);
            rr_renderer_bezier_curve_to(renderer, -59.445932, -11.425099500000009, -62.633959, 1.9427599999999927, -56.351011199999995, 12.15513099999999);
            rr_renderer_line_to(renderer, 2.4387648000000084, 107.712671);
            rr_renderer_bezier_curve_to(renderer, 5.4559386000000085, 112.6168153, 10.298322800000008, 116.122522, 15.90063280000001, 117.458612);
            rr_renderer_bezier_curve_to(renderer, 21.502950800000008, 118.7946716, 27.40628580000001, 117.85161737, 32.31197880000001, 114.83693840000001);
            rr_renderer_bezier_curve_to(renderer, 42.52755480000001, 108.55922840000001, 45.715573800000016, 95.1913384, 39.43263000000001, 84.97896740000002);
            rr_renderer_line_to(renderer, -19.35714999999999, -10.57855859999998);
            rr_renderer_bezier_curve_to(renderer, -25.64009369999999, -20.79093059999998, -39.01478499999999, -23.98058159999998, -49.23035999999999, -17.702841599999978);
            rr_renderer_fill(renderer);
            break;
        case rr_petal_id_rake:
            rr_renderer_scale(renderer, 0.07);
            rr_renderer_translate(renderer, -103 ,-210);
            rr_renderer_set_fill(renderer, 0xffbf924d);
            rr_renderer_set_stroke(renderer, 0xff806033);
            rr_renderer_set_line_width(renderer, 5.0f);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, 94.5, 107.5);
            rr_renderer_line_to(renderer, 94.5, 410.0);
            rr_renderer_bezier_curve_to(renderer, 94.5, 414.142, 97.8579, 417.5, 102.0, 417.5);
            rr_renderer_line_to(renderer, 104.0, 417.5);
            rr_renderer_bezier_curve_to(renderer, 108.142, 417.5, 111.5, 414.142, 111.5, 410.0);
            rr_renderer_line_to(renderer, 111.5, 107.5);
            rr_renderer_line_to(renderer, 94.5, 107.5);
            rr_renderer_fill(renderer);
            rr_renderer_stroke(renderer);
            rr_renderer_set_fill(renderer, 0xffc0c0c0);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, 91.0, 96.0);
            rr_renderer_line_to(renderer, 115.0, 96.0);
            rr_renderer_line_to(renderer, 115.0, 170.0);
            rr_renderer_bezier_curve_to(renderer, 115.0, 170.552, 114.552, 171.0, 114.0, 171.0);
            rr_renderer_bezier_curve_to(renderer, 91.4477, 171.0, 91.0, 170.552, 91.0, 170.0);
            rr_renderer_fill(renderer);
            rr_renderer_set_stroke(renderer, 0xffffffff);
            rr_renderer_set_line_width(renderer, 4.0f);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, 106.0, 109.0);
            rr_renderer_bezier_curve_to(renderer, 106.0, 107.895, 106.895, 107.0, 108.0, 107.0);
            rr_renderer_bezier_curve_to(renderer, 109.105, 107.0, 110.0, 107.895, 110.0, 109.0);
            rr_renderer_line_to(renderer, 110.0, 157.0);
            rr_renderer_bezier_curve_to(renderer, 110.0, 158.105, 109.105, 159.0, 108.0, 159.0);
            rr_renderer_bezier_curve_to(renderer, 106.895, 159.0, 106.0, 158.105, 106.0, 157.0);
            rr_renderer_line_to(renderer, 106.0, 109.0);
            rr_renderer_fill(renderer);
            rr_renderer_stroke(renderer);
            rr_renderer_set_fill(renderer, 0xff1f2021);
            rr_renderer_set_stroke(renderer, 0xff131415);
            rr_renderer_set_line_width(renderer, 3.0f);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, 5.0, 1.5);
            rr_renderer_line_to(renderer, 5.8418, 1.5);
            rr_renderer_bezier_curve_to(renderer, 7.77479, 1.5, 9.3418, 3.067, 9.3418, 5.0);
            rr_renderer_line_to(renderer, 9.3418, 77.7227);
            rr_renderer_line_to(renderer, 23.1846, 77.7227);
            rr_renderer_line_to(renderer, 23.1846, 5.0);
            rr_renderer_bezier_curve_to(renderer, 23.1846, 3.067, 24.7516, 1.5, 26.6846, 1.5);
            rr_renderer_line_to(renderer, 27.5264, 1.5);
            rr_renderer_bezier_curve_to(renderer, 29.4593, 1.50003, 31.0264, 3.06702, 31.0264, 5.0);
            rr_renderer_line_to(renderer, 31.0264, 77.7227);
            rr_renderer_line_to(renderer, 44.8682, 77.7227);
            rr_renderer_line_to(renderer, 44.8682, 5.0);
            rr_renderer_bezier_curve_to(renderer, 44.8682, 3.06709, 46.4353, 1.50014, 48.3682, 1.5);
            rr_renderer_line_to(renderer, 49.2109, 1.5);
            rr_renderer_bezier_curve_to(renderer, 51.1437, 1.50022, 52.7109, 3.06714, 52.7109, 5.0);
            rr_renderer_line_to(renderer, 52.7109, 77.7227);
            rr_renderer_line_to(renderer, 66.5527, 77.7227);
            rr_renderer_line_to(renderer, 66.5527, 5.0);
            rr_renderer_bezier_curve_to(renderer, 66.5527, 3.067, 68.1197, 1.5, 70.0527, 1.5);
            rr_renderer_line_to(renderer, 70.8945, 1.5);
            rr_renderer_bezier_curve_to(renderer, 72.8275, 1.5, 74.3945, 3.067, 74.3945, 5.0);
            rr_renderer_line_to(renderer, 74.3945, 77.7227);
            rr_renderer_line_to(renderer, 88.2373, 77.7227);
            rr_renderer_line_to(renderer, 88.2373, 5.0);
            rr_renderer_bezier_curve_to(renderer, 88.2373, 3.067, 89.8043, 1.5, 91.7373, 1.5);
            rr_renderer_line_to(renderer, 92.5791, 1.5);
            rr_renderer_bezier_curve_to(renderer, 94.512, 1.50009, 96.0791, 3.06706, 96.0791, 5.0);
            rr_renderer_line_to(renderer, 96.0791, 77.7227);
            rr_renderer_line_to(renderer, 109.921, 77.7227);
            rr_renderer_line_to(renderer, 109.921, 5.0);
            rr_renderer_bezier_curve_to(renderer, 109.921, 3.06706, 111.488, 1.50008, 113.421, 1.5);
            rr_renderer_line_to(renderer, 114.263, 1.5);
            rr_renderer_bezier_curve_to(renderer, 116.196, 1.5, 117.763, 3.067, 117.763, 5.0);
            rr_renderer_line_to(renderer, 117.763, 77.7227);
            rr_renderer_line_to(renderer, 131.605, 77.7227);
            rr_renderer_line_to(renderer, 131.605, 5.0);
            rr_renderer_bezier_curve_to(renderer, 131.605, 3.067, 133.172, 1.5, 135.105, 1.5);
            rr_renderer_line_to(renderer, 135.947, 1.5);
            rr_renderer_bezier_curve_to(renderer, 137.88, 1.5, 139.447, 3.067, 139.447, 5.0);
            rr_renderer_line_to(renderer, 139.447, 77.7227);
            rr_renderer_line_to(renderer, 153.289, 77.7227);
            rr_renderer_line_to(renderer, 153.289, 5.0);
            rr_renderer_bezier_curve_to(renderer, 153.289, 3.06714, 154.856, 1.50022, 156.789, 1.5);
            rr_renderer_line_to(renderer, 157.632, 1.5);
            rr_renderer_bezier_curve_to(renderer, 159.565, 1.50014, 161.132, 3.06709, 161.132, 5.0);
            rr_renderer_line_to(renderer, 161.132, 77.7227);
            rr_renderer_line_to(renderer, 174.974, 77.7227);
            rr_renderer_line_to(renderer, 174.974, 5.0);
            rr_renderer_bezier_curve_to(renderer, 174.974, 3.06702, 176.541, 1.50002, 178.474, 1.5);
            rr_renderer_line_to(renderer, 179.315, 1.5);
            rr_renderer_bezier_curve_to(renderer, 181.248, 1.5, 182.815, 3.067, 182.815, 5.0);
            rr_renderer_line_to(renderer, 182.815, 77.7227);
            rr_renderer_line_to(renderer, 196.658, 77.7227);
            rr_renderer_line_to(renderer, 196.658, 5.0);
            rr_renderer_bezier_curve_to(renderer, 196.658, 3.067, 198.225, 1.5, 200.158, 1.5);
            rr_renderer_line_to(renderer, 201.0, 1.5);
            rr_renderer_bezier_curve_to(renderer, 202.933, 1.5, 204.5, 3.06701, 204.5, 5.0);
            rr_renderer_line_to(renderer, 204.5, 91.0);
            rr_renderer_bezier_curve_to(renderer, 204.5, 94.0376, 202.038, 96.5, 199.0, 96.5);
            rr_renderer_line_to(renderer, 7.0, 96.5);
            rr_renderer_bezier_curve_to(renderer, 3.96244, 96.5, 1.5, 94.0376, 1.5, 91.0);
            rr_renderer_line_to(renderer, 1.5, 5.0);
            rr_renderer_bezier_curve_to(renderer, 1.5, 3.06701, 3.067, 1.5, 5.0, 1.5);
            rr_renderer_fill(renderer);
            rr_renderer_stroke(renderer);
            break;
        case rr_petal_id_trol:
            rr_renderer_scale(renderer, 0.1);
            rr_renderer_set_fill(renderer, 0xffffb300);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, 80.90, -82.33);
            rr_renderer_bezier_curve_to(renderer, 125.72, -37.51, 125.72, 35.15,
                                        80.90, 79.97);
            rr_renderer_bezier_curve_to(renderer, 59.38, 101.49, 30.19, 113.58,
                                        -0.25, 113.58);
            rr_renderer_bezier_curve_to(renderer, -30.68, 113.58, -59.87,
                                        101.49, -81.40, 79.97);
            rr_renderer_bezier_curve_to(renderer, -126.21, 35.15, -126.21,
                                        -37.51, -81.40, -82.33);
            rr_renderer_bezier_curve_to(renderer, -36.58, -127.15, 36.08,
                                        -127.15, 80.90, -82.33);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xffffb300);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, 95.58, 39.57);
            rr_renderer_bezier_curve_to(renderer, 110.79, 54.78, 110.79, 79.44,
                                        95.58, 94.65);
            rr_renderer_bezier_curve_to(renderer, 88.27, 101.95, 78.37, 106.05,
                                        68.04, 106.05);
            rr_renderer_bezier_curve_to(renderer, 57.71, 106.05, 47.80, 101.95,
                                        40.50, 94.65);
            rr_renderer_bezier_curve_to(renderer, 25.29, 79.44, 25.29, 54.78,
                                        40.50, 39.57);
            rr_renderer_bezier_curve_to(renderer, 55.71, 24.36, 80.37, 24.36,
                                        95.58, 39.57);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xffffd000);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, -0.25, -82.33);
            rr_renderer_bezier_curve_to(renderer, 44.57, -82.33, 80.90, -46.00,
                                        80.90, -1.18);
            rr_renderer_quadratic_curve_to(renderer, 80.90, 34.64, 71.39,
                                           70.45);
            rr_renderer_quadratic_curve_to(renderer, 35.57, 79.97, -0.25,
                                           79.97);
            rr_renderer_bezier_curve_to(renderer, -45.07, 79.97, -81.40, 43.64,
                                        -81.40, -1.18);
            rr_renderer_bezier_curve_to(renderer, -81.40, -46.00, -45.07,
                                        -82.33, -0.25, -82.33);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xffffb300);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, -74.23, -77.81);
            rr_renderer_bezier_curve_to(renderer, -15.66, -81.51, 35.64, -38.94,
                                        42.81, 19.30);
            rr_renderer_line_to(renderer, 6.68, 23.75);
            rr_renderer_bezier_curve_to(renderer, 1.86, -15.37, -32.60, -43.96,
                                        -71.93, -41.48);
            rr_renderer_fill(renderer);
            rr_renderer_set_fill(renderer, 0xffffb300);
            rr_renderer_begin_path(renderer);
            rr_renderer_move_to(renderer, 37.65, 9.86);
            rr_renderer_bezier_curve_to(renderer, 44.74, 16.95, 44.74, 28.44,
                                        37.65, 35.53);
            rr_renderer_bezier_curve_to(renderer, 34.25, 38.93, 29.63, 40.84,
                                        24.82, 40.84);
            rr_renderer_bezier_curve_to(renderer, 20.00, 40.84, 15.39, 38.93,
                                        11.98, 35.53);
            rr_renderer_bezier_curve_to(renderer, 4.89, 28.44, 4.89, 16.95,
                                        11.98, 9.86);
            rr_renderer_bezier_curve_to(renderer, 19.07, 2.77, 30.56, 2.77,
                                        37.65, 9.86);
            rr_renderer_fill(renderer);
            rr_renderer_scale(renderer, 1 / 0.1);
            break;
        default:
            break;
        }
    }
}

void rr_renderer_draw_static_petal(struct rr_renderer *renderer, uint8_t id,
                                   uint8_t rarity, uint8_t flags)
{
    struct rr_renderer_context_state state;
    rr_renderer_context_state_init(renderer, &state);
    uint32_t count = RR_PETAL_DATA[id].count[rarity];
    if (id == rr_petal_id_peas)
        rr_renderer_rotate(renderer, 1.0f - M_PI / 4.0f);
    if (count <= 1)
    {
        if (id == rr_petal_id_shell)
            rr_renderer_rotate(renderer, 1.0f);
        else if (id == rr_petal_id_leaf)
            rr_renderer_rotate(renderer, -1.0f);
        else if (id == rr_petal_id_magnet)
            rr_renderer_rotate(renderer, -1.0f);
        else if (id == rr_petal_id_bone)
            rr_renderer_rotate(renderer, -1.0f);
        else if (id == rr_petal_id_club)
            rr_renderer_rotate(renderer, -1.0f);
        else if (id == rr_petal_id_feather)
            rr_renderer_rotate(renderer, 0.5f);
        else if (id == rr_petal_id_beak)
            rr_renderer_rotate(renderer, 1.0f);
        else if (id == rr_petal_id_lightning)
            rr_renderer_rotate(renderer, 1.0f);
        else if (id == rr_petal_id_fireball)
            rr_renderer_rotate(renderer, -1.0f + M_PI);
        else if (id == rr_petal_id_meteor)
            rr_renderer_rotate(renderer, -M_PI / 4);
        else if (id == rr_petal_id_clover)
            rr_renderer_rotate(renderer, 0.3f);
        else if (id == rr_petal_id_mandible)
            rr_renderer_rotate(renderer, -1.0f);
        else if (id == rr_petal_id_wax)
            rr_renderer_rotate(renderer, 0.3f);
        else if (id == rr_petal_id_rice)
            rr_renderer_rotate(renderer, 0.6f + M_PI);
        else if (id == rr_petal_id_missile)
            rr_renderer_rotate(renderer, -1.0f);
        else if (id == rr_petal_id_stick)
            rr_renderer_rotate(renderer, 1.0f);
        else if (id == rr_petal_id_rake)
            rr_renderer_rotate(renderer, 0.5f);
        rr_renderer_draw_petal(renderer, id, rarity, flags);
    }
    else
    {
        struct rr_renderer_context_state state;
        float r = RR_PETAL_DATA[id].clump_radius == 0.0f
                      ? 10.0f
                      : RR_PETAL_DATA[id].clump_radius;
        for (uint32_t i = 0; i < count; ++i)
        {
            rr_renderer_context_state_init(renderer, &state);
            rr_renderer_translate(renderer, r, 0.0f);
            if (id == rr_petal_id_shell)
            {
                if (rarity == rr_rarity_id_mythic)
                {
                    rr_renderer_scale2(renderer, 1, -1);
                    rr_renderer_rotate(renderer, -1.0f);
                }
                else
                    rr_renderer_rotate(renderer, 1.0f);
            }
            else if (id == rr_petal_id_leaf)
                rr_renderer_rotate(renderer, -1.0f);
            else if (id == rr_petal_id_stinger && rarity >= rr_rarity_id_exotic)
                rr_renderer_rotate(renderer, M_PI);
            else if (id == rr_petal_id_wax)
                rr_renderer_rotate(renderer, 0.3f);
            else if (id == rr_petal_id_stick)
                rr_renderer_rotate(renderer, -0.75f + M_PI);
            rr_renderer_draw_petal(renderer, id, rarity, flags);
            rr_renderer_context_state_free(renderer, &state);
            rr_renderer_rotate(renderer, M_PI * 2.0f / count);
        }
    }
    rr_renderer_context_state_free(renderer, &state);
}

void rr_renderer_draw_petal_with_name(struct rr_renderer *renderer, uint8_t id,
                                      uint8_t rarity)
{
    rr_renderer_translate(renderer, 0, -5);
    rr_renderer_draw_static_petal(renderer, id, rarity, 1);
    rr_renderer_translate(renderer, 0, 25);
    rr_renderer_draw_petal_name(renderer, id, 12, 0, 0);
}

static void rr_renderer_petal_cache_draw()
{
    rr_renderer_set_transform(&petal_cache, 1, 0, 0, 0, 1, 0);
    rr_renderer_translate(&petal_cache, IMAGE_SIZE / 2, IMAGE_SIZE / 2);
    struct rr_renderer_context_state state;
    for (uint32_t i = 0; i < rr_petal_id_max; ++i)
    {
        rr_renderer_context_state_init(&petal_cache, &state);
        rr_renderer_scale(&petal_cache, IMAGE_SIZE / 50);
        rr_renderer_draw_petal(&petal_cache, i, 0, 0);
        rr_renderer_context_state_free(&petal_cache, &state);
        rr_renderer_translate(&petal_cache, IMAGE_SIZE, 0);
    }
    rr_renderer_context_state_init(&petal_cache, &state);
    rr_renderer_scale(&petal_cache, IMAGE_SIZE / 50);
    rr_renderer_draw_petal(&petal_cache, rr_petal_id_clover,
                           rr_rarity_id_exotic, 0);
    rr_renderer_context_state_free(&petal_cache, &state);
}

static void rr_renderer_petal_cache_redraw(void *captures)
{
    rr_renderer_petal_cache_draw();
}

void rr_renderer_petal_cache_init()
{
    rr_renderer_init(&petal_cache);
    rr_renderer_set_dimensions(&petal_cache, IMAGE_SIZE * (rr_petal_id_max + 1),
                               IMAGE_SIZE);
    petal_cache.on_context_restore = rr_renderer_petal_cache_redraw;
    rr_renderer_petal_cache_draw();
}
