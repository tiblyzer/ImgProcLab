#pragma once

#include "opencv_headers.hh"

struct CropParameters {
	int x0;
	int y0;
	int size;
	int ratio_x;
	int ratio_y;

	CropParameters(int p_x0, int p_y0, int p_size, int p_ratio_x, int p_ratio_y) :
		x0(p_x0), y0(p_y0), size(p_size), ratio_x(p_ratio_x), ratio_y(p_ratio_y) {}

	CropParameters(const CropParameters&) = default;

};

struct Point {
	int x;
	int y;
};

struct MaskRegion {
	Point start;
	Point end;
	Point length;
};

class CropHandler
{
public:
	void demoCropping();
private:
	void performCrop(cv::Mat& input, cv::Mat& output, MaskRegion& region);
	MaskRegion calculateMaskRegion(CropParameters parameters);
};

