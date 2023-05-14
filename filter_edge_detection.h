#pragma once
#include "filter_grayscale.h"

class FilterEdgeDetection: public MatrixFilters, public FilterGrayscale {
    int param_;
public:
    FilterEdgeDetection(int param) : MatrixFilters({0, -1, 0, -1, 4, -1, 0, -1, 0}), param_(param) {};
    virtual ~FilterEdgeDetection() {};
    void Apply(Image& image) final;
};