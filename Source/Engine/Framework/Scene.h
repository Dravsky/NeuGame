#pragma once
#include "Actor.h"
#include <list>

#include "NeuGame/Player.h"

namespace lola 
{
	class Renderer; //Substitute to #include, only works if passing a reference.

	class Scene 
	{
	public:
		Scene() = default;

		void Update(float dt);
		void Draw(Renderer& renderer);

		void Add(std::unique_ptr<Actor> actor);
		void RemoveAll();
		Actor GetPlayer();

		template<typename T>
		T* GetActor();

		friend class Scene;

	private:
		std::list<std::unique_ptr<Actor>> m_actors;
	};

	template<typename T>
	inline T* Scene::GetActor() 
	{
		for (auto& actor : m_actors)
		{
			T* result = dynamic_cast<T*>(actor.get());
			if (result) return result;
		}

		return nullptr;
	}
}