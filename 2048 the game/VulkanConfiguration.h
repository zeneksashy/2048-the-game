#pragma once
struct VulkanConfiguration
{
	const char * application_name = "";
	uint32_t application_version = VK_MAKE_VERSION(0, 0, 0);
	const char * engine_name = "my own";
	const uint32_t engine_version = VK_MAKE_VERSION(0, 0, 0);
	const uint32_t api_version = VK_MAKE_VERSION(1, 1, 130);
};