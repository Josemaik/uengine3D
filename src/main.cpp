#ifdef _MSC_VER
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
#endif

//std
#include <iostream>
#include <vector>
#include <array>
//strings
#include <sstream>
#include <fstream>
#include <string>



//#include "managers/GameEngine.hpp"
#include "managers/EntityFactory.hpp"
#include "ECS/types.hpp"
#include "ECS/systems/RenderSystem.hpp"
#include "ECS/systems/InputSystem.hpp"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

int main() {
	//Init Engine
	ENGI::GameEngine engine(SCREEN_WIDTH, SCREEN_HEIGHT);
	//Init ECS
	EntityManager em{};
	EntityFactory ef{};
	//systems
	RenderSystem rsys{};
	InputSystem insys{};

	//Create Triangles
	//ef.CreateTriangles(em);
	//ef.CreateCube(em);
	ef.CreateBoxStack(em);
	ef.CreateGunSlinger(em);

	//Load Models
	rsys.LoadModels(em, engine);
	
	// main loop
	double lastTime = engine.GetTime();
	while (!engine.windowShouldClose() && !engine.IsKeyDown(GLFW_KEY_ESCAPE)) {
		// get delta time
		float deltaTime = static_cast<float>(engine.GetTime() - lastTime);
		lastTime = engine.GetTime();

		//Begin Frame
		engine.beginFrame();
		//Update render system
		insys.update(engine, deltaTime);
		rsys.update(em, deltaTime);
		//End frame
		engine.EndFrame();
	}
	//Free Memory
	rsys.UnloadModels(em);
	// shutdown
	engine.CloseWindow();
	return 0;
}