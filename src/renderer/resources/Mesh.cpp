#include "Mesh.hpp"
#include "State.hpp"
#include <unordered_map>
#include <filesystem>
#define TINYOBJLOADER_IMPLEMENTATION  
#include "../lib/tinyobjloader-master/tiny_obj_loader.h"

Mesh::Mesh(std::size_t id, shared_buffer buffer, Material* material)
{
	m_id = id;
	addBuffer(buffer,*material);
	//name
}

bool Mesh::load(const char* filepath)
{
	m_filepath = filepath;
	m_isLoad = true;

	if(m_filepath != "") 
		setup(); //obj	

	return isLoaded();
}

void Mesh::unload()
{
	m_isLoad = false;
	printf("Unload mesh\n");
}

void Mesh::addBuffer(shared_buffer buffer, const Material& material)
{
	//Vec_Buffers.emplace_back(std::make_pair(buffer, shader));
	if (buffer)
	{
		buffers.push_back(buffer);
		//printf("Buffer agregado. Total ahora: %d", getNumBuffers());
	}
	materials.push_back(material);
	//shaders.push_back(shader ? shader : State::defaultShader);
}

size_t Mesh::getNumBuffers() const
{
	//return Vec_Buffers.size();
	return buffers.size();
}

shared_buffer Mesh::getBuffer(size_t index) const
{
	//return Vec_Buffers.at(index).first;
	return buffers.at(index);
}

const Material& Mesh::getMaterial(size_t index) const
{
	return materials.at(index);
}

Material& Mesh::getMaterial(size_t index)
{
	return materials.at(index);
}

void Mesh::draw()
{
	//mvp
	//glm::mat4 mvp = State::projectionMatrix * State::viewMatrix * State::modelMatrix;

	for (size_t i = 0; i < buffers.size(); ++i) {
		/*GLint uniMVP = glGetUniformLocation(shaders[i]->getID(), "mvp");
		shaders[i]->setMatrix(uniMVP, mvp);*/
		materials[i].prepare();
		Shader& shader = *materials[i].getShader();
		buffers[i]->draw(shader);

		shader.use();
	}
}

void Mesh::setup()
{
	tinyobj::attrib_t attrib;
	std::vector<tinyobj::shape_t> shapes;
	std::vector < tinyobj::material_t> materials;
	std::string warn, err;

	//almacenar vertices e indices
	std::vector<Vertex> vertices;
	std::vector<uint16_t> indices;
	//paths de textura
	/*std::vector<const char*> texturePaths;*/
	//save vertex index for evoit duplicates
	std::unordered_map<std::string, uint16_t> uniqueVertex;

	std::unordered_map<int, std::vector<Vertex>> materialVertices;
	std::unordered_map<int, std::vector<uint16_t>> materialIndices;

	std::string mtldirectory = std::filesystem::path(m_filepath).parent_path().string() + "/";

	if (!tinyobj::LoadObj(&attrib, &shapes, &materials, &warn, &err, m_filepath.c_str(), mtldirectory.c_str(), true))
	{
		m_isLoad = false;
		throw std::runtime_error(warn + err);
	}
	
	for (const auto& shape : shapes) //loop shapes
	{
		size_t index_offset = 0; //offset index

		for (size_t f = 0; f < shape.mesh.num_face_vertices.size();f++) //Loop faces
		{
			int material_id = shape.mesh.material_ids[f]; // material ID of current face

			for (size_t v = 0; v < shape.mesh.num_face_vertices[f]; v++) { //Loop vertices of each face
				tinyobj::index_t idx = shape.mesh.indices[index_offset + v];

				Vertex vertexAux = {};
				//extract position of Vertex
				vertexAux.position.x = attrib.vertices[3 * idx.vertex_index + 0];
				vertexAux.position.y = attrib.vertices[3 * idx.vertex_index + 1];
				vertexAux.position.z = attrib.vertices[3 * idx.vertex_index + 2];
				//extract texture coordinates
				if (!attrib.texcoords.empty())
				{
					vertexAux.textureCord.x = attrib.texcoords[2 * idx.texcoord_index + 0];
					vertexAux.textureCord.y = attrib.texcoords[2 * idx.texcoord_index + 1];
				}
				else
				{
					vertexAux.textureCord.x = 0.0f;
					vertexAux.textureCord.y = 0.0f;
				}
				//extract color
				vertexAux.color.r = 1.f;
				vertexAux.color.g = 1.f;
				vertexAux.color.b = 1.f;

				materialVertices[material_id].push_back(vertexAux); //save vertex asociated with current material
				materialIndices[material_id].push_back(static_cast<uint16_t>(materialIndices[material_id].size()));//save index size asociated with current material
			}

			index_offset += shape.mesh.num_face_vertices[f]; //add num vertex of current face
			// Evitar duplicados y generar índice
			/*std::string key = std::to_string(index.vertex_index) + "/" +
				std::to_string(index.texcoord_index) + "/" +
				std::to_string(index.normal_index);

			if (uniqueVertex.find(key) == uniqueVertex.end()) {
				uniqueVertex[key] = static_cast<uint16_t>(vertices.size());
				vertices.push_back(vertexAux);
			}*/
			//save index
			//indices.push_back(uniqueVertex[key]);

			/*meshAux->m_vertexArray->push_back(*vertexAux);
			meshAux->m_indexArray.push_back(meshAux->m_indexArray.size());*/
		}
	}
	// extract mat and textures
	//for (const auto& material : materials)
	//{
	//	if (!material.ambient_texname.empty()) {
	//		std::string fullPath = "../data/" + material.ambient_texname;
	//		texturePaths.push_back(fullPath.c_str());
	//	}
	//}
	for (size_t i = 0; i < materials.size(); i++)
	{
		if (materialVertices[i].empty()) continue;

		//Create buffer with vertex/index of current material
		std::shared_ptr<Buffer> buffer = std::make_shared<Buffer>(materialVertices[i], materialIndices[i]);
		std::shared_ptr<Material> mat = std::make_shared<Material>(i); // m_resourceManager.loadResource<Material>(materials[i].name);
		//Cargar textura y material
		if (!materials[i].ambient_texname.empty()) {
			std::string texturePath = mtldirectory + materials[i].ambient_texname;
			texturePaths.push_back(texturePath);
			//mat->setTexture(LoadTexture2D(texturePath.c_str()));
		}
		addBuffer(buffer, *mat);
	}

	m_isLoad = true;
	//texturas, vertices e indices
	// falta construir el Material , anadir los buffers y listo
	//addBuffer(std::shared_ptr<)
	//std::vector<std::vector<uint16_t>> indexGroups = { indices };
	//Add buffer
	//std::shared_ptr<Buffer> buffer = std::make_shared<Buffer>(vertices,indices);
	//addBuffer(buffer, material);
}
