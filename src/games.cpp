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
}

/**
 *  Adds a game.
 *
 *  @param id Game console ID.
 *  @return True if everything works fine.
 */
bool Games::add(string console, map<string, string> games) {
	// Add.
	m_mGames[console] = games;
	m_vConsoles.push_back(console);

	return true;
}

/**
 *  Draws the games in the screen.
 */
void Games::draw() {
	// Some position variables.
	unsigned int y = m_ypos;
	const unsigned int spacing = 35;
	//unsigned int midpoint = (spacing / 2) - (m_width / 2);
	SDL_Color color = {255, 255, 255};

	// Center the selected item.
	y -= spacing * m_selected;

	// Icon loop.
	for (unsigned int i = 0; i < 7; ++i) {
		if (i >= m_selected) {
			m_pText->print("Testing", color, 0, y, true);
		}

		y += spacing;
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
void Games::next() {
	if (m_selected < 6) {//(m_vIDs.size() - 1)) {
		m_selected++;
	}

	#ifdef DEBUG
	cout << "Console selected: " << m_vIDs[m_selected] << endl;
	#endif
}
