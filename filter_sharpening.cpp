#include "filter_sharpening.h"

void FilterSharpening::Apply(Image& image) {
    std::vector<std::vector<Color>>& C = image.get_matrix_pixel();
    add_matrix(C);
}
