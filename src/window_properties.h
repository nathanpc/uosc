/**
 *  window_properties.h
 *  Window properties for SDL.
 *
 *  @author Nathan Campos <nathanpc@dreamintech.net>
 */

#ifndef WINDOW_PROPERTIES_H_
#define WINDOW_PROPERTIES_H_

class WindowProperty {
	public:
		// Window size.
		static unsigned int width;
		static unsigned int height;

		// Fixed FPS stuff.
		static const unsigned int FPS = 60;
		static const int DELAY_TIME = 1000.0f / FPS;

		// Functions.
		static void resize(unsigned int _width, unsigned int _height);
};

#endif
