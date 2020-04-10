// PaintStraightLine.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <opencv.hpp>
using namespace cv;
using namespace std;

int main()
{
	cv::Mat dstMat;
	cv::Mat	srcMat = cv::imread("E:\\课程\\大二下\\数字图像处理\\20200410.png",0);
	cv::Mat CannyMat;
	Canny(srcMat, CannyMat, 150, 200);

	//cv::Mat lineMat;
	//cv::HoughLines(CannyMat, lineMat,1, CV_PI / 180,2);


	std::vector<cv::Vec2f> lines;
	cv::HoughLines(CannyMat, lines,1, CV_PI / 180,100);
	std::vector<cv::Vec2f>::iterator it = lines.begin();

	//绘制直线参考代码
	for (; it != lines.end(); ++it)
	{
		float rho = (*it)[0], theta = (*it)[1];
		cv::Point pt1, pt2;
		double a = cos(theta);
		double b = sin(theta);
		double x0 = a * rho;
		double y0 = b * rho;
		pt1.x = cv::saturate_cast<int>(x0 + 1000 * (-b));
		pt1.y = cv::saturate_cast<int>(y0 + 1000 * (a));
		pt2.x = cv::saturate_cast<int>(x0 - 1000 * (-b));
		pt2.y = cv::saturate_cast<int>(y0 - 1000 * (a));
		cv::line(srcMat, pt1, pt2, cv::Scalar(0, 0, 255), 1, CV_AA);
	}


	imshow("srcMat", srcMat);
	imshow("CanntMat", CannyMat);
	waitKey(0);
    //std::cout << "Hello World!\n";
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
