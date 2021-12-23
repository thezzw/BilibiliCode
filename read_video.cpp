#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
    cv::VideoCapture capture("csj.mp4");
    int frame_num_ = capture.get(cv::CAP_PROP_FRAME_COUNT);
    cv::Mat frame;
    std::string img_filename;

    //判断视频是否读取成功
    if (!capture.isOpened())
    {
        std::cout << "Read video Failed !" << std::endl;
        return 0;
    }

    //循环读取视频帧并保存  
    for (int i = 0; i < frame_num_; ++i)
    {
        capture >> frame;
        img_filename = "csj/" + std::to_string(i) + ".jpg";
        cv::imwrite(img_filename, frame);
    }

    capture.release();

    return 0;
}