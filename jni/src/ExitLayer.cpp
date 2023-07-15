#include "ExitAlert.h"

void ExitAlert::FLAlert_Clicked(FLAlertLayer* layer, bool btn2)
{
	if (btn2)
	{
		PlayLayerNew::Quit();
	}
}