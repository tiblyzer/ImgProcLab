#include "MorphologyHandler.hh"
int main()
{
	
	MorphologyHandler morphHandler;

	morphHandler.demoDilation();
	morphHandler.demoErosion();
	morphHandler.demoOpening();
	morphHandler.demoClosing();

	return 0;
}