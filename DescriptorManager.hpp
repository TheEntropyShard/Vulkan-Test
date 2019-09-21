#ifndef DESCRIPTOR_MANAGER_HPP
#define DESCRIPTOR_MANAGER_HPP

struct UniformBufferObject {
    glm::mat4 model;
    glm::mat4 view;
    glm::mat4 proj;
};

class DescriptorManager
{
	private:
	VkDescriptorSetLayout descriptorSetLayout;
	VkDescriptorPool descriptorPool;
	std::vector<VkDescriptorSet> descriptorSets;

	public:
	VkDescriptorSetLayout& getDescriptorSetLayout()
	{
		return descriptorSetLayout;
	}
	std::vector<VkDescriptorSet> getDescriptorSets()
	{
		return descriptorSets;
	}
	void createDescriptorSetLayout();
	void createDescriptorPool();
	void createDescriptorSets();
	void cleanup();
};

#endif
