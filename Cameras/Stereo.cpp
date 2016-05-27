#include "Stereo.h"

StereoCamera::StereoCamera()
	:Camera()
	,viewing_type(parallel)
	, pixel_gap(20)
	,beta(15)
{
}

StereoCamera::StereoCamera(const StereoCamera & ph)
	:Camera(ph)
	,viewing_type(ph.viewing_type)
	,pixel_gap(ph.pixel_gap)
	,beta(ph.beta)
{
}

Camera * StereoCamera::clone(void) const
{
	return new StereoCamera(*this);
}

StereoCamera & StereoCamera::operator=(const StereoCamera & rhs)
{
	// TODO: insert return statement here
	if (this == &rhs)
		return *this;
	Camera::operator= (rhs);
	viewing_type = rhs.viewing_type;
	pixel_gap = rhs.pixel_gap;
	beta = rhs.beta;
	return *this;
}

StereoCamera::~StereoCamera()
{
}

void StereoCamera::setup_cameras(void)
{
	double r = eye.distance(lookat);
	double x = r * tan(0.5 * beta * PI_ON_180);
	left_camera_ptr->set_eye(eye - x * u);
	left_camera_ptr->set_lookat(lookat - x * u);
	left_camera_ptr->compute_uvw();

	right_camera_ptr->set_eye(eye + x * u);
	right_camera_ptr->set_lookat(lookat + x * u);
	right_camera_ptr->compute_uvw();
}

void StereoCamera::render_scene(const World & w)
{
	ViewPlane	vp = w.vp;
	int 		hres = vp.hres;
	int 		vres = vp.vres;

	//w.open_window(2 * hres + pixel_gap, vres);

	double r = eye.distance(lookat);
	double x = r * tan(0.5 * beta * PI_ON_180);

	if (viewing_type == parallel) {
		left_camera_ptr->render_stereo(w, x, 0);						// left view on left
		right_camera_ptr->render_stereo(w, -x, hres + pixel_gap);   	// right view on right
	}

	if (viewing_type == transverse) {
		right_camera_ptr->render_stereo(w, -x, 0);   					// right view on left
		left_camera_ptr->render_stereo(w, x, hres + pixel_gap);    		// left view on right
	}
}
