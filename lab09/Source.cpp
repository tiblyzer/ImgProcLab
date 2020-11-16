#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/core.hpp>
#include <iostream>
#include <iomanip>

void demoDrawContours()
{
	cv::Mat img = cv::imread("shapes.png", 0);
	cv::Mat thresholded;
	std::vector<std::vector<cv::Point> > contours;
	std::vector<cv::Vec4i> hierarchy;

	cv::threshold(img, thresholded, 130, 255, cv::THRESH_BINARY);
	cv::findContours(thresholded, contours, hierarchy, cv::RETR_TREE, cv::CHAIN_APPROX_NONE);
	
	cv::drawContours(img, contours, -1, cv::Scalar(0,255,0), 10);
	cv::imshow("shapes", img);
	cv::waitKey(0);
}

void demoExtractMomentsandProperties()
{
	cv::Mat img = cv::imread("shape.png", 0);
	cv::Mat thresholded;
	std::vector<std::vector<cv::Point> > contours;
	std::vector<cv::Vec4i> hierarchy;

	cv::threshold(img, thresholded, 130, 255, cv::THRESH_BINARY);
	cv::findContours(thresholded, contours, hierarchy, cv::RETR_TREE, cv::CHAIN_APPROX_NONE);

	cv::drawContours(img, contours, -1, cv::Scalar(0, 255, 0), 10);
	cv::imshow("shapes", img);
	cv::waitKey(0);

    std::vector<cv::Moments> mu(contours.size());
    for (size_t i = 0; i < contours.size(); i++)
    {
        mu[i] = moments(contours[i]);
    }
    
    std::vector<cv::Point2f> mc(contours.size());
    for (size_t i = 0; i < contours.size(); i++)
    {
        //add 1e-5 to avoid division by zero
        mc[i] = cv::Point2f(static_cast<float>(mu[i].m10 / (mu[i].m00 + 1e-5)),
            static_cast<float>(mu[i].m01 / (mu[i].m00 + 1e-5)));
        std::cout << "mc[" << i << "]=" << mc[i] << std::endl;
    }
    cv::Mat drawing = cv::Mat::zeros(thresholded.size(), CV_8UC3);
    std::vector<cv::Point> converxPoints;
    for (size_t i = 0; i < contours.size(); i++)
    {
        cv::Scalar color = cv::Scalar(0,255,255);
        cv::Scalar color2 = cv::Scalar(255,0,255);
        std::vector<std::vector<cv::Point>> hullpoints;
        drawContours(drawing, contours, (int)i, color, 2);
        cv::convexHull(contours[i], converxPoints, true, true);

        std::cout << cv::isContourConvex(contours[i]) << std::endl;
        hullpoints.push_back(converxPoints);
        drawContours(drawing, hullpoints, (int)i, color2, 5);
        circle(drawing, mc[i], 4, color, -1);
    }
    imshow("Contours", drawing);
    std::cout << "\t Info: Area and Contour Length \n";
    for (size_t i = 0; i < contours.size(); i++)
    {
        std::cout << " * Contour[" << i << "] - Area (M_00) = " << std::fixed << std::setprecision(2) << mu[i].m00
            << " - Area OpenCV: " << contourArea(contours[i]) << " - Length: " << arcLength(contours[i], true) << std::endl;
    }

    cv::waitKey(0);
}

void demoBounding()
{
    cv::Mat img = cv::imread("shape.png", 0);
    cv::Mat boundary = img.clone();
    cv::Mat circled = img.clone();

    cv::Mat thresholded;
    std::vector<std::vector<cv::Point> > contours;
    std::vector<cv::Vec4i> hierarchy;

    cv::threshold(img, thresholded, 130, 255, cv::THRESH_BINARY);
    cv::findContours(thresholded, contours, hierarchy, cv::RETR_TREE, cv::CHAIN_APPROX_NONE);

    cv::Rect R = cv::boundingRect(contours[0]);
    cv::rectangle(boundary, R, cv::Scalar(0, 0, 255), 5);
    
    cv::Point2f center;
    float radius;

    cv::minEnclosingCircle(contours[0], center, radius);
    circle(circled, center, radius, cv::Scalar(0, 0, 255), 5);
    
    
    cv::imshow("boundary_rect",boundary);
    cv::imshow("smallest circle", circled);

    cv::waitKey(0);
}

void demoMorpSkeleton()
{
    cv::Mat kernel = cv::getStructuringElement(cv::MORPH_CROSS, cv::Size(3, 3));
    cv::Mat open, eroded, temp;
    cv::Mat thresholded;
    cv::Mat img = cv::imread("shape.png", 0);
    cv::Mat skel(img.size(), CV_8UC1, cv::Scalar(0));

    cv::threshold(img, thresholded, 130, 255, cv::THRESH_BINARY);
            while (1) {
                cv::morphologyEx(thresholded, open,cv::MORPH_OPEN, kernel);
                   
                cv::subtract(thresholded,open,temp);
                cv::erode(thresholded, eroded, kernel);
                cv::bitwise_or(skel, temp,skel);
                eroded.copyTo(thresholded);
                //cv::imshow("thresholded", thresholded);
                //cv::imshow("eroded", eroded);
                //cv::imshow("temp", temp);
                cv::imshow("Skeleton", skel);
                cv::waitKey(0);
                if (cv::countNonZero(thresholded) == 0) {
                    break;
                }
            }
            
            cv::imshow("Skeleton", skel);
            cv::waitKey(0);
}

int main() {
	demoDrawContours();
    demoExtractMomentsandProperties();
    demoBounding();
    demoMorpSkeleton();
	return 0;
}