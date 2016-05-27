// this file contains the definition of the class GeometricObject 

#include "Utilities/Constants.h"
#include "Materials/Material.h"
#include "GeometricObject.h"


// ---------------------------------------------------------------------- default constructor


GeometricObject::GeometricObject(void)
	: material_ptr(NULL)
{}


// ---------------------------------------------------------------------- copy constructor

GeometricObject::GeometricObject (const GeometricObject& object) {
	if(object.material_ptr)
		material_ptr = object.material_ptr->clone(); 
	else  material_ptr = NULL;
}	


// ---------------------------------------------------------------------- assignment operator

GeometricObject&														
GeometricObject::operator= (const GeometricObject& rhs) {
	if (this == &rhs)
		return (*this);
			
	if (material_ptr) {
		delete material_ptr;
		material_ptr = NULL;
	}

	if (rhs.material_ptr)
		material_ptr = rhs.material_ptr->clone();

	return (*this);
}


// ---------------------------------------------------------------------- destructor

GeometricObject::~GeometricObject (void) {	
	if (material_ptr) {
		delete material_ptr;
		material_ptr = NULL;
	}
}


// ---------------------------------------------------------------- set_material

void 
GeometricObject::set_material(Material* mPtr) {
	material_ptr = mPtr;
}


// ----------------------------------------------------------------------- compute_normal

Normal
GeometricObject::get_normal(const Point3D& p) {
	return (Normal());
}

Normal
GeometricObject::get_normal(void) const {
	return (Normal());
}

// ----------------------------------------------------------------------- set_bounding_box

void
GeometricObject::set_bounding_box(void) {}


// ----------------------------------------------------------------------- set_bounding_box

BBox GeometricObject::get_bounding_box(void) {
	return BBox();
}



// ----------------------------------------------------------------------- sample
// returns a sample point on the object for area light shading

Point3D
GeometricObject::sample(void) {
	return (Point3D(0.0));
}


// ----------------------------------------------------------------------- pdf
// returns the probability density function for area light shading

float
GeometricObject::pdf(ShadeRec& sr) {
	return (0.0);
}
