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

find_package(glfw3 REQUIRED)
find_package(glm REQUIRED)
find_package(Dawn REQUIRED)

target_link_libraries(${PROJECT_NAME}
    glfw
    glm::glm
    dawn::webgpu_dawn
)

target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDES})

## Extra ##

set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 17
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