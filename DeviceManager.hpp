#ifndef DEVICE_MANAGER_HPP
#define DEVICE_MANAGER_HPP

#include "utils.hpp"

class DeviceManager
{
	private:
	VkDevice device;
	VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
	
	public:
	VkDevice& getDevice()
	{
		return device;
	}
	VkPhysicalDevice& getPhysicalDevice()
	{
		return physicalDevice;
	}
	QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);
	SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice device);
	
	bool checkDeviceExtensionSupport(VkPhysicalDevice device);
	bool isDeviceSuitable(VkPhysicalDevice device);
	void pickPhysicalDevice();
	void createLogicalDevice();
	int rateDeviceSuitability(VkPhysicalDevice device);
	
	VkResult WaitIdle()
	{
		return vkDeviceWaitIdle(device);
	}
};

#endif
