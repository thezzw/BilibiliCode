#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <opencv2/opencv.hpp>

#define CLEAR() std::cout << "\033[2J"

int main(){  
    cv::VideoCapture capture("source/0.mp4");
    int frame_num_ = capture.get(cv::CAP_PROP_FRAME_COUNT);
    cv::Mat temp;
    std::string img_filename_read;
    //std::string img_filename_write;
    //cv::VideoWriter video("result/0.avi", cv::VideoWriter::fourcc('M', 'J', 'P', 'G'), 30.0, cv::Size(1080, 1920));

    cv::waitKey(50000);

    for (int i = 0; i < frame_num_; ++i)
    {
    img_filename_read = "source/OTSU/0." + std::to_string(i) + ".jpg";//获取图像
    //std::string img_filename_write = "source/RESIZE/0." + std::to_string(i) + ".jpg";
    temp = cv::imread(img_filename_read,0);
    cv::resize(temp, temp,cv::Size(54,81));

    int row = temp.rows;
    int col = temp.cols;

    for (int i = 0; i < row; i ++)
    {
        for (int j = 0; j < col; j ++)
        {
            if(temp.at<uchar>(i, j) != 0)
            {
                std::cout << "# ";
            }
            else
            {
                std::cout << "  ";
            }
            
        }
        std::cout << std::endl;
    }
    
    //system("gnome-screenshot -w --file=source/RESIZE/0." + (char)i);
    cv::waitKey(27);
    //system("clear");
    std::cout << "\033[2J";

    //threshold(temp, temp, 0, 255, cv::THRESH_OTSU);

    //cv::imwrite(img_filename_write, temp);
    //video << temp;
    }
    //video.release();
    capture.release();

    return 0;
}