VULKAN_SDK_PATH = ./VulkanSDK-x86_64
VULKAN_LAYER_PATH=$(VULKAN_SDK_PATH)/etc/vulkan/explicit_layer.d

CFLAGS = -std=c++17 -I$(VULKAN_SDK_PATH)/include
LDFLAGS = -L$(VULKAN_SDK_PATH)/lib `pkg-config --static --libs glfw3` -lvulkan

VulkanTest: main.cpp
	g++ $(CFLAGS) -o VulkanTest main.cpp $(LDFLAGS)
VulkanApp: main.cpp
	g++ $(CFLAGS) -DNDEBUG -o VulkanApp main.cpp $(LDFLAGS)

.PHONY: test clean gdb vl nodebug

test: VulkanTest
	LD_LIBRARY_PATH=$(VULKAN_SDK_PATH)/lib VK_LAYER_PATH=$(VULKAN_LAYER_PATH) ./VulkanTest
	
gdb: VulkanTest
	export LD_LIBRARY_PATH=$(VULKAN_SDK_PATH)/lib; export VK_LAYER_PATH=$(VULKAN_LAYER_PATH); gdb ./VulkanTest
nodebug: VulkanApp
	LD_LIBRARY_PATH=$(VULKAN_SDK_PATH)/lib VK_LAYER_PATH=$(VULKAN_LAYER_PATH) NDEBUG=true ./VulkanApp
vl:
	export VK_LAYER_PATH=$(VULKAN_LAYER_PATH);VK_LOADER_DEBUG=all LD_LIBRARY_PATH=$(VULKAN_SDK_PATH)/lib vulkaninfo

clean:
	rm -f VulkanTest
