# How to Build and Run the Ray Tracer Project

## Quick Instruction Flow

1. Open a terminal or command prompt and go to the project directory:
   - macOS/Linux:
     ```sh
     cd <project-directory>
     ```
   - Windows:
     ```bat
     cd <project-directory>
     ```
2. Create and enter a build directory:
   ```sh
   mkdir build
   cd build
   ```
3. Generate build files with CMake:
   - macOS/Linux:
     ```sh
     cmake -DCMAKE_BUILD_TYPE=Release ..
     ```
   - Windows:
     ```bat
     cmake -G "NMake Makefiles" -DCMAKE_BUILD_TYPE=Release ..
     ```
4. Build the project:
   - macOS/Linux:
     ```sh
     cmake --build .
     ```
   - Windows:
     ```bat
     cmake --build . --config Release
     ```
5. Run the program and write the output to an image file:
   - macOS/Linux:
     ```sh
     ./tiny_ray_tracer > ../image.ppm
     ```
   - Windows:
     ```bat
     tiny_ray_tracer.exe > ..\image.ppm
     ```
6. Check the output image in the project directory.

---

## Footnotes

- **<project-directory>:** Replace this with the actual path to the project folder.
- **CMake Version:** CMake 4.0 or higher is required. If an error about CMake version appears, upgrade CMake before proceeding.
- **Toolchain:** A C++17 toolchain must be installed (for example, via Visual Studio or CLion). CMake must be available in the system PATH.
- **Executable Location:** On macOS/Linux, the executable (e.g., `tiny_ray_tracer`) will be in the `build` directory. On Windows, it will be in `build\Release\` if a multi-config generator is used, or in `build\` for single-config.
- **Output Redirection:** The `>` operator writes the program's output to `image.ppm` in the project root. Adjust the filename as needed.
- **Image Viewing:** The `.ppm` file can be viewed with an image viewer that supports PPM format, or converted to PNG/JPG using a tool like ImageMagick:
  ```sh
  convert ../image.ppm ../image.png
  ```
- **Troubleshooting:** If the output is not found, check the build and run steps for errors. The executable name may differ depending on the project configuration. Check the build output for the exact name.
