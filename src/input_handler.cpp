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

#include "input_handler.h"
#include "game_console.h"
#include "window_properties.h"
using namespace std;

/**
 *  Constructor.
 */
InputHandler::InputHandler(GameConsole *game_console) {
	m_pGameConsole = game_console;
}

bool InputHandler::update() {
	m_keystates = SDL_GetKeyboardState(0);
	SDL_Event event;

	if (SDL_PollEvent(&event)) {
		switch (event.type) {
			case SDL_QUIT:
				return false;
			break;

			case SDL_KEYDOWN:
				on_key_down();
			break;

			default:
			break;
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
		m_pGameConsole->previous();
	} else if (is_key_down(SDL_SCANCODE_RIGHT)) {
		m_pGameConsole->next();
	}
}
