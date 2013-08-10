/**
 *  game_console.h
 *
 *  @author Nathan Campos <nathanpc@dreamintech.net>
 */

#ifndef GAME_CONSOLE_H_
#define GAME_CONSOLE_H_

#include <string>
#include <map>
#include <SDL.h>

#include "texture_manager.h"

class GameConsole {
	private:
		TextureManager *m_pTextureManager;

		std::map<std::string, std::map<std::string, std::string> > m_mConsoles;

	public:
		GameConsole(SDL_Renderer *renderer);

		bool add(std::string id);
		void draw();
};

#endif
