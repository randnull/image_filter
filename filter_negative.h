#pragma once
#include "filters.h"

class FilterNegative : public Filters{
public:
    virtual ~FilterNegative() {};
    void Apply(Image& image) final;
};