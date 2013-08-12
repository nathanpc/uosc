/**
 *  games.cpp
 *  Handles the game "rows" in the interface.
 *
 *  @author Nathan Campos <nathanpc@dreamintech.net>
 */

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cstdlib>

#include "games.h"
#include "text.h"
#include "window_properties.h"
using namespace std;

/**
 *  Constructor.
 */
Games::Games(SDL_Renderer *renderer) {
	// Initialize the text stuff.
	m_pText = new Text("assets/FreeSans.ttf", 24, renderer);

	// Set the defaults.
	m_height = 100;
	m_ypos = (WindowProperty::height / 3.5) + 50;
	m_selected = 0;
	y = m_ypos;
}

/**
 *  Adds a game.
 *
 *  @param id Game console ID.
 *  @param emulator Emulator command.
 *  @param games Array with ROMs paths.
 *  @return True if everything works fine.
 */
bool Games::add(string console, string emulator, vector<string> games) {
	// Add.
	m_mGames[console] = games;
	m_mEmulators[console] = emulator;
	m_vConsoles.push_back(console);

	return true;
}

/**
 *  Draws the games in the screen.
 */
void Games::draw(string console) {
	// Some position variables.
	//unsigned int y = m_ypos;
	const unsigned int spacing = 35;
	//unsigned int midpoint = (spacing / 2) - (m_width / 2);
	SDL_Color color = {255, 255, 255};

	// List loop.
	for (size_t i = 0; i < m_mGames[console].size(); ++i) {
		// Animate up and down.
		if (y + (spacing * m_selected) > m_ypos) {
			y -= 5;
		} else if (y + (spacing * m_selected) < m_ypos) {
			y += 5;
		}

		// TODO: Make the top one fade instead of just vanishing.
		if (i >= m_selected) {
			// Get only the name from the path.
			string title = m_mGames[console][i];
			title = title.substr(title.find_last_of("/") + 1);
			title = title.substr(0, title.find_last_of("."));

			// Print.
			m_pText->print(title, color, 0, y + (spacing * i), true);
		}
	}
}

/**
 *  Select the previous game.
 */
void Games::previous() {
	if (m_selected > 0) {
		m_selected--;
	}

	#ifdef DEBUG
	cout << "Console selected: " << m_vIDs[m_selected] << endl;
	#endif
}

/**
 *  Select the next game.
 */
void Games::next(string console) {
	if (m_selected < m_mGames[console].size() - 1) {
		m_selected++;
	}

	#ifdef DEBUG
	cout << "Game selected: " << m_mGames[console][m_selected] << endl;
	#endif
}

/**
 *  Reset the selected item (used when changing consoles).
 */
void Games::reset_selected() {
	m_selected = 0;
}

/**
 *  Start playing!
 *
 *  @param console The console ID.
 */
void Games::execute(string console) {
	// Replace {rom} with the ROM path.
	string command = m_mEmulators[console];
	command = command.substr(0, command.find("{rom}")) +
			  "\"" + m_mGames[console][m_selected] + "\"" +
			  command.substr(command.find("{rom}") + 5);

	cout << command << endl;
	system(command.c_str());
}
