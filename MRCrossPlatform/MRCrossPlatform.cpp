#include "mrdir.h"
#include "mropencv.h"
#include "mrutil.h"
#include "fstream"
using namespace std;

void testImage()
{
	cv::Mat img = cv::imread("../opencv.png");
	cv::namedWindow("img", 0);
	cv::imshow("img", img);
	cv::waitKey();
}

void testCamera(int device=0)
{
	cv::VideoCapture capture(device);
	cv::Mat frame;
	while (1)
	{
		capture >> frame;
		if (!frame.data)
			break;
		cv::imshow("img", frame);
		cv::waitKey(1);
	}
}

void testVideo(const std::string &videoPath="../1.mov")
{
	cv::VideoCapture capture(videoPath);
	cv::Mat frame;
	int frame_count = 0;
	while (1)
	{
		capture >> frame;
		if (!frame.data)
			break;
		cout << frame_count << endl;
		cv::imshow("img", frame);
		cv::imwrite("test.jpg", frame);
		cv::waitKey(1);
		frame_count++;
	}
}
int main()
{
//	testImage();
//	testCamera();
	testVideo();
	return 0;
}