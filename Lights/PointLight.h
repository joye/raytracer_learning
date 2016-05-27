#pragma once
#include "Light.h"
#include "Utilities/Vector3D.h"
#include "Utilities/RGBColor.h"

#include "World/World.h"			// you will need this later on for shadows
#include "Utilities/ShadeRec.h"


class PointLight : public Light {
public:

	PointLight(void);

	PointLight(const PointLight& dl);

	virtual Light*
		clone(void) const;

	PointLight&
		operator= (const PointLight& rhs);

	virtual
		~PointLight(void);

	void
		scale_radiance(const float b);

	void
		set_color(const float c);

	void
		set_color(const RGBColor& c);

	void
		set_color(const float r, const float g, const float b);

	virtual Vector3D
		get_direction(ShadeRec& sr);

	virtual RGBColor
		L(ShadeRec& sr);

	void set_location(const float x, const float y, const float z);

	void set_shadows(bool shadows);

private:

	float		ls;
	RGBColor	color;
	Vector3D    location;
};


// inlined access functions


// ------------------------------------------------------------------------------- scale_radiance

inline void
PointLight::scale_radiance(const float b) {
	ls = b;
}

// ------------------------------------------------------------------------------- set_color

inline void
PointLight::set_color(const float c) {
	color.r = c; color.g = c; color.b = c;
}


// ------------------------------------------------------------------------------- set_color

inline void
PointLight::set_color(const RGBColor& c) {
	color = c;
}


// ------------------------------------------------------------------------------- set_color

inline void
PointLight::set_color(const float r, const float g, const float b) {
	color.r = r; color.g = g; color.b = b;
}

