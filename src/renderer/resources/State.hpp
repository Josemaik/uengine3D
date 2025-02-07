#pragma once

#include <memory>
#include "../glm/mat4x4.hpp"
#include "Shader.h"

struct State
{
public:
	static inline std::shared_ptr<Shader> defaultShader = nullptr;
	static inline glm::mat4 projectionMatrix = glm::mat4(1.f);
	static inline glm::mat4 viewMatrix = glm::mat4(1.f);
	static inline glm::mat4 modelMatrix = glm::mat4(1.f);
};