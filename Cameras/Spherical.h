#pragma once

#include "Utilities/Point2D.h"
#include "World/World.h"

class Spherical : public Camera
{
public:
	Spherical();

	Spherical(const Spherical& ph);

	virtual Camera*
		clone(void) const;

	Spherical&
		operator= (const Spherical& rhs);

	virtual
		~Spherical();

	Vector3D
		ray_direction(const Point2D& pixel_point, const int hres, const int vres, const float s) const;

	virtual void render_scene(const World& w);

private:
	float psi_max;
	float lambda_max;
};