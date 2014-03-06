#pragma once
#include "stdafx.h"

class CustomPoint
{
public:
	CustomPoint(void);
	CustomPoint(float, float);

	operator string();

	void set(float, float);

	float getLength();
	void normalize(float = 1);

	float x;
	float y;

};

