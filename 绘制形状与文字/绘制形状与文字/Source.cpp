#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;

// 定义全局图片Mat对象
Mat bgImage;

// 函数申明
void Lines();
void rectangle();
void Ellipse();
void circle();
void randomLineDemo();

int main(int argc, char** argv){
	// 绘制形状与文字

	// 读取背景图片

	bgImage = imread("D:/OpenCVProject/day1210/绘制形状与文字/绘制形状与文字/background.jpg");

	// 判断背景图片是否存在
	if (!bgImage.data)
	{
		printf("could not load image\n");
		return -1;
	}

	// 调用添加线段函数
	Lines();
	rectangle();
	Ellipse();
	circle();
	//randomLineDemo();
	/*
		img,				待绘制的图像
		text,				待绘制的文字
		origin,				文本框的左下角
		fontFace,			字体 (如cv::FONT_HERSHEY_PLAIN)
		fontScale,			尺寸因子，值越大文字越大
		color,				线条的颜色（RGB）
		thickness			线条宽度
		lineType			线型（4邻域或8邻域，默认8邻域）
		bottomLeftOrigin	true='origin at lower left'

	*/
	putText(bgImage, "Hello OpenCV", Point(30, 30), CV_FONT_HERSHEY_COMPLEX, 1.0, Scalar(12, 23, 200), 3, 8);


	// 展示处理过的图片
	imshow("handled image", bgImage);
	waitKey(0);
	return 0;
}

void Lines(){
	// 添加线段

	// 定义起始点p1的坐标，定义结束点p2的坐标，定义线段的颜色
	Point p1 = Point(20, 30);
	Point p2 = Point(400, 300);
	Scalar color = Scalar(255, 0, 0);
	// 调用line方法实现添加线段
	/*
		void line(Mat& img, Point pt1, Point pt2, const Scalar& color, int thickness=1, int lineType=8, int shift=0)
		img: 要绘制线段的图像。
		pt1: 线段的起点。
		pt2: 线段的终点。
		color: 线段的颜色，通过一个Scalar对象定义。
		thickness: 线条的宽度。
		lineType: 线段的类型。可以取值8， 4， 和CV_AA， 分别代表8邻接连接线，4邻接连接线和反锯齿连接线。默认值为8邻接。为了获得更好地效果可以选用CV_AA(采用了高斯滤波)。
		shift: 坐标点小数点位数。
	*/
	line(bgImage, p1, p2, color, 1, LINE_8);
}

void rectangle(){
	// 添加矩形

	// 定义矩形左上角定点的坐标，矩形的宽和高
	/*
		Rect()的4个参数
		方形的左上角顶点的x坐标 
		方形的左上角顶点的y坐标
		方形的宽 
		方形的高 
	*/
	Rect rect = Rect(50, 50, 200, 300);

	// 定义矩形的颜色
	Scalar color = Scalar(0, 255, 0);

	// 调用rectangle方法，添加矩形
	/*		
		void rectangle(InputOutputArray img, Point pt1, Point pt2,const Scalar& color, int thickness = 1,int lineType = LINE_8, int shift = 0);
		img			图像.
		pt1			矩形的一个顶点。
		pt2			矩形对角线上的另一个顶点
		color		线条颜色 (RGB) 或亮度（灰度图像 ）(grayscale image）。
		thickness	组成矩形的线条的粗细程度。取负值时（如 CV_FILLED）函数绘制填充了色彩的矩形。
		line_type	线条的类型。见cvLine的描述
		shift		坐标点的小数点位数。
	*/
	rectangle(bgImage, rect, color, 2, LINE_8);
}

void Ellipse(){
	// 椭圆

	// 定义椭圆颜色
	Scalar color = Scalar(0, 255, 0);

	// 调用ellipse方法添加椭圆
	/*
		void cvEllipse( CvArr* img, CvPoint center, CvSize axes, double angle,double start_angle, double end_angle, CvScalar color,int thickness=1, int line_type=8, int shift=0 );
		img			图像。
		center		椭圆圆心坐标。
		axes		轴的长度。
		angle		偏转的角度。
		start_angle	圆弧起始角的角度。.
		end_angle	圆弧终结角的角度。
		color		线条的颜色。
		thickness	线条的粗细程度。
		line_type	线条的类型,见CVLINE的描述。
		shift		圆心坐标点和数轴的精度
	*/
	ellipse(bgImage, Point(bgImage.cols / 2, bgImage.rows / 2), Size(bgImage.cols / 4, bgImage.rows / 8), 90, 0, 360, color, 2, LINE_8);
}

void circle(){
	// 圆

	// 定义元的颜色
	Scalar color = Scalar(0, 255, 255);

	// 定义圆的中兴坐标
	Point center = Point(bgImage.cols / 2, bgImage.rows / 2);

	// 调用circle方法，添加圆
	/*
		void cvCircle( CvArr* img, CvPoint center, int radius, CvScalar color,int thickness=1, int line_type=8, int shift=0 );
		img			图像。
		center		圆心坐标。
		radius		圆形的半径。
		color		线条的颜色。
		thickness	如果是正数，表示组成圆的线条的粗细程度。否则，表示圆是否被填充。
		line_type	线条的类型。见 cvLine 的描述
		shift		圆心坐标点和半径值的小数点位数。
	*/
	circle(bgImage, center, 150, color, 2, 8);
}

void randomLineDemo(){
	// 随机添加线段

	// 用于生成随机数
	RNG rng(12345);

	// 点坐标
	Point pt1;
	Point pt2;

	// 背景图片
	Mat bg = Mat::zeros(bgImage.size(), bgImage.type());
	namedWindow("random line demo", CV_WINDOW_AUTOSIZE);

	// 生成随机数
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
