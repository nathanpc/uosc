/**
 *  game_console.cpp
 *
 *  @author Nathan Campos <nathanpc@dreamintech.net>
 */

#include <iostream>
#include <string>
#include <map>

#include "texture_manager.h"
#include "game_console.h"
using namespace std;

/**
 *  Constructor.
 */
GameConsole::GameConsole(SDL_Renderer *renderer) {
	m_pTextureManager = new TextureManager(renderer);
}

bool GameConsole::add(string id) {
	map<string, string> console;
	console["filename"] = "assets/" + id + ".png";

	m_mConsoles[id] = console;

	if (!m_pTextureManager->load(id, console["filename"])) {
		cout << "Couldn't load image: " << console["filename"] << endl;
		return false;
	}

	return true;
}

void GameConsole::draw() {
	unsigned int x = 100;

	for (auto it = m_mConsoles.begin(); it != m_mConsoles.end(); ++it) {
		m_pTextureManager->draw(it->first, x, 100, 100, 100);
		x += 100;
	}
}
