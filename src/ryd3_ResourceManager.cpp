#include "ryd3_ResourceManager.h"

void ResourceManager::ClearResources() {
	for (auto const &ent : resourceList) {
		std::cout << "Deleting resource: " << ent.first << std::endl;
		delete ent.second;
	}
	resourceList.clear();
}