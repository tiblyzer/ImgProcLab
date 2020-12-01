#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <string>

void loadImg(cv::Mat& img,std::string& path,int mode) 
{
	img = cv::imread(path, mode);
}

void correctImg(cv::Mat& img, cv::Mat& result)
{
	cv::Mat blurred, blurred2, sharped,contrasted, splitted[3];

	if (img.type() == CV_8UC3) {
		cv::split(img, splitted);

		for (int i = 0; i < 3; ++i)
			cv::equalizeHist(splitted[i], splitted[i]);

		cv::merge(splitted, 3, result);
	}

	if (img.type() == CV_8UC1) {
		cv::equalizeHist(img, result);
	}
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

	loadImg(img,path,1);
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

void colorModifyText(cv::Mat& img, cv::Mat& result, int color)
{
	result.create(img.size(), CV_8UC3);
	
	for (int i = 0; i < img.rows; ++i) {
		for (int j = 0; j < img.cols; ++j) {
			cv::Vec3b pixelgroup;
			
			
			if (img.at<uchar>(i, j) < 20) {
				pixelgroup[0] = color;
				pixelgroup[1] = 0;
				pixelgroup[2] = 255;
			}
			else {
				pixelgroup[0] =180;
				pixelgroup[1] =255;
				pixelgroup[2] =255;
			}
			result.at<cv::Vec3b>(i, j) = pixelgroup;
		}
	}
}

void task_2()
{
	cv::Mat img, filtered;
	std::string path;

	std::cout << "Image Path: ";
	std::cin >> path;

	loadImg(img, path,0);
	correctImg(img, filtered);

	imshow("filtered", filtered);
	cv::waitKey();

	cv::Mat thresholded;
	int blockSize = 5;

	cv::adaptiveThreshold(img, thresholded, 255, cv::ADAPTIVE_THRESH_MEAN_C, cv::THRESH_BINARY, blockSize, 2);

	cv::Mat modified;
	int color;

	std::cout << "Color: ";
	std::cin >> color;

	colorModifyText(thresholded, modified, color);


	imshow("modified", modified);
	cv::waitKey();

	std::vector<int> formatParameters_jpg;

	formatParameters_jpg.push_back(cv::IMWRITE_JPEG_QUALITY);
	formatParameters_jpg.push_back(92);

	cv::imwrite("out.jpg", modified, formatParameters_jpg);
}

void task_3()
{

}

int main()
{
	//task_1();
	task_2();
	return 0;
}