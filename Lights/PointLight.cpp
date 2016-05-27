#include "PointLight.h"

// ---------------------------------------------------------------------- default constructor

PointLight::PointLight(void)
	: Light(),
	ls(1.0),
	color(1.0),
	location(0, 0, 0)
{}


// ---------------------------------------------------------------------- dopy constructor

PointLight::PointLight(const PointLight& dl)
	: Light(dl),
	ls(dl.ls),
	color(dl.color),
	location(dl.location)
{}


// ---------------------------------------------------------------------- clone

Light*
PointLight::clone(void) const {
	return (new PointLight(*this));
}


// ---------------------------------------------------------------------- assignment operator

PointLight&
PointLight::operator= (const PointLight& rhs)
{
	if (this == &rhs)
		return (*this);

	Light::operator= (rhs);

	ls = rhs.ls;
	color = rhs.color;
	location = rhs.location;

	return (*this);
}


// ---------------------------------------------------------------------- destructor																			

PointLight::~PointLight(void) {}

Vector3D
PointLight::get_direction(ShadeRec& sr) {
	return ((location - sr.hit_point).hat());
}

RGBColor
PointLight::L(ShadeRec& sr) {
	return (ls * color);
}

void PointLight::set_location(const float x, const float y, const float z)
{
	location = Vector3D(x, y, z);
}

void PointLight::set_shadows(bool shadows)
{
	this->shadows = shadows;
}