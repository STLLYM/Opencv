#include <iostream>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace std;
int main() {
    VideoCapture video("C:\\Users\\Administrator\\Desktop\\cx.mp4");
    double  totalFramenumber = video.get(CV_CAP_PROP_FRAME_COUNT);
    cout<<"all have "<<totalFramenumber<<" frames"<<endl;//获取总帧数并显示

    while(1)
    {
        Mat frame;
        video >> frame;
        if (frame.empty())
        {
            cout<<"worry";
            break;
        }
        imshow("video",frame);
        waitKey(10);
    }
    Mat frame1,frame2,frame3,frame4,frame5,frame6;//定义共六个图然后每个分别取对应帧赋给图片
    video.set(CAP_PROP_POS_FRAMES,1);
    video>>frame1;
    namedWindow("1",0);
    cvResizeWindow("1",200,130);
    imshow("1",frame1);
    video.set(CAP_PROP_POS_FRAMES,135);
    video>>frame2;
    namedWindow("2",0);
    cvResizeWindow("2",200,130);
    imshow("2",frame2);
    video.set(CAP_PROP_POS_FRAMES,212);
    video>>frame3;
    namedWindow("3",0);
    cvResizeWindow("3",200,130);
    imshow("3",frame3);
    video.set(CAP_PROP_POS_FRAMES,273);
    video>>frame4;
    namedWindow("4",0);
    cvResizeWindow("4",200,130);
    imshow("4",frame4);
    video.set(CAP_PROP_POS_FRAMES,332);
    video>>frame5;
    namedWindow("5",0);
    cvResizeWindow("5",200,130);
    imshow("5",frame5);
    video.set(CAP_PROP_POS_FRAMES,395);
    video>>frame6;
    namedWindow("6",0);
    cvResizeWindow("6",200,130);
    imshow("6",frame6);
    waitKey();

    return 0;
}
