#include "ColorSpaces.hh"

int main()
{
	ColorSpaces colorsHandler;
	
	colorsHandler.demoConvertRGBToGray();
	colorsHandler.demoConvertColorSpaces();
	colorsHandler.demoCopyColorChannels();
	colorsHandler.demoModifyColorChannelsRGB();
	colorsHandler.demoModifyColorTypeHSV();
	
	return 0;
}