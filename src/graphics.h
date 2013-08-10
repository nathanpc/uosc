/**
 *  graphics.h
 *  Interacts with SDL.
 *
 *  @author Nathan Campos <nathanpc@dreamintech.net>
 */

#ifndef GRAPHICS_H_
#define GRAPHICS_H_

#include <string>
#include <vector>
#include <SDL.h>

#include "game_console.h"
#include "input_handler.h"

class Graphics {
	private:
		SDL_Window *m_pWindow;
		SDL_Renderer *m_pRenderer;
		GameConsole *m_pGameConsole;
		InputHandler *m_pInputHandler;

	public:
		bool g_bRunning;

		Graphics();
		~Graphics();

		bool init(const char *title, int x, int y, int width, int height, int flags);

		void update();
		void handle_events();
		void render();

		void clean();
};

#endif
