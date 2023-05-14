#pragma once
#include "filters.h"

class FilterCrop : Filters {
    BIT32 width;
    BIT32 height;
public:
    FilterCrop(BIT32 new_width, BIT32 new_height) : width(new_width), height(new_height) {}
    virtual ~FilterCrop() {}
    void Apply(Image& image) override;
};