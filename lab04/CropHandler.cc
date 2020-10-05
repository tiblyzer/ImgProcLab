#include "CropHandler.hh"

void CropHandler::demoCropping()
{
	cv::Mat Img = cv::imread("kacsa.jpg", 0);
	cv::Mat cropped;
	CropParameters parameters(100, 100, 1000, 5, 7);
	MaskRegion cropRegion = calculateMaskRegion(parameters);

	performCrop(Img, cropped, cropRegion);
	cv::imshow("origin", Img);
	cv::imshow("cropped", cropped);
}

void CropHandler::performCrop(cv::Mat& input, cv::Mat& output, MaskRegion& region)
{
	output.create(region.length.x, region.length.y, input.type());

	for (int i = 0; i < region.length.x; ++i) {
		for (int j = 0; j < region.length.y; ++j) {
			output.at<uchar>(i, j) = input.at<uchar>(region.start.x + i, region.start.y + j);
		}
	}
}

MaskRegion CropHandler::calculateMaskRegion(CropParameters parameters)
{
	MaskRegion newRegion;
	int ratioUnit;

	ratioUnit = (double)parameters.size / ((double)parameters.ratio_x + (double)parameters.ratio_y);
	newRegion.start.x = parameters.x0;
	newRegion.start.y = parameters.y0;
	newRegion.length.x = ratioUnit * parameters.ratio_x;
	newRegion.length.y = ratioUnit * parameters.ratio_y;

	newRegion.end.x = newRegion.start.x + newRegion.length.x;
	newRegion.end.y = newRegion.start.y + newRegion.length.y;

	return newRegion;
}