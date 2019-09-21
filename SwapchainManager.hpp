#ifndef SWAPCHAINMANAGER_HPP
#define SWAPCHAINMANAGER_HPP

#include "utils.hpp"
#include "DescriptorManager.hpp"
class SwapchainManager
{
	private:
	std::vector<VkBuffer> uniformBuffers;
	std::vector<VkDeviceMemory> uniformBuffersMemory;
	
	VkSwapchainKHR swapChain;
	std::vector<VkImage> swapChainImages;
	VkFormat swapChainImageFormat;
	VkExtent2D swapChainExtent;
	std::vector<VkImageView> swapChainImageViews;
	
	public:
	std::vector<VkBuffer>& getUniformBuffers()
	{
		return uniformBuffers;
	}
	std::vector<VkDeviceMemory>& getUniformBuffersMemory()
	{
		return uniformBuffersMemory;
	}
	std::vector<VkImage>& getSwapChainImages()
	{
		return swapChainImages;
	}
	std::vector<VkImageView>& getSwapChainImageViews()
	{
		return swapChainImageViews;
	}
	VkFormat& getSwapChainImageFormat()
	{
		return swapChainImageFormat;
	}
	VkSwapchainKHR& getSwapChain()
	{
		return swapChain;
	}
	VkExtent2D& getSwapChainExtent()
	{
		return swapChainExtent;
	}
	
	VkSurfaceFormatKHR chooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats) {
		for (const auto& availableFormat : availableFormats) {
			if (availableFormat.format == VK_FORMAT_B8G8R8A8_UNORM && availableFormat.colorSpace == VK_COLOR_SPACE_SRGB_NONLINEAR_KHR) {
				return availableFormat;
			}
		}

		return availableFormats[0];
	}
	VkPresentModeKHR chooseSwapPresentMode(const std::vector<VkPresentModeKHR>& availablePresentModes) {
		for (const auto& availablePresentMode : availablePresentModes) {
			if (availablePresentMode == VK_PRESENT_MODE_MAILBOX_KHR) {
				return availablePresentMode;
			}
		}

		return VK_PRESENT_MODE_FIFO_KHR;
	}
	VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities);
	void createFramebuffers();
	void createUniformBuffers();
	
	void createImageViews();
	void createSwapChain();
	void recreateSwapChain();
	void cleanupSwapChain();
	void setUniformBuffer(uint32_t currentImage, UniformBufferObject& ubo);
};

#endif
