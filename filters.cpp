#include "filters.h"

void MatrixFilters::add_matrix(std::vector<std::vector<Color>>& C) {
    std::vector<std::vector<Color>> C_tmp = C;
    for (size_t i = 0; i < C.size(); i++) {
        for (size_t j = 0; j < C[i].size(); j++) {
            if (!(i == 0 || j == 0 || i == C.size() - 1 || j == C[i].size() - 1)) {
                C[i][j].red = std::min(
                    255, std::max(0, matrix[0] * C_tmp[i - 1][j - 1].red + matrix[1] * C_tmp[i][j - 1].red +
                                         matrix[2] * C_tmp[i + 1][j - 1].red + matrix[3] * C_tmp[i - 1][j].red +
                                         matrix[4] * C_tmp[i][j].red + matrix[5] * C_tmp[i + 1][j].red +
                                         matrix[6] * C_tmp[i - 1][j + 1].red + matrix[7] * C_tmp[i][j + 1].red +
                                         matrix[8] * C_tmp[i + 1][j + 1].red));
                C[i][j].green = std::min(
                    255, std::max(0, matrix[0] * C_tmp[i - 1][j - 1].green + matrix[1] * C_tmp[i][j - 1].green +
                                         matrix[2] * C_tmp[i + 1][j - 1].green + matrix[3] * C_tmp[i - 1][j].green +
                                         matrix[4] * C_tmp[i][j].green + matrix[5] * C_tmp[i + 1][j].green +
                                         matrix[6] * C_tmp[i - 1][j + 1].green + matrix[7] * C_tmp[i][j + 1].green +
                                         matrix[8] * C_tmp[i + 1][j + 1].green));
                C[i][j].blue = std::min(
                    255, std::max(0, matrix[0] * C_tmp[i - 1][j - 1].blue + matrix[1] * C_tmp[i][j - 1].blue +
                                         matrix[2] * C_tmp[i + 1][j - 1].blue + matrix[3] * C_tmp[i - 1][j].blue +
                                         matrix[4] * C_tmp[i][j].blue + matrix[5] * C_tmp[i + 1][j].blue +
                                         matrix[6] * C_tmp[i - 1][j + 1].blue + matrix[7] * C_tmp[i][j + 1].blue +
                                         matrix[8] * C_tmp[i + 1][j + 1].blue));
            } else {
                int k = 0;
                int m = 0;
                if (i == 1){
                    k = 2;
                } else {
                    k = C.size() - 2;
                }
                if (j == 1) {
                    m = 2;
                } else {
                    m = C[i].size() - 2;
                }
                C[i][j].red = std::min(255, std::max(0, matrix[0] * C_tmp[k - 1][m - 1].red + matrix[1] * C_tmp[k][m - 1].red +
                                                            matrix[2] * C_tmp[k + 1][m - 1].red + matrix[3] * C_tmp[k - 1][m].red +
                                                            matrix[4] * C_tmp[k][m].red + matrix[5] * C_tmp[k + 1][m].red +
                                                            matrix[6] * C_tmp[k - 1][m + 1].red + matrix[7] * C_tmp[k][m + 1].red +
                                                            matrix[8] * C_tmp[k + 1][m + 1].red));
                C[i][j].green = std::min(255, std::max(0, matrix[0] * C_tmp[k - 1][m - 1].green + matrix[1] * C_tmp[k][m - 1].green +
                                                              matrix[2] * C_tmp[k + 1][m - 1].green + matrix[3] * C_tmp[k - 1][m].green +
                                                              matrix[4] * C_tmp[k][m].green + matrix[5] * C_tmp[k + 1][m].green +
                                                              matrix[6] * C_tmp[k - 1][m + 1].green + matrix[7] * C_tmp[k][m + 1].green +
                                                              matrix[8] * C_tmp[k + 1][m + 1].green));
                C[i][j].blue = std::min(255, std::max(0, matrix[0] * C_tmp[k - 1][m - 1].blue + matrix[1] * C_tmp[k][m - 1].blue +
                                                             matrix[2] * C_tmp[k + 1][m - 1].blue + matrix[3] * C_tmp[k - 1][m].blue +
                                                             matrix[4] * C_tmp[k][m].blue + matrix[5] * C_tmp[k + 1][m].blue +
                                                             matrix[6] * C_tmp[k - 1][m + 1].blue + matrix[7] * C_tmp[k][m + 1].blue +
                                                             matrix[8] * C_tmp[k + 1][m + 1].blue));
            }
        }
    }
}
