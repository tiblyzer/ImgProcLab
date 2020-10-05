#include "ThresholdHandler.hh"
#include "CropHandler.hh"


int main()
{
	ThresholdHandler thresholdHandler;
	CropHandler cropHandler;
	
	thresholdHandler.demoSimpleThreshold();
	thresholdHandler.demoGlobalThreshold();
	thresholdHandler.demoAdaptiveThreshold();
	cropHandler.demoCropping();
	
	return 0;
}