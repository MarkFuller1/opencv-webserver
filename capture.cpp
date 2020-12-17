#include "capture.h"
#include "opencv2/opencv.hpp"
#include <stdio.h>
#include <string.h>

using namespace cv;

void Capture::TakePicture(String filename) {
    VideoCapture cap;

    if (!cap.open(0)) {
        std::cout << "could not open camera" << std::endl;
    }

    Mat *frame = new Mat();
    cap >> *frame;

    //imshow("window title", *frame);
    //waitKey(0);
    imwrite(filename, *frame);
}

void Capture::matToBytes(Mat image, std::byte *dst, int size) {
    memcpy(dst, image.data, size * sizeof(std::byte));
}

Mat Capture::bytesToMat(std::byte *bytes, int width, int height) {
    Mat image = Mat(height, width, CV_8UC3, bytes).clone(); //make a copy
    return image;
}

