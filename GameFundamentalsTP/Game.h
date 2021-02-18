#ifndef __GAME__
#define __GAME__

#include <SDL.h>
#include "Sprite.h"

class Game
{

public:

	Game();
	~Game();

	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	//We do one time preparation stuff here
	void prepare();

	void render();
	void update();
	void handleEvents();
	void cleanup();

	//function to aaccess the running variable
	bool running() { return m_bRunning; }
private:

	Sprite ship;
	Sprite background;
	Sprite enemyShip1, enemyShip2, alienShip;
	Sprite allyMissle, enemyMissle1, enemyMissle2, alienMissle;
	Sprite meteor1, meteor2, meteor3, meteor4;


	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;

	bool m_bRunning;
};

#endif /* defined (__Game__) */

