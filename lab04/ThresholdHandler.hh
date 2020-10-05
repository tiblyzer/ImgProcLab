#pragma once

#define NumberofSimpleThreshModes 5

enum SimpleThreshMode {
	Binary,
	Binary_inv,
	Trunc,
	Tozero,
	Tozero_inv
};

class ThresholdHandler
{
public:
	void demoSimpleThreshold();
	void demoGlobalThreshold();
	void demoAdaptiveThreshold();
};

