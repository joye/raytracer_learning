#pragma once
class Material;

#include "Utilities/Point3D.h"
#include "Utilities/Ray.h"
#include "Utilities/ShadeRec.h"
#include "Utilities/BBox.h"

//----------------------------------------------------------------------------------------------------- Class GeometricObject

class GeometricObject {

public:

	GeometricObject(void);									// default constructor

	GeometricObject(const GeometricObject& object);			// copy constructor

	virtual GeometricObject*								// virtual copy constructor
		clone(void) const = 0;

	virtual 												// destructor
		~GeometricObject(void);

	virtual bool
		hit(const Ray& ray, double& t, ShadeRec& s) const = 0;

	//virtual bool
	//	shadow_hit(const Ray& ray, double& tmin) const = 0;

	Material*
		get_material(void) const;

	virtual void 							// needs to virtual so that it can be overriden in Compound
		set_material(Material* mPtr);

	void
		set_color(const RGBColor& c);

	void
		set_color(const float r, const float g, const float b);

	RGBColor
		get_color(void);

	virtual void
		set_bounding_box(void);

     virtual BBox get_bounding_box(void);

	 //virtual void 										// required for compound objects
		//add_object(GeometricObject* object_ptr);


	// The following two functions are only required for objects that are light sources, eg disks, rectangles, and spheres

	virtual Point3D
		sample(void);

	virtual float
		pdf(ShadeRec& sr);


	// The following two functions allow us to simplify the code for smooth shaded triangle meshes

	virtual Normal
		get_normal(void) const;

	virtual Normal
		get_normal(const Point3D& p);

protected:

	mutable Material*   material_ptr;   	// mutable allows Compound::hit, Instance::hit and Grid::hit to assign to material_ptr. hit functions are const
	RGBColor   			color;				// only used for Bare Bones ray tracing

	GeometricObject&						// assignment operator
		operator= (const GeometricObject& rhs);
};


// ------------------------------------------------------------------------- get_material

inline Material*
GeometricObject::get_material(void) const {
	return (material_ptr);
}