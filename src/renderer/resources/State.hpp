#pragma once

#include <memory>
#include "../glm/mat4x4.hpp"
#include "Shader.h"
#include "../components/Light.hpp"

struct State
{
public:
	//default Shader
	static inline std::shared_ptr<Shader> defaultShader = nullptr;
	static inline glm::mat4 projectionMatrix = glm::mat4(1.f);
	static inline glm::mat4 viewMatrix = glm::mat4(1.f);
	static inline glm::mat4 modelMatrix = glm::mat4(1.f);
	//World lights
	static std::vector<std::shared_ptr<Light>> lights;
	static inline glm::vec3 ambient;
};