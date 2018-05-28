//功能：将连续图片合成视频AVI
//注意：检查路径是否存在空格，否则影响结果
//注意：根据文件名设置循环，何时开始循环
#include<opencv2/opencv.hpp>
#include<iostream>


cv::VideoWriter writer;
using namespace std;
using namespace cv;

int main()
{
    Mat src=imread("/Users/arcstone_mems_108/Desktop/result/自动抽核/次靠前/3/1.jpg",1);
    if(!src.data)
    {
        cout<<"buxinga!"<<endl;
    }
    char image_name[200];
    int isColor = 1;
    int fps = 5;
    int frameWidth = src.cols;
    int frameHeight = src.rows;

    writer = VideoWriter("/Users/arcstone_mems_108/Desktop/result/自动抽核/次靠前/3/test_1_3.avi",CV_FOURCC('M','J','P','G'), fps,
                         Size(frameWidth, frameHeight), isColor);

    cout << "info:" << endl
         << "ff.avi" << endl
         << "Size:" << frameWidth << "*" << frameHeight << endl
         << "fps:" << fps << endl;


    for (int i = 1; i < 1000; i++)
    {
        sprintf(image_name, "/Users/arcstone_mems_108/Desktop/result/自动抽核/次靠前/3/%d.jpg", i);
        src = imread(image_name, 1);
        if (src.empty())
        {
            cout<<" 全部图像加载完成！";
            break;
        }
        imshow("【src】", src);
        waitKey(5);
        writer.write(src);
    }
}