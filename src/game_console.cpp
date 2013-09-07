/**
 *  game_console.cpp
 *  Handles the game console "collumns" in the interface.
 *
 *  @author Nathan Campos <nathanpc@dreamintech.net>
 */

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cstdlib>

#include "texture_manager.h"
#include "game_console.h"
#include "games.h"
#include "window_properties.h"
using namespace std;

/**
 *  Constructor.
 */
GameConsole::GameConsole(SDL_Renderer *renderer) {
	// Initialize the TextureManager.
	m_pTextureManager = new TextureManager(renderer);

	// Load the texture.
	if (!m_pTextureManager->load("all", "assets/consoles.png")) {
		cout << "Couldn't load image: assets/consoles.png" << endl;
		exit(EXIT_FAILURE);
	}

	// Set the defaults.
	refresh_pos();
	m_selected = 0;
}

/**
 *  Adds a game console.
 *
 *  @param id Game console ID.
 *  @param x Sprite X.
 *  @param y Sprite Y.
 *  @return True if everything worked fine.
 */
bool GameConsole::add(string id, string x, string y) {
	// Prepare the console properties map.
	map<string, string> console;
	console["x"] = x;
	console["y"] = y;

	// Add.
	m_mConsoles[id] = console;
	m_vIDs.push_back(id);

	return true;
}

/**
 *  Draws the game consoles in the screen.
 */
void GameConsole::draw() {
	// Set the number of icons to display.
	unsigned int max_icons = 3;
	if (m_vIDs.size() < max_icons) {
		max_icons = m_vIDs.size();
	}

	// Some position variables.
	const unsigned int grid = WindowProperty::width / 3;
	unsigned int midpoint = (grid / 2) - (m_width / 2);

	// Icon loop.
	for (size_t i = 0; i < m_vIDs.size(); ++i) {
		int cpos = (WindowProperty::width / 2) - (grid * m_selected) + midpoint - (m_width / 2);

		if (x > cpos) {
			// Left.
			x -= 5;
		} else if (x < cpos) {
			// Right.
			x += 5;
		}

		m_pTextureManager->draw("all",
								atoi(m_mConsoles[m_vIDs[i]]["x"].c_str()),
								atoi(m_mConsoles[m_vIDs[i]]["y"].c_str()),
								x + (grid * i) - midpoint, m_ypos,
								m_width, m_height);
	}
}

/**
 *  Select the previous game console.
 */
void GameConsole::previous(Games *games) {
	if (m_selected > 0) {
		m_selected--;
		games->reset_selected();
	}

	#ifdef DEBUG
	cout << "Console selected: " << m_vIDs[m_selected] << endl;
	#endif
}

/**
 *  Select the next game console.
 */
void GameConsole::next(Games *games) {
	if (m_selected < (m_vIDs.size() - 1)) {
		m_selected++;
		games->reset_selected();
	}

	#ifdef DEBUG
	cout << "Console selected: " << m_vIDs[m_selected] << endl;
	#endif
}

/**
 *  Refresh the main positions (for resizing).
 */
void GameConsole::refresh_pos() {
	m_width = 100;
	m_height = 100;
	m_ypos = (WindowProperty::height / 3.5) - (m_height / 2);
	x = (WindowProperty::width / 2) - (m_width / 2);
}

/**
 *  Gets the ID of the currently selected game console.
 */
string GameConsole::get_selected_id() {
	return m_vIDs[m_selected];
}
