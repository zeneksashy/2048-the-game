#include "initializers.h"

VkApplicationInfo Intitializers::ApplicationInfo(VulkanConfiguration & config)
{
	VkApplicationInfo info = {};
	info.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	info.pApplicationName = config.application_name;
	info.pEngineName = config.engine_name;
	info.applicationVersion = config.application_version;
	info.engineVersion = config.engine_version;
	info.apiVersion = config.api_version;
	return info;
}

VkInstanceCreateInfo Intitializers::InstanceCreateInfo(VkApplicationInfo & appInfo, std::vector<const char *>& layers, std::vector < const char *>& extensions)
{
	VkInstanceCreateInfo info = {};
	info.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	info.pApplicationInfo = &appInfo;
	info.enabledExtensionCount = extensions.size();
	info.enabledLayerCount = layers.size();
	info.ppEnabledExtensionNames = extensions.data();
	info.ppEnabledLayerNames = layers.data();
	return info;
}
