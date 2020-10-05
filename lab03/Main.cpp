#include "BasicComponents.hh"
#include "MatHandler.hh"
#include "MatBasics.hh"
#include "ColorSpaces.hh"
#include "FilterHandler.hh"
#include "ThresholdHandler.hh"
#include "CropHandler.hh"
#include "MorphologyHandler.hh"

int size = 1;
int size_limit = 20;
Image test;
cv::Mat boxResult;


static void on_trackbar(int, void*)
{
	if (size > 0) {
		cv::boxFilter(test, boxResult, -1, cv::Size(size, size));
		cv::imshow("BoxFilter", boxResult);
	}
}


int main()
{
	
	FilterHandler filterHandler;
	filterHandler.demoBoxFilter();
	filterHandler.demoGaussianFilter();
	filterHandler.demoMedianFilter();
	filterHandler.demoHistoEqualize();
	filterHandler.demoRGBHistoEqualize();
	return 0;
}