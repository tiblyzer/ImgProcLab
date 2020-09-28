#include "opencv_headers.hh"
#include "std_headers_basic.hh"
#include "MatBasics.hh"

void MatBasics::demoOpenCV(){
	demoImageIO();
	demoMatCreate();
	demoMatInfo();
	demoMatMemory();
	demoMatMethods();
	demoIterateMat();
}

void MatBasics::demoImageIO()
{
	//imread(eleresi_utvonal,megnyitasi mod)
	//megnyitasi modok: -1 modositatlan(raw), 0 - szurkeskalas , 1 - szines
	Image I = cv::imread("test.jpg", 0);
	Image I2 = cv::imread("test.jpg", 1);

	//imwrite(eleresi_utvonal,kiirando matrix, formatumparameterek

	cv::imshow("I",I);
	cv::imshow("I2", I2);
	cv::waitKey();

	std::vector<int> formatParameters_png,formatParameters_jpg;
	formatParameters_png.push_back(cv::IMWRITE_PNG_COMPRESSION);
	formatParameters_png.push_back(5);

	formatParameters_jpg.push_back(cv::IMWRITE_JPEG_QUALITY);
	formatParameters_jpg.push_back(90);

	cv::imwrite("out.png", I, formatParameters_png);
	cv::imwrite("out.jpg", I2, formatParameters_jpg);

}

void MatBasics::demoMatCreate()
{
	//7x7es matrix, 8bites 1 csatornas
	cv::Mat M(7, 7, CV_8UC1);

	//10x10-es matrix, 8bites 3 csatornas
	cv::Mat M2(10, 10, CV_8UC(3));

	//500x500es matrix, 8bites 1 csatornas, 100-as ertekkel feltoltve + kirajzoltatas
	cv::Mat M3(500, 500, CV_8UC1,100);
	plotMat(M3);

	//ures matrix
	cv::Mat M4;

	//ures matrix feltoltese 100x50-es haromcsatornas 8bitesre.
	M4.create(100, 50, CV_8UC3);

	//matrix felszabaditasa
	M3.release();
}
void MatBasics::demoMatInfo()
{
	cv::Mat Image = cv::imread("test.jpg");

	std::cout << "Image Properties: " << std::endl
		<< "rows: " << Image.rows << std::endl
		<< "cols: " << Image.cols << std::endl
		<< "channels:" << Image.channels() << std::endl
		<< "type: " << Image.type() << std::endl;



}

void MatBasics::demoMatMemory()
{
	cv::Mat M(7, 7, CV_8UC1);
	//csak referenciakent tesszuk egyenlove a teljes matrixszal
	cv::Mat M2 = M;
	//adott sor es oszlop elerese ertekmasolas nelkul
	cv::Mat row = M.row(3);
	cv::Mat col = M.col(2);

	//adott matrix, sor, es oszlop ertekmasolassal
	cv::Mat M3 = M.clone();
	cv::Mat row2 = M.row(2).clone();
	cv::Mat col4 = M.row(4).clone();

	//release meghivasa a referenciara, nem szabaditja fel a memoriat!
	M2.release();

	//release meghivasa az eredeti Mat objektumra, a lefoglalt memoria felszabadul.
	M.release();


}

void MatBasics::demoMatMethods()
{
	cv::Mat M(100, 100, CV_8UC1);
	cv::Mat M2;
	cv::Mat mask = cv::Mat::eye(100, 100, CV_8UC1);
	
	M.setTo(200);

	plotMat(M);

	M.setTo(0);
	M.setTo(240, mask);

	plotMat(M);

	M.copyTo(M2);
	M2.resize(200);

	plotMat(M2);
}

void MatBasics::plotMat(cv::Mat& M)
{
	cv::imshow("M", M);
	cv::waitKey();
}

void MatBasics::demoIterateMat()
{
	cv::Mat M = cv::Mat::eye(10, 10, CV_8UC1);

	for (int i = 0; i < M.rows; ++i) {
		for (int j = 0; j < M.cols; ++j) {
			std::cout << (int)M.at<uchar>(i, j) << " ";
		}
		std::cout << std::endl;
	}
}