#include "Plane.h"
#include "Ray.h"
#include <iostream>
bool Plane::intersect(
  const Ray & ray, const double min_t, double & t, Eigen::Vector3d & n) const
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  if (ray.direction.dot(normal) != 0){
    double t_temp = (- normal.dot(ray.origin - point))/normal.dot(ray.direction);
    if (t_temp >= min_t ){
      t = t_temp;
      n = normal;
      return true;
    }
  }
  return false;
  ////////////////////////////////////////////////////////////////////////////
}

