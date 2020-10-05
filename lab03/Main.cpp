#include "FilterHandler.hh"

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