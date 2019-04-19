#include <fstream>
#include <opencv2/core/ocl.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/stitching.hpp>
#include <iostream>
using namespace cv;
using namespace std;

vector<Mat> imgs; //保存拼接的原始图像向量

int main() {
    VideoCapture video("C:\\Users\\Administrator\\Desktop\\1.mp4");
    if (!video.isOpened()) {
        printf("can not open ...\n");
        return -1;
    }
    Mat frame;
    //导入拼接图像
    int i = 0, k = 0;
    while (1) {//读取图像路径
        i++;
        video >> frame;
        if (frame.empty()) {
            cout << "Can't read image " << "\n" << endl;
            break;
        }

        if (!(i % 90)) {
            k++;
            char imgName[10];
            sprintf(imgName, "%d.jpg", k);//给每张图片命名
            imwrite(imgName, frame);
            //imshow("Frame", frame);
        }

        //imgs.push_back(frame);
        char c = (char) waitKey(25);
        if (c == 27)
            break;


    }

    Mat img1;
    int j, k=4;
    for (j = k; j; j--) {
        char imgName[10];
        sprintf(imgName, "%d.jpg", j);
        cout << "完成" << imgName << endl;
        Mat img1 = imread(imgName);

        if (img1.empty()) {
            cout << "Can't read image" << endl;
            return -1;
        }
        imshow("q", img1);
        imgs.push_back(img1);
        if(j==1)
            break;
    }
    ocl::setUseOpenCL(true);
    Stitcher stitcher = Stitcher::createDefault();
    // 使用 stitch 函数进行拼接
    Mat pano;
    Stitcher::Status status = stitcher.stitch(imgs, pano);
    if (status != Stitcher::OK) //判断拼接是否成功
    {
        cout << "Can't stitch images, error code = " << int(status) << endl;
        return -1;
    }
    imwrite("全景拼接.jpg", pano);
    return 0;
}
