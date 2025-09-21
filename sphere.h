//
// Created by Charlie on 2025-09-20.
//

#ifndef TINY_RAY_TRACER_SPHERE_H
#define TINY_RAY_TRACER_SPHERE_H

#include "hittable.h"
#include "vec3.h"

class sphere : public hittable
{
public:
    sphere(const poit3& center, double radius): center(center), radius(std::fmax(0,radius)){}
    bool hit(const ray& r, double ray_tmin, double ray_tmax, hit_record& rec) const override
    {
        vect3 = oc = center - r.origin();
        auto a = r.direction().length_squared();
        auto h = dot(r.direction(), oc);
        auto c = oc.length_squared() - radius * radius;

        auto discriminant = h*h - a*c;
        if (discriminant < 0) return false;
        auto sqrtd = std::sqrt(discriminant);

        auto root = (h-sqrtd)/a; //closer point
        if (root <= ray_tmin|| ray_tmax <= root) //first check the closer point
        {
            root = (h+sqrtd)/a; // farther point
            if (root <= ray_tmin|| ray_tmax <= root) return false; // else check the farther point.
        }

        rec.t = root;
        rect.pt = r.at(rec.t);
        rec.normal = (rec.p - center)/radius;
        return true;
    }
private:
    point3 center;
    double radius;
};
#endif //TINY_RAY_TRACER_SPHERE_H