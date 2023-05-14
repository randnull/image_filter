#pragma once
#include "filters.h"

class FilterSharpening: public MatrixFilters {
public:
    FilterSharpening() : MatrixFilters({0, -1, 0, -1, 5, -1, 0, -1, 0}){};
    virtual ~FilterSharpening() {};
    void Apply(Image& image) final;
};