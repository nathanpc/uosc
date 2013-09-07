/**
 *  input_handler.cpp
 *  Handles input.
 *
 *  @author Nathan Campos <nathanpc@dreamintech.net>
 */

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <SDL.h>
#include <cstdlib>

#include "input_handler.h"
#include "game_console.h"
#include "games.h"
#include "window_properties.h"
using namespace std;

/**
 *  Constructor.
 */
InputHandler::InputHandler(GameConsole *game_console, Games *games) {
	m_pGameConsole = game_console;
	m_pGames = games;
}

bool InputHandler::update() {
	m_keystates = SDL_GetKeyboardState(0);
	SDL_Event event;

	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) {
			return false;
		} else if (event.type == SDL_KEYDOWN) {
			on_key_down();
		} else if (event.type == SDL_WINDOWEVENT) {
			switch (event.window.event) {
			case SDL_WINDOWEVENT_RESIZED:
				SDL_Log("Window %d resized to %dx%d",
						event.window.windowID, event.window.data1,
						event.window.data2);

				WindowProperty::resize(event.window.data1, event.window.data2);
				m_pGameConsole->refresh_pos();
				m_pGames->refresh_pos();
				break;
			}
		}
	}

	return true;
}

bool InputHandler::is_key_down(SDL_Scancode key) {
	if (m_keystates != 0) {
		if (m_keystates[key] == 1) {
			return true;
		} else {
			return false;
		}
	}

	return false;
}

void InputHandler::on_key_down() {
	if (is_key_down(SDL_SCANCODE_LEFT)) {
		// Left
		m_pGameConsole->previous(m_pGames);
	} else if (is_key_down(SDL_SCANCODE_RIGHT)) {
		// Right
		m_pGameConsole->next(m_pGames);
	} else if (is_key_down(SDL_SCANCODE_UP)) {
		// Up
		m_pGames->previous(m_pGameConsole->get_selected_id());
	} else if (is_key_down(SDL_SCANCODE_DOWN)) {
		// Down
		m_pGames->next(m_pGameConsole->get_selected_id());
	} else if (is_key_down(SDL_SCANCODE_RETURN)) {
		// Enter
		m_pGames->execute(m_pGameConsole->get_selected_id());
	} else if (is_key_down(SDL_SCANCODE_ESCAPE)) {
		// Escape
		SDL_Quit();
		exit(0);
	}
}
