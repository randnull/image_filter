#include <iostream>
#include "BMP.h"
#include "filter_edge_detection.h"
#include "filter_grayscale.h"
#include "filter_negative.h"
#include "filter_sharpening.h"
#include "filter_crop.h"

void InfoHelp() {
    std::cout << "This programm can apply different filtres for your image (avaliable image type: BMP 24)" << std::endl;
    std::cout << "How to use it:" << std::endl;
    std::cout << "{programm name} {path for input file} {path for output file} [-{name filter 1} [filter parametr 1] [filter parametr 2] ...] [-{name filter 2} [filter parametr 1] [filter parametr 2] ...] ..." << std::endl;
    std::cout << "avaliable filters:" << std::endl;
    std::cout << "-crop height width: apply crop filter" << std::endl;
    std::cout << "-gs : apply grayscale filter" << std::endl;
    std::cout << "-neg : apply negative filter" << std::endl;
    std::cout << "-sharp : apply sharpening filter" << std::endl;
    std::cout << "-edge threshold: apply Edge Detection filter" << std::endl;
}

int main(int argc, char** argv) {
    std::vector<Filters*> filters;
    std::vector<std::string> commands;
    std::vector<std::string> available_commands{"-neg", "-gs", "-sharp", "-edge", "-crop"};
    try {
        if (argc == 1) {
            InfoHelp();
        } else if (argc == 2) {
            throw std::runtime_error("not correct input");
        } else if (argc > 2) {
            std::string input_image = argv[1];
            std::string out_image = argv[2];
            size_t i = 3;
            while (i < argc) {
                std::string new_command = argv[i];
                if (std::find(available_commands.begin(), available_commands.end(), new_command) !=
                    available_commands.end()) {
                    commands.push_back(new_command);
                    if (new_command == "-edge") {
                        if (i + 1 < argc) {
                            try {
                                i++;
                                std::stoi(argv[i]);
                                std::string thresholdtmp = argv[i];
                                commands.push_back(thresholdtmp);
                            } catch (std::exception) {
                                throw std::runtime_error("no or bad parametr for -edge");
                            }
                        } else {
                            throw std::runtime_error("no parametr for -edge");
                        }
                    } else if (new_command == "-crop") {
                        if (i + 2 < argc) {
                            try {
                                i++;
                                if (std::stoi(argv[i]) < 0) {
                                    throw std::runtime_error("bad height for -crop");
                                }
                                std::string height = argv[i];
                                i++;
                                if (std::stoi(argv[i]) < 0) {
                                    throw std::runtime_error("bad width for -crop");
                                }
                                std::string width = argv[i];
                                commands.push_back(height);
                                commands.push_back(width);
                            } catch (std::exception) {
                                throw std::runtime_error("no or bad parametr for -crop");
                            }
                        } else {
                            throw std::runtime_error("no parametr for -crop");
                        }
                    }
                } else {
                    throw std::runtime_error("it's not avaliable filter");
                }
                i++;
            }
            BMPReadAndWrite image_read_and_write;
            Image image = image_read_and_write.read(input_image);
            for (size_t j = 0; j < commands.size(); j++) {
                if (commands[j] == "-gs") {
                    FilterGrayscale filter_grayscale;
                    filter_grayscale.Apply(image);
                } else if (commands[j] == "-neg") {
                    FilterNegative filter_negative;
                    filter_negative.Apply(image);
                } else if (commands[j] == "-sharp") {
                    FilterSharpening filter_sharpening;
                    filter_sharpening.Apply(image);
                } else if (commands[j] == "-edge") {
                    j++;
                    int threshold = std::stoi(commands[j]);
                    FilterEdgeDetection filter_edge_detection(threshold);
                    filter_edge_detection.Apply(image);
                } else if (commands[j] == "-crop") {
                    j++;
                    int height = std::stoi(commands[j]);
                    if (height > image.get_height()) {
                        height = image.get_height();
                    }
                    j++;
                    int width = std::stoi(commands[j]);
                    if (width > image.get_width()) {
                        width = image.get_width();
                    }
                    FilterCrop filter_crop(height, width);
                    filter_crop.Apply(image);
                }
            }
            image_read_and_write.write(out_image, image);
        }
    } catch (std::runtime_error& exception) {
        std::cout << exception.what() << std::endl;
    }
}