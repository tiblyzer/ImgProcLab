#include "FilterHandler.hh"

void FilterHandler::demoBoxFilter()
{
	boxParameter.Size.value = 1;
	boxParameter.Size.LIMIT = 10;
	imageIO.input = cv::imread("noisy_img.jpg", 0);
	cv::namedWindow("BoxFilter", cv::WINDOW_AUTOSIZE); // Create Window
	cv::createTrackbar("boxSize", "BoxFilter", &boxParameter.Size.value, boxParameter.Size.LIMIT, FilterHandler::boxCallBack,(void*)this);
}

void FilterHandler::demoGaussianFilter()
{
	gaussianParameter.Size.value = 1;
	gaussianParameter.Size.LIMIT = 10;
	gaussianParameter.Sigma.value = 5;
	gaussianParameter.Sigma.LIMIT = 100;

	imageIO.input = cv::imread("kacsa.jpg", 1);
	cv::namedWindow("GaussFilter", cv::WINDOW_AUTOSIZE); // Create Window
	cv::createTrackbar("kernelSize", "GaussFilter", &gaussianParameter.Size.value, gaussianParameter.Size.LIMIT, FilterHandler::gaussianCallBackSize, (void*)this);
	cv::createTrackbar("sigmaSize", "GaussFilter", &gaussianParameter.Sigma.value, gaussianParameter.Sigma.LIMIT, FilterHandler::gaussianCallBackSigma, (void*)this);
}

void FilterHandler::demoMedianFilter()
{
	medianParameter.Size.value = 1;
	medianParameter.Size.LIMIT = 10;

	imageIO.input = cv::imread("kacsa.jpg", 1);
	cv::namedWindow("MedianFilter", cv::WINDOW_AUTOSIZE); // Create Window
	cv::createTrackbar("kernelSize", "MedianFilter", &medianParameter.Size.value, medianParameter.Size.LIMIT, FilterHandler::medianCallBack, (void*)this);
}

void FilterHandler::demoHistoEqualize()
{
	imageIO.input = cv::imread("lov_contrast.png", 0);
	cv::Mat result;

	cv::equalizeHist(imageIO.input, imageIO.output);

	cv::imshow("low_contrast",imageIO.input);
	cv::imshow("equalized", imageIO.output);
	cv::waitKey();
}

void FilterHandler::demoRGBHistoEqualize()
{
	imageIO.input = cv::imread("rgb_low_contrast.jpg", 1);
	cv::Mat splitted[3], equalized[3];
	cv::Mat result;

	cv::split(imageIO.input, splitted);

	for(int i=0;i<3;++i)
		cv::equalizeHist(splitted[i], equalized[i]);

	cv::merge(equalized,3, result);
	cv::imshow("low_contrast", imageIO.input);
	cv::imshow("equalized", result);
	cv::waitKey();
}

void FilterHandler::demoHSVHistoEqualize()
{
	/*
	rgb->hsv
	split
	V csatornan equalizeHist
	0,1-es csatorna clone az ujba
	merge
	hsv->rgb
	*/
}

void FilterHandler::demoUnsharpFilter()
{

}

void FilterHandler::boxOnTrackBar()
{
	if (boxParameter.Size.value > 0) {
		cv::boxFilter(imageIO.input, imageIO.output, -1, cv::Size(boxParameter.Size.value, boxParameter.Size.value));
		cv::imshow("BoxFilter", imageIO.output);
	}
}

void FilterHandler::gaussianOnTrackBar()
{
	if ((gaussianParameter.Size.value % 2 )==1) {
		cv::GaussianBlur(imageIO.input, imageIO.output, cv::Size(gaussianParameter.Size.value, gaussianParameter.Size.value),gaussianParameter.Sigma.value);
		cv::imshow("GaussFilter", imageIO.output);
	}
}

void FilterHandler::medianOnTrackBar()
{
	if ((medianParameter.Size.value % 2) == 1) {
		cv::medianBlur(imageIO.input, imageIO.output, medianParameter.Size.value);
		cv::imshow("MedianFilter", imageIO.output);
	}
}

/*void FilterHandler::unsharpOnTrackBar()
{
	/*Mat blurred; double sigma = 1, threshold = 5, amount = 1;
	GaussianBlur(img, blurred, Size(), sigma, sigma);
	Mat lowContrastMask = abs(img - blurred) < threshold;
	Mat sharpened = img * (1 + amount) + blurred * (-amount);
	img.copyTo(sharpened, lowContrastMask);*/
//}