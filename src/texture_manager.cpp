/**
 *  texture_manager.cpp
 *
 *  @author Nathan Campos <nathanpc@dreamintech.net>
 */

#include <iostream>
#include <string>
#include <map>
#include <SDL.h>
#include <SDL_image.h>

#include "texture_manager.h"
using namespace std;

/**
 *  Constructor.
 */
TextureManager::TextureManager(SDL_Renderer *renderer) {
	m_pRenderer = renderer;
}

bool TextureManager::load(string id, string file) {
	// Load image.
	SDL_Surface *temp_surface = IMG_Load(file.c_str());
	if (temp_surface == 0) {
		return false;
	}

	// Create a texture from the surface.
	SDL_Texture *texture;
	texture = SDL_CreateTextureFromSurface(m_pRenderer, temp_surface);
	SDL_FreeSurface(temp_surface);

	// Check if everything went fine.
	if (texture != 0) {
		m_mTextures[id] = texture;
		return true;
	}

	return false;
}

void TextureManager::draw(string id, unsigned int x, unsigned int y, unsigned int width, unsigned int height) {
	SDL_Rect source;
	SDL_Rect destination;

	// Get the texture size for the source rectangle.
	SDL_QueryTexture(m_mTextures[id], NULL, NULL, &source.w, &source.h);

	// Set the positions and sizes for everything.
	source.x = 0;
	source.y = 0;
	destination.x = x;
	destination.y = y;
	destination.w = width;
	destination.h = height;

	// Copy the texture to the render buffer.
	SDL_RenderCopy(m_pRenderer, m_mTextures[id], &source, &destination);
}
