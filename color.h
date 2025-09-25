//
// Created by Charlie on 2025-09-20.
//

#ifndef TINY_RAY_TRACER_COLOR_H
#define TINY_RAY_TRACER_COLOR_H

#include "vec3.h"
#include "interval.h"

using color = vec3;

inline void write_color(std::ostream& out, const color& pixel_color) {
    auto r = pixel_color.x();
    auto g = pixel_color.y();
    auto b = pixel_color.z();

    // Translate the [0,1] component values to the byte range [0,255].
    static const interval intensity(0.000,0.999);
    const int rbyte = static_cast<int>(256 * intensity.clamp(r));
    const int gbyte = static_cast<int>(256 * intensity.clamp(g));
    const int bbyte = static_cast<int>(256 * intensity.clamp(b));

    // Write out the pixel color components.
    out << rbyte << ' ' << gbyte << ' ' << bbyte << '\n';
}
#endif //TINY_RAY_TRACER_COLOR_H