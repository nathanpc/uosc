/**
 *  input_handler.h
 *  Handles input.
 *
 *  @author Nathan Campos <nathanpc@dreamintech.net>
 */

#ifndef INPUT_HANDLER_H_
#define INPUT_HANDLER_H_

#include <string>
#include <map>
#include <vector>
#include <cstdint>
#include <SDL.h>

#include "game_console.h"

class InputHandler {
	private:
		GameConsole *m_pGameConsole;
		const uint8_t *m_keystates;

	public:
		InputHandler(GameConsole *game_console);

		bool update();

		bool is_key_down(SDL_Scancode key);
		void on_key_down();
};

#endif
