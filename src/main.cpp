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
bool g_bRunning = false;

bool init(const char *title, int x, int y, int width, int height, int flags);
void render();

/**
 *  That old C thing.
 *
 *  @param argc Number of arguments.
 *  @param argv Array of arguments.
 *  @return Exit code.
 */
int main(int argc, char *argv[]) {
	// Initialize SDL.
	g_bRunning = init("The Ultimate Old School Console",
					  SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
					  640, 480,
					  SDL_WINDOW_SHOWN);

	// Check if the initialization was successful.
	if (!g_bRunning) {
		return 1;
	}

	// Render loop.
	while (g_bRunning) {
		render();
	}

	// Clean up SDL.
	SDL_Quit();

	return 0;
}

/**
 *  Initialize SDL.
 *
 *  @param title Window title.
 *  @param x Window X position.
 *  @param y Window Y position.
 *  @param width Window width.
 *  @param height Window height.
 *  @param flags SDL init flags.
 *  @return True if everything initialized corrrectly.
 */
bool init(const char *title, int x, int y, int width, int height, int flags) {
	// Initialize SDL.
	int sdl_init_status = SDL_Init(SDL_INIT_EVERYTHING);
	if (sdl_init_status >= 0) {
		// Create a window.
		g_pWindow = SDL_CreateWindow(title, x, y, width, height, flags);

		// Create the renderer.
		if (g_pWindow != 0) {
			g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
		} else {
			cout << "Couldn't create the SDL window: " << g_pWindow << endl;
			return false;
		}
	} else {
		cout << "There was an error while trying to initialize SDL: " << sdl_init_status << endl;
		return false;
	}

	return true;
}

void render() {
	// Set to black.
	SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 0, 255);

	// Clear window to black.
	SDL_RenderClear(g_pRenderer);

	// Show the window.
	SDL_RenderPresent(g_pRenderer);
}
