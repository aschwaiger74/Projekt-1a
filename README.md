SFML setup for this project

If you see compilation errors like "SFML/Graphics.hpp: No such file or directory", it means CMake can't find your SFML installation.

Options to fix:

1) Download prebuilt SFML 3 for MinGW
   - Get SFML 3.0.x prebuilt for MinGW (matching your MinGW toolchain).
   - Extract it so the path to `SFMLConfig.cmake` is: `.../libs/SFML-3.0.2-mingw64/lib/cmake/SFML`
   - From the project root place the extracted folder at `../libs/SFML-3.0.2-mingw64` (relative to the project folder), or set `SFML_DIR` as described below.

2) Point CMake to your SFML installation
   - Run CMake with the `SFML_DIR` variable pointing to the folder that contains `SFMLConfig.cmake`.

   Example (from project root):

   ```bash
   cmake -S . -B build -G "Ninja" -DSFML_DIR="C:/path/to/SFML/lib/cmake/SFML"
   cmake --build build
   ```

3) Ensure toolchain compatibility
   - Use an SFML build that matches your compiler (MinGW vs MSVC). Using an incompatible SFML build will fail at link or include time.

If you need, tell me which compiler/toolchain you use (MinGW or MSVC) and I can provide an exact download link and example `SFML_DIR` value.
