/**
 *  graphics.cpp
 *  Interacts with SDL.
 *
 *  @author Nathan Campos <nathanpc@dreamintech.net>
 */

#include <iostream>
#include <string>
#include <map>
#include <SDL.h>
#include <boost/filesystem.hpp>

#include "graphics.h"
#include "game_console.h"
#include "games.h"
#include "input_handler.h"
#include "config.h"

using namespace std;
namespace fs = boost::filesystem;

/**
 *  Constructor.
 */
Graphics::Graphics() {
	m_pWindow = 0;
	m_pRenderer = 0;
	m_pGameConsole = 0;
	m_pGames = 0;
	m_pInputHandler = 0;
	m_pConfig = new Config("config.yml");

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
			m_pGames = new Games(m_pRenderer);
		} else {
			cout << "Couldn't create the SDL window: " << m_pWindow << endl;
			return false;
		}

		// Initialize input handler.
		m_pInputHandler = new InputHandler(m_pGameConsole, m_pGames);
	} else {
		cout << "There was an error while trying to initialize SDL: " << sdl_init_status << endl;
		return false;
	}

	if (!populate_values()) {
		return false;
	}

	return true;
}

/**
 *  Populates the consoles and games.
 */
bool Graphics::populate_values() {
	map<string, map<string, string> > emulators = m_pConfig->emulators();
	for (auto it = emulators.begin(); it != emulators.end(); ++it) {
		// Add game console.
		if (!m_pGameConsole->add(it->first, it->second["icon"])) {
			cout << "Error while populating game consoles: (" << it->first << ") " << it->second["icon"] << endl;
			return false;
		}

		// Populate games.
		vector<string> games;
		fs::directory_iterator end_iter;

		// Iterate through the ROMs directory.
		for (fs::directory_iterator dir_itr(it->second["roms"]); dir_itr != end_iter; ++dir_itr) {
			try {
				// Ignore hidden directories.
				if (dir_itr->path().filename().c_str()[0] != '.') {
					// Ignore directories.
					if (fs::is_regular_file(dir_itr->status())) {
						games.push_back(string(dir_itr->path().c_str()));
					}
				}
			} catch (const exception &e) {
				cout << "Error while populating games: " << dir_itr->path().filename() << ": " << e.what() << endl;
				return false;
			}
		}

		// Add games.
		m_pGames->add(it->first, it->second["exec"], games);
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

	// Draw the collumns.
	m_pGameConsole->draw();

	// Draw the rows.
	m_pGames->draw(m_pGameConsole->get_selected_id());

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
