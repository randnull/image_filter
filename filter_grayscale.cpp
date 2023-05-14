#include "filter_grayscale.h"

void FilterGrayscale::Apply(Image& image) {
    std::vector<std::vector<Color>>& C = image.get_matrix_pixel();
    for (size_t i = 0; i < C.size(); i++) {
        for (size_t j = 0; j < C[i].size(); j++) {
            const auto new_mean = 0.299 * C[i][j].red + 0.587 * C[i][j].green + 0.114 * C[i][j].blue;
            C[i][j].red = new_mean;
            C[i][j].green = new_mean;
            C[i][j].blue = new_mean;
        }
    }
}
