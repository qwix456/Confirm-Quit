#pragma once
#include "includes.h"
#include "PlayLayer.hpp"

class ExitAlert : public FLAlertLayerProtocol {
protected:
	virtual void FLAlert_Clicked(FLAlertLayer* layer, bool btn2);
};