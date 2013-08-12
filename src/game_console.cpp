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

#include "texture_manager.h"
#include "game_console.h"
#include "window_properties.h"
using namespace std;

/**
 *  Constructor.
 */
GameConsole::GameConsole(SDL_Renderer *renderer) {
	// Initialize the TextureManager.
	m_pTextureManager = new TextureManager(renderer);

	// Set the defaults.
	m_width = 100;
	m_height = 100;
	m_ypos = (WindowProperty::height / 3.5) - (m_height / 2);
	m_selected = 0;
}

/**
 *  Adds a game console.
 *
 *  @param id Game console ID.
 *  @return True if everything works fine.
 */
bool GameConsole::add(string id, string logo) {
	// Prepare the console properties map.
	map<string, string> console;
	console["filename"] = logo;

	// Add.
	m_mConsoles[id] = console;
	m_vIDs.push_back(id);

	// Load the texture.
	if (!m_pTextureManager->load(id, console["filename"])) {
		cout << "Couldn't load image: " << console["filename"] << endl;
		return false;
	}

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
	unsigned int x = 0;
	const unsigned int spacing = WindowProperty::width / 3;
	unsigned int midpoint = (spacing / 2) - (m_width / 2);

	// Center the selected item.
	x -= spacing * (m_selected - 1);

	// Icon loop.
	for (size_t i = 0; i < m_vIDs.size(); ++i) {//max_icons; ++i) {
		m_pTextureManager->draw(m_vIDs[i], x + midpoint, m_ypos, m_width, m_height);

		x += spacing;
	}
}

/**
 *  Select the previous game console.
 */
void GameConsole::previous() {
	if (m_selected > 0) {
		m_selected--;
	}

	#ifdef DEBUG
	cout << "Console selected: " << m_vIDs[m_selected] << endl;
	#endif
}

/**
 *  Select the next game console.
 */
void GameConsole::next() {
	if (m_selected < (m_vIDs.size() - 1)) {
		m_selected++;
	}

	#ifdef DEBUG
	cout << "Console selected: " << m_vIDs[m_selected] << endl;
	#endif
}

/**
 *  Gets the ID of the currently selected game console.
 */
string GameConsole::get_selected_id() {
	return m_vIDs[m_selected];
}
