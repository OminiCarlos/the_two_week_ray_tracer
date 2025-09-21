cmake_minimum_required(VERSION 4.0)
project(tiny_ray_tracer)

set(CMAKE_CXX_STANDARD 17)

add_executable(tiny_ray_tracer main.cpp
        vec3.h
        color.h
        ray.h
        hittable.h
        sphere.h
        hittable_list.h
        rtweekend.h)
