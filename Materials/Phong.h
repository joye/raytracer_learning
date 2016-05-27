#pragma once
#include "Material.h"
#include "BRDFs/Lambertian.h"
#include "BRDFs/GlossySpecular.h"
class Phong : public Material
{
public:
	Phong(void);
	virtual RGBColor shade(ShadeRec& s);

	void
		set_ka(const float k);

	void
		set_kd(const float k);

	void
		set_cd(const RGBColor c);

	void
		set_cd(const float r, const float g, const float b);

	void
		set_cd(const float c);

	void set_exp(const float exp);
protected:
	Lambertian* ambient_brdf;
	Lambertian* diffuse_brdf;
	GlossySpecular* specular_brdf;
};

inline void
Phong::set_ka(const float ka) {
	ambient_brdf->set_kd(ka);
}


// ---------------------------------------------------------------- set_kd
// this also sets Lambertian::kd, but for a different Lambertian object

inline void
Phong::set_kd(const float kd) {
	diffuse_brdf->set_kd(kd);
}


// ---------------------------------------------------------------- set_cd

inline void
Phong::set_cd(const RGBColor c) {
	ambient_brdf->set_cd(c);
	diffuse_brdf->set_cd(c);
}


// ---------------------------------------------------------------- set_cd

inline void
Phong::set_cd(const float r, const float g, const float b) {
	ambient_brdf->set_cd(r, g, b);
	diffuse_brdf->set_cd(r, g, b);
}

// ---------------------------------------------------------------- set_cd

inline void
Phong::set_cd(const float c) {
	ambient_brdf->set_cd(c);
	diffuse_brdf->set_cd(c);
}

inline void 
Phong::set_exp(const float exp)
{
	specular_brdf->set_exp(exp);
}