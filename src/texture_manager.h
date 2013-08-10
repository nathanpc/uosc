/**
 *  texture_manager.h
 *
 *  @author Nathan Campos <nathanpc@dreamintech.net>
 */

#ifndef TEXTURE_MANAGER_H_
#define TEXTURE_MANAGER_H_

#include <string>
#include <map>
#include <SDL.h>
#include <SDL_image.h>

class TextureManager {
	private:
		std::map<std::string, SDL_Texture*> m_mTextures;

	public:
		TextureManager();

		bool load(std::string id, std::string file, SDL_Renderer *renderer);
		void draw(std::string id, unsigned int x, unsigned int y, unsigned int width, unsigned int height, SDL_Renderer *renderer);
};

#endif
