#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;

// ����ȫ��ͼƬMat����
Mat bgImage;

// ��������
void Lines();
void rectangle();
void Ellipse();
void circle();
void randomLineDemo();

int main(int argc, char** argv){
	// ������״������

	// ��ȡ����ͼƬ

	bgImage = imread("D:/OpenCVProject/day1210/������״������/������״������/background.jpg");

	// �жϱ���ͼƬ�Ƿ����
	if (!bgImage.data)
	{
		printf("could not load image\n");
		return -1;
	}

	// ��������߶κ���
	Lines();
	rectangle();
	Ellipse();
	circle();
	//randomLineDemo();
	/*
		img,				�����Ƶ�ͼ��
		text,				�����Ƶ�����
		origin,				�ı�������½�
		fontFace,			���� (��cv::FONT_HERSHEY_PLAIN)
		fontScale,			�ߴ����ӣ�ֵԽ������Խ��
		color,				��������ɫ��RGB��
		thickness			�������
		lineType			���ͣ�4�����8����Ĭ��8����
		bottomLeftOrigin	true='origin at lower left'

	*/
	putText(bgImage, "Hello OpenCV", Point(30, 30), CV_FONT_HERSHEY_COMPLEX, 1.0, Scalar(12, 23, 200), 3, 8);


	// չʾ�������ͼƬ
	imshow("handled image", bgImage);
	waitKey(0);
	return 0;
}

void Lines(){
	// ����߶�

	// ������ʼ��p1�����꣬���������p2�����꣬�����߶ε���ɫ
	Point p1 = Point(20, 30);
	Point p2 = Point(400, 300);
	Scalar color = Scalar(255, 0, 0);
	// ����line����ʵ������߶�
	/*
		void line(Mat& img, Point pt1, Point pt2, const Scalar& color, int thickness=1, int lineType=8, int shift=0)
		img: Ҫ�����߶ε�ͼ��
		pt1: �߶ε���㡣
		pt2: �߶ε��յ㡣
		color: �߶ε���ɫ��ͨ��һ��Scalar�����塣
		thickness: �����Ŀ�ȡ�
		lineType: �߶ε����͡�����ȡֵ8�� 4�� ��CV_AA�� �ֱ����8�ڽ������ߣ�4�ڽ������ߺͷ���������ߡ�Ĭ��ֵΪ8�ڽӡ�Ϊ�˻�ø��õ�Ч������ѡ��CV_AA(�����˸�˹�˲�)��
		shift: �����С����λ����
	*/
	line(bgImage, p1, p2, color, 1, LINE_8);
}

void rectangle(){
	// ��Ӿ���

	// ����������ϽǶ�������꣬���εĿ�͸�
	/*
		Rect()��4������
		���ε����ϽǶ����x���� 
		���ε����ϽǶ����y����
		���εĿ� 
		���εĸ� 
	*/
	Rect rect = Rect(50, 50, 200, 300);

	// ������ε���ɫ
	Scalar color = Scalar(0, 255, 0);

	// ����rectangle��������Ӿ���
	/*		
		void rectangle(InputOutputArray img, Point pt1, Point pt2,const Scalar& color, int thickness = 1,int lineType = LINE_8, int shift = 0);
		img			ͼ��.
		pt1			���ε�һ�����㡣
		pt2			���ζԽ����ϵ���һ������
		color		������ɫ (RGB) �����ȣ��Ҷ�ͼ�� ��(grayscale image����
		thickness	��ɾ��ε������Ĵ�ϸ�̶ȡ�ȡ��ֵʱ���� CV_FILLED���������������ɫ�ʵľ��Ρ�
		line_type	���������͡���cvLine������
		shift		������С����λ����
	*/
	rectangle(bgImage, rect, color, 2, LINE_8);
}

void Ellipse(){
	// ��Բ

	// ������Բ��ɫ
	Scalar color = Scalar(0, 255, 0);

	// ����ellipse���������Բ
	/*
		void cvEllipse( CvArr* img, CvPoint center, CvSize axes, double angle,double start_angle, double end_angle, CvScalar color,int thickness=1, int line_type=8, int shift=0 );
		img			ͼ��
		center		��ԲԲ�����ꡣ
		axes		��ĳ��ȡ�
		angle		ƫת�ĽǶȡ�
		start_angle	Բ����ʼ�ǵĽǶȡ�.
		end_angle	Բ���ս�ǵĽǶȡ�
		color		��������ɫ��
		thickness	�����Ĵ�ϸ�̶ȡ�
		line_type	����������,��CVLINE��������
		shift		Բ������������ľ���
	*/
	ellipse(bgImage, Point(bgImage.cols / 2, bgImage.rows / 2), Size(bgImage.cols / 4, bgImage.rows / 8), 90, 0, 360, color, 2, LINE_8);
}

void circle(){
	// Բ

	// ����Ԫ����ɫ
	Scalar color = Scalar(0, 255, 255);

	// ����Բ����������
	Point center = Point(bgImage.cols / 2, bgImage.rows / 2);

	// ����circle���������Բ
	/*
		void cvCircle( CvArr* img, CvPoint center, int radius, CvScalar color,int thickness=1, int line_type=8, int shift=0 );
		img			ͼ��
		center		Բ�����ꡣ
		radius		Բ�εİ뾶��
		color		��������ɫ��
		thickness	�������������ʾ���Բ�������Ĵ�ϸ�̶ȡ����򣬱�ʾԲ�Ƿ���䡣
		line_type	���������͡��� cvLine ������
		shift		Բ�������Ͱ뾶ֵ��С����λ����
	*/
	circle(bgImage, center, 150, color, 2, 8);
}

void randomLineDemo(){
	// �������߶�

	// �������������
	RNG rng(12345);

	// ������
	Point pt1;
	Point pt2;

	// ����ͼƬ
	Mat bg = Mat::zeros(bgImage.size(), bgImage.type());
	namedWindow("random line demo", CV_WINDOW_AUTOSIZE);

	// ���������
	for (int i = 0; i < 100000; i++) {
		pt1.x = rng.uniform(0, bgImage.cols);
		pt2.x = rng.uniform(0, bgImage.cols);
		pt1.y = rng.uniform(0, bgImage.rows);
		pt2.y = rng.uniform(0, bgImage.rows);
		Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
		if (waitKey(50) > 0) {
			break;
		}
		line(bg, pt1, pt2, color, 1, 8);
		imshow("random line demo", bg);
	}
}
