#include "filter_negative.h"

void FilterNegative::Apply(Image& image) {
    std::vector<std::vector<Color>>& C = image.get_matrix_pixel();
    for (size_t i = 0; i < C.size(); i++) {
        for (size_t j = 0; j < C[i].size(); j++) {
            C[i][j].red = 255 - C[i][j].red;
            C[i][j].green = 255 - C[i][j].green;
            C[i][j].blue = 255 - C[i][j].blue;
        }
    }
}