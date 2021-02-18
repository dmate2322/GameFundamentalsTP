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
		//initialization successful

		int flags = 0;

		if (fullscreen)
		{
			flags = SDL_WINDOW_FULLSCREEN;
		}


		//initialize the window
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);



		if (m_pWindow != 0)
		{
			//window creation successful

			//set up renderer
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

			if (m_pRenderer != 0)
			{
				//renderer creation successful
				SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 255, 255);
			}
			else
			{
				//renderer init failed
				return false;
			}
		}
		else
		{
			//SDL Init failed
			return false;
		}

		//init success! start running the main loop
		m_bRunning = true;

		return true;
	}

	//init failed
	return false;
}

void Game::prepare()
{

	meteor4 = Sprite(m_pRenderer, "meteorSmall.png", 0, 0, 100, 100, 475, 200, 25, 25);
	meteor3 = Sprite(m_pRenderer, "meteorSmall.png", 0, 0, 100, 100, 400, 200, 35, 35);
	meteor2 = Sprite(m_pRenderer, "meteorMed.png", 0, 0, 100, 100, 300, 200, 50, 50);
	meteor1 = Sprite(m_pRenderer, "meteorBig.png", 0, 0, 100, 100, 200, 200, 75, 75);
	alienMissle = Sprite(m_pRenderer, "alienMissle2.png", 0, 0, 100, 100, 110, 75, 25, 25);
	enemyMissle2 = Sprite(m_pRenderer, "enemyMissle2.png", 0, 0, 100, 100, 60, 75, 25, 25);
	enemyMissle1 = Sprite(m_pRenderer, "enemyMissle1.png", 0, 0, 200, 200, 17, 75, 25, 25);
	allyMissle = Sprite(m_pRenderer, "allyMissle.png", 0, 0, 200, 200, 17, 350, 25, 25);
	alienShip = Sprite(m_pRenderer, "alienShip.png", 0, 0, 200, 200, 100, 0, 50, 50);
	enemyShip2 = Sprite(m_pRenderer, "enemyShip2.png", 0, 0, 200, 200, 50, 0, 50, 50);
	enemyShip1 = Sprite(m_pRenderer, "enemyShip1.png", 50, 50);
	ship = Sprite(m_pRenderer, "allyShip.png", 0, 0, 200, 200, 0, 400, 50, 50);
	background = Sprite(m_pRenderer, "background.png", 0, 0, 640, 480, 0, 0, 640, 480);

}

void Game::handleEvents()
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			m_bRunning = false;
			break;
		case SDL_KEYDOWN:

		default:
			break;
		}
	}

}

void Game::update()
{
}

void Game::render()
{

	SDL_RenderClear(m_pRenderer);


	background.draw(m_pRenderer);


	ship.draw(m_pRenderer);
	enemyShip1.draw(m_pRenderer);
	enemyShip2.draw(m_pRenderer);
	alienShip.draw(m_pRenderer);
	allyMissle.draw(m_pRenderer);
	enemyMissle1.draw(m_pRenderer);
	enemyMissle2.draw(m_pRenderer);
	alienMissle.draw(m_pRenderer);
	meteor1.draw(m_pRenderer);
	meteor2.draw(m_pRenderer);
	meteor3.draw(m_pRenderer);
	meteor4.draw(m_pRenderer);


	//draw to the screen
	SDL_RenderPresent(m_pRenderer);
}


void Game::cleanup()
{
	//cleaning game

	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}

