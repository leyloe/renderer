#include <webgpu/webgpu_glfw.h>
#include <iostream>
#include <GLFW/glfw3.h>

int main()
{
    wgpu::InstanceDescriptor desc = {};

    wgpu::Instance instance = wgpu::CreateInstance(&desc);

    if (!instance)
    {
        std::cerr << "Could not initialize WebGPU!" << std::endl;
        return 1;
    }

    std::cout << "WGPU instance: " << instance.Get() << std::endl;

    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

    GLFWwindow *window = glfwCreateWindow(800, 800, "app", nullptr, nullptr);

    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
