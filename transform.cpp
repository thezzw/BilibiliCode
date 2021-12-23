#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>

int main(){  
    cv::VideoCapture capture("csj.mp4");
    int frame_num = capture.get(cv::CAP_PROP_FRAME_COUNT);
    cv::Mat temp;
    std::string img_filename_read;

    for (int i = 0; i < frame_num; ++i)
    {
        img_filename_read = "csj/" + std::to_string(i) + ".jpg";//获取图像
        temp = cv::imread(img_filename_read,0);
        threshold(temp, temp, 0, 255, cv::THRESH_OTSU);
        std::string img_filename = "csj_OTSU/" + std::to_string(i) + ".jpg";
        cv::imwrite(img_filename, temp);
    }
    capture.release();

    return 0;
}