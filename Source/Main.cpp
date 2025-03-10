#include <webgpu/webgpu.h>
#include <iostream>
#include <cassert>
#include <glm/glm.hpp>

// WGPUAdapter requestAdapterSync(WGPUInstance instance, WGPURequestAdapterOptions const *options)
// {
//     struct UserData
//     {
//         WGPUAdapter adapter = nullptr;
//         bool requestEnded = false;
//     };
//     UserData userData;

//     auto onAdapterRequestEnded = [](WGPURequestAdapterStatus status, WGPUAdapter adapter, char const *message, void *pUserData)
//     {
//         UserData &userData = *reinterpret_cast<UserData *>(pUserData);
//         if (status == WGPURequestAdapterStatus_Success)
//         {
//             userData.adapter = adapter;
//         }
//         else
//         {
//             std::cout << "Could not get WebGPU adapter: " << message << std::endl;
//         }
//         userData.requestEnded = true;
//     };

//     wgpuInstanceRequestAdapter(
//         instance /* equivalent of navigator.gpu */,
//         options,
//         onAdapterRequestEnded,
//         (void *)&userData);

//     assert(userData.requestEnded);

//     return userData.adapter;
// }

int main()
{
    WGPUInstanceDescriptor desc = {};
    desc.nextInChain = nullptr;

    WGPUInstance instance = wgpuCreateInstance(&desc);

    if (!instance)
    {
        std::cerr << "Could not initialize WebGPU!" << std::endl;
        return 1;
    }

    std::cout << "WGPU instance: " << instance << std::endl;

    wgpuInstanceRelease(instance);

    return 0;
}
