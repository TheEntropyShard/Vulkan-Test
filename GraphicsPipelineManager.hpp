#ifndef GRAPHICS_PIPELINE_MANAGER_HPP
#define GRAPHICS_PIPELINE_MANAGER_HPP
#include "utils.hpp"
class GraphicsPipelineManager
{
	private:
	
	VkPipelineLayout pipelineLayout;
	VkPipeline graphicsPipeline;
	
	public:
	VkPipeline& getGraphicsPipeline()
	{
		return graphicsPipeline;
	}
	VkPipelineLayout& getPipelineLayout()
	{
		return pipelineLayout;
	}
	void createGraphicsPipeline();
	VkShaderModule createShaderModule(const std::vector<char>& code);
};

#endif
