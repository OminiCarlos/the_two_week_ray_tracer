# Ray Tracing Renderer

A physically-based ray tracing renderer implemented in C++ following Peter Shirley's "Ray Tracing in One Weekend" series. This project simulates light transport through 3D scenes to produce photorealistic images.

<img width="1200" height="675" alt="image" src="https://github.com/user-attachments/assets/c49af32f-7f92-4068-a956-d3fa3a4e70a4" />

## Overview

This renderer traces rays of light through scenes, simulating realistic material interactions. The implementation covers ray-object intersection, multiple material types, antialiasing, and advanced camera effects.

## Key Concepts Implemented

**Core Ray Tracing**
- Ray-sphere intersection using quadratic equation solutions
- Surface normal calculation for realistic shading
- Recursive ray tracing to simulate light bouncing between objects

**Material System**
- **Lambertian Diffuse**: Matte surfaces with uniform light scattering
  
  <img width="400" height="225" alt="image" src="https://github.com/user-attachments/assets/73954117-2a49-437f-a442-de01aec4ef50" />
  

- **Metal**: Reflective surfaces with configurable fuzziness

  <img width="400" height="225" alt="image" src="https://github.com/user-attachments/assets/beaf90cd-aecc-4b68-bbd9-5a7bb5bb6d9e" />


- **Dielectrics**: Glass-like materials with refraction (Snell's Law). Forces reflection based on physical based reflection probability prescirbled by Schlick's approximation. 

  <img width="400" height="225" alt="image" src="https://github.com/user-attachments/assets/f013fb77-3cdf-4c65-bc94-b1563223c060" />

- Physically-based light transport with proper energy conservation

**Rendering Quality**
- Antialiasing through multisampling (multiple rays per pixel)
- Gamma correction for accurate color display
- Configurable samples-per-pixel for quality/performance balance

**Camera System**
- Positionable camera with adjustable field of view
- Depth of field through thin lens approximation
- Defocus blur via aperture simulation. Instead of shooting rays from one focal point, the camera randomly shoots rays from a disk, which makes sample rays passing through the same pixel more likely to hit different points on objects when those objects are far from the focal plane, causing a blurry effect 

  <img width="400" height="225" alt="image" src="https://github.com/user-attachments/assets/5bc813f9-4198-4708-b1e9-83a307ddd309" />


**Software Design**
- Object-oriented architecture with abstract base classes for extensibility
- Efficient hit record data structures
- Modern C++ with inheritance and virtual functions

## Technical Skills

- **C++ Programming**: Classes, inheritance, memory management
- **3D Mathematics**: Vector operations, linear algebra, geometric calculations
- **Physics Simulation**: Light transport, reflection, refraction
- **Algorithm Design**: Recursive algorithms, Monte Carlo methods, random sampling

## Potential Enhancements

- Signed Distance Functions (SDF) for complex shapes (cubes, cones, CSG operations)
- BVH acceleration structures for faster rendering
- Texture mapping and procedural patterns
- Triangle primitives and mesh loading
- Multi-threading for parallel rendering
- PNG/JPEG export support

## How to use the code
please see how-to-build.md

