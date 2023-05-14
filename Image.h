#pragma once
#include <string>
#include <vector>
#include "Color.h"

using BIT32 = uint32_t;

class Image {
    std::vector<std::vector<Color>> C_;
    BIT32 width;
    BIT32 height;
public:
    Image(std::vector<std::vector<Color>>& C);
    std::vector<std::vector<Color>>& get_matrix_pixel();
    std::vector<std::vector<Color>> get_matrix_pixel_const() const;
    void set_width_height(BIT32 new_height, BIT32 new_width);
    BIT32 get_width() const;
    BIT32 get_height() const;
};