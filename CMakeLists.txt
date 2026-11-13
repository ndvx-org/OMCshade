cmake_minimum_required(VERSION 3.20)

project(OMCshade LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(OMCSHADE_HEADLESS "Build GLFW fallback with null platform backend" OFF)

find_package(glfw3 CONFIG QUIET)

if(NOT TARGET glfw)
  include(FetchContent)
  if(OMCSHADE_HEADLESS)
    set(GLFW_BUILD_WAYLAND OFF CACHE BOOL "" FORCE)
    set(GLFW_BUILD_X11 OFF CACHE BOOL "" FORCE)
    set(GLFW_BUILD_NULL ON CACHE BOOL "" FORCE)
  else()
    find_program(OMCSHADE_WAYLAND_SCANNER wayland-scanner)
    find_package(X11 QUIET)

    if(OMCSHADE_WAYLAND_SCANNER)
      set(GLFW_BUILD_WAYLAND ON CACHE BOOL "" FORCE)
    else()
      set(GLFW_BUILD_WAYLAND OFF CACHE BOOL "" FORCE)
    endif()

    if(X11_FOUND)
      set(GLFW_BUILD_X11 ON CACHE BOOL "" FORCE)
    else()
      set(GLFW_BUILD_X11 OFF CACHE BOOL "" FORCE)
    endif()

    if(OMCSHADE_WAYLAND_SCANNER OR X11_FOUND)
      set(GLFW_BUILD_NULL OFF CACHE BOOL "" FORCE)
    else()
      set(GLFW_BUILD_NULL ON CACHE BOOL "" FORCE)
      message(STATUS "No X11 or Wayland toolchain found; enabling GLFW null backend")
    endif()
  endif()
  FetchContent_Declare(
    glfw
    GIT_REPOSITORY https://github.com/glfw/glfw.git
    GIT_TAG 3.4
  )
  FetchContent_MakeAvailable(glfw)
endif()

add_executable(omcshade src/main.cpp)
target_link_libraries(omcshade PRIVATE glfw)
