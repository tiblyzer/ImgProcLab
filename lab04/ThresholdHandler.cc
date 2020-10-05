#include "ThresholdHandler.hh"
#include "opencv_headers.hh"

void ThresholdHandler::demoSimpleThreshold()
{
	cv::Mat Img = cv::imread("rose_gray_noised.jpg");
	cv:imshow("origin", Img);
	int thresh_value = 50;

	cv::Mat thresh[NumberofSimpleThreshModes];

	for (int i = 0; i < NumberofSimpleThreshModes; ++i) {
		switch (i) {
		case SimpleThreshMode::Binary: {
			cv::threshold(Img, thresh[SimpleThreshMode::Binary], thresh_value, 255, cv::THRESH_BINARY);
			cv::imshow("Binary", thresh[SimpleThreshMode::Binary]);
			break;
		}
		case SimpleThreshMode::Binary_inv: {
			cv::threshold(Img, thresh[SimpleThreshMode::Binary_inv], thresh_value, 255, cv::THRESH_BINARY_INV);
			cv::imshow("Binary_inv", thresh[SimpleThreshMode::Binary_inv]);
			break;
		}
		case SimpleThreshMode::Trunc: {
			cv::threshold(Img, thresh[SimpleThreshMode::Trunc], thresh_value, 255, cv::THRESH_TRUNC);
			cv::imshow("Trunc", thresh[SimpleThreshMode::Trunc]);
			break;
		}
		case SimpleThreshMode::Tozero: {
			cv::threshold(Img, thresh[SimpleThreshMode::Tozero], thresh_value, 255, cv::THRESH_TOZERO);
			cv::imshow("Tozero", thresh[SimpleThreshMode::Tozero]);
			break;
		}
		case SimpleThreshMode::Tozero_inv: {
			cv::threshold(Img, thresh[SimpleThreshMode::Tozero_inv], thresh_value, 255, cv::THRESH_TOZERO_INV);
			cv::imshow("Tozero_inv", thresh[SimpleThreshMode::Tozero_inv]);
			break;
		}
		default: {
			break;
		}
		}	
	}

	cv::Mat thresh_with_operator = Img > thresh_value;

	cv::Mat masked, masked_with_operator;
	cv::bitwise_and(Img, thresh[SimpleThreshMode::Binary], masked);
	cv::bitwise_and(Img, thresh_with_operator, masked_with_operator);
	cv::imshow("masked", masked);
	cv::imshow("masked_with_operator", masked_with_operator);
}

void ThresholdHandler::demoGlobalThreshold()
{
	cv::Mat Img = cv::imread("rose_gray.jpg",0);
	cv:imshow("origin", Img);
	cv::Mat thresh;
	
	cv::threshold(Img, thresh, 0,255,cv::THRESH_BINARY | cv::THRESH_OTSU);
	cv::imshow("Otsu", thresh);
}

void ThresholdHandler::demoAdaptiveThreshold()
{
	cv::Mat Img = cv::imread("text.png",0);
	cv::Mat thresh;
	int blockSize = 5;

	cv::adaptiveThreshold(Img, thresh, 255, cv::ADAPTIVE_THRESH_MEAN_C, cv::THRESH_BINARY,blockSize,2);
	cv:imshow("origin", Img);
	cv::imshow("thresh", thresh);
}