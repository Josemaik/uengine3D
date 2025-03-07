#pragma once

//Componentes
#include "components/RenderComponent.hpp"
//Singletons
#include "../renderer/resources/State.hpp"
//#include "sngtn/GameData.hpp"
//#include "sngtn/PlayerInfo.hpp"
//Entity Manager
#include "Entitymanager.hpp"
#include "../managers/GameEngine.hpp"
//#include "../managers/GameEngine.hpp"
//Metaprogramación
#include "meta_program.hpp"

//Fordward declaration
namespace ENGI { class GameEngine; }

//declare TAGS
//draw
struct triangleTag{};
struct boxTag{};
struct boxStackTag{};
struct gunslingerTag{};

//COMPONENTS
using CL = MP::TypeList <
	RenderComponent
>;

//TAGS
using TL = MP::TypeList <
	triangleTag,
	boxTag,
	boxStackTag,
	gunslingerTag
>;
//SINGLETONS
using SCL = MP::TypeList <
	State
>;

using EntityManager = ETMG::EntityManager<CL,TL,SCL>;
using Entity = EntityManager::Entity;
using GameEngine = ENGI::GameEngine;

//Definimos variables globales 
static int Screenwidth = 800; //el alto y ancho de la ventana
static int Screenheight = 600;