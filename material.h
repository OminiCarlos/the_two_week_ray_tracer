//
// Created by Charlie on 2025-09-27.
//

#ifndef TINY_RAY_TRACER_MATERIAL_H
#define TINY_RAY_TRACER_MATERIAL_H

#include "hittable.h"


class material
{
public:
    virtual ~material()=default;
    virtual bool scatter(const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered) const {
        return false;
    }
};

class lambertian: public material
{
public:
    lambertian(const color& albedo):albedo(albedo){}

    bool scatter(const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered) const override
    {
        vec3 scatter_direction = rec.normal + random_unit_vector();

        // Catch degenerate scatter direction
        if (scatter_direction.near_zero())
            scatter_direction = rec.normal;

        scattered = ray(rec.p, scatter_direction);
        attenuation = albedo;
        return true;
    }


private:
    color albedo;
};

#endif //TINY_RAY_TRACER_MATERIAL_H