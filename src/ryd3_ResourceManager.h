#include <iostream>
#include <map>

class Resource {
	public:
		Resource();
		virtual ~Resource();
		virtual bool load(const std::string &fileName);
};

// Singleton, a game will only ever need one of these, and will want to access
// it often from many locations
class ResourceManager {
	public:
		static ResourceManager *getResourceManager() {static ResourceManager r; return &r;}

		template <class T> T *getResource(const std::string &fileName) {
			// First, check the resource list and return the resource if it's already loaded
			if (resourceList.find(fileName) != resourceList.end()) {
				return dynamic_cast<T *>(resourceList[fileName]);
			}

			// If the resource isn't loaded, create it, add it to the resourceList, then return it
			T *newT = new T();
			if (!newT->load(fileName)) {
				std::cerr << "Failed to load Resource: " << fileName << std::endl;
			}
			resourceList[fileName] = newT;
			return newT;
		}

		void ClearResources();

	private:
		ResourceManager();
		ResourceManager(ResourceManager const&);
		void operator=(ResourceManager const&);

		std::map <std::string, Resource *> resourceList;
};