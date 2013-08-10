/**
 *  window_properties.h
 *
 *  @author Nathan Campos <nathanpc@dreamintech.net>
 */

#ifndef WINDOW_PROPERTIES_H_
#define WINDOW_PROPERTIES_H_

class WindowProperty {
	public:
		static const unsigned int width = 640;
		static const unsigned int height = 480;

		// Fixed FPS stuff.
		static const unsigned int FPS = 60;
		static const int DELAY_TIME = 1000.0f / FPS;
};

#endif
