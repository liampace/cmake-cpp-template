# Version 1.1.0
## Bug Fixes
- Linux/macOS presets now use the Ninja build generator

## Features
- Linux and macOS now unified under `<build_type>-unix-<architecture>` build configurations using the `gcc/g++` compilers
- Compiler flags now supported via `<PROJECT-NAME>_CXX_FLAGS` and `<PROJECT-NAME>_CXX_WARNING_FLAGS` in `CMakePresets.txt`:

```json
{
  ...
  "cacheVariables": {
    "<PROJECT-NAME>_CXX_FLAGS": "<flag1>;<flag2>;...<flagN>",
    "<PROJECT-NAME>_CXX_WARNING_FLAGS": "<warning1>;<warning2>;...<warningN>"
  },
  ...
}
```
- Debug build type now compiles with warnings as errors. You can set which warnings are enabled with `<PROJECT-NAME>_CXX_WARNING_FLAGS`.
- For `MSVC` users, the following flags are applied automatically to enforce C++ standard compliance:
  - `/permissive-`
  - `/Zc:__cplusplus`
  - `/Zc:__STDC__`
  - `/Zc:enumTypes`
  - `/Zc:externConstexpr`
  - `/Zc:inline`
  - `/Zc:lambda`
  - `/Zc:templateScope`
  - `/Zc:ternary`
  - `/Zc:throwingNew`
  - `/Zc:trigraphs`
- Can now choose to whether to build the project as a static or shared library using the `BUILD_SHARED_LIBS` option. 