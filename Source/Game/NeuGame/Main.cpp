#include "Core/Core.h"
#include "Renderer/Renderer.h"
#include "Renderer/ModelManager.h"
#include "Renderer/Font.h"
#include "Renderer/Text.h"
#include "Input/InputSystem.h"
#include "Audio/AudioSystem.h"
#include "Framework/Scene.h"
#include "Player.h"
#include "Enemy.h"

#include "Renderer/Particle.h"
#include "Renderer/ParticleSystem.h"
#include "Framework/Emitter.h"

#include "SpaceGame.h"

#include <iostream>
#include <vector>
#include <thread>
#include <memory>

using namespace std;

int main(int argc, char* argv[])
{
	lola::MemoryTracker::Initialize();
	lola::seedRandom((unsigned int)time(nullptr));
	lola::setFilePath("assets");

	lola::g_renderer.Initialize();
	lola::g_renderer.CreateWindow("CSC196", 800, 600);

	lola::g_inputSystem.Initialize();
	lola::g_audioSystem.Initialize();

	unique_ptr<SpaceGame> game = make_unique<SpaceGame>();
	game->Initialize();

	// Main Game Loop
	bool quit = false;
	while (!quit)
	{
		// Update Engine
		lola::g_time.Tick();
		lola::g_inputSystem.Update();

		if (lola::g_inputSystem.GetKeyDown(SDL_SCANCODE_ESCAPE))
		{
			quit = true;
		}

		// Update Game
		game->Update(lola::g_time.GetDeltaTime());
		lola::g_audioSystem.Update();
		lola::g_particleSystem.Update(lola::g_time.GetDeltaTime());

		// Draw Game
		lola::g_renderer.SetColor(0, 0, 0, 0);
		lola::g_renderer.BeginFrame();
		lola::g_particleSystem.Draw(lola::g_renderer);

		game->Draw(lola::g_renderer);

		lola::g_renderer.EndFrame();
	}

	return 0;
}