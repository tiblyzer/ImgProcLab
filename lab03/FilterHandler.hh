#pragma once

#include "std_headers_basic.hh"
#include "opencv_headers.hh"

template<typename T>
struct Parameter
{
	T value;
	T LIMIT;
};

struct BoxFilterParameter {
	Parameter<int> Size;
};

struct MedianFilterParameter {
	Parameter<int> Size;
};

struct GaussianFilterParameter {
	Parameter<int> Size;
	Parameter<int> Sigma;
};

struct UnsharpFilterParameter {
	Parameter<int> Sigma;
	Parameter<int> Threshold;
	Parameter<int> Amount;
};

struct FilterIO {
	cv::Mat input;
	cv::Mat output;
};

class FilterHandler
{
public:
	
	void demoBoxFilter();
	void demoGaussianFilter();
	void demoMedianFilter();
	void demoUnsharpFilter();
	void demoHistoEqualize();
	void demoRGBHistoEqualize();
	void demoHSVHistoEqualize();

	void setBoxSize(int value) {
		boxParameter.Size.value = value;
	}

	void setGaussianKernel(int size,int sigma) {
		if (size)  gaussianParameter.Size.value = size;
		if (sigma) gaussianParameter.Sigma.value = sigma;
	}

	void setMedianSize(int value) {
		if (value) medianParameter.Size.value = value;
	}

	void setUnsharpParameters(int sigma, int threshold, int amount) {
		if (sigma)     unsharpParameter.Sigma.value = sigma;
		if (threshold) unsharpParameter.Threshold.value = threshold;
		if (amount)    unsharpParameter.Amount.value = amount;
	}

private:
	static void boxCallBack(int value, void* object) {
		FilterHandler* box = (FilterHandler*)object;
		box->setBoxSize(value);
		box->boxOnTrackBar();
	}

	static void gaussianCallBackSize(int value, void* object) {
		FilterHandler* gauss = (FilterHandler*)object;
		gauss->setGaussianKernel(value,0);
		gauss->gaussianOnTrackBar();
	}

	static void gaussianCallBackSigma(int value, void* object) {
		FilterHandler* gauss = (FilterHandler*)object;
		gauss->setGaussianKernel(0, value);
		gauss->gaussianOnTrackBar();
	}

	static void medianCallBack(int value, void* object) {
		FilterHandler* median = (FilterHandler*)object;
		median->setMedianSize(value);
		median->medianOnTrackBar();
	}

	static void unsharpCallBackSigma(int value, void* object) {

	}

	static void unsharpCallBackThreshold(int value, void* object) {

	}

	static void unsharpCallBackAmount(int value, void* object) {

	}

	void boxOnTrackBar();
	void gaussianOnTrackBar();
	void medianOnTrackBar();


	BoxFilterParameter      boxParameter;
	GaussianFilterParameter gaussianParameter;
	MedianFilterParameter   medianParameter;
	UnsharpFilterParameter  unsharpParameter;

	FilterIO imageIO;
};

