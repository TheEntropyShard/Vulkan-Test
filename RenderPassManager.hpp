#ifndef RENDER_PASS_MANAGER_HPP
#define RENDER_PASS_MANAGER_HPP

#include "utils.hpp"
class RenderPassManager
{
	private:
	VkRenderPass renderPass;
	public:
		VkRenderPass& getRenderPass()
		{
			return renderPass;
		}
		void createRenderPass();
};

#endif
