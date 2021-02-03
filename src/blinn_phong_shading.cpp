#include "blinn_phong_shading.h"
// Hint:
#include "first_hit.h"
#include <iostream>

#define SMALL_CONST 1e-10

Eigen::Vector3d blinn_phong_shading(
  const Ray & ray,
  const int & hit_id, 
  const double & t,
  const Eigen::Vector3d & n,
  const std::vector< std::shared_ptr<Object> > & objects,
  const std::vector<std::shared_ptr<Light> > & lights)
{
  ////////////////////////////////////////////////////////////////////////////
  //sudo code: textbook p86
  Eigen::Vector3d ka,kd,ks;
  ka = objects[hit_id]->material->ka;
  ks = objects[hit_id]->material->ks;
  kd = objects[hit_id]->material->kd;
  double p = objects[hit_id]->material->phong_exponent;
  const Eigen::Vector3d Ia(0.1, 0.1, 0.1);
  
  Eigen::Vector3d hit_point = ray.origin+ray.direction*t;

  Eigen::Vector3d c = (ka.array() * Ia.array()).matrix();

  for (auto eachLight : lights ){
     
    Ray shadow_ray;
    shadow_ray.origin = hit_point; 

    Eigen::Vector3d d;
    double max_t;
    eachLight->direction(hit_point,d,max_t);
    
    shadow_ray.direction = d; 
    
    int h_id = -1; 
    double t_temp; //parametric distance along ray
    Eigen::Vector3d n_temp;
    bool found_hit = first_hit(shadow_ray,SMALL_CONST,objects,h_id,t_temp,n_temp);
    if (!found_hit || t_temp> max_t){
      Eigen::Vector3d l = shadow_ray.direction;
      Eigen::Vector3d d = ray.direction;
      Eigen::Vector3d h = (l.normalized() + (-d).normalized()).normalized();
      Eigen::Vector3d I = eachLight->I;

      c = c + (kd.array() * I.array()).matrix() * std::max(0.0, n.dot(l)) + 
              (ks.array() * I.array()).matrix() * pow(n.dot(h), p);
    }
  }

  return c;
  ////////////////////////////////////////////////////////////////////////////
}
