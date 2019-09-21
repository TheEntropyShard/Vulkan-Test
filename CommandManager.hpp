#ifndef COMMAND_MANAGER_HPP
#define COMMAND_MANAGER_HPP
#include "utils.hpp"

class CommandManager
{
	private:
	VkCommandPool commandPool;
	std::vector<VkCommandBuffer> commandBuffers;
	
	public:
	VkCommandPool& getCommandPool()
	{
		return commandPool;
	}
	std::vector<VkCommandBuffer>& getCommandBuffers()
	{
		return commandBuffers;
	}

	
	void createCommandBuffers();
	void createCommandPool();
	void freeCommandBuffers(VkDevice device)
	{
		return vkFreeCommandBuffers(device, commandPool, static_cast<uint32_t>(commandBuffers.size()), commandBuffers.data());
	}
};

#endif
