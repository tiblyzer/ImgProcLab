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
	/*MatHandler m;
	Image I1, I2;

	m.ReadImage(I1, std::string("C:\\Users\\kapusi\\Pictures\\rose_gray.jpg"));
	m.Create(I2, CV_8UC3);
	m.Release(I1);
	I2.create(7, 7, CV_8UC3);
	cv::imshow("rose", I2);
	cv::waitKey();*/
	test = cv::imread("C:\\Users\\kapusi\\Pictures\\paak.jpg");
	cv::Mat boxResult;
	cv::Mat gaussianResult;
	cv::Mat medianResult;
	cv::Mat unsharpResult;
	/*Image gray = cv::imread("C:\\Users\\kapusi\\Pictures\\rose.jpg");
	//cv::imshow("paak", test);

	Image test2,test3,test4;
	test2.create(test.size(), CV_8UC3);
	test3.create(test.size(), CV_8UC3);
	test4.create(gray.size(), CV_8U);*/

	//for (int i = 0; i < test.rows; ++i) {
	//	for (int j = 0; j < test.cols; ++j) {
	//		cv::Vec3b currentPixelGroup = test.at<cv::Vec3b>(i, j);
	//		float percentage = - 0.2;
	//		float ratio = 140 / 255;
	//		//int check = currentPixelGroup[1];

	//		//if (1)
	//		

	//		if ((currentPixelGroup[2] - 100) < 0) {
	//			currentPixelGroup[2];
	//		}
	//		else {
	//			currentPixelGroup[2] -= 100;
	//		}
	//		
	//		
	//		test2.at<cv::Vec3b>(i, j) = currentPixelGroup;
	//		//uchar currentPixel = test.at<uchar>(i, j);
	//		//test4.at<uchar>(i, j) = gray.at<uchar>(i, j);
	//	}
	//}
	//for (int i = 0; i < test.rows; ++i) {
	//	for (int j = 0; j < test.cols; ++j) {
	//		cv::Vec3b currentPixelGroup = test.at<cv::Vec3b>(i, j);
	//		uchar ratio = 140 / 255;
	//		float percentage = 0.4;
	//		//currentPixelGroup[2] *= 0.9;
	//		//test2.at<cv::Vec3b>(i, j) = test.at<cv::Vec3b>(i, j);
	//		
	//		//szinkivonas
	//		int check = currentPixelGroup[1];
	//		if ((check * (1 - percentage)) > 255) {
	//			currentPixelGroup[1] = 255;
	//		}
	//		else {
	//			currentPixelGroup[1] *= (1 - percentage);
	//		}
	//		check = currentPixelGroup[2];
	//		if ((check * (1 - percentage)) > 255) {
	//			currentPixelGroup[2] = 255;
	//		}
	//		else {
	//			currentPixelGroup[2] *= (1 - percentage);
	//		}
	//		//currentPixelGroup[1] *= (1 - percentage);
	//		//currentPixelGroup[1] *= (1- percentage*ratio);
	//		//currentPixelGroup[2] *= (1-percentage);
	//		test2.at<cv::Vec3b>(i, j) = currentPixelGroup;

	//		//fehergeyensuly
	//		// 5000k == (255,255,255) folotte sargat novelunk ( 0-255 , 255,255), alatta keket (255, 0-255, 0-255) az utolso ketto egyszerre vatozik!
	//		cv::Vec3b actualKelvin(255, 20, 20);
	//		cv::Vec3b currentPixelGroupK = test.at<cv::Vec3b>(i, j);

	//		for (int n = 0; n < 3; ++n) {
	//			int check = currentPixelGroupK[n];
	//			float ratio = (float)actualKelvin[n] / 255;
	//			if (check * ratio < 0) {
	//				currentPixelGroupK[n] = 0;
	//			}
	//			else {
	//				currentPixelGroupK[n] *= ratio;
	//			}
	//		}
	//		
	//		test3.at<cv::Vec3b>(i, j) = currentPixelGroupK;

	//	}
	//}
	//cv::imshow("pipi", test2);
	//cv::imshow("pipiK", test3);
	//cv::waitKey();
	//cv::imshow("testgray", test2);
	//cv::waitKey();
	MatBasics basics;
	ColorSpaces colorsHandler;
	FilterHandler filterHandler;
	ThresholdHandler thresholdHandler;
	CropHandler cropHandler;
	//basics.demoOpenCV();

	//colorsHandler.demoConvertRGBToGray();
	//colorsHandler.demoConvertColorSpaces();
	//colorsHandler.demoCopyColorChannels();
	//colorsHandler.demoModifyColorChannelsRGB();
	
	//colorsHandler.demoModifyColorTypeHSV();

	//cv::boxFilter(test, boxResult, -1, cv::Size(3,3));


	//cv::imshow("box", boxResult);
	//cv::namedWindow("BoxFilter", cv::WINDOW_AUTOSIZE); // Create Window
	//cv::createTrackbar("boxSize", "BoxFilter", &size, size_limit, on_trackbar);
	//on_trackbar(size, 0);
	
	//filterHandler.demoBoxFilter();
	/*filterHandler.demoGaussianFilter();
	filterHandler.demoMedianFilter();*/

	//*************************************
	///HOLNAP LEADNI
	//filterHandler.demoHistoEqualize();
	
	//filterHandler.demoRGBHistoEqualize();
	//**************************************

	//thresholdHandler.demoSimpleThreshold();
	//thresholdHandler.demoGlobalThreshold();
	//thresholdHandler.demoAdaptiveThreshold();
	//cropHandler.demoCropping();


	cv::waitKey(0);

}