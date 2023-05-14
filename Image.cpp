#include "Image.h"

std::vector<std::vector<Color>>& Image::get_matrix_pixel() {
    return C_;
}

std::vector<std::vector<Color>> Image::get_matrix_pixel_const() const{
    return C_;
}

Image::Image(std::vector<std::vector<Color>>& C) {
    C_ = C;
}

void Image::set_width_height(BIT32 new_height, BIT32 new_width) {
    height = new_width;
    width = new_width;
}

BIT32 Image::get_height() const{
    return height;
}

BIT32 Image::get_width() const{
    return width;
}
