#pragma once

#include "opencv_headers.hh"

class MatBasics {
public:
	void demoOpenCV();
private:
	void demoImageIO();
	void demoMatCreate();
	void demoMatInfo();
	void demoMatMemory();
	void demoMatMethods();
	void demoIterateMat();
	void plotMat(cv::Mat& M);
};


