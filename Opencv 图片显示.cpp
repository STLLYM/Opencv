#include <iostream>
#include <opencv2/highgui/highgui.hpp>
using namespace  std;
using namespace  cv;
int main() {
    Mat img = imread("C:\\Users\\Administrator\\Desktop\\hehe.jpg");//图片路径引入，路径为自己确定
    if (img.empty()) {
        cout << "Error好" << endl;
        return -1;
    }//这个结构为如果未读到图片者输出Error
    namedWindow("picture",WINDOW_FULLSCREEN);//后边参数可有可无，只是是否全屏播放图
    cvResizeWindow("picture",800,500);//上边的右侧参数为图示或者为0时，可由该行规定显示窗口大小
    imshow("picture",img);//展示图片
    waitKey();//等待按键后进行之后操作
    return 0;//返回，退出
}