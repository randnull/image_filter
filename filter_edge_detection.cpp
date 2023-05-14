#include "filter_edge_detection.h"

void FilterEdgeDetection::Apply(Image& image) {
    FilterGrayscale::Apply(image);
    std::vector<std::vector<Color>>& C = image.get_matrix_pixel();
    add_matrix(C);
    for (size_t i = 0; i < C.size(); i++) {
        for (size_t j = 0; j < C[i].size(); j++) {
            if (C[i][j].red > param_ || C[i][j].green > param_ || C[i][j].blue > param_) {
                C[i][j].red = 255;
                C[i][j].green = 255;
                C[i][j].blue = 255;
            } else {
                C[i][j].red = 0;
                C[i][j].green = 0;
                C[i][j].blue = 0;
            }
        }
    }
}
