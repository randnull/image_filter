#pragma once
#include "filters.h"

class FilterGrayscale : public virtual Filters{
public:
    virtual ~FilterGrayscale() {};
    void Apply(Image& image) override;
};
