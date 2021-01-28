#include <iostream>
#include "sdl.h"
using namespace std;


int main(int argc, char* argv[])
{
	SDL_Window* p_window; // Pointer to window that SDL manages
	SDL_Renderer* p_renderer; // Back buffer/assembly area for objects

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) // 0 means fine!
	{
		cout << "SDL innitialized!" << endl;
	}
	else
	{
		cout << "Problem innitializing SDL! Problem report :" << SDL_GetError << endl;
		return 1; // Immediately exits program
	}

	p_window = SDL_CreateWindow("HEllo world", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
		1024, 1024, NULL);
	p_renderer = SDL_CreateRenderer(p_window, -1, NULL);
	// Initialization done

	SDL_SetRenderDrawColor(p_renderer, 255, 124, 0, 255); //0-255 for eache color channel
	SDL_RenderClear(p_renderer); // 'paint over' window with draw color
	SDL_RenderPresent(p_renderer); // refreshes window
	system("pause");
	SDL_DestroyRenderer(p_renderer);
	SDL_DestroyWindow(p_window);
	SDL_Quit();
	return 0;
}