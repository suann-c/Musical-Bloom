#pragma once

#include "Mode.hpp"

#include "MeshBuffer.hpp"
#include "GL.hpp"
#include "Scene.hpp"
#include "Sound.hpp"

#include <SDL.h>
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

#include <vector>

// The 'GameMode' mode is the main gameplay mode:

struct GameMode : public Mode {
	GameMode();
	virtual ~GameMode();

	//handle_event is called when new mouse or keyboard events are received:
	// (note that this might be many times per frame or never)
	//The function should return 'true' if it handled the event.
	virtual bool handle_event(SDL_Event const &evt, glm::uvec2 const &window_size) override;

	//update is called at the start of a new frame, after events are handled:
	virtual void update(float elapsed) override;

	//CHANGED
	//plays the order of glowing lights for player
	void playPattern(std::vector<std::string> play);

	//checks player order against correct order
	bool match(std::vector<std::string> attempt, std::vector<std::string> ref);

	//draw is called after update:
	virtual void draw(glm::uvec2 const &drawable_size) override;

	float camera_spin = 0.0f;
	float spot_spin = 0.0f;

	//CHANGED
	std::vector<std::string> playerOrder;
	std::vector<std::string> correctOrder;
	std::shared_ptr< Sound::PlayingSample > topC;
	std::shared_ptr< Sound::PlayingSample > bottomC;
	std::shared_ptr< Sound::PlayingSample > leftC;
	std::shared_ptr< Sound::PlayingSample > rightC;
	Scene::Object *generateSound;
	glm::vec3 topPos = glm::vec3(-1.029, 1.11468, 10.577);
	glm::vec3 bottomPos = glm::vec3(-0.08166, -3.51383, 3.25076);
	glm::vec3 leftPos = glm::vec3(-4.15767, .71361, 6.791);
	glm::vec3 rightPos = glm::vec3(3.8855, 0.949, 8.7663);
	bool firstRound = true;
};
