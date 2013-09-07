/**
 *  window_properties.cpp
 *  Window properties for SDL.
 *
 *  @author Nathan Campos <nathanpc@dreamintech.net>
 */

#include "window_properties.h"

unsigned int WindowProperty::width  = 1000;//640;
unsigned int WindowProperty::height = 600;//480;

/**
 *  "Resizes" the window.
 *
 *  @param _width Window width.
 *  @param _height Window height.
 */
void WindowProperty::resize(unsigned int _width, unsigned int _height) {
	width  = _width;
	height = _height;
}
