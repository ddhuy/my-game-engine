#ifndef __GAME_H__
#define __GAME_H__

#include <SDL2/SDL.h>

const int FPS = 60;
const int MILLISECS_PER_FRAME = 1000 / FPS;

class Game
{
public:
	Game();
	~Game();

	void Initialize();
	void Run();
	void ProcessInput();
	void Setup();
	void Update();
	void Render();
	void Destroy();


private:
	bool isRunning = false;
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;

	size_t windowWidth;
	size_t windowHeigh;

	int millisecsPreviousFrame;
};

#endif // __GAME_H__
