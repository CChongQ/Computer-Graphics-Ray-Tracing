#include "TriangleSoup.h"
#include "Triangle.h"
#include "first_hit.h"
bool TriangleSoup::intersect(
  const Ray & ray, const double min_t, double & t, Eigen::Vector3d & n) const
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  int h_id = -1; 
  return first_hit(ray,min_t,triangles,h_id,t,n);
  ////////////////////////////////////////////////////////////////////////////
}
