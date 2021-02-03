#include "first_hit.h"

bool first_hit(
  const Ray & ray, 
  const double min_t,
  const std::vector< std::shared_ptr<Object> > & objects,
  int & hit_id, 
  double & t,
  Eigen::Vector3d & n)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  double t_temp; 
  Eigen::Vector3d n_temp;
  bool found = false;

  for (int i = 0; i<objects.size(); i++ ){
    bool hit = objects[i]->intersect(ray,min_t,t_temp,n_temp);
    if ( hit && ( found == false || t_temp<t) ){
        hit_id = i;
        n = n_temp;
        t = t_temp;
        found = true;
    }
  }

  return found;
  ////////////////////////////////////////////////////////////////////////////
}
