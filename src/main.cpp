/**
 *  UOSC
 *  The ultimate old school console.
 *
 *  @author Nathan Campos <nathanpc@dreamintech.net>
 */

#include <iostream>
#include <string>
#include <SDL.h>

using namespace std;

SDL_Window *g_pWindow = 0;
SDL_Renderer *g_pRenderer = 0;

/**
 *  That old C thing.
 *
 *  @param argc Number of arguments.
 *  @param argv Array of arguments.
 *  @return Exit code.
 */
int main(int argc, char *argv[]) {
	// Initialize SDL.
	int sdl_init_status = SDL_Init(SDL_INIT_EVERYTHING);
	if (sdl_init_status >= 0) {
		// Create a window.
		g_pWindow = SDL_CreateWindow("The Ultimate Old School Console",
									 SDL_WINDOWPOS_CENTERED,
									 SDL_WINDOWPOS_CENTERED,
									 640,
									 480,
									 SDL_WINDOW_SHOWN);

		// Create the renderer.
		if (g_pWindow != 0) {
			g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
		} else {
			cout << "Couldn't create the SDL window: " << g_pWindow << endl;
			return 1;
		}
	} else {
		cout << "There was an error while trying to initialize SDL: " << sdl_init_status << endl;
		return 1;
	}

	// Set to black.
	SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 0, 255);

	// Clear window to black.
	SDL_RenderClear(g_pRenderer);

	// Show the window.
	SDL_RenderPresent(g_pRenderer);

	// Set a delay before quitting.
	SDL_Delay(5000);

	// Clean up SDL.
	SDL_Quit();

	return 0;
}
