#include "opencv2/opencv.hpp"
#include <iostream>

int main() {

    cv::Mat frame;
    cv::namedWindow("Video Feed");
    // cap(0) is webcam, try other numbers if it doesn't work
    cv::VideoCapture cap(0);

    if (!cap.isOpened()) {
        std::cout << "cannot open camera" << std::endl;
    }

    while (true) {
        cap >> frame;
        cv::imshow("Video Feed", frame);

        // Press spacebar to exit
        int key = cv::waitKey(1);
        if (key == 32) { break; }
    }

    cap.release();
    cv::destroyAllWindows();

    return 0;
}