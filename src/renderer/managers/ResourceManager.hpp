#pragma once

#include "../resources/Resource.hpp"

#include <unordered_map>
#include <memory>
#include <vector>
#include <array>
#include "../resources/Mesh.hpp"
#include "../resources/Material.hpp"

class ResourceManager
{
public:
	/*template<typename T>
	std::shared_ptr<T>& loadResource(std::vector<const char*>& filepaths, std::vector<Vertex>& vertices, std::vector< std::vector<uint16_t>> indices_vec)
	{*/
		////Mesh
		//std::shared_ptr<Mesh> mesh = std::make_shared<Mesh>();
		//
		////Materials
		//std::shared_ptr<Material> mat;
		//if (filepaths.size() > 0) //set textures
		//{
		//	for (int i = 0; i < filepaths.size();i++)
		//	{
		//		//Buffer
		//		std::shared_ptr<Buffer> buffer = std::make_shared<Buffer>(vertices, indices_vec[i]);
		//		mat = std::make_shared<Material>();
		//		std::shared_ptr<Texture> tex = std::make_shared<Texture>(filepaths[i]);
		//		if (tex->load(filepaths[i]))
		//		{
		//			mat->setTexture(tex);
		//			mesh->addBuffer(buffer, *mat);
		//		}
		//	}
		//}
		//else
		//{
		//	std::shared_ptr<Buffer> buffer = std::make_shared<Buffer>(vertices, indices_vec[0]);
		//	mat = std::make_shared<Material>();//Empty material
		//	mesh->addBuffer(buffer, *mat);
		//}
		//

		//m_meshes[nextID] = mesh;

		//return m_meshes[nextID++];
	//}
	~ResourceManager()
	{
		unloadAllResources();
	}
	template<typename T>
	T* getResource(const std::size_t& id)
	{
		auto it = m_resources.find(id);
		if (it != m_resources.end())
		{
			return static_cast<T*>(it->second.get());
		}
		return nullptr;
	}

	template<typename T, typename... Args>
	T* loadResource(const char* filepath, Args&&... args)
	{
		//Search if the resource is already loaded
		for (auto& pair : m_filenames)
		{
			if (pair.second == filepath && m_filetypes[pair.first] == typeid(T).hash_code())
			{
				return getResource<T>(pair.first);
			}
		}
		//load resource 
		nextID++;
		auto resource = std::make_unique<T>(nextID, std::forward<Args>(args)...);
		if (resource->load(filepath))
		{
			auto rawptr = resource.get();
			m_resources[nextID] = std::move(resource);
			m_filenames[nextID] = std::string(filepath);
			m_filetypes[nextID] = typeid(T).hash_code();
			return rawptr;
		}
		else {
			nextID--;
			return nullptr;
		}
	}

	void unloadAllResources()
	{
		m_resources.clear();
		m_filenames.clear();
		m_filetypes.clear();
	}
	static ResourceManager& getInstance() {
		static ResourceManager instance;
		return instance;
	}
private:
	ResourceManager() = default;

	inline static std::size_t nextID{ 0 };
	//Recursos
	std::unordered_map<std::size_t, std::unique_ptr<Resource>> m_resources;
	//filenames
	std::unordered_map<std::size_t, std::string> m_filenames;
	//filetipes
	std::unordered_map<std::size_t, std::size_t> m_filetypes;

	//std::unordered_map<std::size_t, std::shared_ptr<Mesh>> m_meshes;
};