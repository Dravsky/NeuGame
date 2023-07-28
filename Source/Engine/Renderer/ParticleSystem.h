#pragma once
#include "Core/Core.h"
#include "Particle.h"
namespace lola {
	class ParticleSystem
	{
	public:
		ParticleSystem() = default;
		ParticleSystem(int maxCount)
		{
			m_particles.resize(maxCount);
		}
		void Update(float dt);
		void Draw(Renderer& renderer);
		Particle* GetFreeParticle();
	private:
		std::vector<Particle> m_particles;
	};

	extern ParticleSystem g_particleSystem;
}