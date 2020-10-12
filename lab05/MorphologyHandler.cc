#include "MorphologyHandler.hh"
#include "opencv_headers.hh"

void MorphologyHandler::demoDilation()
{
	cv::Mat Img = cv::imread("morp_test.png", 0);
	cv::Mat kernel = cv::Mat::ones(cv::Size(5, 5), CV_8UC1);
	cv::Mat dilated;

	cv::dilate(Img, dilated, kernel);

	cv::imshow("dilated",dilated);
	cv::waitKey(0);

}

void MorphologyHandler::demoErosion()
{
	cv::Mat Img = cv::imread("morp_test.png", 0);
	cv::Mat kernel = cv::Mat::ones(cv::Size(3, 3), CV_8UC1);
	cv::Mat eroded;

	cv::erode(Img, eroded, kernel);

	cv::imshow("eroded", eroded);
	cv::waitKey(0);
}

void MorphologyHandler::demoOpening()
{
	cv::Mat Img = cv::imread("morp_test_open.png", 0);
	cv::Mat kernel = cv::Mat::ones(cv::Size(3, 3), CV_8UC1);
	cv::Mat eroded,opened;

	cv::erode(Img, eroded, kernel);
	cv::dilate(eroded, opened, kernel);

	cv::imshow("opened", eroded);
	cv::waitKey(0);
}

void MorphologyHandler::demoClosing()
{
	cv::Mat Img = cv::imread("morp_test_closed.png", 0);
	cv::Mat kernel = cv::Mat::ones(cv::Size(7, 7), CV_8UC1);
	cv::Mat dilated, closed;

	cv::dilate(Img, dilated, kernel);
	cv::erode(dilated, closed, kernel);

	cv::imshow("closed", closed);
	cv::waitKey(0);
}