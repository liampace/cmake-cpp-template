# Version 1.0.1
## Bug Fixes
- `CMakePresets.json` now respects `Visual Studio`'s maximum supported version  `version`
- `<project_name>/export.h` is now generated for all configurations
- `<project_name>_tests` target now only builds when test source files exist
- Targets linking this project can now copy the built `.dll` files as a post build step like so:
```cmake
add_executable(exe main.cpp)
target_link_libraries(exe PRIVATE <project_name>)

include(CopyDLLs)
target_copy_dlls(exe)
```