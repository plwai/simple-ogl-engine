#ifndef GAME_H
#define GAME_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glfw/glfw3.h>

#include <ResourceManager.h>
#include <Renderer/SpriteRenderer.h>
#include <Renderer/TextRenderer.h>
#include <Audio/AudioEngine.h>

#include "PostProcessor.h"
#include "GameImpl.h"

class Game {
	public:
		Game(GLuint width, GLuint height);
		~Game();
		void init();
		void processInput(GLfloat dt);
		void update(GLfloat dt);
		void render();
		void clearBuffer();

		// Accessors
		Screen getScreen();
		GameState getState();
		GLboolean getKeys(GLuint key);
		GLboolean getKeysProcessed(GLuint key);
		
		// Mutators
		void setScreen(GLuint width, GLuint height);
		void setState(GameState state);
		void setKeys(GLuint key, GLboolean isPress);
		void setKeysProcessed(GLuint key, GLboolean isPress);

	private:
		GameState state;
		GLboolean keys[1024];
		GLboolean keysProcessed[1024];
		Screen screen;

		Renderer2D* spriteRenderer;
		TextRenderer* textRenderer;
		PostProcessor* effect;
		ResourceManager* resMgr;
		AudioEngine* audioEngine;

		static GameImpl* gameImplementation;
};

#endif // !GAME_H
