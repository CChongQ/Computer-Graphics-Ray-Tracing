#include "Sphere.h"
#include "Ray.h"

bool Sphere::intersect(
  const Ray & ray, const double min_t, double & t, Eigen::Vector3d & n) const
{
  ////////////////////////////////////////////////////////////////////////////
   // Replace with your code here:
  double A = ray.direction.dot(ray.direction); // d*d
  double B = 2* ray.direction.dot(ray.origin- center); // 2d*(e-c)
  double C = (ray.origin- center).dot(ray.origin- center) - radius*radius;//(e-c)*(e-c)-r^2
  double discriminant = B*B-4*A*C;

  if (discriminant >=0){
    double t_1 = (-B - sqrt(discriminant))/(2*A);
    double t_2 = (-B + sqrt(discriminant))/(2*A);

    double found = true;
    if ( t_1 < min_t && min_t <= t_2 )
      t = t_2;
    else if (t_1 >= min_t)
      t = t_1;
    else
      found = false;
    
    if (found){
      Eigen::Vector3d p = ray.origin + ray.direction * t;
      n = (p-center)/radius; //unit normal = (p-c)/R
      return true;
    }
    else{
      return false;
    }
     
  }

  return false;
  ////////////////////////////////////////////////////////////////////////////
}

