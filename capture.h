#ifndef CAPTURE_H
#define CAPTURE_H

#include "opencv2/opencv.hpp"
#include <string.h>

using namespace cv;

class Capture {
public:
    static void TakePicture(String filename);

    void matToBytes(Mat image, std::byte *dst, int size);

    Mat bytesToMat(std::byte *bytes, int width, int height);
};

#endif
