/**
 *  graphics.cpp
 *  Interacts with SDL.
 *
 *  @author Nathan Campos <nathanpc@dreamintech.net>
 */

#include <iostream>
#include <string>
#include <SDL.h>

#include "graphics.h"
#include "game_console.h"
#include "input_handler.h"
using namespace std;

/**
 *  Constructor.
 */
Graphics::Graphics() {
	m_pWindow = 0;
	m_pRenderer = 0;
	m_pGameConsole = 0;
	m_pInputHandler = 0;

	g_bRunning = false;
}

/**
 * Destructor.
 */
Graphics::~Graphics() {
	clean();
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
bool Graphics::init(const char *title, int x, int y, int width, int height, int flags) {
	// Initialize SDL.
	int sdl_init_status = SDL_Init(SDL_INIT_EVERYTHING);
	if (sdl_init_status >= 0) {
		// Create a window.
		m_pWindow = SDL_CreateWindow(title, x, y, width, height, flags);

		// Create the renderer.
		if (m_pWindow != 0) {
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
			m_pGameConsole = new GameConsole(m_pRenderer);
		} else {
			cout << "Couldn't create the SDL window: " << m_pWindow << endl;
			return false;
		}

		// Initialize input handler.
		m_pInputHandler = new InputHandler(m_pGameConsole);
	} else {
		cout << "There was an error while trying to initialize SDL: " << sdl_init_status << endl;
		return false;
	}

	if (!m_pGameConsole->add("gameboy")) {
		return false;
	}
	if (!m_pGameConsole->add("nes")) {
		return false;
	}
	if (!m_pGameConsole->add("psone")) {
		return false;
	}
	if (!m_pGameConsole->add("dos")) {
		return false;
	}

	return true;
}

/**
 *  Update stuff.
 */
void Graphics::update() {
	// Set to black.
	SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255);
}

/**
 *  Handles events.
 */
void Graphics::handle_events() {
	g_bRunning = m_pInputHandler->update();
}

/**
 *  Render stuff.
 */
void Graphics::render() {
	// Clear window.
	SDL_RenderClear(m_pRenderer);

	m_pGameConsole->draw();

	// Show the window.
	SDL_RenderPresent(m_pRenderer);
}

/**
 *  Clean all the trash.
 */
void Graphics::clean() {
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}
