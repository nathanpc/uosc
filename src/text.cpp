/**
 *  text.cpp
 *  Renders text.
 *
 *  @author Nathan Campos <nathanpc@dreamintech.net>
 */

#include <iostream>
#include <string>
#include <map>
#include <cstdlib>
#include <SDL.h>
#include <SDL_ttf.h>

#include "text.h"
#include "window_properties.h"
using namespace std;


// FIXME: There's a huge memory leak somewhere in this class.



/**
 *  Constructor.
 */
Text::Text(string font_name, unsigned int font_size, SDL_Renderer *renderer) {
	m_pRenderer = renderer;

	// Initialize SDL_ttf library.
	if (TTF_Init() != 0) {
		cout << "TTF_Init() failed: " << TTF_GetError() << endl;
		SDL_Quit();
		exit(1);
	}

	// Load a font.
	m_pFont = TTF_OpenFont(font_name.c_str(), font_size);
	if (m_pFont == NULL) {
		cout << "TTF_OpenFont() failed: " << TTF_GetError() << endl;
		TTF_Quit();
		exit(1);
	}
}

/**
 *  Destructor.
 */
Text::~Text() {
	TTF_CloseFont(m_pFont);
	TTF_Quit();
}

/**
 *  Draws a texture.
 *
 *  @param id The texture ID.
 *  @param x Texture X position.
 *  @param y Texture Y position.
 *  @param width Texture width.
 *  @param height Texture height.
 */
void Text::print(string text, SDL_Color color, int x, int y, bool center) {
	SDL_Rect source;
	SDL_Rect destination;
	SDL_Surface *text_surface;
	SDL_Texture *text_texture;

	// Create surface from text.
	text_surface = TTF_RenderText_Solid(m_pFont, text.c_str(), color);
	if (text_surface == NULL) {
		cout << "TTF_RenderText_Solid() Failed: " << TTF_GetError() << endl;
		TTF_Quit();
		SDL_Quit();
		exit(1);
	}

	// Convert from surface to texture.
	text_texture = SDL_CreateTextureFromSurface(m_pRenderer, text_surface);
	SDL_FreeSurface(text_surface);

	// Get the text size for the source rectangle.
	SDL_QueryTexture(text_texture, NULL, NULL, &source.w, &source.h);

	// Set the positions and sizes for everything.
	source.x = 0;
	source.y = 0;
	destination.y = y;
	destination.w = source.w;
	destination.h = source.h;

	if (center) {
		destination.x = (WindowProperty::width / 2) - (source.w / 2);
	} else {
		destination.x = x;
	}

	// Copy the texture to the render buffer.
	SDL_RenderCopy(m_pRenderer, text_texture, &source, &destination);
}
