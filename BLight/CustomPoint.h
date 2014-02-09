#pragma once
#include "stdafx.h"

class CustomPoint
{
public:
	CustomPoint(void);
	CustomPoint(float, float);

	operator string();

	float x;
	float y;
};

