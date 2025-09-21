//
// Created by Charlie on 2025-09-20.
//

#ifndef TINY_RAY_TRACER_HITTABLE_H
#define TINY_RAY_TRACER_HITTABLE_H
#include "ray.h"

class hit_record
{
public:
    point3 p;
    vec3 normal;
    double t;
};

class hittable
{
public:
    virtual ~hittable()=default;
    virtual bool hit(const ray& r, double ray_tmin, double ray_tmax, hit_record& rec) const = 0;
};

#endif //TINY_RAY_TRACER_HITTABLE_H
