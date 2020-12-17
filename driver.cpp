#include "TCP_Server.h"
#include <string>
#include "capture.h"
#include <fstream>
#include <iostream>
#include <unistd.h>

int fileToBuffer(std::string, char **image);

char *concat_c_str(const char *a, int a_size, const char *b, int b_size);

int main() {

    TCP_Server serv;

    serv.connect();

    std::string header = "HTTP/1.1 200 OK\r\nContent-Type: image/png\r\n\r\n";

    std::string filename = "./mostrecent.png";

    while(true) {
        Capture::TakePicture(filename);

        //sleep(1);

        std::ifstream f(filename, std::ios::in | std::ios::binary | std::ios::ate);
        if (!f.is_open()) {
            std::cout << "Call the cops" << std::endl;
        }

        char *image;
        int image_size = fileToBuffer(filename, &image);

        char *data = concat_c_str(header.c_str(), (int) header.length(), image, image_size);

        serv.respond(data, header.length() + image_size);
    }

    serv.disconnect();

    return 0;
}

int fileToBuffer(std::string filename, char **image) {

    std::cout << filename << std::endl;

    //open file
    std::ifstream infile(filename);

    //get  length of file
    infile.seekg(0, std::ios::end);
    size_t length = infile.tellg();
    infile.seekg(0, std::ios::beg);

    *image = new char[length];

    //read file
    infile.read(*image, length);

    std::cout << "size:" << length << std::endl;

    infile.close();

    std::cout << std::endl;

    return length;

}

char *concat_c_str(const char *a, int a_size, const char *b, int b_size) {

    int length = a_size + b_size;
    std::cout << length << std::endl;

    char *concatd = new char[length];

    for (int i = 0; i < a_size; i++) {
        concatd[i] = a[i];
    }

    for (int i = 0; i < b_size; i++) {
        concatd[a_size + i] = b[i];
    }

    return concatd;
}




