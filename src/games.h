/**
 *  games.h
 *  Handles the game "rows" in the interface.
 *
 *  @author Nathan Campos <nathanpc@dreamintech.net>
 */

#ifndef GAMES_H_
#define GAMES_H_

#include <string>
#include <map>
#include <vector>
#include <SDL.h>

#include "text.h"

class Games {
	private:
		Text *m_pText;
		std::map<std::string, std::vector<std::string> > m_mGames;
		std::map<std::string, std::string> m_mEmulators;
		std::vector<std::string> m_vConsoles;
		unsigned int m_selected;

		unsigned int m_ypos;
		unsigned int m_height;
		unsigned int y;

	public:
		Games(SDL_Renderer *renderer);

		bool add(std::string console, std::string emulator, std::vector<std::string> games);
		void draw(std::string console);

		void previous(std::string console);
		void next(std::string console);

		void reset_selected();
		void refresh_pos();

		void execute(std::string console);
};

#endif
