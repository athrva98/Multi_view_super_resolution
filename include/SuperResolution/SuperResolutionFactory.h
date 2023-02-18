#pragma once
#include "include/SuperResolution/SuperResolutionBase.h"

class SuperResolutionFactory
{
public:
	static Ptr<SuperResolutionBase> CreateSuperResolutionBase()
	{
		return new SuperResolutionBase();
	}
};

