//
// Created by Charlie on 2025-09-20.
//

#ifndef TINY_RAY_TRACER_HITTABLE_H
#define TINY_RAY_TRACER_HITTABLE_H

class hit_record
{
public:
    point3 p;
    vec3 normal;
    double t{0.0};
    bool front_face;

    void set_face_normal(const ray& r, const vec3& outward_normal)
    {
        front_face = dot(r.direction(), outward_normal) < 0;
        normal = front_face ? outward_normal : -outward_normal;
    }
};

class hittable
{
public:
    virtual ~hittable()=default;
    virtual bool hit(const ray& r, double ray_tmin, double ray_tmax, hit_record& rec) const = 0;
};

#endif //TINY_RAY_TRACER_HITTABLE_H
