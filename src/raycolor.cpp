#include "raycolor.h"
#include "first_hit.h"
#include "blinn_phong_shading.h"
#include "reflect.h"

#define SMALL_CONST 1e-10
#define MAX_DEPTH 5

bool raycolor(
  const Ray & ray, 
  const double min_t,
  const std::vector< std::shared_ptr<Object> > & objects,
  const std::vector< std::shared_ptr<Light> > & lights,
  const int num_recursive_calls,
  Eigen::Vector3d & rgb)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:

  int h_id = -1; 
  double t;
  Eigen::Vector3d n;
  double found_hit = first_hit(ray,min_t,objects,h_id,t,n);

  if (found_hit){
    rgb = blinn_phong_shading(ray,h_id, t, n, objects,lights);
    
    if (num_recursive_calls < MAX_DEPTH ){
      //Recursive ray tracing
      Ray reflecction_ray;
      reflecction_ray.origin = ray.origin + t*ray.direction; //the hit location
      reflecction_ray.direction = reflect(ray.direction.normalized(), n);
      Eigen::Vector3d rbg_recursive;
      bool ray_hit_found = raycolor(reflecction_ray,SMALL_CONST,objects,lights,num_recursive_calls+1,rbg_recursive);
      
      if (ray_hit_found){
        rgb = rgb + ( rbg_recursive.array() * (objects[h_id]->material->km).array() ).matrix(); //color = c+km*raycolor(reflectedRay)
      }
    }

    return true;
  }

  return false;
  ////////////////////////////////////////////////////////////////////////////
}
