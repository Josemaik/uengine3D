#pragma once

#include <unordered_map>
#include <memory>
#include <vector>
#include <array>
#include "../resources/Mesh.hpp"

class ResourceManager
{
public:
	template<typename T>
	std::shared_ptr<T>& loadResource(std::vector<Vertex>& vertices, std::array<uint16_t, 3>& indices)
	{
		std::shared_ptr<Buffer> buffer = std::make_shared<Buffer>(vertices, indices);
		std::shared_ptr<Mesh> mesh = std::make_shared<Mesh>();
		mesh->addBuffer(buffer);

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