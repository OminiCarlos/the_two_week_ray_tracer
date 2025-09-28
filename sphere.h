//
// Created by Charlie on 2025-09-20.
//

#ifndef TINY_RAY_TRACER_SPHERE_H
#define TINY_RAY_TRACER_SPHERE_H

#include <utility>

#include "hittable.h"

class sphere : public hittable
{
public:
    sphere(const point3& center, double radius, shared_ptr<material> mat) : center(center),
                                                                            radius(std::fmax(0, radius)), mat(std::move(mat)) {}

    bool hit(const ray& r, interval ray_t, hit_record& rec) const override {
        const vec3 oc = center - r.origin();
        const auto a = r.direction().length_squared();
        const auto h = dot(r.direction(), oc);
        const auto c = oc.length_squared() - radius * radius;

        const auto discriminant = h * h - a * c;
        if (discriminant < 0) return false;
        const auto sqrtd = std::sqrt(discriminant);

        auto root = (h - sqrtd) / a; //closer point
        if (!ray_t.surrounds(root)) //first check the closer point
        {
            root = (h + sqrtd) / a; // farther point
            if (!ray_t.surrounds(root)) return false; // else check the farther point.
        }

        // update hit record
        rec.t = root;
        rec.p = r.at(rec.t);
        const vec3 outward_normal = (rec.p - center) / radius;
        rec.set_face_normal(r, outward_normal);
        rec.mat = mat;
        return true;
    }

private:
    point3 center;
    double radius;
    shared_ptr<material> mat;
};
#endif //TINY_RAY_TRACER_SPHERE_H
