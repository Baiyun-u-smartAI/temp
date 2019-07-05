

#include <opencv2/core/core.hpp>

#include <opencv2/imgcodecs.hpp>

#include <opencv2/highgui/highgui.hpp>

#include <iostream>

#include <string>

using namespace cv;

using namespace std;

int main() {

    string imageName("E:\\1.jpg"); // 图片在电脑中的绝对地址

    Mat image;//Mat是OpenCV最基本的数据结构，这是定义一个图像矩阵类型

    image = imread(imageName.c_str(), IMREAD_COLOR);//读入图片数据

    if (image.empty())//读取失败时

    {

        cout << "Could not open or find the image" << std::endl;

        return -1;

    }

    namedWindow("Display window", WINDOW_AUTOSIZE); // 创建一个窗口

    imshow("Display window", image);                // 在窗口中显示图片

    waitKey(0); // 等待一次按键，程序结束

    return 0;

}
