cmake_minimum_required(VERSION 3.30)

project(gpu)

set(SOURCE_DIR Source)
set(INCLUDE_DIR Include)
set(THIRD_PARTY_SOURCE_DIR ThirdParty)

set(INCLUDES ${SOURCE_DIR} ${INCLUDE_DIR})

set(SOURCES
    ${SOURCE_DIR}/Main.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

find_package(glm REQUIRED)

target_link_libraries(${PROJECT_NAME}
    glm::glm
    webgpu_dawn
    webgpu_glfw
    webgpu_cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDES})

## Extra ##

set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 23
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
    COMPILE_WARNING_AS_ERROR ON
)

if (MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic)
endif()

if (XCODE)
    set_target_properties(${PROJECT_NAME} PROPERTIES
        XCODE_GENERATE_SCHEME ON
        XCODE_SCHEME_ENABLE_GPU_FRAME_CAPTURE_MODE "Metal"
    )
endif()

## Set ##

set(DAWN_FETCH_DEPENDENCIES ON)

## Fetch ##

include(cmake/CPM.cmake)

CPMAddPackage(NAME dawn URL "https://dawn.googlesource.com/dawn/+archive/refs/heads/main.tar.gz")