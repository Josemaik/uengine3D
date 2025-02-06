#pragma once

#include <memory>
#include "../glm/mat4x4.hpp"
#include "Shader.h"

struct State
{
	static std::shared_ptr<Shader> defaultShader;
	static glm::mat4 projectionMatrix;
	static glm::mat4 viewMatrix;
	static glm::mat4 modelMatrix;
};