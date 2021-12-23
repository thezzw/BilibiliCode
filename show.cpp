#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>

int main()
{  
    cv::VideoCapture capture("csj.mp4");
    int frame_num = capture.get(cv::CAP_PROP_FRAME_COUNT);
    cv::Mat temp;
    std::string img_filename_read;

    cv::waitKey(1000);

    for (int i = 0; i < frame_num; ++i)
    {
        img_filename_read = "csj_OTSU/" + std::to_string(i) + ".jpg";//获取图像
        temp = cv::imread(img_filename_read,0);
        cv::resize(temp, temp,cv::Size(96,54));

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
        cv::waitKey(38);
        //system("clear");
        std::cout << "\033[2J";
    }

    capture.release();

    return 0;
}