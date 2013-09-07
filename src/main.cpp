/**
 *  UOSC
 *  The ultimate old school console.
 *
 *  @author Nathan Campos <nathanpc@dreamintech.net>
 */

#include <iostream>
#include <string>
#include <cstdint>
#include <unistd.h>
#include <SDL.h>

#include "graphics.h"
#include "window_properties.h"
using namespace std;

#define VERSION "0.1a"

Graphics *g_graphics = 0;

/**
 *  That old C thing.
 *
 *  @param argc Number of arguments.
 *  @param argv Array of arguments.
 *  @return Exit code.
 */
int main(int argc, char *argv[]) {
	char arg;
	int fullscreen = SDL_WINDOW_FULLSCREEN;

	// Parse arguments.
	while ((arg = getopt (argc, argv, "w")) != -1) {
		switch (arg) {
		case 'w':
			// Windowed mode.
			fullscreen = 0;
			break;
		}
	}

	// Setup our FPS limiting variables.
	uint32_t frame_start, frame_time;

	// Create the window title.
	string title = "The Ultimate Old School Console v";
	title += VERSION;

	// Initialize SDL.
	g_graphics = new Graphics();
	g_graphics->g_bRunning = g_graphics->init(title.c_str(),
											  SDL_WINDOWPOS_CENTERED,
											  SDL_WINDOWPOS_CENTERED,
											  WindowProperty::width,
											  WindowProperty::height,
											  SDL_WINDOW_RESIZABLE |
											  SDL_WINDOW_SHOWN |
											  fullscreen);

	// Check if the initialization was successful.
	if (!g_graphics->g_bRunning) {
		return 1;
	}

	// Render loop.
	while (g_graphics->g_bRunning) {
		frame_start = SDL_GetTicks();

		// Main loop.
		g_graphics->handle_events();
		g_graphics->update();
		g_graphics->render();

		frame_time = SDL_GetTicks() - frame_start;
		if (frame_time < WindowProperty::DELAY_TIME) {
			SDL_Delay((int)(WindowProperty::DELAY_TIME - frame_time));
		}
	}

	g_graphics->clean();

	return 0;
}
