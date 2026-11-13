# OMCshade

A rendering-focused sandbox game (-engine) written in C++ and OpenGL.

## Build

```bash
cmake -S . -B build
cmake --build build
```

For headless environments without desktop backends available:

```bash
cmake -S . -B build -DOMCSHADE_HEADLESS=ON
cmake --build build
```

## Run

Single-config generators (Ninja, Unix Makefiles):

```bash
./build/omcshade
```

Multi-config generators (Visual Studio, Xcode):

```bash
cmake --build build --config Release
./build/Release/omcshade      # Windows: .\build\Release\omcshade.exe
```
