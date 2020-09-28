#include "ColorSpaces.hh"
#include "opencv_headers.hh"

void ColorSpaces::demoConvertRGBToGray()
{
	cv::Mat I = cv::imread("test.jpg", 1);
	cv::Mat gray(I.size(), CV_8UC1);

	for (int i = 0; i < I.rows; ++i) {
		for (int j = 0; j < I.cols; ++j) {
			cv::Vec3b currentPixelGroup = I.at<cv::Vec3b>(i, j);
			gray.at<uchar>(i, j) = currentPixelGroup[ChannelIndexRGB::BLUE] * 0.07 + 
				currentPixelGroup[ChannelIndexRGB::GREEN] * 0.72 +
				currentPixelGroup[ChannelIndexRGB::RED] * 0.21;
		}
	}

	cv::imshow("Gray", gray);
	cv::waitKey();
}

void ColorSpaces::demoConvertColorSpaces()
{
	cv::Mat I = cv::imread("test.jpg", 1);
	cv::Mat gray, hsv;

	cv::cvtColor(I, gray, cv::COLOR_RGB2GRAY);
	cv::cvtColor(I, hsv, cv::COLOR_RGB2HSV);
}

void ColorSpaces::demoCopyColorChannels()
{
	cv::Mat I = cv::imread("test.jpg", 1);
	cv::Mat I2(I.size(), CV_8UC3);

	for (int i = 0; i < I.rows; ++i) {
		for (int j = 0; j < I.cols; ++j) {
			cv::Vec3b currentPixelGroup = I.at<cv::Vec3b>(i, j);
			currentPixelGroup[ChannelIndexRGB::GREEN] = 0;
			currentPixelGroup[ChannelIndexRGB::RED] = 0;

			I2.at<cv::Vec3b>(i, j) = currentPixelGroup;
		}
	}

	cv::imshow("BlueChannel", I2);
	cv::waitKey();

}

void ColorSpaces::demoModifyColorChannelsRGB()
{
	cv::Mat I = cv::imread("test.jpg", 1);
	cv::Mat I2(I.size(), CV_8UC3);

	uchar modifyValueB = -50;
	uchar modifyValueG = +20;
	uchar modifyValueR = -10;

	for (int i = 0; i < I.rows; ++i) {
		for (int j = 0; j < I.cols; ++j) {
			cv::Vec3b currentPixelGroup = I.at<cv::Vec3b>(i, j);
			checkChannelOverflow(currentPixelGroup[ChannelIndexRGB::BLUE],modifyValueB,ChannelLimits::RGB_B);
			checkChannelOverflow(currentPixelGroup[ChannelIndexRGB::GREEN], modifyValueG,ChannelLimits::RGB_G);
			checkChannelOverflow(currentPixelGroup[ChannelIndexRGB::RED], modifyValueR, ChannelLimits::RGB_R);
			I2.at<cv::Vec3b>(i, j) = currentPixelGroup;
		}
	}

	cv::imshow("Modified", I2);
	cv::waitKey();
}

void ColorSpaces::demoModifyColorTypeHSV()
{
	cv::Mat I = cv::imread("test.jpg", 1);
	cv::Mat I2(I.size(), CV_8UC3);
	cv::Mat I_converted, I_converted2;
	uchar modifyValue = -100;
	int colorModifyRange_min = 150;
	int colorModifyRange_max = 179;

	cv::cvtColor(I, I_converted, cv::COLOR_RGB2HSV);
	
	for (int i = 0; i < I.rows; ++i) {
		for (int j = 0; j < I.cols; ++j) {
			cv::Vec3b currentPixelGroup = I_converted.at<cv::Vec3b>(i, j);
			
			if ((currentPixelGroup[ChannelIndexHSV::HUE] >= colorModifyRange_min) && 
				(currentPixelGroup[ChannelIndexHSV::HUE] <= colorModifyRange_max))
			{
				//currentPixelGroup[ChannelIndexHSV::VALUE] += 30;
				checkChannelOverflow(currentPixelGroup[ChannelIndexHSV::SATURATION], modifyValue, ChannelLimits::HSV_V);
			}

			I2.at<cv::Vec3b>(i, j) = currentPixelGroup;
		}
	}

	cv::cvtColor(I2, I_converted2, cv::COLOR_HSV2RGB);
	cv::imshow("Origin", I);
	cv::imshow("Modified", I_converted2);
	cv::waitKey();
}


void ColorSpaces::checkChannelOverflow(uchar& channelValue, uchar n,uchar LIMIT)
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