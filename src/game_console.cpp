/**
 *  game_console.cpp
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

bool GameConsole::add(string id) {
	// Prepare the console properties map.
	map<string, string> console;
	console["filename"] = "assets/" + id + ".png";

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
	for (unsigned int i = 0; i < m_vIDs.size(); ++i) {//max_icons; ++i) {
		m_pTextureManager->draw(m_vIDs[i], x + midpoint, m_ypos, m_width, m_height);

		x += spacing;
	}
}

void GameConsole::previous() {
	if (m_selected > 0) {
		m_selected--;
	}

	#ifdef DEBUG
	cout << "Console selected: " << m_vIDs[m_selected] << endl;
	#endif
}

void GameConsole::next() {
	if (m_selected < (m_vIDs.size() - 1)) {
		m_selected++;
	}

	#ifdef DEBUG
	cout << "Console selected: " << m_vIDs[m_selected] << endl;
	#endif
}
