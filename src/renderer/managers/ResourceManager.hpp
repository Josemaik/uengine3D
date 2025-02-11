#pragma once

#include <unordered_map>
#include <memory>
#include <vector>
#include <array>
#include "../resources/Mesh.hpp"
#include "../resources/Material.hpp"

class ResourceManager
{
public:
	template<typename T>
	std::shared_ptr<T>& loadResource(std::vector<const char*>& filepaths,std::vector<Vertex>& vertices, std::array<uint16_t, 3>& indices)
	{
		//Mesh
		std::shared_ptr<Mesh> mesh = std::make_shared<Mesh>();
		//Buffer
		std::shared_ptr<Buffer> buffer = std::make_shared<Buffer>(vertices, indices);
		//Materials
		for(auto& path : filepaths)
		{
			std::shared_ptr<Material> mat = std::make_shared<Material>();
			std::shared_ptr<Texture> tex= std::make_shared<Texture>();
			if (tex->load(path))
			{
				mat->setTexture(tex);
				mesh->addBuffer(buffer, *mat);
			}
		}

		m_meshes[nextID] = mesh;

		return m_meshes[nextID++];
	}

	static ResourceManager& getInstance() {
		static ResourceManager instance;
		return instance;
	}
private:
	ResourceManager() = default;

	inline static std::size_t nextID{ 0 };
	std::unordered_map<std::size_t, std::shared_ptr<Mesh>> m_meshes;
};