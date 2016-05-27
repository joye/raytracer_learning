#pragma once
#include "Utilities/Point2D.h"
#include "World/World.h"

class ThinLens : public Camera
{
public:
	ThinLens();

	ThinLens(const ThinLens& ph);

	virtual Camera*
		clone(void) const;

	ThinLens&
		operator= (const ThinLens& rhs);

	virtual
		~ThinLens();
	void
		set_sampler(Sampler* sp);

	Vector3D
		ray_direction(const Point2D& pixel_point, const Point2D& lens_point) const;

	virtual void render_scene(const World& w);
private:
	float lens_radius;  //lens radius
	float d;            //view plane distance
	float f;            //focal plance distance
	float zoom;         //zoom factor
	Sampler* sampler_ptr;
};