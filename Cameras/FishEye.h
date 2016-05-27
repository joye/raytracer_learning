#pragma once
#include "Utilities/Point2D.h"
#include "World/World.h"

class FishEye : public Camera
{
public:
	FishEye();

	FishEye(const FishEye& ph);

	virtual Camera*
		clone(void) const;

	FishEye&
		operator= (const FishEye& rhs);

	virtual
		~FishEye();

	Vector3D
		ray_direction(const Point2D& pixel_point, const int hres, const int vres, const float s, float &r) const;

	virtual void render_scene(const World& w);

private:
	float psi_max;
};