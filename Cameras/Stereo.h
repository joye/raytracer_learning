#pragma once
#include "World/World.h"

typedef enum {
	parallel,
	transverse
} ViewingType;


class StereoCamera : public Camera {
public:

	// constructors, etc.
	StereoCamera();

	StereoCamera(const StereoCamera& ph);

	virtual Camera*
		clone(void) const;

	StereoCamera&
		operator= (const StereoCamera& rhs);

	virtual
		~StereoCamera();

	void
		setup_cameras(void);

	virtual void
		render_scene(const World& w);

private:

	ViewingType	viewing_type;		// parallel or transverse viewing
	int			pixel_gap;			// gap in pixels between the left and right images
	float		beta;				// stereo separation angle	
	Camera*		left_camera_ptr;	// left eye camera
	Camera*		right_camera_ptr;	// right eye camera
};
