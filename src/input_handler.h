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
#include "games.h"

class InputHandler {
	private:
		GameConsole *m_pGameConsole;
		Games *m_pGames;
		const uint8_t *m_keystates;

	public:
		InputHandler(GameConsole *game_console, Games *games);

		bool update();

		bool is_key_down(SDL_Scancode key);
		void on_key_down();
};

#endif
