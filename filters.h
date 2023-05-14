#pragma once
#include <string>
#include <vector>
#include "BMP.h"

class Filters {
public:
    virtual void Apply(Image& image) = 0;
    virtual ~Filters() {};
};

class MatrixFilters : public virtual Filters{
private:
    std::vector<int> matrix;
public:
    MatrixFilters(std::vector<int> matr): matrix(matr) {}
    void add_matrix(std::vector<std::vector<Color>>& C);
};
