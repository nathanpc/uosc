/**
 *  game_console.h
 *  Handles the game console "collumns" in the interface.
 *
 *  @author Nathan Campos <nathanpc@dreamintech.net>
 */

#ifndef GAME_CONSOLE_H_
#define GAME_CONSOLE_H_

#include <string>
#include <map>
#include <vector>
#include <SDL.h>

#include "texture_manager.h"
#include "games.h"

class GameConsole {
	private:
		TextureManager *m_pTextureManager;
		std::map<std::string, std::map<std::string, std::string> > m_mConsoles;
		std::vector<std::string> m_vIDs;
		unsigned int m_selected;

		unsigned int m_ypos;
		unsigned int m_width;
		unsigned int m_height;

	public:
		GameConsole(SDL_Renderer *renderer);

		bool add(std::string id, std::string logo);
		void draw();

		void previous(Games *games);
		void next(Games *games);

		std::string get_selected_id();
};

#endif
