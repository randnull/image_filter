#include "filter_crop.h"

void FilterCrop::Apply(Image& image) {
    std::vector<std::vector<Color>>& C = image.get_matrix_pixel();
    std::reverse(std::begin(C), std::end(C));
    C.resize(height);
    for (auto i : C) {
        i.resize(width);
    }
    std::reverse(std::begin(C), std::end(C));
    image.set_width_height(height, width);
}
