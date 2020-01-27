#pragma once
#include"includes.h"
namespace Intitializers
{
	VkApplicationInfo ApplicationInfo(VulkanConfiguration & config);
	VkInstanceCreateInfo InstanceCreateInfo(VkApplicationInfo & appInfo, std::vector<const char *>& layers, std::vector < const char *>& extensions );
}
