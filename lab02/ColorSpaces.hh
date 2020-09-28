#pragma once
#include "opencv_headers.hh"

enum ChannelIndexRGB {
	BLUE,
	GREEN,
	RED
};

enum ChannelIndexHSV {
	HUE,
	SATURATION,
	VALUE
};

enum ChannelLimits {
	RGB_R = 255,
	RGB_G = 255,
	RGB_B = 255,
	HSV_H = 360,
	HSV_S = 100,
	HSV_V = 100
};

class ColorSpaces
{
public:
	void demoConvertRGBToGray();
	void demoConvertColorSpaces();
	
	void demoCopyColorChannels();
	void demoModifyColorChannelsRGB();
	void demoModifyColorTypeHSV();
private:
	void checkChannelOverflow(uchar& channelValue, uchar n, uchar LIMIT);
};

