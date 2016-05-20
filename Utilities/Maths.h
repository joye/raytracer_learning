#pragma once

#include "Utilities\Constants.h"
inline double
max(double x0, double x1);

int
rand_int(void);

float
rand_float(void);

float 						// for multi-jittered sampling
rand_float(int l, float h);

int							// for multi-jittered sampling
rand_int(int l, int h);

inline double
max(double x0, double x1)
{
	return((x0 > x1) ? x0 : x1);
}

inline int
rand_int(void)
{
	return rand();
}

inline float
rand_float(void)
{
	return((float)rand_int() * invRAND_MAX);
}

inline float
rand_float(int l, float h) {
	return (rand_float() * (h - l) + l);
}

inline int
rand_int(int l, int h) {
	return ((int)(rand_float(0, h - l + 1) + l));
}

