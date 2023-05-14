#include <catch.hpp>
#include "BMP.h"

TEST_CASE("input-output") {
    {
        BMPReadAndWrite open;
        std::string input_path = "image_processor/examples/example.bmp";
        Image image;
        image = open.read(input_path);
        std::string output_path = "image_processor/examples/result_test_example.bmp";
        Image image2;
        open.write(output_path, image);
        image2 = open.read(output_path);
        REQUIRE(image.get_matrix_pixel() == image2.get_matrix_pixel());
    }
}

TEST_CASE("exception with input-output") {
    {
        //not BMP 24
        BMPReadAndWrite open;
        std::string input_path = "image_processor/examples/new_example.bmp";
        Image image;
        try {
            image = open.read(input_path);
            throw std::runtime_error("not the same text");
        } catch (std::runtime_error& exception) {
            REQUIRE(strcmp(exception.what(), "programm can work with only 24 bit format BMP") == 0);
        }
    }
    {
        //not BMP
        BMPReadAndWrite open;
        Image image;
        std::string input_path = "image_processor/examples/Bmp_format.png";
        try {
            image = open.read(input_path);
            throw std::runtime_error("not the same text");
        } catch (std::runtime_error& exception) {
            REQUIRE(strcmp(exception.what(), "programm can work with format BMP only") == 0);
        }
    }
}

TEST_CASE("Pixel") {
    {
        BMPReadAndWrite open;
        Image image;
        std::string input_path = "image_processor/examples/example.bmp";
        image = open.read(input_path);
        std::vector<std::vector<Color>>& C = image.get_matrix_pixel();
        REQUIRE(sizeof(C[0][0]) == 3);
    }
}

TEST_CASE("Image") {
    {
        BMPReadAndWrite open;
        Image image;
        std::string input_path = "image_processor/examples/example.bmp";
        image = open.read(input_path);
        std::vector<std::vector<Color>>& C = image.get_matrix_pixel();
        REQUIRE(C.size() == 2048);
        REQUIRE(C[0].size() == 2048);
    }
}
