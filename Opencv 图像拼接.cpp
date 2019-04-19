#include <fstream>
#include <opencv2/core/ocl.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/stitching.hpp>
#include <iostream>
using namespace cv;
using namespace std;

vector<Mat> imgs; //����ƴ�ӵ�ԭʼͼ������

int main() {
    VideoCapture video("C:\\Users\\Administrator\\Desktop\\1.mp4");
    if (!video.isOpened()) {
        printf("can not open ...\n");
        return -1;
    }
    Mat frame;
    //����ƴ��ͼ��
    int i = 0, k = 0;
    while (1) {//��ȡͼ��·��
        i++;
        video >> frame;
        if (frame.empty()) {
            cout << "Can't read image " << "\n" << endl;
            break;
        }

        if (!(i % 90)) {
            k++;
            char imgName[10];
            sprintf(imgName, "%d.jpg", k);//��ÿ��ͼƬ����
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
        cout << "���" << imgName << endl;
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
    // ʹ�� stitch ��������ƴ��
    Mat pano;
    Stitcher::Status status = stitcher.stitch(imgs, pano);
    if (status != Stitcher::OK) //�ж�ƴ���Ƿ�ɹ�
    {
        cout << "Can't stitch images, error code = " << int(status) << endl;
        return -1;
    }
    imwrite("ȫ��ƴ��.jpg", pano);
    return 0;
}
