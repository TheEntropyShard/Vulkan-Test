#ifndef VERTEX_MANAGER_HPP
#define VERTEX_MANAGER_HPP

#include "utils.hpp"

struct Vertex {
    glm::vec2 pos;
    glm::vec3 color;

	static VkVertexInputBindingDescription getBindingDescription() {
		VkVertexInputBindingDescription bindingDescription = {};
		bindingDescription.binding = 0;
		bindingDescription.stride = sizeof(Vertex);
		bindingDescription.inputRate = VK_VERTEX_INPUT_RATE_VERTEX;
		return bindingDescription;
    }
    static std::array<VkVertexInputAttributeDescription, 2> getAttributeDescriptions() {
		std::array<VkVertexInputAttributeDescription, 2> attributeDescriptions = {};
		//Positions
		attributeDescriptions[0].binding = 0;
		attributeDescriptions[0].location = 0;
		attributeDescriptions[0].format = VK_FORMAT_R32G32_SFLOAT;//2D vertices, so use "r" and "g"
		attributeDescriptions[0].offset = offsetof(Vertex, pos);
		//Colors
		attributeDescriptions[1].binding = 0;
		attributeDescriptions[1].location = 1;
		attributeDescriptions[1].format = VK_FORMAT_R32G32B32_SFLOAT;//RGB, so use r g and b
		attributeDescriptions[1].offset = offsetof(Vertex, color);
		return attributeDescriptions;
	}
};
class VertexManager
{
	private:
	VkBuffer vertexBuffer;
	VkDeviceMemory vertexBufferMemory;
	VkBuffer indexBuffer;
	VkDeviceMemory indexBufferMemory;
	
	const std::vector<Vertex> vertices = {
		{{-0.5f, -0.5f}, {1.0f, 0.0f, 0.0f}},
		{{0.5f, -0.5f}, {0.0f, 1.0f, 0.0f}},
		{{0.5f, 0.5f}, {0.0f, 0.0f, 1.0f}},
		{{-0.5f, 0.5f}, {1.0f, 1.0f, 1.0f}}
	};
	const std::vector<uint16_t> indices = {
		0, 1, 2, 2, 3, 0
	};
	
	void copyBuffer(VkBuffer srcBuffer, VkBuffer dstBuffer, VkDeviceSize size);
	
	public:
	const std::vector<Vertex>& getVertices()
	{
		return vertices;
	}
	const std::vector<uint16_t>& getIndices()
	{
		return indices;
	}
	VkBuffer& getVertexBuffer()
	{
		return vertexBuffer;
	}
	VkBuffer& getIndexBuffer()
	{
		return indexBuffer;
	}
	void createVertexBuffer();
	void createIndexBuffer();
	void cleanup();
};


#endif
