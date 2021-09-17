#include "Mode.hpp"

#include "Scene.hpp"

#include <glm/glm.hpp>

#include <vector>
#include <deque>

struct PlayMode : Mode {
	PlayMode();
	virtual ~PlayMode();

	//functions called by main loop:
	virtual bool handle_event(SDL_Event const &, glm::uvec2 const &window_size) override;
	virtual void update(float elapsed) override;
	virtual void draw(glm::uvec2 const &drawable_size) override;

	//----- game state -----

	//input tracking:
	struct Button {
		uint8_t downs = 0;
		uint8_t pressed = 0;
	} left, right, down, up;

	//local copy of the game scene (so code can change it during gameplay):
	Scene scene;

	// transform pointers
	Scene::Transform *mouse = nullptr;
	std::vector<Scene::Transform *> carrots; 

	// transform infos
	glm::quat mouse_offset_rotation;
	glm::vec3 mouse_offset_forward;
	glm::quat mouse_move_roration = glm::quat(1.0f, 0.0f, 0.0f, 0.0f);
	float wobble = 0.0f;
	
	//camera:
	Scene::Camera *camera = nullptr;

	// game play
	float ratateSpeed = 90.0f; // degree
	float moveSpeed = 30.0f;

};
