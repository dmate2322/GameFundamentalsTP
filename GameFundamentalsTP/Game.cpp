#include "Game.h"

Game::Game()
{
}

Game::~Game()
{
}

bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{

		int flags = 0;
		if (fullscreen)
		{
			flags = SDL_WINDOW_FULLSCREEN;
		}

		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (m_pWindow != 0)
		{
			//window creation successful

			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

			if (m_pRenderer != 0)
			{
				//renderer creation successful
				SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 255, 255); // colour blue
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
		
		m_bRunning = true;
		return true;
	}

	return false; // init failed
}

void Game::render()
{
	SDL_RenderClear(m_pRenderer); // to clear renderer during every frame
	SDL_RenderPresent(m_pRenderer); // rerender the screen
}

void Game::update()
{
}

void Game::handleEvents()
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			m_bRunning = false; // stop running our game when the quit event is raised, aka when the X is hit

		default:
			break;

		}
	}
}

void Game::cleanup() // does all this to avoid memory leaks
{
	SDL_DestroyWindow(m_pWindow); // destroys window
	SDL_DestroyRenderer(m_pRenderer); // destroys render
	SDL_Quit();
}