#include "viewing_ray.h"

void viewing_ray(
  const Camera & camera,
  const int i,
  const int j,
  const int width,
  const int height,
  Ray & ray)
{
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here

  double l = -camera.width/2;//left edge
  double r = camera.width/2; //right edge
  /*Note: In this assignment, the origin is in the top-left*/
  double b = camera.height/2;//bottom edge
  double t = -camera.height/2; //top edge

  double u = l + (r-l)*(j+0.5)/width;
  double v = b + (t-b)*(i+0.5)/height;

  ray.origin = camera.e;
  ray.direction = camera.u*u + camera.v * v - camera.d*camera.w;
  ////////////////////////////////////////////////////////////////////////////
}
