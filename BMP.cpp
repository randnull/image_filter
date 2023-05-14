#include "BMP.h"
#include <fstream>
#include <iostream>

Image BMPReadAndWrite::read(const std::string& str) {
    try {
        std::ifstream inp(str, std::ios_base::binary);
        std::vector<std::vector<Color>> C;
        if (inp.is_open()) {
            try {
                inp.read((char *)&file_header, sizeof(file_header));
                inp.read((char *)&info_header, sizeof(info_header));
            } catch (std::exception) {
                throw std::runtime_error("problem with read image");
            }
            if (file_header.signature != bmp_signature) {
                throw std::runtime_error("programm can work with format BMP only");
            }
            if (info_header.bit_per_pixel != bmp_bit_for_pixel) {
                throw std::runtime_error("programm can work with only 24 bit format BMP");
            } else {
                C.resize(info_header.height);
                for (size_t i = 0; i < info_header.height; i++) {
                    C[i].resize(info_header.width);
                    inp.read((char *)(C[i].data()), info_header.width * 3);
                }
            }
        } else {
            throw std::runtime_error("bad open");
        }
        inp.close();
        Image image(C);
        image.set_width_height(info_header.height, info_header.width);
        return image;
    } catch (std::exception) {
        throw std::runtime_error("Not correct input file!");
    }
}

void BMPReadAndWrite::write(const std::string& str, const Image& image) {
    try {
        std::ofstream of(str, std::ios_base::binary);
        if (of) {
            std::vector<std::vector<Color>> C = image.get_matrix_pixel_const();
            info_header.height = image.get_height();
            info_header.width = image.get_width();
            of.write((char *)&file_header, sizeof(file_header));
            of.write((char *)&info_header, sizeof(info_header));
            for (size_t i = 0; i < info_header.height; i++) {
                of.write((char *)(C[i].data()), info_header.width * 3);
            }
        } else {
            throw std::runtime_error("Not correct output file!");
        }
        of.close();
    } catch (std::exception) {
        throw std::runtime_error("Error with write");
    }
}
