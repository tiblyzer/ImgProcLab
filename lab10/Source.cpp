#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/core.hpp>
#include <iostream>
#include <iomanip>

using namespace cv;

void demoKmeans()
{
	Mat ocv = cv::imread("IMG_5077.jpg", 1);
	Mat data;
	ocv.convertTo(data, CV_32F);
	data = data.reshape(1, data.total());

	// do kmeans
	Mat labels, centers;
	kmeans(data, 8, labels, TermCriteria(TermCriteria::MAX_ITER, 10, 1.0), 3,
		KMEANS_PP_CENTERS, centers);

	// reshape both to a single row of Vec3f pixels:
	centers = centers.reshape(3, centers.rows);
	data = data.reshape(3, data.rows);

	// replace pixel values with their center value:
	Vec3f* p = data.ptr<Vec3f>();
	for (size_t i = 0; i < data.rows; i++) {
		int center_id = labels.at<int>(i);
		p[i] = centers.at<Vec3f>(center_id);
	}

	// back to 2d, and uchar:
	ocv = data.reshape(3, ocv.rows);
	ocv.convertTo(ocv, CV_8U);

	imshow("clustered", ocv);
	cv::waitKey(0);
}

int main()
{
	demoKmeans();
	return 0;
}