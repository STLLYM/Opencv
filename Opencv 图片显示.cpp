#include <iostream>
#include <opencv2/highgui/highgui.hpp>
using namespace  std;
using namespace  cv;
int main() {
    Mat img = imread("C:\\Users\\Administrator\\Desktop\\hehe.jpg");//ͼƬ·�����룬·��Ϊ�Լ�ȷ��
    if (img.empty()) {
        cout << "Error��" << endl;
        return -1;
    }//����ṹΪ���δ����ͼƬ�����Error
    namedWindow("picture",WINDOW_FULLSCREEN);//��߲������п��ޣ�ֻ���Ƿ�ȫ������ͼ
    cvResizeWindow("picture",800,500);//�ϱߵ��Ҳ����Ϊͼʾ����Ϊ0ʱ�����ɸ��й涨��ʾ���ڴ�С
    imshow("picture",img);//չʾͼƬ
    waitKey();//�ȴ����������֮�����
    return 0;//���أ��˳�
}