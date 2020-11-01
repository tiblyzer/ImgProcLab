#include <iostream>
#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"

void exercise_one()
{
	//read images
	cv::Mat Img_gray = cv::imread("rose_gray.jpg", 0);
	cv::Mat Img_rgb = cv::imread("kacsa.jpg", 1);
	cv::Mat kernel = cv::getStructuringElement(cv::MORPH_CROSS, cv::Size(3,3));

	//declare required Mat classes
	cv::Mat dilated_rgb, eroded_rgb, contures_rgb, dilated_gray, eroded_gray, contures_gray;

	//perform morphology operations
	cv::dilate(Img_gray, dilated_gray, kernel);
	cv::erode(Img_gray, eroded_gray, kernel);

	cv::dilate(Img_rgb, dilated_rgb, kernel);
	cv::erode(Img_rgb, eroded_rgb, kernel);

	//get contures
	contures_gray = dilated_gray - eroded_gray;
	contures_rgb = dilated_rgb - eroded_rgb;

	cv::imshow("contures gray", contures_gray);
	cv::imshow("contures rgb", contures_rgb);
	cv::waitKey(0);
}

void exercise_two()
{
	cv::Mat Img_gray = cv::imread("rose_gray.jpg", 0);
	cv::Mat kernel = cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(9, 9));
	cv::Mat eroded, opened, dilated, closed;

	cv::erode(Img_gray, eroded, kernel);
	cv::dilate(eroded, opened, kernel);

	cv::dilate(Img_gray, dilated, kernel);
	cv::erode(dilated, closed, kernel);

	cv::imshow("tophat", Img_gray - opened);
	cv::imshow("blackhat", closed - Img_gray);
	cv::waitKey(0);
}

void exercise_three()
{
	cv::Mat Img_rgb = cv::imread("kacsa.jpg", 1);
	cv::Mat kernel = cv::getStructuringElement(cv::MORPH_CROSS, cv::Size(5, 5));

	//declare required Mat classes
	cv::Mat dilated_rgb, eroded_rgb, contures_rgb,bolded;


	cv::dilate(Img_rgb, dilated_rgb, kernel);
	cv::erode(Img_rgb, eroded_rgb, kernel);

	//get contures
	contures_rgb = dilated_rgb - eroded_rgb;
	cv::addWeighted(Img_rgb, 0.5, contures_rgb, 0.5, 1,bolded);

	cv::imshow("bolded", bolded);
	cv::waitKey(0);
}

void exercise_four()
{
	cv::Mat Img_rgb = cv::imread("kacsa.jpg", 1);
	cv::Mat blurry,unsharped;

	cv::medianBlur(Img_rgb, blurry, 5);
	cv::addWeighted(Img_rgb, 2.5, blurry, -1.5, 1, unsharped);

	cv::imshow("unsharped", unsharped);
	cv::waitKey(0);
}

void exercise_five()
{
	cv::Mat Img = cv::imread("tennis.jpg", 1);
	cv::Mat objects(Img.size(), CV_8UC3), hsv,balls;
	cv::cvtColor(Img, hsv, cv::COLOR_RGB2HSV);

	uchar hue_ball_lower = 83;
	uchar hue_ball_upper = 90;
	
	uchar sat_ball_lower = 100;
	uchar sat_ball_upper = 255;

	uchar val_ball_lower = 100;
	uchar val_ball_upper = 255;

	uchar channel_hue = 0;
	uchar channel_sat = 1;
	uchar channel_val = 2;

	//std::cout << hsv;
	//cv::imshow("Img", Img);
	//cv::waitKey(0);

	for (int i = 0; i < Img.rows;++i) {
		for (int j = 0; j < Img.cols;++j) {
			cv::Vec3b pixelgroup = hsv.at<cv::Vec3b>(i, j);

			if ((pixelgroup[channel_hue] >= hue_ball_lower) &&
				(pixelgroup[channel_hue] <= hue_ball_upper) &&
				
				(pixelgroup[channel_sat] >= sat_ball_lower) &&
				(pixelgroup[channel_sat] <= sat_ball_upper) &&

				(pixelgroup[channel_val] >= val_ball_lower) &&
				(pixelgroup[channel_val] <= val_ball_upper)
				) 
			
			{
				objects.at<cv::Vec3b>(i, j) = hsv.at<cv::Vec3b>(i, j);
				//std::cout << hsv.at<cv::Vec3b>(i, j) << std::endl;
			}
		}
	}
	cv::cvtColor(objects, balls, cv::COLOR_HSV2RGB);

	cv::Mat dilated, eroded, opened;
	cv::Mat kernel_opened = cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(3, 3));
	cv::Mat kernel_conture = cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(5, 5));
	cv::erode(balls, eroded, kernel_opened);
	cv::dilate(eroded, opened, kernel_opened);

	cv::dilate(opened, dilated, kernel_conture);
	cv::erode(opened, eroded, kernel_conture);

	cv::imshow("contures", dilated - eroded);
	cv::waitKey(0);
}

void showHSVColors()
{
	cv::Mat channels[3];

	channels[0].create(50, 50, CV_8UC1);
	channels[1].create(50, 50, CV_8UC1);
	channels[2].create(50, 50, CV_8UC1);

	channels[0].setTo(cv::Scalar(100));
	channels[1].setTo(cv::Scalar(255));
	channels[2].setTo(cv::Scalar(0));
	cv::Mat color;
	cv::Mat hsv;

	cv::merge(channels, 3, color);
	cv::cvtColor(color, hsv, cv::COLOR_RGB2HSV);

	std::cout << hsv;
	cv::imshow("color",color);
	cv::waitKey(0);
}

int main()
{
	exercise_one();
	exercise_two();
	exercise_three();
	exercise_four();
	exercise_five();
	showHSVColors();

	return 0;
}