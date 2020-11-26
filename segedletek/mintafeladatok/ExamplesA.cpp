#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <string>

void loadImg(cv::Mat& img,std::string& path) 
{
	img = cv::imread(path, 1);
}

void correctImg(cv::Mat& img, cv::Mat& result)
{
	cv::Mat blurred, blurred2, sharped,contrasted, splitted[3];

	cv::split(img, splitted);

	for (int i = 0; i < 3; ++i)
		cv::equalizeHist(splitted[i], splitted[i]);

	cv::merge(splitted, 3, result);

	cv::GaussianBlur(result, blurred, cv::Size(5, 5), 3);
	cv::GaussianBlur(blurred, blurred2, cv::Size(7, 7), 1);

	cv::addWeighted(blurred, 2.5, blurred2, -2, 1, result);
}

void checkChannelOverflow(uchar& channelValue, uchar n, uchar LIMIT)
{
	if ((channelValue + n) > LIMIT) {
		channelValue = LIMIT;
	}

	else if (channelValue < n) {
		channelValue = 0;
	}

	else {
		channelValue += n;
	}
}

void exposition(cv::Mat& img, cv::Mat& result,int value)
{
	cv::cvtColor(img, result, cv::COLOR_BGR2HSV);

	for (int i = 0; i < img.rows; ++i) {
		for (int j = 0; j < img.cols; ++j) {
			cv::Vec3b currentPixelGroup = result.at<cv::Vec3b>(i, j);
			checkChannelOverflow(currentPixelGroup[2], value, 255);
			result.at<cv::Vec3b>(i, j) = currentPixelGroup;
		}
	}

	//cv::cvtColor(temp, result, cv::COLOR_HSV2RGB);
}

void colorModify(cv::Mat& img, cv::Mat& result, std::string colorType, double factor)
{
	img.copyTo(result);
	int range_min = 0;
	int range_max = 0;

	if (colorType == "red") {
		range_min = 0;
		range_max = 30;
	}

	if (colorType == "green") {
		range_min = 90;
		range_max = 120;
	}

	if (colorType == "blue") {
		range_min = 150;
		range_max = 180;
	}

	for (int i = 0; i < img.rows; ++i) {
		for (int j = 0; j < img.cols; ++j) {
			cv::Vec3b currentPixelGroup = img.at<cv::Vec3b>(i, j);
			checkChannelOverflow(currentPixelGroup[1], currentPixelGroup[1]*(1 + factor/100), 255);
			result.at<cv::Vec3b>(i, j) = currentPixelGroup;
		}
	}
}

void task_1()
{
	cv::Mat img,filtered,corrected;
	std::string path;

	std::cout << "Image Path: ";
	std::cin >> path;

	loadImg(img,path);
	correctImg(img, filtered);

	imshow("filtered", filtered);
	cv::waitKey();

	int value;

	std::cout << "Exposition correction factor: ";
	std::cin >> value;

	exposition(filtered, corrected, value * 33);

	cv::Mat modified;
	std::string colorType;
	double factor;

	std::cout << "Color: ";
	std::cin >> colorType;
	std::cout << "Modification factor: ";
	std::cin >> factor;

	colorModify(corrected, modified,colorType,factor);

	cv::cvtColor(modified, modified, cv::COLOR_HSV2BGR);

	imshow("modified", modified);
	cv::waitKey();

	std::vector<int> formatParameters_jpg;

	formatParameters_jpg.push_back(cv::IMWRITE_JPEG_QUALITY);
	formatParameters_jpg.push_back(85);

	cv::imwrite("out.jpg", modified, formatParameters_jpg);
}

void task_2()
{

}

int main()
{
	task_1();
	task_2();
	return 0;
}