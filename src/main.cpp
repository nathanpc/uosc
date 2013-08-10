/**
 *  UOSC
 *  The ultimate old school console.
 *
 *  @author Nathan Campos <nathanpc@dreamintech.net>
 */

#include <iostream>
#include <string>
#include <SDL.h>

#include "graphics.h"

using namespace std;

Graphics *g_graphics = 0;

/**
 *  That old C thing.
 *
 *  @param argc Number of arguments.
 *  @param argv Array of arguments.
 *  @return Exit code.
 */
int main(int argc, char *argv[]) {
	// Initialize SDL.
	g_graphics = new Graphics();
	g_graphics->g_bRunning = g_graphics->init("The Ultimate Old School Console",
											  SDL_WINDOWPOS_CENTERED,
											  SDL_WINDOWPOS_CENTERED,
											  640, 480,
											  SDL_WINDOW_SHOWN);

	// Check if the initialization was successful.
	if (!g_graphics->g_bRunning) {
		return 1;
	}

	// Render loop.
	while (g_graphics->g_bRunning) {
		g_graphics->handle_events();
		g_graphics->update();
		g_graphics->render();
	}

	g_graphics->clean();

	return 0;
}
