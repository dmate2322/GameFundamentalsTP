
#include "Game.h"




Game* g_game = 0;

int main(int argc, char* args[]) // Main MUST have these parameter for SDL.
{
	g_game = new Game();


	g_game -> init("SDL_Window",100,100,640,480,false);

	while (g_game->running())
	{
		g_game->handleEvents();
		g_game->update();
		g_game->render();
	}

	g_game->cleanup();

	return 0;
}