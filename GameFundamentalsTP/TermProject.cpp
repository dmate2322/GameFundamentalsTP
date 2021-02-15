#include <iostream>
#include <SDL.h>

int main(int argc, char* args[])
{

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "Success!" << std::endl;
	}
	system("Pause");
	return 0;



}