#ifndef __GAME_H__
#define __GAME_H__

class Game
{
public:
	Game();
	~Game();

	void Initialize();
	void Run();
	void ProcessInput();
	void Update();
	void Render();
	void Destroy();
};

#endif // __GAME_H__
