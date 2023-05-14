#pragma once
#include <string>
#include <vector>
#include "Image.h"
#pragma pack(push, 1)

using BIT16 = uint16_t;
using BIT32 = uint32_t;

struct BMPFileHeader {
    BIT16 signature = 19778;
    BIT32 file_size = 0;
    BIT16 reserved1 = 0;
    BIT16 reserved2 = 0;
    BIT32 offset_pixel_array = 0;
};

struct BMPInfoHeader {
    BIT32 size = 0;
    BIT32 width = 0;
    BIT32 height = 0;
    BIT16 planes = 1;
    BIT16 bit_per_pixel = 0;
    BIT32 compression = 0;
    BIT32 image_size = 0;
    BIT32 x_pixels_per_meter = 0;
    BIT32 y_pixels_per_meter = 0;
    BIT32 colors_in_table = 0;
    BIT32 important_color = 0;
};

class BMPReadAndWrite {
    const int bmp_signature = 19778;
    const int bmp_bit_for_pixel = 24;
    BMPFileHeader file_header;
    BMPInfoHeader info_header;
public:
    Image read(const std::string& str);
    void write(const std::string& str, const Image& image);
};
#pragma pack(pop)